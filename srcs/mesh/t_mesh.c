/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mesh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:04:38 by gboutin           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/20 11:25:41 by jubeal           ###   ########.fr       */
=======
/*   Updated: 2020/01/20 11:28:39 by gboutin          ###   ########.fr       */
>>>>>>> 58d0095a255fb66f686e5516ec18f8f993391c05
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_mesh	new_mesh(t_vec4 pos)
{
	t_mesh		result;

	result.camera = NULL;
	result.primitive = 10;
	result.pos = pos;
	result.is_visible = BOOL_TRUE;
	result.center = pos;
	result.bubble_radius = 0.0;
	result.collectible = 0;
	result.force = new_vec4(0.0, 0.0, 0.0);
	result.kinetic = 0.0;
	result.angle = new_vec4(0.0, 90.0, 0.0);
	result.texture = NULL;
	result.name = NULL;
	result.no_hitbox = 0;
	result.hp = 0;
	result.vertices_in_world = initialize_t_vec4_list();
	result.next_vertices_in_world = initialize_t_vec4_list();
	result.vertices = initialize_t_vec4_list();
	result.uvs = initialize_t_vec4_list();
	result.faces = initialize_t_face_list();
	result.normales = initialize_t_vec4_list();
	result.rotation = new_vec4(0.0, 0.0, 0.0);
	t_mesh_look_at(&result);
	return (result);
}

void	delete_t_mesh(t_mesh mesh)
{
	free_t_vec4_list(mesh.vertices);
	free_t_vec4_list(mesh.uvs);
	free(mesh.faces->face);
	free(mesh.faces);
}

void	free_t_mesh(t_mesh *mesh)
{
	delete_t_mesh(*mesh);
	free(mesh);
}

<<<<<<< HEAD

void	t_mesh_rotate_around_point(t_mesh *mesh, t_vector4 delta_angle, t_vector4 center)
{
	t_matrix	translate;
	t_matrix	rotation;
	t_matrix	inv_translate;
	t_vector4	*target;
	int			i;

	translate = create_translation_matrix(substract_vector4_to_vector4(center, \
																	mesh->pos));
	inv_translate = create_translation_matrix(inv_t_vector4(\
							substract_vector4_to_vector4(center, mesh->pos)));
	rotation = create_rotation_matrix(delta_angle.x, delta_angle.y,\
													delta_angle.z);
	mesh->angle = add_vector4_to_vector4(mesh->angle, delta_angle);
	t_mesh_look_at(mesh);
	i = -1;
	while (++i < mesh->vertices->size)
	{
		target = t_vector4_list_get(mesh->vertices, i);
		*target = mult_vector4_by_matrix(*target, inv_translate);
		*target = mult_vector4_by_matrix(*target, rotation);
		*target = mult_vector4_by_matrix(*target, translate);
	}
	t_mesh_compute_normals(mesh);
	t_mesh_compute_bubble_box(mesh);
}



void	t_mesh_add_uv(t_mesh *dest, t_vector4 new_uv)
{
	t_vector4_list_push_back(dest->uvs, new_uv);
}

void	t_mesh_add_point(t_mesh *dest, t_vector4 new_point)
{
	t_vector4_list_push_back(dest->vertices, new_point);
}

void	t_mesh_add_face(t_mesh *dest, t_face new_face)
{
	t_face_list_push_back(dest->faces, new_face);
}

void	t_mesh_set_texture(t_mesh *dest, t_texture *p_texture)
{
	dest->texture = p_texture;
}

void	t_mesh_compute_normals(t_mesh *mesh)
{
	t_face		*face;
	t_vector4	a;
	t_vector4	b;
	t_vector4	c;
	int			i;

	clean_t_vector4_list(mesh->normales);
	i = -1;
	while (++i < mesh->faces->size)
	{
		face = t_face_list_get(mesh->faces, i);
		a = t_vector4_list_at(mesh->vertices, face->index_vertices[0]);
		b = substract_vector4_to_vector4(t_vector4_list_at(mesh->vertices,
											face->index_vertices[1]), a);
		c = substract_vector4_to_vector4(t_vector4_list_at(mesh->vertices,
											face->index_vertices[2]), a);
		face->normale = normalize_t_vector4(cross_t_vector4(b, c));
		t_vector4_list_push_back(mesh->normales, create_t_vector4(0, 0, 0));
		t_vector4_list_push_back(mesh->normales, face->normale);
	}
}

void	t_mesh_compute_bubble_box(t_mesh *mesh)
{
	int			i;
	float		tmp;
	t_vector4	total;

	total = create_t_vector4(0.0, 0.0, 0.0);
	i = -1;
	while (++i < mesh->vertices->size)
		total = add_vector4_to_vector4(total,
					t_vector4_list_at(mesh->vertices, i));
	if (i > 0)
		total = divide_vector4_by_float(total, (float)(i));
	mesh->center = add_vector4_to_vector4(total, mesh->pos);
	i = -1;
	while (++i < mesh->vertices->size)
	{
		tmp = calc_dist_vector4_to_vector4(total,
					t_vector4_list_at(mesh->vertices, i));
		if (mesh->bubble_radius < tmp)
			mesh->bubble_radius = tmp;
	}
}

void	t_mesh_look_at(t_mesh *mesh)
{
	t_vector4	zaxis;
	t_vector4	xaxis;
	t_vector4	yaxis;

	zaxis = normalize_t_vector4(create_t_vector4(\
		cos(degree_to_radius(mesh->angle.z)) \
			* sin(degree_to_radius(mesh->angle.y)),
		sin(degree_to_radius(mesh->angle.z)),
		cos(degree_to_radius(mesh->angle.z)) \
			* cos(degree_to_radius(mesh->angle.y))));
	xaxis = normalize_t_vector4(create_t_vector4(\
					sin(degree_to_radius(mesh->angle.y) - 3.14f / 2.0f),
					0, cos(degree_to_radius(mesh->angle.y) - 3.14f / 2.0f)));
	yaxis = normalize_t_vector4(cross_t_vector4(xaxis, zaxis));
	mesh->forward = zaxis;
	mesh->right = xaxis;
	mesh->up = inv_t_vector4(yaxis);
}

void	t_mesh_rotate(t_mesh *mesh, t_vector4 delta_angle)
{
	t_matrix	rotation;
	t_vector4	*target;
	int			i;

	mesh->rotation = add_vector4_to_vector4(mesh->rotation,
			create_t_vector4(delta_angle.x, delta_angle.y, delta_angle.z));
	rotation = create_rotation_matrix(delta_angle.x, delta_angle.y,\
										delta_angle.z);
	mesh->angle = add_vector4_to_vector4(mesh->angle, delta_angle);
	t_mesh_look_at(mesh);
	i = -1;
	while (++i < mesh->vertices->size)
	{
		target = t_vector4_list_get(mesh->vertices, i);
		*target = mult_vector4_by_matrix(*target, rotation);
	}
	t_mesh_compute_normals(mesh);
	t_mesh_compute_bubble_box(mesh);
}

void	t_mesh_set_color(t_mesh *dest, t_color p_color)
{
	int i;

	i = -1;
	while (++i < dest->faces->size)
		set_t_face_color(t_face_list_get(dest->faces, i), p_color);
}

void	t_mesh_move(t_mesh *dest, t_vector4 delta)
{
	dest->pos = add_vector4_to_vector4(dest->pos, delta);
	dest->center = add_vector4_to_vector4(dest->center, delta);
}

void	t_mesh_apply_force(t_mesh *dest)
{
	dest->pos = add_vector4_to_vector4(dest->pos, dest->force);
	dest->center = add_vector4_to_vector4(dest->center, dest->force);
}

void	t_mesh_activate_gravity(t_mesh *dest, float gravity)
{
	dest->kinetic = gravity;
}

void	t_mesh_set_visibility(t_mesh *dest, int new_state)
=======
void	t_mesh_resize(t_mesh *mesh, t_vec4 modif)
>>>>>>> 58d0095a255fb66f686e5516ec18f8f993391c05
{
	t_vec4		tmp;
	int			i;

	i = 4;
	while (i <= 7)
	{
		tmp = t_vec4_list_at(mesh->vertices, i);
		tmp = add_vec4(tmp, modif);
		t_vec4_list_set(mesh->vertices, i, &tmp);
		i++;
	}
}

void	destroy_mesh(t_mesh *mesh)
{
	mesh->no_hitbox = 1;
	t_mesh_set_visibility(mesh, BOOL_FALSE);
	t_mesh_set_name(mesh, "mesh_destroy");
}
