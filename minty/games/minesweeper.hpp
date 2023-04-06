#include "../imgui/imgui.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime> 
#include <future>
#include <chrono>
#include <thread>
#include <random>

static bool mswpr_isopen = false;
static bool mswpr_is_game_done = false;
static bool mswpr_show_mines = false;

static int mswpr_game_end_state = 0;
static int mswpr_flag_count = 0;
static int mswpr_grid_x = 1;
static int mswpr_grid_y = 1;

static float mswpr_btn_size_x = 15;
static float mswpr_btn_size_y = 15;

const char* mswpr_diffuculty[] = {"Easy", "Medium", "Hard"};
static int mswpr_difficulty_index = 0;

const char* mswpr_grid_size[] = {"8x8", "9x9", "16x16","30x16", "30x24"};
static int mswpr_grid_size_index = 0;

static int mswpr_cur_hover_item_index = 0;

void minesweeper_main()
{

    ImGui::BeginDisabled(mswpr_isopen);

    ImGui::Combo("Diffuculty", &mswpr_difficulty_index, mswpr_diffuculty, IM_ARRAYSIZE(mswpr_diffuculty));
    ImGui::Combo("Grid size", &mswpr_grid_size_index, mswpr_grid_size, IM_ARRAYSIZE(mswpr_grid_size));

    ImGui::EndDisabled();

    ImGui::SliderInt("grid X", &mswpr_grid_x, 1, 100);
    ImGui::SliderInt("grid Y", &mswpr_grid_y, 1, 100);

    if(ImGui::Button("Begin game"))
        mswpr_isopen = true;

    if (mswpr_isopen)
    {
        static float timer = 0;
        if (!mswpr_is_game_done)
        {
            timer += ImGui::GetIO().DeltaTime;
        }
        ImGui::Begin("Minesweeper", &mswpr_isopen);
        ImGui::Text("%d", (int)floor(timer));

        ImGui::Text("cur hovered item idx: %i", mswpr_cur_hover_item_index);
        ImGui::SeparatorText("");
        
        ImGui::BeginChild("child", ImVec2(0,0), false, ImGuiWindowFlags_AlwaysAutoResize);
        
        for (int y = 0; y < mswpr_grid_y; y++) {
            for (int x = 0; x < mswpr_grid_x; x++) { 
                int index = y*mswpr_grid_x+x;
                if(x>0){ImGui::SameLine();}

                ImGui::PushID(index);

                if(ImGui::Button(" ", ImVec2(mswpr_btn_size_x, mswpr_btn_size_y))) {
                    
                }

                if (ImGui::IsItemHovered()) {
                    mswpr_cur_hover_item_index = index;
                }
                // else {
                //     mswpr_cur_hover_item_index = 0;
                // }
                ImGui::PopID();
            }
        }
        ImGui::EndChild();

        ImGui::End();

    }
    
}












