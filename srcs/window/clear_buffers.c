/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_buffers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:03:02 by jubeal            #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		t_view_port_clear_buffers(t_view_port *view)
{
	int i;

	i = -1;
	while (++i < view->window->size_x * view->window->size_y)
		view->depth_buffer[i] = INT_MAX;
}

void		window_handler_clear_buffers(t_window *win)
{
	int i;

	i = -1;
	while (++i < (win->size_x * win->size_y))
		win->color_data[i].a = 0;
}
