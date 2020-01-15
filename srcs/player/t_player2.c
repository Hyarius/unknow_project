/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:53:46 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 15:53:47 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void			change_weapon(t_keyboard *p_keyboard, t_player *player)
{
	static int index = 0;

	if (ft_strcmp(player->current_weapon->name, "bb") == 0)
	{
		index = 5;
		return ;
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_1]) == 1)
		index = 0;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_2]) == 1
										&& player->weapons[1].total_ammo >= 0)
		index = 1;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_3]) == 1
										&& player->weapons[2].total_ammo >= 0)
		index = 2;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_4]) == 1
										&& player->weapons[3].total_ammo >= 0)
		index = 3;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_5]) == 1
										&& player->weapons[4].total_ammo >= 0)
		index = 4;
	player->current_weapon = &player->weapons[index];
}

void			reload_weapon(t_camera *camera, t_player *player, int tick, t_engine *engine)
{
	int			to_fill;
	static int	i = 0;

	if (ft_strcmp(engine->user_engine->player->current_weapon->name, "pistol") == 0)
		i = 18;
	if (ft_strcmp(engine->user_engine->player->current_weapon->name, "ar") == 0)
		i = 19;
	if (ft_strcmp(engine->user_engine->player->current_weapon->name, "rifle") == 0)
		i = 20;
	if (ft_strcmp(engine->user_engine->player->current_weapon->name, "shotgun") == 0)
		i = 21;
	if (ft_strcmp(engine->user_engine->player->current_weapon->name, "rpg") == 0)
		i = 21;
	to_fill = player->current_weapon->mag_size - player->current_weapon->ammo;
	if (tick - player->reload_time == player->current_weapon->tick_reload)
	{
		while (to_fill > 0
			&& player->current_weapon->ammo < player->current_weapon->mag_size
			&& player->current_weapon->total_ammo > 0)
		{
			player->current_weapon->ammo++;
			player->current_weapon->total_ammo--;
			to_fill--;
			if (ft_strcmp(player->current_weapon->name, "pistol") == 0
			&& player->current_weapon->ammo == player->current_weapon->mag_size)
				player->current_weapon->total_ammo = 15;
		}
		camera->r_press = 0;
	}
	if (!Mix_Playing(5))
		Mix_PlayChannel(5, engine->sound_engine->sounds[i], 0);
}

void			shoot_weapon(t_engine *engine)
{
	t_mesh	*target;
	float	dist;
	static int	i = 0;

	// ajouter un ID sur les armes pour eviter ces IF
	if (ft_strcmp(engine->user_engine->player->current_weapon->name, "pistol") == 0)
		i = 7;
	if (ft_strcmp(engine->user_engine->player->current_weapon->name, "ar") == 0)
		i = 8;
	if (ft_strcmp(engine->user_engine->player->current_weapon->name, "rifle") == 0)
		i = 9;
	if (ft_strcmp(engine->user_engine->player->current_weapon->name, "shotgun") == 0)
		i = 10;
	if (ft_strcmp(engine->user_engine->player->current_weapon->name, "rpg") == 0)
		i = 11;
	dist = 0.0;
	if (t_mouse_state(engine->user_engine->mouse) == 1 && engine->tick % engine->user_engine->player->current_weapon->tick_shoot == 0)
	{
		if (engine->user_engine->player->current_weapon->ammo > 0)
		{
			Mix_PlayChannel(-1, engine->sound_engine->sounds[i], 0);
			target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
			if (target != NULL && target->hp > 0)
			{
				if (ft_strcmp(engine->user_engine->player->current_weapon->name, "shotgun") == 0)
					dist = calc_dist_vector4_to_vector4(engine->user_engine->player->hitbox.pos, target->pos);
				if (engine->user_engine->player->current_weapon->dmg - dist * 4 >= 0)
					target->hp -= engine->user_engine->player->current_weapon->dmg - dist * 4;
				if (target->hp <= 0)
				{
					if (ft_strcmp(target->name, "wall_script") == 0)
					{
						Mix_PlayChannel(-1, engine->sound_engine->sounds[14], 0);
						t_mesh_activate_gravity(&engine->user_engine->player->hitbox, 0.0f);
						engine->user_engine->player->current_weapon = &engine->user_engine->player->weapons[5];
					}
					destroy_mesh(target);
				}
			}
			if (ft_strcmp(engine->user_engine->player->current_weapon->name, "ar") == 0)
				engine->user_engine->player->current_weapon->ammo -= 2;
			engine->user_engine->player->current_weapon->ammo--;
		}
		engine->user_engine->player->shoot_time = engine->tick;
	}
}

void			player_action(t_camera *camera, t_keyboard *p_keyboard, t_engine *engine)
{
	static t_mesh	*door = NULL;
	static t_mesh	*elevator = NULL;
	t_mesh			*target;
	int				i;

	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_L]) == 1)
	{
		if (engine->user_engine->player->camera->body->kinetic != 0.0f)
			t_mesh_activate_gravity(engine->user_engine->player->camera->body, 0.0f);
		else
			t_mesh_activate_gravity(engine->user_engine->player->camera->body, 100.0f);
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_R]) == 1 && camera->r_press == 0
		&& engine->user_engine->player->current_weapon->mag_size - engine->user_engine->player->current_weapon->ammo != 0
		&& engine->user_engine->player->current_weapon->total_ammo != 0)
	{
		camera->r_press = 1;
		engine->user_engine->player->reload_time = engine->tick;
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_F]) == 1)
	{
		i = 0;
		while(i < engine->physic_engine->mesh_list->size && camera->f_press == 0)
		{
			target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
			if (camera->body != target && target->bubble_radius + camera->body->bubble_radius >= calc_dist_vector4_to_vector4(camera->body->center, target->center) && (ft_strcmp(target->name, "door") == 0 || ft_strcmp(target->name, "door") == '_'))
			{
				if (ft_strcmp(target->name, "door") == 0 || (ft_strcmp(target->name, "door_red") == 0
				&& engine->user_engine->player->red_card == 1) || (ft_strcmp(target->name, "door_blue") == 0
				&& engine->user_engine->player->blue_card == 1) || (ft_strcmp(target->name, "door_green") == 0
				&& engine->user_engine->player->green_card == 1))
				{
					target->door.move = 1;
					door = target;
				}
			}
			if (camera->body != target && target->bubble_radius + camera->body->bubble_radius >= calc_dist_vector4_to_vector4(camera->body->center, target->center) && ft_strcmp(target->name, "elevator") == 0)
			{
				target->door.move = 1;
				elevator = target;
			}
			i++;
		}
		camera->f_press = 1;
	}
	else
		camera->f_press = 0;
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_B]) == 1)
		save_map(engine, 1);
	change_weapon(engine->user_engine->keyboard, engine->user_engine->player);
	if (door != NULL)
		t_mesh_move_door(door, engine);
	if (elevator != NULL)
		t_mesh_move_elevator(elevator, camera);
	if (camera->r_press == 1)
		reload_weapon(camera, engine->user_engine->player, engine->tick, engine);
	if (engine->user_engine->player->shoot_time != engine->tick && camera->r_press != 1)
		shoot_weapon(engine);
	if (engine->user_engine->player->hp <= 0)
	{
		Mix_PlayChannel(-1, engine->sound_engine->sounds[15], 0);
		engine->playing = -3;
	}
}

void			player_take_dmg(t_engine *engine, int dmg)
{
	int		diff;

	if (engine->user_engine->player->armor != 0)
	{
		if (engine->user_engine->player->armor >= dmg)
		{
			//rajouter son degat armur
			engine->user_engine->player->armor -= dmg;
		}
		else
		{
			if (rand() % 2 == 0)
				Mix_PlayChannel(4, engine->sound_engine->sounds[16], 0);
			else
				Mix_PlayChannel(4, engine->sound_engine->sounds[17], 0);
			diff = dmg - engine->user_engine->player->armor;
			engine->user_engine->player->armor = 0;
			engine->user_engine->player->hp -= diff;
		}
	}
	else
	{
		if (rand() % 2 == 0)
			Mix_PlayChannel(4, engine->sound_engine->sounds[16], 0);
		else
			Mix_PlayChannel(4, engine->sound_engine->sounds[17], 0);
		engine->user_engine->player->hp -= dmg;
	}
}