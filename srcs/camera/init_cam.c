/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:23:40 by adjouber          #+#    #+#             */
/*   Updated: 2019/12/04 15:27:02 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_engine	*init_cam(t_engine *engine, t_window *win)
{
	t_camera	*main_camera;

	engine = initialize_t_engine(win);
	main_camera = t_camera_list_get(engine->visual_engine->camera_list, 0);
	t_engine_place_camera(engine, 0, create_t_vector4(5.0, 5.0, 0.0));
	t_camera_look_at_point(main_camera, create_t_vector4(0, 0, 0));
	t_engine_add_camera(engine, create_t_camera(win, create_t_vector4(0.0, 0.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
	resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(300, 240));
	move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(WIN_X - 300, 0));
	// t_engine_add_camera(engine, create_t_camera(win, create_t_vector4(0.0, 0.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(300, 240));
	// move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(300, 0));
	return(engine);
}
