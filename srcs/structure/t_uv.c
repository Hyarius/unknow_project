/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_uv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:45:08 by jubeal            #+#    #+#             */
/*   Updated: 2020/02/07 15:08:18 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_uv	new_uv(t_triangle p_triangle, t_texture *p_texture)
{
	t_uv	result;

	result.texture = p_texture;
	result.uv = p_triangle;
	return (result);
}

t_uv	*initialize_t_uv(t_triangle p_triangle, t_texture *p_texture)
{
	t_uv	*result;

	if (!(result = (t_uv *)ft_memalloc(sizeof(t_uv))))
		return (NULL);
	*result = new_uv(p_triangle, p_texture);
	return (result);
}
