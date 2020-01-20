/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:28:51 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/20 11:28:39 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	draw_minimap(t_camera *main_camera, t_engine *engine, t_window *win)
{
	t_camera	*cam;

	t_engine_place_camera(engine, 1, add_vec4(t_camera_list_get(
		engine->visual_engine->camera_list, 0)->pos,
		new_vec4(0.0, 7.0, 0.0)));
	t_camera_look_at_point(t_camera_list_get(
		engine->visual_engine->camera_list, 1),
		t_camera_list_get(engine->visual_engine->camera_list, 0)->pos);
	cam = t_camera_list_get(engine->visual_engine->camera_list, 1);
	compute_t_camera(cam);
	draw_triangle_from_camera_on_screen(cam);
}
