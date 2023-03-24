#include "includes.h"
#include "themes.h"

int fontindex_menu = 1; // define variable in themes.cpp
int theme_index = 1;
int style_index = 1;

void settheme(int themefunc_index) {
	switch(themefunc_index) {
		case 1:
			ImGui::StyleColorsDark();
			theme_index = 1;
			break;
		case 2:
			ImGui::StyleColorsLight();
			theme_index = 2;
			break;
		case 3: 
			ImGui::StyleColorsClassic();
			theme_index = 3;
			break;
		case 4: 
			dark_theme();
			theme_index = 4;
			break;
		case 5:
			minty_red_theme();
			theme_index = 5;
			break;
		case 6:
			mint_theme();
			theme_index = 6;
			break;
		case 7:
			mint_theme_light();
			theme_index = 7;
			break;
		default:
			break;
	}
}

void setstyle(int stylefunc_index) {
	switch(stylefunc_index) {
		case 1:
			style_index = 1;
			round_compact_style();
			break;
		case 2:
			style_index = 2;
			big_style();
			break;
		case 3:
			style_index = 3;
			default_style();
			break;
		case 4:
			style_index = 4;
			big_square_style();
			break;
		default:
			break;
	}
}

void setfont(int fontfunc_index) {
    switch(fontfunc_index) {
        case 1:
            fontindex_menu = 1;
            break;
        case 2:
            fontindex_menu = 0;
            break;
		case 3:
			fontindex_menu = 2;
			break;
        default:
            break;
    }
}

void dark_theme()
{
  ImGuiStyle& style = ImGui::GetStyle();
  ImVec4* colors = ImGui::GetStyle().Colors;
  colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
  colors[ImGuiCol_WindowBg]               = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
  colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_PopupBg]                = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
  colors[ImGuiCol_Border]                 = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
  colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_FrameBg]                = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
  colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
  colors[ImGuiCol_FrameBgActive]          = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
  colors[ImGuiCol_TitleBg]                = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_TitleBgActive]          = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
  colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
  colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
  colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
  colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
  colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
  colors[ImGuiCol_CheckMark]              = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
  colors[ImGuiCol_SliderGrab]             = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
  colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
  colors[ImGuiCol_Button]                 = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
  colors[ImGuiCol_ButtonHovered]          = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
  colors[ImGuiCol_ButtonActive]           = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
  colors[ImGuiCol_Header]                 = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
  colors[ImGuiCol_HeaderHovered]          = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
  colors[ImGuiCol_HeaderActive]           = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
  colors[ImGuiCol_Separator]              = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
  colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
  colors[ImGuiCol_SeparatorActive]        = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
  colors[ImGuiCol_ResizeGrip]             = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
  colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
  colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
  colors[ImGuiCol_Tab]                    = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
  colors[ImGuiCol_TabHovered]             = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
  colors[ImGuiCol_TabActive]              = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
  colors[ImGuiCol_TabUnfocused]           = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
  colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
  colors[ImGuiCol_PlotLines]              = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogram]          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
  colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
  colors[ImGuiCol_TableBorderLight]       = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
  colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
  colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
  colors[ImGuiCol_DragDropTarget]         = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
  colors[ImGuiCol_NavHighlight]           = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
  colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
  colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);

}

void mint_theme()
{
	ImGui::StyleColorsDark();
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_FrameBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.01f, 0.35f, 0.20f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.01f, 0.69f, 0.40f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.01f, 0.48f, 0.28f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 0.51f, 0.29f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.08f, 0.72f, 0.48f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.13f, 0.43f, 0.31f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.82f, 0.47f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.43f, 0.25f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.79f, 0.45f, 1.00f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 0.63f, 0.36f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.55f, 0.31f, 1.00f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.40f, 0.23f, 1.00f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.00f, 0.75f, 0.43f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.00f, 0.68f, 0.39f, 1.00f);
}

void mint_theme_light()
{
	ImGui::StyleColorsLight();
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_FrameBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.01f, 0.35f, 0.20f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.01f, 0.69f, 0.40f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.01f, 0.48f, 0.28f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 0.51f, 0.29f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.08f, 0.72f, 0.48f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.13f, 0.43f, 0.31f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.82f, 0.47f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.43f, 0.25f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.79f, 0.45f, 1.00f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 0.63f, 0.36f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.55f, 0.31f, 1.00f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.05f, 0.90f, 0.54f, 1.00f);
	colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.40f, 0.23f, 1.00f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.00f, 0.75f, 0.43f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.00f, 0.68f, 0.39f, 1.00f);
}

void minty_red_theme()
{
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(0.75f, 0.75f, 0.75f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.94f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.37f, 0.14f, 0.14f, 0.67f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.39f, 0.20f, 0.20f, 0.67f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.48f, 0.16f, 0.16f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.48f, 0.16f, 0.16f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.56f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 0.19f, 0.19f, 0.40f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.89f, 0.00f, 0.19f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(1.00f, 0.19f, 0.19f, 0.40f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.80f, 0.17f, 0.00f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.89f, 0.00f, 0.19f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.33f, 0.35f, 0.36f, 0.53f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.76f, 0.28f, 0.44f, 0.67f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.47f, 0.47f, 0.47f, 0.67f);
	colors[ImGuiCol_Separator] = ImVec4(0.32f, 0.32f, 0.32f, 1.00f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.32f, 0.32f, 0.32f, 1.00f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.32f, 0.32f, 0.32f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
	colors[ImGuiCol_Tab] = ImVec4(0.07f, 0.07f, 0.07f, 0.51f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.86f, 0.23f, 0.43f, 0.67f);
	colors[ImGuiCol_TabActive] = ImVec4(0.19f, 0.19f, 0.19f, 0.57f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.05f, 0.05f, 0.05f, 0.90f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.13f, 0.13f, 0.13f, 0.74f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.07f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

void round_compact_style()
{
  ImGuiStyle& style = ImGui::GetStyle();
  style.WindowPadding                     = ImVec2(8.00f, 8.00f);
  style.FramePadding                      = ImVec2(5.00f, 2.00f);
  style.CellPadding                       = ImVec2(6.00f, 6.00f);
  style.ItemSpacing                       = ImVec2(6.00f, 6.00f);
  style.ItemInnerSpacing                  = ImVec2(6.00f, 6.00f);
  style.TouchExtraPadding                 = ImVec2(0.00f, 0.00f);
  style.IndentSpacing                     = 25;
  style.ScrollbarSize                     = 15;
  style.GrabMinSize                       = 10;
  style.WindowBorderSize                  = 1;
  style.ChildBorderSize                   = 0;
  style.PopupBorderSize                   = 0;
  style.FrameBorderSize                   = 1;
  style.TabBorderSize                     = 1;
  style.WindowRounding                    = 7;
  style.ChildRounding                     = 4;
  style.FrameRounding                     = 3;
  style.PopupRounding                     = 4;
  style.ScrollbarRounding                 = 9;
  style.GrabRounding                      = 3;
  style.LogSliderDeadzone                 = 4;
  style.TabRounding                       = 4;
}

void big_style()
{
  ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(15, 15);
	style.WindowRounding = 5.0f;
	style.FramePadding = ImVec2(5, 5);
	style.FrameRounding = 4.0f;
	style.ItemSpacing = ImVec2(12, 8);
	style.ItemInnerSpacing = ImVec2(8, 6);
	style.IndentSpacing = 25.0f;
	style.ScrollbarSize = 15.0f;
	style.ScrollbarRounding = 9.0f;
	style.GrabMinSize = 5.0f;
	style.GrabRounding = 3.0f;
}

void big_square_style()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(15, 15);
	style.WindowRounding = 0.0f;
	style.FramePadding = ImVec2(5, 5);
	style.FrameRounding = 0.0f;
	style.ItemSpacing = ImVec2(12, 8);
	style.ItemInnerSpacing = ImVec2(8, 6);
	style.IndentSpacing = 25.0f;
	style.ScrollbarSize = 15.0f;
	style.ScrollbarRounding = 0.0f;
	style.GrabMinSize = 5.0f;
	style.GrabRounding = 0.0f;
	style.TabRounding = 0.0f;
}

void default_style()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.Alpha                   = 1.0f;             
    style.DisabledAlpha           = 0.60f;            
    style.WindowPadding           = ImVec2(8,8);      
    style.WindowRounding          = 0.0f;             
    style.WindowBorderSize        = 1.0f;             
    style.WindowMinSize           = ImVec2(32,32);    
    style.WindowTitleAlign        = ImVec2(0.0f,0.5f);
    style.WindowMenuButtonPosition= ImGuiDir_Left;    
    style.ChildRounding           = 0.0f;             
    style.ChildBorderSize         = 1.0f;             
    style.PopupRounding           = 0.0f;             
    style.PopupBorderSize         = 1.0f;             
    style.FramePadding            = ImVec2(4,3);      
    style.FrameRounding           = 0.0f;             
    style.FrameBorderSize         = 0.0f;             
    style.ItemSpacing             = ImVec2(8,4);      
    style.ItemInnerSpacing        = ImVec2(4,4);      
    style.CellPadding             = ImVec2(4,2);      
    style.TouchExtraPadding       = ImVec2(0,0);      
    style.IndentSpacing           = 21.0f;            
    style.ColumnsMinSpacing       = 6.0f;             
    style.ScrollbarSize           = 14.0f;            
    style.ScrollbarRounding       = 9.0f;             
    style.GrabMinSize             = 12.0f;            
    style.GrabRounding            = 0.0f;             
    style.LogSliderDeadzone       = 4.0f;             
    style.TabRounding             = 4.0f;             
    style.TabBorderSize           = 0.0f;             
    style.TabMinWidthForCloseButton = 0.0f;           
    style.ColorButtonPosition     = ImGuiDir_Right;   
    style.ButtonTextAlign         = ImVec2(0.5f,0.5f);
    style.SelectableTextAlign     = ImVec2(0.0f,0.0f);
    style.SeparatorTextBorderSize = 3.0f;             
    style.SeparatorTextAlign      = ImVec2(0.0f,0.5f);
    style.SeparatorTextPadding    = ImVec2(20.0f,3.f);
    style.DisplayWindowPadding    = ImVec2(19,19);    
    style.DisplaySafeAreaPadding  = ImVec2(3,3);      
    style.MouseCursorScale        = 1.0f;             
    style.AntiAliasedLines        = true;             
    style.AntiAliasedLinesUseTex  = true;             
    style.AntiAliasedFill         = true;             
    style.CurveTessellationTol    = 1.25f;            
    style.CircleTessellationMaxError = 0.30f;
}