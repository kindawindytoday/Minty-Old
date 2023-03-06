#include "includes.h"
//#include "lua/funcs.h"
#include "themes.h"
#include "res/fonts/font.h"
#include "gilua/luaHook.h"
//#include "lua/luaHook.cpp"
#include "lua/funcs.hpp"
#include "imgui/TextEditor.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}



LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);

}

bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)& pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
			ImGuiIO& io = ImGui::GetIO();
			ImFontConfig font;
			font.FontDataOwnedByAtlas = false;

			io.Fonts->AddFontFromMemoryTTF((void*)rawData, sizeof(rawData), 18.f, &font);
			io.Fonts->Build();
			ImGui_ImplDX11_InvalidateDeviceObjects();
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();

	// imgui code between newframe and render

	ImGui::NewFrame();
	ImGui::GetStyle().IndentSpacing = 7.0f;
	static float TimeScale = 1.0f;
	static bool showEditor = false; 
	ImGui::Begin("Minty");
	//ImGui::PushFont(font);
	ImGui::BeginTabBar("Minty");
	//auto gi_LL = luaL_newstate();

	if (ImGui::IsKeyDown(ImGui::GetKeyIndex(ImGuiKey_F11)))
	{
		TimeScale = 1.0f;
		std::string result = "CS.UnityEngine.Time.timeScale = 1.0";
		luahookfunc(result.c_str());
	}
	
	if (ImGui::BeginTabItem("Lua"))
	{
		if (ImGui::Button("Change UID")) {

			luahookfunc(char_changeuid);
		}

		if (ImGui::Button("Change Elemental Inf (visual)")) {
			luahookfunc(char_eleminf);
		}

		if (ImGui::Button("Spawn Browser")) {
			luahookfunc(char_browser);
		}

		static float boob_size = 1.0f;
		static bool show_resizer = false;
		
		if (ImGui::Checkbox("booba resizer", &show_resizer))
		{
		}

		if (show_resizer)
		{
			ImGui::SameLine();
			if (ImGui::Button("Initiate resize")) {
			boob_size = 1.0f;
			luahookfunc(char_bub_initiate);
			}
			ImGui::SameLine();
			if (ImGui::SliderFloat("Booba scale", &boob_size, 0.0f, 2.0f, "%.3f"))
			{
				std::string result = char_bub_resize + std::to_string(boob_size) + "," + std::to_string(boob_size) + "," + std::to_string(boob_size) + ")";
				luahookfunc(result.c_str());
			}
		}

		if (ImGui::Checkbox("Lua editor", &showEditor))
		{
			// Checkbox value has changed, do something here
		}
		static char inputTextBuffer[512] = "";

		ImGui::InputTextWithHint("##input", "Enter custom UID text here...", inputTextBuffer, sizeof(inputTextBuffer));

		ImGui::SameLine();
		if (ImGui::Button("Update custom UID")) {
			std::string result = R"MY_DELIMITER(CS.UnityEngine.GameObject.Find("/BetaWatermarkCanvas(Clone)/Panel/TxtUID"):GetComponent("Text").text = ")MY_DELIMITER" + std::string(inputTextBuffer) + "\"";
			luahookfunc(result.c_str());
		}
		
		if (ImGui::SliderFloat("Timescale", &TimeScale, 0.0f, 2.0f, "%.3f")) 
		{
			std::string result = "CS.UnityEngine.Time.timeScale = " + std::to_string(TimeScale);
			luahookfunc(result.c_str());
		}
		ImGui::SameLine();
		if (ImGui::Button("Reset")) {
			std::string result = "CS.UnityEngine.Time.timeScale = 1.0";
			luahookfunc(result.c_str());
		}


		ImGui::EndTabItem();
	}

if (showEditor)
{
    static TextEditor editor;
    static bool initialized = false;

    if (!initialized)
    {
        // Set the initial code and editor options
        editor.SetLanguageDefinition(TextEditor::LanguageDefinition::Lua());
		editor.SetPalette(TextEditor::GetDarkPalette());

        editor.SetTabSize(4);
        editor.SetShowWhitespaces(false);
		editor.SetColorizerEnable(true);
        initialized = true;
    }

    ImGui::Begin("Lua editor", &showEditor, ImGuiWindowFlags_MenuBar);

	if (ImGui::Button("Run"))
	{
		// Retrieve the text from the TextEditor
		std::string code = editor.GetText();
		
		// Call your function with the code string
		if (!code.empty())
		{
			luahookfunc(code.c_str());
		}
	}

	if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Save"))
				{
					auto textToSave = editor.GetText();
					/// save text....
				}
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Edit"))
			{
				bool ro = editor.IsReadOnly();
				if (ImGui::MenuItem("Read-only mode", nullptr, &ro))
					editor.SetReadOnly(ro);
				ImGui::Separator();

				if (ImGui::MenuItem("Undo", "ALT-Backspace", nullptr, !ro && editor.CanUndo()))
					editor.Undo();
				if (ImGui::MenuItem("Redo", "Ctrl-Y", nullptr, !ro && editor.CanRedo()))
					editor.Redo();

				ImGui::Separator();

				if (ImGui::MenuItem("Copy", "Ctrl-C", nullptr, editor.HasSelection()))
					editor.Copy();
				if (ImGui::MenuItem("Cut", "Ctrl-X", nullptr, !ro && editor.HasSelection()))
					editor.Cut();
				if (ImGui::MenuItem("Delete", "Del", nullptr, !ro && editor.HasSelection()))
					editor.Delete();
				if (ImGui::MenuItem("Paste", "Ctrl-V", nullptr, !ro && ImGui::GetClipboardText() != nullptr))
					editor.Paste();

				ImGui::Separator();

				if (ImGui::MenuItem("Select all", nullptr, nullptr))
					editor.SetSelection(TextEditor::Coordinates(), TextEditor::Coordinates(editor.GetTotalLines(), 0));

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("View"))
			{
				if (ImGui::MenuItem("Dark palette"))
					editor.SetPalette(TextEditor::GetDarkPalette());
				if (ImGui::MenuItem("Light palette"))
					editor.SetPalette(TextEditor::GetLightPalette());
				if (ImGui::MenuItem("Retro blue palette"))
					editor.SetPalette(TextEditor::GetRetroBluePalette());
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}

    // Draw the text editor
    editor.Render("TextEditor");

    ImGui::End();
}

	if (ImGui::BeginTabItem("Themes"))
	{
		// Content for themes
		ImGui::Text("Test..");

		static int selectedRadioButton = 0;

		if (ImGui::RadioButton("Default", &selectedRadioButton, 0))
		{
			ImGui::StyleColorsDark();
		}

		if (ImGui::RadioButton("Dark theme", &selectedRadioButton, 1))
		{
			dark_theme();
		}

		if (ImGui::RadioButton("Minty Red", &selectedRadioButton, 2))
		{
			minty_red_theme();
		}

		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("About"))
	{
		// Content for About
		ImGui::Text("Minty v0.5");
		ImGui::Text("ImGui version: %s", ImGui::GetVersion());
		ImGui::Text("Contributors: мятный пряник#0086, Moistcrafter#9172, yarik#4571, azzu#2731");
		ImGui::EndTabItem();
	}

	ImGui::EndTabBar();
	ImGui::End();
	ImGui::EndFrame();
	ImGui::Render();

	//end of imgui code
	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

//DWORD WINAPI MainThread(LPVOID lpReserved)
//{
//	bool init_hook = false;
//	do
//	{
//		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
//		{
//			kiero::bind(8, (void**)& oPresent, hkPresent);
//			init_hook = true;
//			//initLua();
//		}
//	} while (!init_hook);
//	return TRUE;
//}

//BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
//{
//	/*switch (dwReason)
//	{
//	case DLL_PROCESS_ATTACH:
//		DisableThreadLibraryCalls(hMod);
//		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
//		initLua();
//		break;
//	case DLL_PROCESS_DETACH:
//		kiero::shutdown();
//		break;
//	}
//	return TRUE;*/
//	initLua();
//	return TRUE;
//}
//HMODULE hMod = nullptr;
//DWORD start(LPVOID)
//{
//	//create thread initLua
//	//CreateThread(nullptr, 0, initLua, hMod, 0, nullptr);
//	CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
//	return 0;
//}
//BOOL WINAPI DllMain(HMODULE hMod, DWORD fdwReason, LPVOID lpvReserved)
//{
//	hMod = hMod;
//	if (fdwReason == DLL_PROCESS_ATTACH)
//		CloseHandle(CreateThread(NULL, 0, &start, NULL, NULL, NULL));
//	return TRUE;
//}
DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}
//BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
//{
//	//initLua();
//	//switch (dwReason)
//	//{
//	//case DLL_PROCESS_ATTACH:
//	//	//DisableThreadLibraryCalls(hMod);
//	//	CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
//	//	break;
//	//case DLL_PROCESS_DETACH:
//	//	kiero::shutdown();
//	//	break;
//	//}
//	//return TRUE;
//}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH) {
		CloseHandle(CreateThread(NULL, 0, &initLua, NULL, NULL, NULL));
		CreateThread(NULL, 0, &MainThread, NULL, NULL, NULL);
	}
	return TRUE;
}