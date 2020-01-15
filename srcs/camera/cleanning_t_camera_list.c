/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanning_t_camera_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:31:22 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/09 14:31:37 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void			delete_t_camera_list(t_camera_list dest)
{
	free(dest.camera);
}

void			free_t_camera_list(t_camera_list *dest)
{
	delete_t_camera_list(*dest);
	free(dest);
}

void			clean_t_camera_list(t_camera_list *dest)
{
	dest->size = 0;
}
