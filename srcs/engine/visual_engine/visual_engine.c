/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:06:45 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/30 11:28:23 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_visual_engine	new_visual_engine(t_window *p_window)
{
	t_visual_engine	result;
	t_camera		tmp;

	result.camera_list = initialize_t_camera_list();
	result.main_camera = 0;
	result.textures_path = load_path_texture();
	tmp = new_camera(p_window, new_vec4(0, 0, 0), FOV,
									create_vec2(NEAR, FAR));
	t_camera_list_push_back(result.camera_list, tmp);
	return (result);
}

t_visual_engine	*initialize_t_visual_engine(t_window *p_window)
{
	t_visual_engine	*result;

	if (!(result = (t_visual_engine *)malloc(sizeof(t_visual_engine))))
		return (NULL);
	*result = new_visual_engine(p_window);
	return (result);
}

void			delete_t_visual_engine(t_visual_engine dest)
{
	free_t_camera_list(dest.camera_list);
}

void			free_t_visual_engine(t_visual_engine *dest)
{
	delete_t_visual_engine(*dest);
	free(dest);
}
