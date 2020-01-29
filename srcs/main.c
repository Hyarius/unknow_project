/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:24:27 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/29 17:14:54 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		exit_prog(void)
{
	Mix_CloseAudio();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
	tar_ressources();
}

void		begin_prog(t_engine **engine, t_gui **gui, char **argv)
{
	t_window	*win;
	
	untar_ressources();
	start_sdl();
	TTF_Init();
	Mix_Init(MIX_INIT_OGG);
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 1, 1024) == -1)
		error_exit(-100, (char*)Mix_GetError());
	win = initialize_t_window(argv[0], WIN_X, WIN_Y);
	*engine = initialize_t_engine(win);
	*gui = initialize_t_gui();
	load_menu(*gui);
	set_t_gui_texte(*gui);
	create_minimap(*engine);
}

void		load_textures(t_gui *gui, t_engine *engine)
{
	engine->visual_engine->textures_path = load_path_texture();
	gui->text_am[0] = png_load("ressources/assets/textures/pistol_ammo.png");
	gui->text_am[1] = png_load("ressources/assets/textures/ar_ammo.png");
	gui->text_am[2] = png_load("ressources/assets/textures/rifle_ammo.png");
	gui->text_am[3] = png_load("ressources/assets/textures/shotgun_ammo.png");
	gui->text_am[4] = png_load("ressources/assets/textures/wall_destroyer_ammo.png");
	gui->text_am[5] = png_load("ressources/assets/imgs/Hands_baby.png");
	gui->text_weap[0] = png_load("ressources/assets/imgs/pistol.png");
	gui->text_weap[1] = png_load("ressources/assets/imgs/ar.png");
	gui->text_weap[2] = png_load("ressources/assets/imgs/rifle.png");
	gui->text_weap[3] = png_load("ressources/assets/imgs/shotgun.png");
	gui->text_weap[4] = png_load("ressources/assets/imgs/wall_destroyer.png");
	gui->text_weap[5] = png_load("ressources/assets/imgs/Hands_baby.png");
	gui->text_weap[6] = png_load("ressources/assets/imgs/pistol_shoot_0.png");
	gui->text_weap[7] = png_load("ressources/assets/imgs/ar_shoot_0.png");
	gui->text_weap[8] = png_load("ressources/assets/imgs/rifle_shoot_0.png");
	gui->text_weap[9] = png_load("ressources/assets/imgs/shotgun_shoot_0.png");
	gui->text_weap[10] = png_load("ressources/assets/imgs/wall_destroyer_shoot_0.png");
	gui->skybox = png_load("ressources/assets/textures/skybox.png");
}

int			main(int argc, char **argv)
{
	t_engine		*engine;
	t_gui			*gui;
	t_playing_funct	playing_functions[6];
	t_camera		*camera;

	if (argc != 1)
		error_exit(-1, "Bad argument");
	engine = NULL;
	gui = NULL;
	begin_prog(&engine, &gui, argv);
	load_textures(gui, engine);
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	Mix_PlayMusic(engine->sound_engine->music[0], -1);
	playing_functions[0] = NULL;
	playing_functions[1] = display_tittle_screen;
	playing_functions[2] = game_playing;
	playing_functions[3] = game_pausing;
	playing_functions[4] = level_editing;
	playing_functions[5] = level_editing_pausing;
	camera = t_camera_list_get(engine->visual_engine->camera_list, 0);
	while (engine->playing != 0)
	{	
		prepare_screen(engine->win, new_color(0.2f, 0.2f, 0.2f, 1.0f));
		t_engine_prepare_camera(engine);
		if (engine->playing != 0)
			playing_functions[engine->playing](camera, gui, engine);
		t_engine_handle_event(camera, gui, engine);
		render_screen(engine);
	}
	exit_prog();
	return (0);
}
