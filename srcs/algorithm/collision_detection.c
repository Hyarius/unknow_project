/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:15:31 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/11 11:08:31 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_triangle		is_triangle_target(t_face *face, t_mesh *target)
{
	t_triangle	result;

	result.a = t_vec4_list_at(target->vertices_in_world,
													face->index_vertices[0]);
	result.b = t_vec4_list_at(target->vertices_in_world,
													face->index_vertices[1]);
	result.c = t_vec4_list_at(target->vertices_in_world,
													face->index_vertices[2]);
	return (result);
}

int				sat_test(t_face *face, t_mesh *target, t_mesh *moving_mesh)
{
	t_triangle	tri_comp;
	t_triangle	tri_tar;
	t_face		*current;
	int			i;
	float		dist;

	tri_tar = is_triangle_target(face, target);
	dist = fabs(calc_dist_vec4(moving_mesh->center, triangle_center(tri_tar)));
	if (dist < fabs(calc_dist_vec4(tri_tar.a, tri_tar.b))
	|| dist < fabs(calc_dist_vec4(tri_tar.a, tri_tar.c))
	|| dist < fabs(calc_dist_vec4(tri_tar.c, tri_tar.b)))
	{
		i = -1;
		while (++i < moving_mesh->faces->size)
		{
			if (moving_mesh->next_vertices_in_world->size == 0)
				break ;
			current = t_face_list_get(moving_mesh->faces, i);
			tri_comp.a = t_vec4_list_at(moving_mesh->next_vertices_in_world,
														current->index_vertices[0]);
			tri_comp.b = t_vec4_list_at(moving_mesh->next_vertices_in_world,
														current->index_vertices[1]);
			tri_comp.c = t_vec4_list_at(moving_mesh->next_vertices_in_world,
														current->index_vertices[2]);
			if (triangles_intersection(tri_comp, tri_tar))
				return (BOOL_TRUE);
		}
	}
	return (BOOL_FALSE);
}

int				mesh_intersect(t_mesh *mesh_compared, t_mesh *target)
{
	int		i;

	i = -1;
	while (++i < target->faces->size)
		if (sat_test(t_face_list_get(target->faces, i), target, mesh_compared))
			return (BOOL_TRUE);
	return (BOOL_FALSE);
}
