/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:02:06 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/29 13:24:27 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	display_tittle_screen(t_camera *camera, t_gui *gui, t_engine *engine)
{
	t_rectangle		rec;

	(void)engine;
	SDL_ShowCursor(SDL_ENABLE);
	rec = new_rectangle(create_vec2(-1, 1), create_vec2(2, -2));
	draw_rectangle_texture_cpu(camera->view_port, rec, gui->menu[0]);
}

void	game_playing(t_camera *camera, t_gui *gui, t_engine *engine)
{
	t_mesh		mesh;

	mesh = create_primitive_skybox(camera->pos, new_vec4(1.0, 1.0, 1.0),
						png_load("ressources/assets/textures/skybox.png"));
	mesh.pos = camera->pos;
	draw_t_mesh(camera, &mesh);
	t_engine_render_camera(engine);
	SDL_ShowCursor(SDL_DISABLE);
	t_engine_apply_physic(engine);
	printf("HERE 1\n");
	t_engine_handle_camera(engine, engine->win);
	printf("HERE 3\n");
	t_engine_prepare_camera(engine);
	t_engine_draw_mesh(engine);
	t_engine_render_camera(engine);
	player_action(camera, engine->user_engine->keyboard,
										engine, gui->text_weap);
	enemy_look(engine);
	enemy_shoot(engine);
	enemy_move(engine);
	drawing_front_hp(camera, engine->user_engine->player);
	drawing_front_mun(camera, gui->text_am, engine->user_engine->player);
	drawing_front_weapons(camera, gui->text_weap,
								engine->user_engine->player);
	draw_minimap(engine);
	print_info_bar(camera, engine->user_engine->player, gui);
}

void	game_pausing(t_camera *camera, t_gui *gui, t_engine *engine)
{
	t_rectangle		rec;

	rec = new_rectangle(create_vec2(-1, 1), create_vec2(2, -2));
	SDL_ShowCursor(SDL_ENABLE);
	t_engine_draw_mesh(engine);
	t_engine_render_camera(engine);
	t_view_port_clear_buffers(camera->view_port);
	draw_rectangle_texture_cpu(camera->view_port, rec,
									gui->menu[engine->menu_nbr]);	
}

void	level_editing(t_camera *camera, t_gui *gui, t_engine *engine)
{
	t_mesh			mesh;
	t_mesh_editing	mesh_editing;

	mesh = create_primitive_skybox(camera->pos, new_vec4(1.0, 1.0, 1.0),
						png_load("ressources/assets/textures/skybox.png"));
	mesh.pos = camera->pos;
	draw_t_mesh(camera, &mesh);
	t_engine_render_camera(engine);
	SDL_ShowCursor(SDL_DISABLE);
	t_engine_apply_physic(engine);
	t_engine_handle_camera(engine, engine->win);
	t_engine_prepare_camera(engine);
	t_engine_draw_mesh(engine);
	t_engine_render_camera(engine);
	mesh_editing = select_mesh(engine->user_engine->keyboard,
		engine->user_engine->player->camera->pos,
		engine->visual_engine->textures_path);
	map_editor(camera, gui, engine, mesh_editing);
}

void	level_editing_pausing(t_camera *camera, t_gui *gui, t_engine *engine)
{
	t_rectangle		rec;

	rec = new_rectangle(create_vec2(-1, 1), create_vec2(2, -2));
	t_engine_draw_mesh(engine);
	t_engine_render_camera(engine);
	t_view_port_clear_buffers(camera->view_port);
	draw_rectangle_texture_cpu(camera->view_port, rec,
									gui->menu[engine->menu_nbr]);
	if (engine->menu_nbr == 14)
		print_set_player(camera, gui, engine);
	else if (engine->menu_nbr == 15)
		print_set_weapon(camera, gui, engine);
}
