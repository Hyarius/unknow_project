/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_editor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:49:02 by adjouber          #+#    #+#             */
/*   Updated: 2020/01/20 13:15:20 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		print_info_editing(t_camera *main_camera, t_keyboard *key,
																	t_gui *gui)
{
	static int		r_press = 0;

	if (get_key_state(key, key->key[SDL_SCANCODE_R]) == 1 && r_press == 0)
	{
		if (gui->info_print == 0)
			gui->info_print = 1;
		else if (gui->info_print == 1)
			gui->info_print = 0;
		printf("%d\n", gui->info_print);
		r_press = 1;
	}
	else if (get_key_state(key, key->key[SDL_SCANCODE_R]) == 0)
		r_press = 0;
	if (gui->info_print == 1)
	{
		t_view_port_clear_buffers(main_camera->view_port);
		draw_rectangle_texture_cpu(main_camera->view_port,
			new_rectangle(create_vec2(-1.0, 1.0), create_vec2(2.0, -2.0)),
			gui->menu[12]);
		t_view_port_clear_buffers(main_camera->view_port);
		draw_rectangle_texture_cpu(main_camera->view_port,
			new_rectangle(create_vec2(-1.1, 0.86 - (0.079 * key->i)),
			create_vec2(0.7, 0.1)), gui->menu[13]);
	}
}

void		print_set_hp(t_camera *main_camera, t_gui *gui, t_player *player)
{
	if (player->hp == 100)
		draw_rectangle_texture_cpu(main_camera->view_port,
			new_rectangle(create_vec2(0.0, 0.11),
			create_vec2(0.4, 0.1)), gui->menu[13]);
	else if (player->hp == 50)
		draw_rectangle_texture_cpu(main_camera->view_port,
			new_rectangle(create_vec2(-0.38, 0.11),
			create_vec2(0.4, 0.1)), gui->menu[13]);
}

void		print_set_armor(t_camera *main_cam, t_gui *gui, t_player *player)
{
	if (player->armor == 100)
		draw_rectangle_texture_cpu(main_cam->view_port,
			new_rectangle(create_vec2(0.125, -0.33),
			create_vec2(0.4, 0.1)), gui->menu[13]);
	else if (player->armor == 50)
		draw_rectangle_texture_cpu(main_cam->view_port,
			new_rectangle(create_vec2(-0.145, -0.33),
			create_vec2(0.3, 0.1)), gui->menu[13]);
	else if (player->armor == 0)
		draw_rectangle_texture_cpu(main_cam->view_port,
			new_rectangle(create_vec2(-0.41, -0.33),
			create_vec2(0.2, 0.1)), gui->menu[13]);
}

void		print_set_player(t_camera *main_camera, t_gui *gui,
															t_engine *engine)
{
	t_player	*player;

	if (engine->user_engine->player->hitbox.name == NULL)
		return ;
	player = engine->user_engine->player;
	if (ft_strcmp(player->hitbox.name, "Player") == 0)
	{
		t_view_port_clear_buffers(main_camera->view_port);
		if (player->hitbox.kinetic == 100.0f)
			draw_rectangle_texture_cpu(main_camera->view_port,
				new_rectangle(create_vec2(-0.08, 0.55),
				create_vec2(0.7, 0.1)), gui->menu[13]);
		else if (player->hitbox.kinetic == 20.0f)
			draw_rectangle_texture_cpu(main_camera->view_port,
				new_rectangle(create_vec2(-0.61, 0.55),
				create_vec2(0.7, 0.1)), gui->menu[13]);
		print_set_hp(main_camera, gui, player);
		print_set_armor(main_camera, gui, player);
	}
}
