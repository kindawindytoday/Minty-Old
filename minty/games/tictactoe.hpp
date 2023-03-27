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


const std::string image_x_b64 = "";
const std::string image_o_b64 = "";

static int tictactoe_state_array[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static int player_role = 0; //later ill add a switch for x or o
const char* get_tictactoe_name(int index, bool ignore_array = false)
{
    int state = ignore_array ? index : tictactoe_state_array[index];
    return (state == 1 && player_role == 0) || (state == 2 && player_role == 1) ? "x" :
           (state == 1 && player_role == 1) || (state == 2 && player_role == 0) ? "o" :
           " ";
}

int check_win(int board[9]) {

    for (int i = 0; i < 9; i += 3) {
        if (board[i] != 0 && board[i] == board[i+1] && board[i] == board[i+2]) {
            return board[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[i] != 0 && board[i] == board[i+3] && board[i] == board[i+6]) {
            return board[i];
        }
    }

    if (board[0] != 0 && board[0] == board[4] && board[0] == board[8]) {
        return board[0];
    }
    if (board[2] != 0 && board[2] == board[4] && board[2] == board[6]) {
        return board[2];
    }

    bool draw = true;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            draw = false;
            break;
        }
    }
    if (draw) {
        return 3;
    }

    return 0;
}

int minimax(int board[9], int player) {

    int result = check_win(board);
    if (result != 0) {
        if (result == 3) {
            return 0;
        } else if (result == 2) {
            return 1;
        } else {
            return -1;
        }
    }

    int best_score = (player == 1) ? 2 : -2;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            board[i] = player;
            int score = minimax(board, (player == 1) ? 2 : 1);
            board[i] = 0;

            if (player == 1) {
                best_score = min(best_score, score);
            } else {
                best_score = max(best_score, score);
            }
        }
    }

    return best_score;
}

int AI_Move(int board[9]) { //add a copy of the board, and rotate randomly when start, same for medium
    int best_move = -1;
    int best_score = -2;

    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            board[i] = 2;
            int score = minimax(board, 1);
            board[i] = 0;

            if (score > best_score) {
                best_score = score;
                best_move = i;
            }
        }
    }

    board[best_move] = 2;
    return best_move;
}

void ttt_easy_bot()
{
    srand(static_cast<unsigned int>(time(NULL)));

    int index = -1;
    bool found_empty_space = false;
    for (int i = 0; i < 9; i++) {
        if (tictactoe_state_array[i] == 0) {
            found_empty_space = true;
            break;
        }
    }
    if (found_empty_space) {
        do {
            index = rand() % 9;
        } while (tictactoe_state_array[index] != 0);
        tictactoe_state_array[index] = 2;
    }
}

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

int simulate_game(int board[9], int player) {
    int winner = 0;
    while (winner == 0) {

        int move = random(0, 8);
        while (board[move] != 0) {
            move = random(0, 8);
        }

        board[move] = player;
        winner = check_win(board);
        if (winner != 0) {
            break;
        }

        player = 3 - player;
    }
    return winner;
}

int ttt_medium_bot(int board[9], int player) {
    int counts[9] = {0};
    int wins[9] = {0};

    const int simulations = 69420;
    for (int i = 0; i < simulations; i++) {

        int copy[9];
        std::copy(board, board + 9, copy);

        int move = random(0, 8);
        while (copy[move] != 0) {
            move = random(0, 8);
        }

        copy[move] = player;
        int result = simulate_game(copy, 3 - player);

        counts[move]++;
        if (result == player) {
            wins[move]++;
        }
    }

    int best_move = -1;
    double best_rate = -1.0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            double rate = static_cast<double>(wins[i]) / counts[i];
            if (rate > best_rate) {
                best_rate = rate;
                best_move = i;
            }
        }
    }
    board[best_move] = player;
    return best_move;
}


static bool try_gameover_notif = false;
static bool ttt_is_my_turn = true;
static bool ttt_game_begun = false;

static int win = 0; //0=draw, 1=x wins, 2=o wins
static int ttt_score_x = 0;
static int ttt_score_o = 0;
static int ttt_difficulty_select_index = 1;

const char* ttt_difficulty_options[3] = {"Easy","Medium","Impossible"};
const char* ttt_player_options[2] = {"x", "o"};

void ttt_bot_turn(int difficulty)
{

    if (difficulty == 0)
    {
        ttt_easy_bot(); //easy its completely random 💀💀💀
    } 
    if (difficulty == 1) 
    {
        ttt_medium_bot(tictactoe_state_array, 2); //medium - Monte carlo algorithm
    } 
    if (difficulty == 2) 
    {
        AI_Move(tictactoe_state_array); //Impossible - Minmax algorithm
    } 

}

void clear_tictactoe_board() //fancy anims bc why NOT
{   
    ttt_is_my_turn = false;
    for (int j = 2; j >= 0; j--) 
    {
        for (int i = 0; i < 9; i++) 
        {
            tictactoe_state_array[i] = j;
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
        }
    }
    ttt_is_my_turn = true;
}


void round_logic_main()
{
    //add game begun check thing
    //add round turn logic - if i began this round, the next round ai will begin
    ttt_is_my_turn = false;
    std::this_thread::sleep_for(std::chrono::milliseconds(420));
    if (check_win(tictactoe_state_array) == 0)
    {
        ttt_bot_turn(ttt_difficulty_select_index);
        try_gameover_notif = true;
       
    }
     ttt_is_my_turn = true;
    
}


void tictactoe_main() 
{
    ImVec2 ttt_btn = ImVec2(48, 48);
    std::string score_txt = "x - " + std::to_string(ttt_score_x) + " o - " + std::to_string(ttt_score_o);
    ImGui::Text(score_txt.c_str());
   
    ImGui::Text(ttt_is_my_turn ? "Your turn!" : "My turn...");

    ImGui::BeginDisabled(ttt_game_begun);
    ImGui::SetNextItemWidth(120.0f);
    ImGui::Combo("Difficulty", &ttt_difficulty_select_index, ttt_difficulty_options, IM_ARRAYSIZE(ttt_difficulty_options));
    ImGui::SetNextItemWidth(40.0f);
    ImGui::Combo("Your role", &player_role , ttt_player_options, IM_ARRAYSIZE(ttt_player_options));

    ImGui::EndDisabled();

    //ImGui::BeginChild("Button Box", ImVec2(0, 0), false, ImGuiWindowFlags_NoResize);
    ImGui::BeginDisabled(!ttt_is_my_turn);

    ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, ImVec2(0.5f, 0.5f));
    if (true)
    {
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        { 
            int index = y*3+x;
            if(x>0){ImGui::SameLine();}

            ImGui::PushID(index);

            if(ImGui::Button(get_tictactoe_name(index), ttt_btn))
            {
                if(tictactoe_state_array[index] == 0)
                {
                    try_gameover_notif = true;
                    tictactoe_state_array[index] = 1;
                    std::thread TTT_Logic_Thread(round_logic_main); //SEPARATE Player Turn Logic ********************************************** <---------------
                    TTT_Logic_Thread.detach(); //remember to add score
                }

            }
            ImGui::PopID();
        }
    }
    }

    ImGui::PopStyleVar();

    ImGui::EndDisabled();
    //ImGui::EndChild();

    if(ImGui::Button("Reset game"))
    {
        std::thread TTT_Clear_Thread(clear_tictactoe_board);
        TTT_Clear_Thread.detach();
    }
    if(try_gameover_notif)
    {
        if(check_win(tictactoe_state_array) != 0)
        {
            ImGui::OpenPopup("Game Over!");
            try_gameover_notif = false;
        }
        else
        {
            try_gameover_notif = false;
        }
    }
    if(ImGui::BeginPopupModal("Game Over!", NULL, ImGuiWindowFlags_AlwaysAutoResize)) 
    {
        ImGui::Separator();
        switch (check_win(tictactoe_state_array))
        {
            case 1:
                ImGui::Text("Player %s wins!", get_tictactoe_name(1, true));
                break;
            case 2:
                ImGui::Text("Player %s wins!", get_tictactoe_name(2, true));
                break;
            case 3:
                ImGui::Text("It's a Draw!");
                break;
            default:
                ImGui::Text("No winners");
                break;
        }
        ImGui::Separator();

        ImGui::SameLine();
        if(ImGui::Button("New Game"))
        {
            ImGui::CloseCurrentPopup();
            std::thread TTT_Clear_Thread(clear_tictactoe_board);
            TTT_Clear_Thread.detach();
        }

        ImGui::EndPopup();
    }
}












