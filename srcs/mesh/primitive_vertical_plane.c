/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive_vertical_plane.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:26:12 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/07 11:28:45 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		t_mesh_init_uv_point_primitive_vertical_plane(t_mesh *result)
{
	t_mesh_add_uv(result, create_t_vector4(0.0f, 0.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(1.0f, 0.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(0.0f, 1.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(1.0f, 1.0f, 0.0f));
}

t_mesh		create_primitive_vertical_plane(t_vector4 pos, t_vector4 size,
											char *texture_path, float gravity)
{
	t_mesh	result;
	t_face	tmp_face;

	result = create_t_mesh(pos);
	result.primitive = 2;
	result.size = create_t_vector4(size.x, size.y, size.z);
	t_mesh_activate_gravity(&result, gravity);
	t_mesh_add_point(&result, create_t_vector4(-size.x, -size.z, 0.0));
	t_mesh_add_point(&result, create_t_vector4(size.x, -size.z, 0.0));
	t_mesh_add_point(&result, create_t_vector4(size.x, size.z, 0.0));
	t_mesh_add_point(&result, create_t_vector4(-size.x, size.z, 0.0));
	t_mesh_init_uv_point_primitive_vertical_plane(&result);
	tmp_face = create_t_face();
	set_t_face_vertices(&tmp_face, 2, 1, 3);
	set_t_face_uvs(&tmp_face, 4, 3, 1);
	t_mesh_add_face(&result, tmp_face);
	tmp_face = create_t_face();
	set_t_face_vertices(&tmp_face, 0, 1, 3);
	set_t_face_uvs(&tmp_face, 0, 1, 3);
	t_mesh_add_face(&result, tmp_face);
	t_mesh_compute_normals(&result);
	t_mesh_compute_bubble_box(&result);
	if (texture_path != NULL)
		result.texture = png_load(texture_path);
	return (result);
}
