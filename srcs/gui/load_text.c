#include "unknow_project.h"

void    load_letter(t_gui *gui, char *str, int idx)
{
    TTF_Font    *police;
    SDL_Color   color = {0, 0, 0};

    str[1] = '\0';
    police = TTF_OpenFont("ressources/assets/ttf/Tinos-Regular.ttf", 240);
    gui->letter[idx]->font = TTF_RenderText_Blended(police, str, color);
    gui->letter[idx]->let->surface->w = gui->letter[idx]->font->w;
    gui->letter[idx]->let->surface->h = gui->letter[idx]->font->h;
    gui->letter[idx]->let->surface->internalFormat = 4;
	gui->letter[idx]->let->surface->pixels = gui->letter[idx]->font->pixels;
    gui->letter[idx]->let->letter = str[0];
    TTF_CloseFont(police);
}

void    load_menu(t_gui *tmp)
{
    tmp->menu[0] = png_load("ressources/assets/imgs/Title_screen.png");
    tmp->menu[1] = png_load("ressources/assets/imgs/settings_screen.png");
    tmp->menu[2] = png_load("ressources/assets/imgs/controls_screen.png");
    tmp->menu[3] = png_load("ressources/assets/imgs/credits_screen.png");
    tmp->menu[4] = png_load("ressources/assets/imgs/pause_menu.png");
    tmp->menu[5] = png_load("ressources/assets/imgs/settings_pause_menu.png");
    tmp->menu[6] = png_load("ressources/assets/imgs/settings_pause_menu.png");
    tmp->menu[7] = png_load("ressources/assets/imgs/settings_pause_menu.png");
    tmp->menu[8] = png_load("ressources/assets/imgs/trainee.png");
    tmp->menu[9] = png_load("ressources/assets/imgs/recruit.png");
    tmp->menu[10] = png_load("ressources/assets/imgs/pirate.png");
    tmp->menu[11] = png_load("ressources/assets/imgs/pirate.png");
    tmp->menu[12] = png_load("ressources/assets/textures/balle.png");
    tmp->menu[13] = png_load("ressources/assets/textures/tdm2.png");
    tmp->menu[14] = png_load("ressources/assets/textures/press_key.png");
}
