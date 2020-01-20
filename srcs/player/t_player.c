/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:53:50 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/20 09:36:49 by gboutin          ###   ########.fr       */
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

void			player_take_dmg(t_engine *engine, int dmg)
{
	int		diff;

	if (engine->user_engine->player->armor != 0)
	{
		Mix_PlayChannel(4, engine->sound_engine->sounds[25], 0);
		if (engine->user_engine->player->armor >= dmg)
			engine->user_engine->player->armor -= dmg;
		else
		{
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
