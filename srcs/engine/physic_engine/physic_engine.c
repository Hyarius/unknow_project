# include "unknow_project.h"

t_physic_engine	create_t_physic_engine()
{
	t_physic_engine	result;

	result.gravity_force = create_t_vector3(0, -GRAVITY, 0);
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

static void	get_min_max_value(t_triangle triangle, t_vector3 *min, t_vector3 *max)
{
	max->x = get_big_float(triangle.a.x, triangle.b.x, triangle.c.x);
	max->y = get_big_float(triangle.a.y, triangle.b.y, triangle.c.y);
	max->z = get_big_float(triangle.a.z, triangle.b.z, triangle.c.z);
	min->x = get_short_float(triangle.a.x, triangle.b.x, triangle.c.x);
	min->y = get_short_float(triangle.a.y, triangle.b.y, triangle.c.y);
	min->z = get_short_float(triangle.a.z, triangle.b.z, triangle.c.z);
}

static int 	is_triangle_contact(t_triangle a, t_triangle b)
{
	t_vector3	min1;
	t_vector3	max1;
	t_vector3	min2;
	t_vector3	max2;

	get_min_max_value(a, &min1, &max1);
	get_min_max_value(b, &min2, &max2);

	if ((min1.x <= max2.x && max1.x >= min2.x)
		&& (min1.y <= max2.y && max1.y >= min2.y)
		&& (min1.z <= max2.z && max1.z >= min2.z))
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}

int can_move(t_mesh *mesh, t_mesh_list *mesh_list)
{
	t_triangle	triangle_mesh;
	t_triangle	triangle_target;
	t_face	*mesh_face;
	t_face	*target_face;
	t_mesh	*target;
	t_vector3_list vertices;
	int i;
	int j;
	int k;

	vertices = create_t_vector3_list();
	i = 0;
	while (i < mesh->vertices->size)
	{
		t_vector3_list_push_back(&vertices, add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, i), mesh->pos));//add_vector3_to_vector3(mesh->pos, mesh->velocity)));
		i++;
	}
	i = 0;
	while (i < mesh_list->size)
	{
		target = t_mesh_list_get(mesh_list, i);
		if (target != mesh)
		{
			if (mesh->bubble_radius >= calc_dist_vector3_to_vector3(mesh->center, target->center) ||
				target->bubble_radius >= calc_dist_vector3_to_vector3(mesh->center, target->center))
			{
				j = 0;
				while (j < mesh->faces->size)
				{
					mesh_face = t_face_list_get(mesh->faces, j);
					triangle_mesh = compose_t_triangle_from_t_vertices(&vertices, mesh_face->index_vertices);

					k = 0;
					while (k < target->faces->size)
					{
						target_face = t_face_list_get(target->faces, k);
						triangle_target = compose_t_triangle_from_t_mesh(target, target_face->index_vertices);

						if (is_triangle_contact(triangle_mesh, triangle_target) == BOOL_TRUE)
							return (BOOL_FALSE);
						k++;
					}

					j++;
				}
			}
		}
		i++;
	}
	return (BOOL_TRUE);
}

void			t_physic_engine_apply_gravity(t_physic_engine *physic_engine)
{
	int i = 0;
	t_mesh *mesh;

	while (i < physic_engine->mesh_list->size)
	{
		mesh = t_mesh_list_get(physic_engine->mesh_list, i);
		if (mesh->kinetic > 0)
		{
			mesh->velocity = add_vector3_to_vector3(mesh->velocity, mult_vector3_by_float(physic_engine->gravity_force, mesh->kinetic));

			if (can_move(mesh, physic_engine->mesh_list) == BOOL_TRUE)
				t_mesh_apply_velocity(mesh);
			else
			{
				mesh->velocity = create_t_vector3(0, 0, 0);
			}

		}
		i++;
	}
}