/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mesh_editor2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:18:22 by adjouber          #+#    #+#             */
/*   Updated: 2020/01/20 15:18:58 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		equals_move(t_engine *engine)
{
	t_mesh		*target;
	static int	press = 0;

	if (get_key_state(engine->user_engine->keyboard,
		engine->user_engine->keyboard->key[SDL_SCANCODE_EQUALS]) == 1
															&& press == 0)
	{
		target = cast_ray(engine,
			t_camera_list_get(engine->visual_engine->camera_list, 0)->pos,
			t_camera_list_get(engine->visual_engine->camera_list, 0)->forward,
																	"Player");
		if (target != NULL)
		{
			press = 1;
			t_mesh_move(target, new_vec4(0.0, 0.1, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard,
			engine->user_engine->keyboard->key[SDL_SCANCODE_EQUALS]) == 0)
		press = 0;
}

void		minus_move(t_engine *engine)
{
	t_mesh		*target;
	static int	press = 0;

	if (get_key_state(engine->user_engine->keyboard,
		engine->user_engine->keyboard->key[SDL_SCANCODE_MINUS]) == 1
															&& press == 0)
	{
		target = cast_ray(engine,
			t_camera_list_get(engine->visual_engine->camera_list, 0)->pos,
			t_camera_list_get(engine->visual_engine->camera_list, 0)->forward,
																	"Player");
		if (target != NULL)
		{
			press = 1;
			t_mesh_move(target, new_vec4(0.0, -0.1, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard,
			engine->user_engine->keyboard->key[SDL_SCANCODE_MINUS]) == 0)
		press = 0;
}
