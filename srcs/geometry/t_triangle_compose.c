/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_triangle_compose.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:29:33 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/17 11:29:54 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_triangle	compose_t_triangle_from_t_mesh(t_mesh *src, int *index)
{
	t_triangle	result;
	int			i;

	i = 0;
	while (i < 3)
	{
		if (src->vertices->size <= index[i])
			error_exit(-14, "can't compose a triangle");
		i++;
	}
	result.a = add_vector4_to_vector4(t_vector4_list_at(src->vertices,
														index[0]), src->pos);
	result.b = add_vector4_to_vector4(t_vector4_list_at(src->vertices,
														index[1]), src->pos);
	result.c = add_vector4_to_vector4(t_vector4_list_at(src->vertices,
														index[2]), src->pos);
	return (result);
}

t_triangle	compose_t_triangle_from_t_vertices(t_vector4_list *src, int *index)
{
	t_triangle	result;
	int			i;

	i = 0;
	while (i < 3)
	{
		if (src->size <= index[i])
			error_exit(-14, "can't compose a triangle");
		i++;
	}
	result.a = t_vector4_list_at(src, index[0]);
	result.b = t_vector4_list_at(src, index[1]);
	result.c = t_vector4_list_at(src, index[2]);
	return (result);
}
