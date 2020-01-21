/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:57:57 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/21 15:27:33 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	player_action2(t_keyboard *p_keyboard, t_engine *engine,
													t_camera *camera)
{
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_L]) == 1)
	{
		if (engine->user_engine->player->camera->body->kinetic != 0.0f)
			t_mesh_activate_gravity(engine->user_engine->player->camera->body,
									0.0f);
		else
			t_mesh_activate_gravity(engine->user_engine->player->camera->body,
									100.0f);
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_R]) == 1
		&& camera->r_press == 0
		&& engine->user_engine->player->current_weapon->mag_size
		- engine->user_engine->player->current_weapon->ammo != 0
		&& engine->user_engine->player->current_weapon->total_ammo != 0)
	{
		camera->r_press = 1;
		engine->user_engine->player->reload_time = engine->tick;
	}
}

void	player_action3(t_camera *camera, t_engine *engine, t_mesh **door,
																t_mesh *target)
{
	t_player		*player;

	player = engine->user_engine->player;
	if (camera->body != target && target->bubble_radius
	+ camera->body->bubble_radius
	>= calc_dist_vec4(camera->body->center,
	target->center) && (ft_strcmp(target->name, "door") == 0
	|| ft_strcmp(target->name, "door") == '_'))
	{
		if (ft_strcmp(target->name, "door") == 0
	|| (ft_strcmp(target->name, "door_red") == 0 && player->red_card == 1)
	|| (ft_strcmp(target->name, "door_blue") == 0 && player->blue_card == 1)
	|| (ft_strcmp(target->name, "door_green") == 0 && player->green_card == 1))
		{
			target->door.move = 1;
			door[0] = target;
		}
	}
	if (camera->body != target && target->bubble_radius
			+ camera->body->bubble_radius
			>= calc_dist_vec4(camera->body->center,
			target->center) && ft_strcmp(target->name, "elevator") == 0
			&& (target->door.move = 1))
		door[1] = target;
}

void	player_action4(t_camera *camera, t_engine *engine, t_mesh **door,
						t_texture **texture_weapons)
{
	change_weapon(engine->user_engine->keyboard, engine->user_engine->player);
	if (door[0] != NULL)
		t_mesh_move_door(door[0], engine);
	if (door[1] != NULL)
		t_mesh_move_elevator(door[1], camera->body);
	if (camera->r_press == 1)
		reload_weapon(camera, engine->user_engine->player, engine->tick,
																engine);
	if (engine->user_engine->player->shoot_time != engine->tick
			&& camera->r_press != 1)
		shoot_weapon(engine, camera, texture_weapons);
	if (engine->user_engine->player->hp <= 0)
	{
		Mix_PlayChannel(-1, engine->sound_engine->sounds[15], 0);
		engine->playing = -3;
	}
}

void	player_action(t_camera *camera, t_keyboard *p_keyboard,
						t_engine *engine, t_texture **texture_weapons)
{
	t_mesh			*target;
	static t_mesh	*door[2] = {NULL, NULL};
	int				i;

	player_action2(p_keyboard, engine, camera);
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_F]) == 1)
	{
		i = -1;
		while (++i < engine->physic_engine->mesh_list->size
			&& camera->f_press == 0)
		{
			target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
			player_action3(camera, engine, door, target);
		}
		camera->f_press = 1;
	}
	else
		camera->f_press = 0;
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_B]) == 1)
		save_map(engine, 1);
	player_action4(camera, engine, door, texture_weapons);
}
