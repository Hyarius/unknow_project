#include "unknow_project.h"

void    load_letter(t_gui *gui, char *str, int idx)
{
    TTF_Font    *police;
    SDL_Surface *font = NULL;
    SDL_Color color = {0, 0, 0};

    str[1] = '\0';
    police = TTF_OpenFont("ressources/assets/ttf/Tinos-Regular.ttf", 60);
    font = TTF_RenderText_Blended(police, str, color);
    gui->letter[idx]->surface->w = (GLuint)(font->w);
    gui->letter[idx]->surface->h = font->h;
    gui->letter[idx]->surface->internalFormat = 4;
    gui->letter[idx]->surface->pixels = (GLubyte *)malloc (sizeof (GLubyte) * gui->letter[idx]->surface->w * gui->letter[idx]->surface->h * gui->letter[idx]->surface->internalFormat);
	gui->letter[idx]->surface->pixels = font->pixels;
    gui->letter[idx]->letter = str[0];
    TTF_CloseFont(police);
}

char	**load_path_texture(void)
{
	char	**path;

	if (!(path = (char**)malloc(sizeof(char*) * 25)))
		error_exit(2, "error malloc");
	path[0] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[1] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[2] = ft_strdup("ressources/assets/textures/door.png");
	path[3] = ft_strdup("ressources/assets/textures/red_door.png");
	path[4] = ft_strdup("ressources/assets/textures/blue_door.png");
	path[5] = ft_strdup("ressources/assets/textures/green_door.png");
	path[6] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[7] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[8] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[9] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[10] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[11] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[12] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[13] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[14] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[15] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[16] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[17] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[18] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[19] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[20] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[21] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[22] = ft_strdup("ressources/assets/textures/window.png");
	path[23] = ft_strdup("ressources/assets/textures/cube_test.png");
	path[24] = ft_strdup("ressources/assets/textures/cube_test.png");
	return (path);
}

void    load_menu(t_gui *gui)
{
    gui->menu[0] = png_load("ressources/assets/imgs/Title_screen.png");
    gui->menu[1] = png_load("ressources/assets/imgs/settings_screen.png");
    gui->menu[2] = png_load("ressources/assets/imgs/controls_screen.png");
    gui->menu[3] = png_load("ressources/assets/imgs/credits_screen.png");
    gui->menu[4] = png_load("ressources/assets/imgs/pause_menu.png");
	gui->menu[5] = png_load("ressources/assets/imgs/settings_pause_menu.png");
    gui->menu[6] = png_load("ressources/assets/imgs/Play_menu.png");
    gui->menu[8] = png_load("ressources/assets/imgs/trainee.png");
    gui->menu[9] = png_load("ressources/assets/imgs/recruit.png");
    gui->menu[10] = png_load("ressources/assets/imgs/pirate.png");
    gui->menu[11] = png_load("ressources/assets/textures/press_key.png");
	gui->menu[12] = png_load("ressources/assets/imgs/Level_editor_menu.png");
	gui->menu[13] = png_load("ressources/assets/imgs/yellow_line.png");
	gui->menu[14] = png_load("ressources/assets/imgs/set_player.png");
	gui->menu[15] = png_load("ressources/assets/imgs/set_weapon.png");
	gui->menu[16] = png_load("ressources/assets/imgs/save_editor.png");
}
