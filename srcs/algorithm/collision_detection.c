/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:09:40 by adjouber          #+#    #+#             */
/*   Updated: 2019/11/22 10:31:51 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

// void	sat_test(t_vector4 normale, t_vector4_list *vector_list,
// 				float *min, float *max)
// {
// 	int		i;
// 	float	dot_result;

// 	*min = INT_MAX;
// 	*max = INT_MIN;
// 	i = 0;
// 	while (i < vector_list->size)
// 	{
// 		dot_result = dot_t_vector4(normale, t_vector4_list_at(vector_list, i));
// 		if (dot_result < *min)
// 			*min = dot_result;
// 		if (dot_result > *max)
// 			*max = dot_result;
// 		i++;
// 	}
// }

int		sat_test(t_face *face, t_mesh *target, t_mesh *mesh_qui_bouge)
{
	t_triangle	tri_comp;
	t_triangle	tri_tar;
	t_face		*current;
	int			i;

	tri_tar.a = t_vector4_list_at(target->vertices_in_world, face->index_vertices[0]);
	tri_tar.b = t_vector4_list_at(target->vertices_in_world, face->index_vertices[1]);
	tri_tar.c = t_vector4_list_at(target->vertices_in_world, face->index_vertices[2]);
	i = 0;
	while (i < mesh_qui_bouge->faces->size)
	{
		if (mesh_qui_bouge->next_vertices_in_world->size == 0)
			break;
		current = t_face_list_get(mesh_qui_bouge->faces, i);
		tri_comp.a = t_vector4_list_at(mesh_qui_bouge->next_vertices_in_world, current->index_vertices[0]);
		tri_comp.b = t_vector4_list_at(mesh_qui_bouge->next_vertices_in_world, current->index_vertices[1]);
		tri_comp.c = t_vector4_list_at(mesh_qui_bouge->next_vertices_in_world, current->index_vertices[2]);
		if (triangles_intersection(tri_comp, tri_tar))
			return (BOOL_TRUE);
		i++;
	}
	return (BOOL_FALSE);
}

int		is_t_mesh_intersecting(t_mesh *mesh_qui_bouge, t_mesh *mesh_target)
{
	int		i;

	i = 0;
	while (i < mesh_target->faces->size)
	{
		if (sat_test(t_face_list_get(mesh_target->faces, i), mesh_target, mesh_qui_bouge))
			return (BOOL_TRUE);
		i++;
	}
	return (BOOL_FALSE);
}

// int		is_t_mesh_intersecting(t_mesh *mesh_compared, t_mesh *mesh_target)
// {
// 	int		i;
// 	float	val[4];


// 	if (mesh_compared->faces == NULL)
// 		error_exit(0,"is_t_mesh_intersecting");
// 	i = -1;
// 	while (++i < mesh_compared->faces->size)
// 	{
// 		sat_test(t_face_list_get(mesh_compared->faces, i)->normale,
// 			mesh_compared->next_vertices_in_world, &(val[0]), &(val[1]));
// 		sat_test(t_face_list_get(mesh_compared->faces, i)->normale,
// 			mesh_target->vertices_in_world, &(val[2]), &(val[3]));
// 		if (!is_mid(val[0], val[1], val[2]) && !is_mid(val[2], val[3], val[0]))
// 			return (BOOL_FALSE);
// 	}
// 	i = -1;
// 	while (++i < mesh_target->faces->size)
// 	{
// 		sat_test(t_face_list_get(mesh_target->faces, i)->normale,
// 			mesh_compared->next_vertices_in_world, &(val[0]), &(val[1]));
// 		sat_test(t_face_list_get(mesh_target->faces, i)->normale,
// 			mesh_target->vertices_in_world, &(val[2]), &(val[3]));
// 		if (!is_mid(val[0], val[1], val[2]) && !is_mid(val[2], val[3], val[0]))
// 			return (BOOL_FALSE);
// 	}
// 	return (BOOL_TRUE);
// }
