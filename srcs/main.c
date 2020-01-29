/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:24:27 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/29 13:22:36 by jubeal           ###   ########.fr       */
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
}

int			main(int argc, char **argv)
{
	t_engine		*engine;
	t_gui			*gui;
	t_playing_funct	playing_functions[6];

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
	engine->playing = 2;
	while (engine->playing != 0)
	{
		prepare_screen(engine->win, new_color(0.2f, 0.2f, 0.2f, 1.0f));
		t_engine_prepare_camera(engine);
		if (engine->playing != 0)
			playing_functions[engine->playing](t_camera_list_get(engine->visual_engine->camera_list, 0), gui, engine);
		t_engine_handle_event(t_camera_list_get(engine->visual_engine->camera_list, 0), gui, engine);
		render_screen(engine);
	}
	exit_prog();
	return (0);
}
/*
int		main(int argc, char **argv)
{
	t_window		*win;
	t_texture		*skybox;
	t_engine		*engine;
	t_gui			*gui;
	t_mesh			mesh;
	t_rectangle		rec;
	t_mesh_editing	mesh_editing;
	char			**path;
	t_texture		*texture2[6];
	t_texture		*texture_weapons[16];

	if (argc != 1)
		error_exit(-1, "Bad argument");

	untar_ressources();
	Mix_Init(MIX_INIT_OGG);
	start_sdl();

	win = initialize_t_window(argv[0], WIN_X, WIN_Y);

	texture2[0] = png_load("ressources/assets/textures/pistol_ammo.png");
	texture2[1] = png_load("ressources/assets/textures/ar_ammo.png");
	texture2[2] = png_load("ressources/assets/textures/rifle_ammo.png");
	texture2[3] = png_load("ressources/assets/textures/shotgun_ammo.png");
	texture2[4] = png_load("ressources/assets/textures/wall_destroyer_ammo.png");
	texture2[5] = png_load("ressources/assets/imgs/Hands_baby.png");

	texture_weapons[0] = png_load("ressources/assets/imgs/pistol.png");
	texture_weapons[1] = png_load("ressources/assets/imgs/ar.png");
	texture_weapons[2] = png_load("ressources/assets/imgs/rifle.png");
	texture_weapons[3] = png_load("ressources/assets/imgs/shotgun.png");
	texture_weapons[4] = png_load("ressources/assets/imgs/wall_destroyer.png");
	texture_weapons[5] = png_load("ressources/assets/imgs/Hands_baby.png");
	texture_weapons[6] = png_load("ressources/assets/imgs/pistol_shoot_0.png");
	texture_weapons[7] = png_load("ressources/assets/imgs/ar_shoot_0.png");
	texture_weapons[8] = png_load("ressources/assets/imgs/rifle_shoot_0.png");
	texture_weapons[9] = png_load("ressources/assets/imgs/shotgun_shoot_0.png");
	texture_weapons[10] = png_load("ressources/assets/imgs/wall_destroyer_shoot_0.png");

	skybox = png_load("ressources/assets/textures/skybox.png");
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 1, 1024) == -1)
		error_exit(-100, (char*)Mix_GetError());
	engine = initialize_t_engine(win);
	gui = initialize_t_gui();

	load_menu(gui);
	TTF_Init();
	set_t_gui_texte(gui);

	create_minimap(engine);

	rec = new_rectangle(create_vec2(-1, 1), create_vec2(2, -2));
	path = load_path_texture();
	mesh = create_primitive_skybox(t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, new_vec4(1.0, 1.0, 1.0), skybox);
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	engine->playing = 2;
	Mix_PlayMusic(engine->sound_engine->music[0], -1);
	while (engine->playing != 0)
	{
		prepare_screen(engine->win, new_color(0.2f, 0.2f, 0.2f, 1.0f));
		t_engine_prepare_camera(engine);
		if (engine->playing != 1 || engine->playing != 10)
		{
			SDL_ShowCursor(SDL_ENABLE);
		}
		if (engine->playing == -1)
		{
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
			t_view_port_clear_buffers(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port);
			draw_rectangle_texture_cpu(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, rec, gui->menu[4]);
		}
		else if (engine->playing == -2)
		{
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
			t_view_port_clear_buffers(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port);
			draw_rectangle_texture_cpu(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, rec, gui->menu[5]);
		}
		else if (engine->playing == 2)
		{
			draw_rectangle_texture_cpu(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, rec, gui->menu[0]);
		}
		else if (engine->playing == 3)
		{
			draw_rectangle_texture_cpu(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, rec, gui->menu[1]);
		}
		else if (engine->playing == 4)
		{
			draw_rectangle_texture_cpu(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, rec, gui->menu[2]);
		}
		else if (engine->playing == 5)
		{
			draw_rectangle_texture_cpu(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, rec, gui->menu[3]);
		}
		else if (engine->playing == 6)
		{
			draw_rectangle_texture_cpu(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, rec, gui->menu[6]);
		}
		else if (engine->playing == 1)
		{
			mesh.pos = t_camera_list_get(engine->visual_engine->camera_list, 0)->pos;
			draw_t_mesh(t_camera_list_get(engine->visual_engine->camera_list, 0), &mesh);
			t_engine_render_camera(engine);
			SDL_ShowCursor(SDL_DISABLE);
			t_engine_apply_physic(engine);
			t_engine_handle_camera(engine, engine->win);
			t_engine_prepare_camera(engine);
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
			player_action(t_camera_list_get(engine->visual_engine->camera_list, 0), engine->user_engine->keyboard, engine, texture_weapons);
			enemy_look(engine);
			enemy_shoot(engine);
			enemy_move(engine);
			drawing_front_hp(t_camera_list_get(engine->visual_engine->camera_list, 0), engine->user_engine->player);
			drawing_front_mun(t_camera_list_get(engine->visual_engine->camera_list, 0), texture2, engine->user_engine->player);
			drawing_front_weapons(t_camera_list_get(engine->visual_engine->camera_list, 0), texture_weapons, engine->user_engine->player);
			draw_minimap(engine);
			print_info_bar(t_camera_list_get(engine->visual_engine->camera_list, 0), engine->user_engine->player, gui);
		}
		else if (engine->playing == 10)
		{
			mesh.pos = t_camera_list_get(engine->visual_engine->camera_list, 0)->pos;
			draw_t_mesh(t_camera_list_get(engine->visual_engine->camera_list, 0), &mesh);
			t_engine_render_camera(engine);
			SDL_ShowCursor(SDL_DISABLE);
			t_engine_apply_physic(engine);
			t_engine_handle_camera(engine, engine->win);
			t_engine_prepare_camera(engine);
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
			mesh_editing = select_mesh(engine->user_engine->keyboard, engine->user_engine->player->camera->pos, path);
			map_editor(t_camera_list_get(engine->visual_engine->camera_list, 0), gui, engine, mesh_editing);
		}
		else if (engine->playing == 11)
		{
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
			t_view_port_clear_buffers(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port);
			draw_rectangle_texture_cpu(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, rec, gui->menu[14]);
			print_set_player(t_camera_list_get(engine->visual_engine->camera_list, 0), gui, engine);
		}
		else if (engine->playing == 12)
		{
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
			t_view_port_clear_buffers(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port);
			draw_rectangle_texture_cpu(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, rec, gui->menu[15]);
			print_set_weapon(t_camera_list_get(engine->visual_engine->camera_list, 0), gui, engine);
		}
		else if (engine->playing == 13 || engine->playing == -3)
		{
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
			t_view_port_clear_buffers(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port);
			draw_rectangle_texture_cpu(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, rec, gui->menu[16]);
		}
		t_engine_handle_event(t_camera_list_get(engine->visual_engine->camera_list, 0), gui, engine);
		render_screen(engine);
	}
	Mix_CloseAudio();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
	tar_ressources();
	return (0);
}*/