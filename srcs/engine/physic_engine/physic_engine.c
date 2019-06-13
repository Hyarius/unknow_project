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

			t_physic_engine_check_hitbox(physic_engine, i);

			t_mesh_apply_velocity(mesh);
		}
		i++;
	}
}

void			t_physic_engine_check_hitbox(t_physic_engine *physic_engine, int index)
{
	t_vector3	next_pos;
	t_mesh		*mesh;
	t_mesh		*target;
	t_face		*face_tested;
	t_triangle	tmp;
	int 		i;
	int 		j;

	i = 0;
	mesh = t_mesh_list_get(physic_engine->mesh_list, index);
	next_pos = add_vector3_to_vector3(mesh->pos, mesh->velocity);
	while (i < physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(physic_engine->mesh_list, i);
		if (i != index && mesh->bubble_radius >= calc_dist_vector3_to_vector3(mesh->center, target->center))
		{
			j = 0;
			while (j < mesh->faces->size)
			{
				face_tested = t_face_list_get(mesh->faces, j);

				tmp = create_t_triangle(add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face_tested->index_vertices[0]), mesh->pos),
										add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face_tested->index_vertices[1]), mesh->pos),
										add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face_tested->index_vertices[2]), mesh->pos));

				if (check_face_contact(tmp, mesh, target, create_t_vector3(1, 0, 0)) == 0)
					mesh->velocity.x = 0.0;
				if (check_face_contact(tmp, mesh, target, create_t_vector3(0, 1, 0)) == 0)
					mesh->velocity.y = 0.0;
				if (check_face_contact(tmp, mesh, target, create_t_vector3(0, 0, 1)) == 0)
					mesh->velocity.z = 0.0;

				j++;
			}
		}
		if (mesh->velocity.x == 0 && mesh->velocity.y == 0 && mesh->velocity.z == 0)
			break;
		i++;
	}
}

int 	check_face_contact(t_triangle face, t_mesh *mesh, t_mesh *target, t_vector3 delta)
{
	t_face		*face_tested;
	t_vector3	min1;
	t_vector3	max1;
	t_vector3	min2;
	t_vector3	max2;
	int i;

	face.a = add_vector3_to_vector3(face.a, mult_vector3_by_vector3(mesh->velocity, delta));
	face.b = add_vector3_to_vector3(face.b, mult_vector3_by_vector3(mesh->velocity, delta));
	face.c = add_vector3_to_vector3(face.c, mult_vector3_by_vector3(mesh->velocity, delta));

	min1.x = get_short_float(face.a.x, face.b.x, face.c.x);
	min1.y = get_short_float(face.a.y, face.b.y, face.c.y);
	min1.z = get_short_float(face.a.z, face.b.z, face.c.z);
	max1.x = get_big_float(face.a.x, face.b.x, face.c.x);
	max1.y = get_big_float(face.a.y, face.b.y, face.c.y);
	max1.z = get_big_float(face.a.z, face.b.z, face.c.z);

	i = 0;
	while (i < target->faces->size)
	{
		face_tested = t_face_list_get(mesh->faces, i);
		face = create_t_triangle(add_vector3_to_vector3(t_vector3_list_at(target->vertices, face_tested->index_vertices[0]), target->pos),
								add_vector3_to_vector3(t_vector3_list_at(target->vertices, face_tested->index_vertices[1]), target->pos),
								add_vector3_to_vector3(t_vector3_list_at(target->vertices, face_tested->index_vertices[2]), target->pos));

		min2.x = get_short_float(face.a.x, face.b.x, face.c.x);
		min2.y = get_short_float(face.a.y, face.b.y, face.c.y);
		min2.z = get_short_float(face.a.z, face.b.z, face.c.z);
		max2.x = get_big_float(face.a.x, face.b.x, face.c.x);
		max2.y = get_big_float(face.a.y, face.b.y, face.c.y);
		max2.z = get_big_float(face.a.z, face.b.z, face.c.z);

		printf("-----\nTest :\n");
		print_t_vector3(min1, "min1 : ");endl();
		print_t_vector3(max1, "max1 : ");endl();
		print_t_vector3(min2, "min2 : ");endl();
		print_t_vector3(max2, "max2 : ");endl();

		if (min1.x >= min2.x && min1.x <= max2.x &&
			min1.y >= min2.y && min1.y <= max2.y &&
			min1.z >= min2.z && min1.z <= max2.z)
		{
			printf("result : 0\n");
			return (0);
		}
		if (max1.x >= min2.x && max1.x <= max2.x &&
			max1.y >= min2.y && max1.y <= max2.y &&
			max1.z >= min2.z && max1.z <= max2.z)
		{
			printf("result : 0\n");
			return (0);
		}

		if (min2.x >= min1.x && min2.x <= max1.x &&
			min2.y >= min1.y && min2.y <= max1.y &&
			min2.z >= min1.z && min2.z <= max1.z)
		{
			printf("result : 0\n");
			return (0);
		}
		if (max2.x >= min1.x && max2.x <= max1.x &&
			max2.y >= min1.y && max2.y <= max1.y &&
			max2.z >= min1.z && max2.z <= max1.z)
		{
			printf("result : 0\n");
			return (0);
		}
			printf("result : 1\n");
		i++;
	}
	return (1);
}