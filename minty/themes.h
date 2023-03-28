#ifndef THEMES_H
#define THEMES_H

extern int fontindex_menu;
extern int theme_index;
extern int style_index;

static ImVec4 wordle_empty = ImVec4(0.07058f, 0.07058f, 0.07450f, 1.0f); //default = not guessed, dark grey
static ImVec4 wordle_guessed_noexist = ImVec4(0.22745f, 0.22745f, 0.23529f, 1.0f); //1 = guessed, letter doesnt exist, brighter grey
static ImVec4 wordle_guessed_wrongpos = ImVec4(0.70980f, 0.62352f, 0.23137f, 1.0f); //2 = guessed, letter exists but wrong position, yellow
static ImVec4 wordle_guessed_correct = ImVec4(0.32549f, 0.55294f, 0.30588f, 1.0f); //3 = guessed, letter exists and in right pos, green

void settheme(int themefunc_index);
void setstyle(int stylefunc_index);
void setfont(int fontfunc_index);

void dark_theme();
void minty_red_theme();
void mint_theme();
void mint_theme_light();

void default_style();
void round_compact_style();
void big_style();
void big_square_style();

#endif
#pragma once
