/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:40:16 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/05 16:20:56 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		delete_t_window(t_window dest)
{
	int	i;

	i = 0;
	while (i < NB_THREAD_MAX)
	{
		delete_t_void_list(dest.data[i]);
		i++;
	}
}

void		free_t_window(t_window **dest)
{
	delete_t_window(**dest);
	ft_memdel((void**)dest);
}

void		delete_t_view_port(t_view_port dest)
{
	free_t_window(&dest.window);
}

void		free_t_view_port(t_view_port **dest)
{
	delete_t_view_port(**dest);
	ft_memdel((void**)dest);
}

void		delete_t_uv(t_uv dest)
{
	if (dest.texture != NULL)
		free_t_texture(&dest.texture);
}

void		free_t_uv(t_uv **dest)
{
	delete_t_uv(**dest);
	ft_memdel((void**)dest);
}

void		delete_t_uv_list(t_uv_list dest)
{
	if (dest.uvs != NULL)
		free_t_uv(&dest.uvs);
}
