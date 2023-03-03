#include "includes.h"
#include "lua/funcs.h"
#include "themes.h"
#include "res/fonts/font.h"
#include "gilua/luahook.h"
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

	lua_State* L;

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();

	// imgui code between newframe and render

	ImGui::NewFrame();

	ImGui::GetStyle().IndentSpacing = 7.0f;
	static bool showEditor = false; // Declare showEditor variable
	ImGui::Begin("Minty");
	//ImGui::PushFont(font);
	ImGui::BeginTabBar("Minty");

	if (ImGui::BeginTabItem("Lua"))
	{
		if (ImGui::Button("Change UID"))
			load_lua_file(L, func_changeuid);

		// Content for Lua
		if (ImGui::Checkbox("Lua editor", &showEditor))
		{
			// Checkbox value has changed, do something here
		}

		ImGui::EndTabItem();
	}

	if (showEditor)
	{

		ImGui::Begin("Lua editor", &showEditor);
		if (ImGui::Button("Run"))
		{
		}
		static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;
		static char code[1024 * 128] = "";

		ImGui::InputTextMultiline("##code", code, IM_ARRAYSIZE(code),
			ImVec2(-1.0f, ImGui::GetContentRegionAvail().y - 30.0f), flags);

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
		ImGui::Text("Minty v69.420");
		ImGui::Text("ImGui version: %s", ImGui::GetVersion());
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

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)& oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}

//DWORD start(LPVOID)
//{
//	AllocConsole();
//	FILE* pConsoleIn = nullptr;
//	FILE* pConsoleOut = nullptr;
//	FILE* pConsoleErr = nullptr;
//	freopen_s(&pConsoleIn, "CONIN$", "r", stdin);
//	freopen_s(&pConsoleOut, "CONOUT$", "w", stdout);
//	freopen_s(&pConsoleErr, "CONOUT$", "w", stderr);
//
//	util::log("GILua by azzu\n");
//
//	/*auto dir = get_scripts_folder();
//	if (!dir)
//		return 0;*/
//
//	/*get_gi_L();
//
//	auto state = luaL_newstate();*/
//
//	// rsapatch breaks input, restore input mode
//	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE),
//		ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS |
//		ENABLE_PROCESSED_INPUT | ENABLE_QUICK_EDIT_MODE |
//		ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT
//	);
//
//	/*command_loop(state, dir.value());*/
//
//	return 0;
//}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved, HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		CloseHandle(CreateThread(NULL, 0, &start, NULL, NULL, NULL));
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}