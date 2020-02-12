/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_recovery_in_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:35:44 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/10 17:21:12 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_camera		t_camera_list_at(t_camera_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_camera_list out of range");
	return (dest->camera[index]);
}

t_camera		*t_camera_list_get(t_camera_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-25, "t_camera_list out of range");
	return (&(dest->camera[index]));
}
