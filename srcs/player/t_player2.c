/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:53:46 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/28 10:34:40 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	change_weapon(t_keyboard *p_keyboard, t_player *player)
{
	static int index = 0;

	if (ft_strcmp(player->current_weapon->name, "bb") == 0)
		index = 5;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_1]) == 1)
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

void	drawing_front_reload(t_camera *cam)
{
	static t_texture	*icon = NULL;

	if (icon == NULL)
		icon = png_load("ressources/assets/imgs/reload_icon.png");
	t_view_port_clear_buffers(cam->view_port);
	draw_rectangle_texture_cpu(cam->view_port, new_rectangle(
					create_vec2(0.1, 0.1), create_vec2(-0.2, -0.2)),
					icon);
}

void	reload_weapon(t_camera *camera, t_player *player, int tick,
						t_engine *engine)
{
	int			to_fill;
	t_weapon	*weapon;

	weapon = engine->user_engine->player->current_weapon;
	if (weapon->index == 5)
		return ;
	to_fill = weapon->mag_size - weapon->ammo;
	if (!Mix_Playing(5) && tick - player->reload_time == 0)
		Mix_PlayChannel(5, engine->sound_engine->sounds[weapon->index + 18], 0);
	if (tick - player->reload_time < weapon->tick_reload)
		drawing_front_reload(camera);
	if (tick - player->reload_time == weapon->tick_reload)
	{
		while (to_fill > 0 && weapon->ammo < weapon->mag_size
<<<<<<< HEAD
			&& weapon->total_ammo > 0 && (to_fill--) > -1)
=======
			&& weapon->total_ammo > 0)
>>>>>>> fad6ac1a9f1901434c0ebb151c92975df95b88ae
		{
			weapon->ammo++;
			weapon->total_ammo--;
			if (ft_strcmp(weapon->name, "pistol") == 0
				&& weapon->ammo == weapon->mag_size)
				weapon->total_ammo = 15;
		}
		camera->r_press = 0;
	}
}

void	shoot_weapon2(t_engine *engine, t_weapon *weapon, t_mesh *target,
						float dist)
{
	target = cast_ray(engine, t_camera_list_get(
	engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(
	engine->visual_engine->camera_list, 0)->forward, "Player");
	if (target != NULL && target->hp > 0)
	{
		if (ft_strcmp(weapon->name, "shotgun") == 0)
			dist = calc_dist_vec4(
				engine->user_engine->player->hitbox.pos, target->pos);
		if (weapon->dmg - dist * 4 >= 0)
			target->hp -= weapon->dmg - dist * 4;
		if (target->hp <= 0)
		{
			if (ft_strcmp(target->name, "wall_script") == 0)
			{
				Mix_PlayChannel(-1, engine->sound_engine->sounds[14], 0);
				t_mesh_activate_gravity(
					&engine->user_engine->player->hitbox, 0.0f);
				weapon->index = 5;
				change_weapon(engine->user_engine->keyboard,
					engine->user_engine->player);
			}
			destroy_mesh(target);
		}
	}
	Mix_PlayChannel(-1, engine->sound_engine->sounds[weapon->index + 7], 0);
}

void	shoot_weapon(t_engine *engine, t_camera *cam,
													t_texture **texture_weapons)
{
	t_mesh		*target;
	t_weapon	*weapon;
	float		dist;

	dist = 0.0;
	target = NULL;
	weapon = engine->user_engine->player->current_weapon;
	if (ft_strcmp(weapon->name, "bb") == 0)
		return ;
	if (t_mouse_state(engine->user_engine->mouse) == 1 && engine->tick
		% weapon->tick_shoot == 0)
	{
		if (weapon->ammo > 0)
		{
			t_view_port_clear_buffers(cam->view_port);
			draw_rectangle_texture_cpu(cam->view_port, new_rectangle(
			create_vec2(-0.65, -0.1), create_vec2(1.3, -0.9)),
			texture_weapons[weapon->index + 6]);
			shoot_weapon2(engine, weapon, target, dist);
			if (ft_strcmp(weapon->name, "ar") == 0)
				weapon->ammo -= 2;
			weapon->ammo--;
		}
		engine->user_engine->player->shoot_time = engine->tick;
	}
}
