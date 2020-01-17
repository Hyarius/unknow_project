/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:06:45 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/17 11:37:52 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_visual_engine	create_t_visual_engine(t_window *p_window)
{
	t_visual_engine	result;
	t_camera		tmp;

	result.camera_list = initialize_t_camera_list();
	result.main_camera = 0;
	tmp = create_t_camera(p_window, create_t_vector4(0, 0, 0), FOV,
									create_vec2(NEAR, FAR));
	t_camera_list_push_back(result.camera_list, tmp);
	return (result);
}

t_visual_engine	*initialize_t_visual_engine(t_window *p_window)
{
	t_visual_engine	*result;

	if (!(result = (t_visual_engine *)malloc(sizeof(t_visual_engine))))
		return (NULL);
	*result = create_t_visual_engine(p_window);
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
