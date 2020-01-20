/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:49:31 by adjouber          #+#    #+#             */
/*   Updated: 2020/01/20 14:18:04 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		player_editing(t_engine *engine, t_gui *gui)
{
	static int	b_press = 0;
	static int	print = 0;

	if (print == 1 && engine->playing == 10)
		print = 0;
	if (get_key_state(engine->user_engine->keyboard,
		engine->user_engine->keyboard->key[SDL_SCANCODE_B]) == 1
		&& b_press == 0)
	{
		print = 1;
		b_press = 1;
	}
	else if (get_key_state(engine->user_engine->keyboard,
		engine->user_engine->keyboard->key[SDL_SCANCODE_B]) == 0)
		b_press = 0;
	if (print == 1)
		engine->playing = 11;
}

void		map_editor(t_camera *cam, t_gui *gui, t_engine *engine, t_mesh_editing mesh_editing)
{
	t_mesh			*target;
	t_mesh			mesh;
	t_vec4		normal;
	static t_color	*color_armor = NULL;
	static int		click = 0;
	static int		l_press = 0;
	static int		i_press = 0;
	static int		b_press = 0;
	static int		left_press = 0;
	static int		right_press = 0;
	static int		up_press = 0;
	static int		down_press = 0;
	static int		equals_press = 0;
	static int		minus_press = 0;

	if (color_armor == NULL)
		color_armor = initialize_t_color(0.3, 0.3, 1.0, 1.0);

	t_view_port_clear_buffers(cam->view_port);
	draw_hud_rect(cam->view_port, new_rectangle(create_vec2(0.0, 0.0), create_vec2(0.005, 0.01)), color_armor);
	print_info_editing(cam, engine->user_engine->keyboard, gui);
	player_editing(engine, gui);
	if (get_mouse_state(engine->user_engine->mouse, MOUSE_RIGHT) == BOOL_TRUE && click == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL && ft_strcmp(target->name, "Player") != 0)
		{
			t_mesh_set_visibility(target, BOOL_FALSE);
			target->no_hitbox = 1;
		}
		click = 1;
	}
	else if (get_mouse_state(engine->user_engine->mouse, MOUSE_RIGHT) == BOOL_FALSE && click == 1)
		click = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_L]) == 1 && l_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL && ft_strcmp(target->name, "Player") != 0)
		{
			printf("here\n");
			if (target->no_hitbox == 0)
				target->no_hitbox = 1;
			else
				target->no_hitbox = 0;
			l_press = 1;
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_L]) == 0)
		l_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_I]) == 1 && i_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL && ft_strcmp(target->name, "Player") != 0)
		{
			printf("here\n");
			if (target->is_visible == 0)
				target->is_visible = 1;
			else
				target->is_visible = 0;
			i_press = 1;
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_I]) == 0)
		i_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_PERIOD]) == 1)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
			t_mesh_rotate(target, new_vec4(0.0, 10.0, 0.0));
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_COMMA]) == 1)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
			t_mesh_rotate(target, new_vec4(0.0, -10.0, 0.0));
	}
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_LEFT]) == 1 && left_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			left_press = 1;
			t_mesh_move(target, new_vec4(0.0, 0.0, 0.1));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_LEFT]) == 0)
		left_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_RIGHT]) == 1 && right_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			right_press = 1;
			t_mesh_move(target, new_vec4(0.0, 0.0, -0.1));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_RIGHT]) == 0)
		right_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_UP]) == 1 && up_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			up_press = 1;
			t_mesh_move(target, new_vec4(0.1, 0.0, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_UP]) == 0)
		up_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_DOWN]) == 1 && down_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			down_press = 1;
			t_mesh_move(target, new_vec4(-0.1, 0.0, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_DOWN]) == 0)
		down_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_EQUALS]) == 1 && equals_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			equals_press = 1;
			t_mesh_move(target, new_vec4(0.0, 0.1, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_EQUALS]) == 0)
		equals_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_MINUS]) == 1 && minus_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			minus_press = 1;
			t_mesh_move(target, new_vec4(0.0, -0.1, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_MINUS]) == 0)
		minus_press = 0;
}
