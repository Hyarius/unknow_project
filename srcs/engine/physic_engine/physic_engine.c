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
	t_vector3 normal;
	t_triangle tmp;
	int			count;

	sort_t_triangle_points(&a);
	sort_t_triangle_points(&b);

	if (t_triangle_is_bigger(a, b) == BOOL_FALSE)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	normal = cross_t_vector3(substract_vector3_to_vector3(a.b, a.a), substract_vector3_to_vector3(a.c, a.a));
	int ab = intersect_triangle_by_segment(a, normal, b.a, b.b);
	int ac = intersect_triangle_by_segment(a, normal, b.a, b.c);
	int bc = intersect_triangle_by_segment(a, normal, b.b, b.c);

	if (ab == 1)
		return (BOOL_TRUE);

	if (ac == 1)
		return (BOOL_TRUE);

	if (bc == 1)
		return (BOOL_TRUE);

	return (BOOL_FALSE);
}

int can_move_axis(t_mesh *mesh, t_mesh *target, t_vector3 axis)
{
	t_vector3	tmp;
	t_triangle	triangle_mesh;
	t_triangle	triangle_mesh2;
	t_triangle	triangle_target;
	t_face	*mesh_face;
	t_face *target_face;
	t_vector3 delta_pos;
	int i;
	int j;

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
		triangle_mesh = compose_t_triangle_from_t_vertices(mesh->check_list, mesh_face->index_vertices);
		i = 0;
		while (i < target->faces->size)
		{
			target_face = t_face_list_get(target->faces, i);
			if (is_triangle_contact(triangle_mesh, t_triangle_list_at(target->triangle_check_list, i)) == BOOL_TRUE)
			{
				return (BOOL_FALSE);
			}
			i++;
		}
		j++;
	}
	return (BOOL_TRUE);
}

int can_move(t_mesh *mesh, t_mesh_list *mesh_list)
{
	float	delta[3];
	t_mesh *target;
	int i;

	i = 0;
	while (i < mesh_list->size)
	{
		target = t_mesh_list_get(mesh_list, i);
		if (mesh != target && target->bubble_radius + mesh->bubble_radius >= calc_dist_vector3_to_vector3(mesh->center, target->center))
		{
			delta[0] = mesh->velocity.x / 10.0;
			delta[1] = mesh->velocity.y / 10.0;
			delta[2] = mesh->velocity.z / 10.0;
			while (mesh->velocity.x != 0 && can_move_axis(mesh, target, create_t_vector3(1, 0, 0)) == BOOL_FALSE)
			{
				mesh->velocity.x -= delta[0];
				if (ft_abs_float(mesh->velocity.x) < EPSILON)
					mesh->velocity.x = 0;
			}
			while (mesh->velocity.y != 0 && can_move_axis(mesh, target, create_t_vector3(0, 1, 0)) == BOOL_FALSE)
			{
				mesh->velocity.y -= delta[1];
				if (ft_abs_float(mesh->velocity.y) < EPSILON)
					mesh->velocity.y = 0;
			}
			while (mesh->velocity.z != 0 && can_move_axis(mesh, target, create_t_vector3(0, 0, 1)) == BOOL_FALSE)
			{
				mesh->velocity.z -= delta[2];
				if (ft_abs_float(mesh->velocity.z) < EPSILON)
					mesh->velocity.z = 0;
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
