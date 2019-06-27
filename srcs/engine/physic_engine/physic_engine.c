# include "unknow_project.h"

t_physic_engine	create_t_physic_engine()
{
	t_physic_engine	result;

	result.gravity_force = create_t_vector3(0, -GRAVITY * 3, 0);
	result.mesh_list = initialize_t_mesh_list();

	return (result);
}

t_physic_engine	*initialize_t_physic_engine()
{
	t_physic_engine	*result;

	if (!(result = (t_physic_engine	*)malloc(sizeof(t_physic_engine))))
		return (NULL);

	*result = create_t_physic_engine();

	return (result);
}

void			free_t_physic_engine(t_physic_engine dest)
{
	delete_t_mesh_list(dest.mesh_list);
}

void			delete_t_physic_engine(t_physic_engine *dest)
{
	free_t_physic_engine(*dest);
	free(dest);
}

void			t_physic_engine_draw_mesh(t_physic_engine *p_physic_engine, t_window *p_win, t_camera *p_cam)
{
	int			i;

	i = 0;
	while (i < p_physic_engine->mesh_list->size)
	{
		draw_t_mesh(p_win, p_cam, t_mesh_list_get(p_physic_engine->mesh_list, i));
		i++;
	}
}

void			t_physic_engine_add_mesh(t_physic_engine *physic_engine, t_mesh p_mesh)
{
	t_mesh_list_push_back(physic_engine->mesh_list, p_mesh);
}

t_mesh			*t_physic_engine_get_mesh(t_physic_engine *physic_engine, int index)
{
	return (t_mesh_list_get(physic_engine->mesh_list, index));
}

int 			is_triangle_contact(t_triangle a, t_triangle b)
{
	int result;
	t_vector3 normal;
	t_triangle inter;

	sort_t_triangles(&a, &b);

	result = BOOL_FALSE;

	// if (is_triangle_cut_triangle(a, b) == BOOL_TRUE)
	// 	result = BOOL_TRUE;

	normal = cross_t_vector3(substract_vector3_to_vector3(a.b, a.a), substract_vector3_to_vector3(a.c, a.a));
	int ab = intersect_triangle_by_segment(a, normal, create_t_line(b.a, b.b), &(inter.a));
	int ac = intersect_triangle_by_segment(a, normal, create_t_line(b.a, b.c), &(inter.b));
	int bc = intersect_triangle_by_segment(a, normal, create_t_line(b.b, b.c), &(inter.c));

	if (ab == BOOL_TRUE && is_point_on_triangle(a, inter.a) == BOOL_TRUE && is_point_on_triangle(b, inter.a) == BOOL_TRUE)
		return (BOOL_TRUE);

	if (ac == BOOL_TRUE && is_point_on_triangle(a, inter.b) == BOOL_TRUE && is_point_on_triangle(b, inter.b) == BOOL_TRUE)
		return (BOOL_TRUE);

	if (bc == BOOL_TRUE && is_point_on_triangle(a, inter.c) == BOOL_TRUE && is_point_on_triangle(b, inter.c) == BOOL_TRUE)
		return (BOOL_TRUE);

	return (result);
}

int can_move_axis(t_mesh *mesh, t_mesh *target, t_vector3 axis)
{
	int			result;
	t_vector3	tmp;
	t_triangle	triangle_mesh;
	t_triangle	triangle_mesh2;
	t_triangle	triangle_target;
	t_face	*mesh_face;
	t_face *target_face;
	t_vector3 delta_pos;
	int i;
	int j;

	result = 0;
	tmp = mult_vector3_by_vector3(mesh->velocity, axis);
	delta_pos = add_vector3_to_vector3(mesh->pos, tmp);
	clean_t_vector3_list(mesh->check_list);
	i = 0;
	while (i < mesh->vertices->size)
	{
		t_vector3_list_push_back(mesh->check_list, add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, i), delta_pos));
		i++;
	}
	j = 0;
	while (j < mesh->faces->size)
	{
		mesh_face = t_face_list_get(mesh->faces, j);
		//set_t_face_color(mesh_face, create_t_color(0.0, 1.0, 0.0, 1.0));
		triangle_mesh = compose_t_triangle_from_t_vertices(mesh->check_list, mesh_face->index_vertices);
		i = 0;
		while (i < target->faces->size)
		{
			target_face = t_face_list_get(target->faces, i);
			triangle_target = t_triangle_list_at(target->triangle_check_list, i);
			if (is_triangle_contact(triangle_mesh, triangle_target) == BOOL_TRUE)
			{
				set_t_face_color(mesh_face, create_t_color(1.0, 0.0, 0.0, 1.0));
				result++;
			}

			i++;
		}
		j++;
	}
	if (result > 0)
		return (BOOL_FALSE);
	return (BOOL_TRUE);
}

int				can_move(t_mesh *mesh, t_mesh_list *mesh_list)
{
	float	delta[3];
	t_mesh	*target;
	int		i;

	i = 0;
	while (i < mesh_list->size)
	{
		target = t_mesh_list_get(mesh_list, i);
		if (mesh != target && target->bubble_radius + mesh->bubble_radius >= calc_dist_vector3_to_vector3(mesh->center, target->center))
		{
			float subdivision = 60.0;
			delta[0] = mesh->velocity.x / subdivision;
			delta[1] = mesh->velocity.y / subdivision;
			delta[2] = mesh->velocity.z / subdivision;
			mesh->velocity.x = delta[0];
			for (int j = 0; j <= subdivision; j++)
			{
				if (can_move_axis(mesh, target, create_t_vector3(1, 0, 0)) == BOOL_FALSE)
				{
					mesh->velocity.x -= delta[0];
					break;
				}
			}
			mesh->velocity.y = delta[1];
			for (int k = 0; k <= subdivision; k++, mesh->velocity.y += delta[1])
			{
				if (can_move_axis(mesh, target, create_t_vector3(0, 1, 0)) == BOOL_FALSE)
				{
					mesh->velocity.y -= delta[1];
					break;
				}
			}
			mesh->velocity.z = delta[2];
			for (int l = 0; l <= subdivision; l++, mesh->velocity.z += delta[2])
			{
				if (can_move_axis(mesh, target, create_t_vector3(0, 0, 1)) == BOOL_FALSE)
				{
					mesh->velocity.z -= delta[2];
					break;
				}
			}
		}
		i++;
	}
	return (BOOL_TRUE);
}

void			t_physic_engine_compute_check_list(t_physic_engine *physic_engine)
{
	int i = 0;

	while (i < physic_engine->mesh_list->size)
	{
		t_mesh_compute_check_list(t_mesh_list_get(physic_engine->mesh_list, i));
		i++;
	}
}

void			t_physic_engine_apply_velocity(t_physic_engine *physic_engine)
{
	int i = 0;
	t_mesh *mesh;

	while (i < physic_engine->mesh_list->size)
	{
		mesh = t_mesh_list_get(physic_engine->mesh_list, i);
		if (mesh->kinetic > 0)
		{
			mesh->velocity = mult_vector3_by_float(physic_engine->gravity_force, mesh->kinetic);

			if (can_move(mesh, physic_engine->mesh_list) == BOOL_TRUE)
				t_mesh_apply_velocity(mesh);
		}
		i++;
	}
}
