/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:40:31 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/17 11:41:03 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		t_engine_place_camera(t_engine *engine, int index,
															t_vector4 p_new_pos)
{
	t_camera_list_get(engine->visual_engine->camera_list,
													index)->pos = p_new_pos;
}

void		t_engine_camera_look_at(t_engine *engine, int index,
															t_vector4 target)
{
	t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list,
																index), target);
	compute_t_camera(t_camera_list_get(engine->visual_engine->camera_list,
																		index));
}

void		t_engine_render_camera(t_engine *engine)
{
	if (engine->playing == 10)
		t_visual_engine_render_first_camera(engine->visual_engine);
	else
		t_visual_engine_render_camera(engine->visual_engine);
}

void		t_engine_prepare_camera(t_engine *engine)
{
	t_visual_engine_prepare_camera(engine->visual_engine);
}

void		t_engine_add_camera(t_engine *p_engine, t_camera new_camera)
{
	t_visual_engine_add_camera(p_engine->visual_engine, new_camera);
}
