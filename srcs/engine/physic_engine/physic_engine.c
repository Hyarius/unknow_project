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

int				can_move_axis(t_mesh *mesh, t_mesh *target, t_vector3 axis)
{

	return (BOOL_FALSE);
}

int				can_fall(t_mesh *mesh, t_mesh_list *mesh_list)
{
	float	delta[3];
	int		subdivision;
	t_mesh	*target;
	int		i;

	subdivision = 10;
	delta[0] = mesh->velocity.x / subdivision;
	delta[1] = mesh->velocity.y / subdivision;
	delta[2] = mesh->velocity.z / subdivision;
	//printf("Delta %f - %f - %f\n", delta[0], delta[1], delta[2]);
	i = 0;
	while (i < mesh_list->size)
	{
		target = t_mesh_list_get(mesh_list, i);
		if (mesh != target && target->bubble_radius + mesh->bubble_radius >= calc_dist_vector3_to_vector3(mesh->center, target->center))
		{
			t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(1, 0, 0));
			while (mesh->velocity.x != 0 && is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
			{
				mesh->velocity.x -= delta[0];
				if (ft_abs_float(mesh->velocity.x) <= EPSILON)
					mesh->velocity.x = 0;
				t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(1, 0, 0));
			}
			t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(0, 1, 0));
			while (mesh->velocity.y != 0 && is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
			{
				mesh->velocity.y -= delta[1];
				if (ft_abs_float(mesh->velocity.y) <= EPSILON)
					mesh->velocity.y = 0;
				t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(0, 1, 0));
			}
			t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(0, 0, 1));
			while (mesh->velocity.z != 0 && is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
			{
				mesh->velocity.z -= delta[2];
				if (ft_abs_float(mesh->velocity.z) <= EPSILON)
					mesh->velocity.z = 0;
				t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(0, 0, 1));
			}
		}
		i++;
	}
	return (BOOL_TRUE);
}
int				can_move(t_mesh *mesh, t_mesh_list *mesh_list)
{
	float	delta[3];
	int		subdivision;
	t_mesh	*target;
	int		i;

	subdivision = 1000;
	delta[0] = mesh->force.x / subdivision;
	delta[1] = mesh->force.y / subdivision;
	delta[2] = mesh->force.z / subdivision;
	//printf("Delta %f - %f - %f\n", delta[0], delta[1], delta[2]);
	i = 0;
	while (i < mesh_list->size)
	{
		target = t_mesh_list_get(mesh_list, i);
		if (mesh != target && target->bubble_radius + mesh->bubble_radius >= calc_dist_vector3_to_vector3(mesh->center, target->center))
		{
			t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(1, 0, 0));
			while (mesh->force.x != 0 && is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
			{
				mesh->force.x -= delta[0];
				if (ft_abs_float(mesh->force.x) <= EPSILON)
					mesh->force.x = 0;
				t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(1, 0, 0));
			}
			t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(0, 1, 0));
			while (mesh->force.y != 0 && is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
			{
				mesh->force.y -= delta[1];
				if (ft_abs_float(mesh->force.y) <= EPSILON)
					mesh->force.y = 0;
				t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(0, 1, 0));
			}
			t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(0, 0, 1));
			while (mesh->force.z != 0 && is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
			{
				mesh->force.z -= delta[2];
				if (ft_abs_float(mesh->force.z) <= EPSILON)
					mesh->force.z = 0;
				t_mesh_compute_next_vertices_in_world(mesh, create_t_vector3(0, 0, 1));
			}
		}
		i++;
	}
	return (BOOL_TRUE);
}

void			t_physic_engine_compute_vertices_in_world(t_physic_engine *physic_engine)
{
	int i = 0;

	while (i < physic_engine->mesh_list->size)
	{
		t_mesh_compute_vertices_in_world(t_mesh_list_get(physic_engine->mesh_list, i));
		i++;
	}
}

void			t_physic_engine_apply_velocity(t_physic_engine *physic_engine)
{
	Uint32 	actual_frame;
	static Uint32 	last_frame = 0;
	int i = 0;
	float time_passed;
	t_mesh *mesh;

	actual_frame = SDL_GetTicks();
	time_passed = (actual_frame - last_frame) / 1000.0;
	while (i < physic_engine->mesh_list->size)
	{
		mesh = t_mesh_list_get(physic_engine->mesh_list, i);
		if (mesh->kinetic > 0)
		{
			mesh->velocity = add_vector3_to_vector3(mesh->velocity, mult_vector3_by_float(physic_engine->gravity_force, mesh->kinetic * time_passed));

			if (can_fall(mesh, physic_engine->mesh_list) == BOOL_TRUE)
				t_mesh_apply_velocity(mesh);
		}
		if (mesh->force.x != 0 || mesh->force.y != 0 || mesh->force.z != 0)
			if (can_move(mesh, physic_engine->mesh_list) == BOOL_TRUE)
				t_mesh_apply_force(mesh);
		i++;
		if (mesh->velocity.y != 0)
		{
			mesh->velocity.y -= (GRAVITY * mesh->kinetic * time_passed);

			// if (mesh->velocity.x > )
			// mesh->velocity.x -= mesh->velocity.x * time_passed / 10;
			// if (ft_abs_float(mesh->velocity.x) <= EPSILON)
			// 	mesh->velocity.x = 0;
			// mesh->velocity.z -= mesh->velocity.z * time_passed / 10;
			// if (ft_abs_float(mesh->velocity.z) <= EPSILON)
			// 	mesh->velocity.z = 0;
		}
		else if (mesh->velocity.y == 0)
		{
			mesh->velocity.x = 0;
			mesh->velocity.z = 0;
		}
	}
	last_frame = actual_frame;
}
