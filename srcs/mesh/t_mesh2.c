/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mesh2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:33:36 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/05 16:44:35 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	t_mesh_add_uv(t_mesh *dest, t_vec4 new_uv)
{
	t_vec4_list_push_back(dest->uvs, new_uv);
}

void	t_mesh_add_point(t_mesh *dest, t_vec4 new_point)
{
	t_vec4_list_push_back(dest->vertices, new_point);
}

void	t_mesh_add_face(t_mesh *dest, t_face new_face)
{
	t_face_list_push_back(dest->faces, new_face);
}

void	t_mesh_apply_force(t_mesh *dest)
{
	dest->pos = add_vec4(dest->pos, dest->force);
	dest->center = add_vec4(dest->center, dest->force);
}

void	t_mesh_activate_gravity(t_mesh *dest, float gravity)
{
	dest->kinetic = gravity;
}
