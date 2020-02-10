/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_t_camera_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:31:22 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/10 14:36:41 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void			free_t_camera_list(t_camera_list **dest)
{
	int	i;

	i = -1;
	while (++i < (*dest)->size)
		delete_t_cam(t_camera_list_at(*dest, i));
	ft_memdel((void**)dest);
}

void			clean_t_camera_list(t_camera_list *dest)
{
	dest->size = 0;
}
