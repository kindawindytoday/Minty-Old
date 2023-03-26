#include "../imgui/imgui.h"
#include <string>
void lightsout_main()
{

    static char sailor_selected[4][4] = { { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } };
    const float time = (float)ImGui::GetTime();
    const bool sailor_winning_state = memchr(sailor_selected, 0, sizeof(sailor_selected)) == NULL;

    if (sailor_winning_state)
    {
        ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, ImVec2(0.5f + 0.5f * cosf(time * 2.0f), 0.5f + 0.5f * sinf(time * 3.0f)));
    }
    else
    {
        ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, ImVec2(0.5f, 0.5f));
    }

    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
        {
            if (x > 0)
                ImGui::SameLine();
                
            ImGui::PushID(y * 4 + x);
            if (ImGui::Selectable("o", sailor_selected[y][x] != 0, 0, ImVec2(45, 45)))
            {
                // Toggle clicked cell + toggle neighbors
                sailor_selected[y][x] ^= 1;
                if (x > 0) { sailor_selected[y][x - 1] ^= 1; }
                if (x < 3) { sailor_selected[y][x + 1] ^= 1; }
                if (y > 0) { sailor_selected[y - 1][x] ^= 1; }
                if (y < 3) { sailor_selected[y + 1][x] ^= 1; }
            }
            ImGui::PopID();
        }

    if (sailor_winning_state)
    {
        ImGui::PopStyleVar();
    }
    else
    {
    ImGui::PopStyleVar();
    }

    if(ImGui::Button("Reset"))
    {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                sailor_selected[i][j] = (i == j) ? 1 : 0;
            }
        }
    }
    //ImGui::SameLine();
}