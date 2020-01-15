/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_uv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:45:08 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 15:46:05 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_uv	create_t_uv(t_triangle p_triangle, t_texture *p_texture)
{
	t_uv	result;

	result.texture = p_texture;
	result.uv = p_triangle;
	return (result);
}

t_uv	*initialize_t_uv(t_triangle p_triangle, t_texture *p_texture)
{
	t_uv	*result;

	if (!(result = (t_uv *)malloc(sizeof(t_uv))))
		return (NULL);
	*result = create_t_uv(p_triangle, p_texture);
	return (result);
}
