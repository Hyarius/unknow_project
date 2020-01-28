/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:24:27 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/28 10:32:44 by jubeal           ###   ########.fr       */
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

t_camera	*begin_prog(t_window *win, t_engine *engine, t_gui *gui,
														char **argv)
{
	t_camera		*main_camera;

	untar_ressources();
	Mix_Init(MIX_INIT_OGG);
	start_sdl();
	TTF_Init();
	win = initialize_t_window(argv[0], WIN_X, WIN_Y);
	engine = initialize_t_engine(win);
	gui = initialize_t_gui();
	load_menu(gui);
	set_t_gui_texte(gui);
	main_camera = t_camera_list_get(engine->visual_engine->camera_list, 0);
	t_engine_place_camera(engine, 0, new_vec4(5.0, 5.0, 0.0));
	t_camera_look_at_point(main_camera, new_vec4(0, 0, 0));
	t_engine_add_camera(engine, new_camera(win, new_vec4(0.0, 0.0, 0.0), 70,
										create_vec2(NEAR, FAR)));
	resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)
										->view_port, create_vec2_int(300, 240));
	move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)
								->view_port, create_vec2_int(WIN_X - 300, 0));
	return (main_camera);
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
	t_window		*win;
	t_engine		*engine;
	t_gui			*gui;
	void			(*playing_functions[6])(t_camera *main_camera, t_gui *gui,
						t_engine *engin, t_window *win);
	t_camera		*main_camera;

	if (argc != 1)
		error_exit(-1, "Bad argument");
	main_camera = begin_prog(win, engine, gui, argv);
	load_textures(gui, engine);
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 1, 1024) == -1)
		error_exit(-100, (char*)Mix_GetError());
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	Mix_PlayMusic(engine->sound_engine->music[0], -1);
	playing_functions[0] = NULL;
	playing_functions[1] = display_tittle_screen;
	playing_functions[2] = game_playing;
	playing_functions[3] = game_pausing;
	playing_functions[4] = level_editing;
	playing_functions[5] = level_editing_pausing;
	engine->playing = 1;
	while (engine->playing != 0)
	{
		prepare_screen(win, new_color(0.2f, 0.2f, 0.2f, 1.0f));
		t_engine_prepare_camera(engine);
		if (engine->playing != 0)
			playing_functions[engine->playing](t_camera_list_get(engine->visual_engine->camera_list, 0), gui, engine, win);
		t_engine_handle_event(t_camera_list_get(engine->visual_engine->camera_list, 0), gui, engine, win);
		render_screen(win, engine);
	}
	exit_prog();
	return (0);
}

// int		main(int argc, char **argv)
// {
// 	t_window		*win;
// 	t_texture		*skybox;
// 	t_engine		*engine;
// 	t_gui			*gui;
// 	t_mesh			mesh;
// 	t_camera		*main_camera;
// 	t_rectangle		rec;
// 	t_mesh_editing	mesh_editing;
// 	char			**path;
// 	t_texture		*texture2[6];
// 	t_texture		*texture_weapons[16];

// 	if (argc != 1)
// 		error_exit(-1, "Bad argument");

// 	untar_ressources();
// 	Mix_Init(MIX_INIT_OGG);
// 	start_sdl();

// 	win = initialize_t_window(argv[0], WIN_X, WIN_Y);

// 	texture2[0] = png_load("ressources/assets/textures/pistol_ammo.png");
// 	texture2[1] = png_load("ressources/assets/textures/ar_ammo.png");
// 	texture2[2] = png_load("ressources/assets/textures/rifle_ammo.png");
// 	texture2[3] = png_load("ressources/assets/textures/shotgun_ammo.png");
// 	texture2[4] = png_load("ressources/assets/textures/wall_destroyer_ammo.png");
// 	texture2[5] = png_load("ressources/assets/imgs/Hands_baby.png");

// 	texture_weapons[0] = png_load("ressources/assets/imgs/pistol.png");
// 	texture_weapons[1] = png_load("ressources/assets/imgs/ar.png");
// 	texture_weapons[2] = png_load("ressources/assets/imgs/rifle.png");
// 	texture_weapons[3] = png_load("ressources/assets/imgs/shotgun.png");
// 	texture_weapons[4] = png_load("ressources/assets/imgs/wall_destroyer.png");
// 	texture_weapons[5] = png_load("ressources/assets/imgs/Hands_baby.png");
// 	texture_weapons[6] = png_load("ressources/assets/imgs/pistol_shoot_0.png");
// 	texture_weapons[7] = png_load("ressources/assets/imgs/ar_shoot_0.png");
// 	texture_weapons[8] = png_load("ressources/assets/imgs/rifle_shoot_0.png");
// 	texture_weapons[9] = png_load("ressources/assets/imgs/shotgun_shoot_0.png");
// 	texture_weapons[10] = png_load("ressources/assets/imgs/wall_destroyer_shoot_0.png");

// 	skybox = png_load("ressources/assets/textures/skybox.png");
// 	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 1, 1024) == -1)
// 		error_exit(-100, (char*)Mix_GetError());
// 	engine = initialize_t_engine(win);
// 	gui = initialize_t_gui();

// 	load_menu(gui);
// 	TTF_Init();
// 	set_t_gui_texte(gui);

// 	main_camera = t_camera_list_get(engine->visual_engine->camera_list, 0);
// 	t_engine_place_camera(engine, 0, new_vec4(5.0, 5.0, 0.0));
// 	t_camera_look_at_point(main_camera, new_vec4(0, 0, 0));
// 	t_engine_add_camera(engine, new_camera(win, new_vec4(0.0, 0.0, 0.0), 70, create_vec2(NEAR, FAR)));
// 	resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_vec2_int(300, 240));
// 	move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_vec2_int(WIN_X - 300, 0));

// 	rec = new_rectangle(create_vec2(-1, 1), create_vec2(2, -2));
// 	path = load_path_texture();
// 	mesh = create_primitive_skybox(main_camera->pos, new_vec4(1.0, 1.0, 1.0), skybox);
// 	Mix_VolumeMusic(MIX_MAX_VOLUME);
// 	engine->playing = 2;
// 	Mix_PlayMusic(engine->sound_engine->music[0], -1);
// 	while (engine->playing != 0)
// 	{
// 		prepare_screen(win, new_color(0.2f, 0.2f, 0.2f, 1.0f));
// 		t_engine_prepare_camera(engine);
// 		if (engine->playing != 1 || engine->playing != 10)
// 		{
// 			SDL_ShowCursor(SDL_ENABLE);
// 		}
// 		if (engine->playing == -1)
// 		{
// 			t_engine_draw_mesh(engine);
// 			t_engine_render_camera(engine);
// 			t_view_port_clear_buffers(main_camera->view_port);
// 			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[4]);
// 		}
// 		else if (engine->playing == -2)
// 		{
// 			t_engine_draw_mesh(engine);
// 			t_engine_render_camera(engine);
// 			t_view_port_clear_buffers(main_camera->view_port);
// 			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[5]);
// 		}
// 		else if (engine->playing == 2)
// 		{
// 			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[0]);
// 		}
// 		else if (engine->playing == 3)
// 		{
// 			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[1]);
// 		}
// 		else if (engine->playing == 4)
// 		{
// 			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[2]);
// 		}
// 		else if (engine->playing == 5)
// 		{
// 			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[3]);
// 		}
// 		else if (engine->playing == 6)
// 		{
// 			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[6]);
// 		}
// 		else if (engine->playing == 1)
// 		{
// 			mesh.pos = main_camera->pos;
// 			draw_t_mesh(main_camera, &mesh);
// 			t_engine_render_camera(engine);
// 			SDL_ShowCursor(SDL_DISABLE);
// 			t_engine_apply_physic(engine);
// 			t_engine_handle_camera(engine, win);
// 			t_engine_prepare_camera(engine);
// 			t_engine_draw_mesh(engine);
// 			t_engine_render_camera(engine);
// 			player_action(main_camera, engine->user_engine->keyboard, engine, texture_weapons);
// 			enemy_look(engine);
// 			enemy_shoot(engine);
// 			enemy_move(engine);
// 			drawing_front_hp(main_camera, engine->user_engine->player);
// 			drawing_front_mun(main_camera, texture2, engine->user_engine->player);
// 			drawing_front_weapons(main_camera, texture_weapons, engine->user_engine->player);
// 			draw_minimap(main_camera, engine, win);
// 			print_info_bar(main_camera, engine->user_engine->player, gui);
// 		}
// 		else if (engine->playing == 10)
// 		{
// 			mesh.pos = main_camera->pos;
// 			draw_t_mesh(main_camera, &mesh);
// 			t_engine_render_camera(engine);
// 			SDL_ShowCursor(SDL_DISABLE);
// 			t_engine_apply_physic(engine);
// 			t_engine_handle_camera(engine, win);
// 			t_engine_prepare_camera(engine);
// 			t_engine_draw_mesh(engine);
// 			t_engine_render_camera(engine);
// 			mesh_editing = select_mesh(engine->user_engine->keyboard, engine->user_engine->player->camera->pos, path);
// 			map_editor(main_camera, gui, engine, mesh_editing);
// 		}
// 		else if (engine->playing == 11)
// 		{
// 			t_engine_draw_mesh(engine);
// 			t_engine_render_camera(engine);
// 			t_view_port_clear_buffers(main_camera->view_port);
// 			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[14]);
// 			print_set_player(main_camera, gui, engine);
// 		}
// 		else if (engine->playing == 12)
// 		{
// 			t_engine_draw_mesh(engine);
// 			t_engine_render_camera(engine);
// 			t_view_port_clear_buffers(main_camera->view_port);
// 			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[15]);
// 			print_set_weapon(main_camera, gui, engine);
// 		}
// 		else if (engine->playing == 13 || engine->playing == -3)
// 		{
// 			t_engine_draw_mesh(engine);
// 			t_engine_render_camera(engine);
// 			t_view_port_clear_buffers(main_camera->view_port);
// 			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[16]);
// 		}
// 		t_engine_handle_event(main_camera, gui, engine, win);
// 		render_screen(win, engine);
// 	}
// 	Mix_CloseAudio();
// 	Mix_Quit();
// 	TTF_Quit();
// 	SDL_Quit();
// 	tar_ressources();
// 	return (0);
// }