/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:53:50 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/16 12:19:52 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_player		create_t_player(t_camera *cam)
{
	t_player	result;

	result.camera = cam;
	result.shoot_time = 10;
	result.speed = 1.0;
	return (result);
}

t_player		*initialize_t_player(t_camera *cam)
{
	t_player *result;

	if (!(result = (t_player *)malloc(sizeof(t_player))))
		error_exit(-13, "Can't create a t_player array");
	*result = create_t_player(cam);
	return (result);
}

void			create_t_weapons2(int index, int ammo, int total_ammo,
									t_weapon *result)
{
	result[2].dmg = 50;
	result[2].tick_shoot = 2;
	result[2].tick_reload = 3;
	result[3].name = "shotgun";
	result[3].ammo = ammo;
	result[3].mag_size = 8;
	result[3].max_ammo = result[3].mag_size * MAX_MAGS;
	result[3].total_ammo = total_ammo;
	result[3].dmg = 120;
	result[3].tick_shoot = 2;
	result[3].tick_reload = 3;
	result[4].name = "rpg";
	result[4].ammo = ammo;
	result[4].mag_size = 1;
	result[4].max_ammo = result[4].mag_size * MAX_MAGS;
	result[4].total_ammo = total_ammo;
	result[4].dmg = 200000;
	result[4].tick_shoot = 1;
	result[4].tick_reload = 4;
	result[5].name = "bb";
	result[5].ammo = 2;
	result[5].total_ammo = 1;
	result[5].dmg = 0;
}

t_weapon		create_t_weapons(int index, int ammo, int total_ammo)
{
	t_weapon	result[6];

	result[0].name = "pistol";
	result[0].ammo = ammo;
	result[0].mag_size = 15;
	result[0].max_ammo = result[0].mag_size * MAX_MAGS;
	result[0].total_ammo = total_ammo;
	result[0].dmg = 10;
	result[0].tick_shoot = 1;
	result[0].tick_reload = 2;
	result[1].name = "ar";
	result[1].ammo = ammo;
	result[1].mag_size = 30;
	result[1].max_ammo = result[1].mag_size * MAX_MAGS;
	result[1].total_ammo = total_ammo;
	result[1].dmg = 25;
	result[1].tick_shoot = 1;
	result[1].tick_reload = 2;
	result[2].name = "rifle";
	result[2].ammo = ammo;
	result[2].mag_size = 10;
	result[2].max_ammo = result[2].mag_size * MAX_MAGS;
	result[2].total_ammo = total_ammo;
	create_t_weapons2(index, ammo, total_ammo, result);
	return (result[index]);
}

void			player_take_dmg(t_engine *engine, int dmg)
{
	int		diff;

	if (engine->user_engine->player->armor != 0)
	{
		if (engine->user_engine->player->armor >= dmg)
			engine->user_engine->player->armor -= dmg;
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
