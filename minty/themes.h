#ifndef THEMES_H
#define THEMES_H

extern int fontindex_menu;
extern int theme_index;
extern int style_index;

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
