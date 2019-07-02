# include "unknow_project.h"

t_engine	create_t_engine()
{
	t_engine	result;

	result.playing = BOOL_TRUE;
	result.cam = initialize_t_camera(create_t_vector3(0, 0, 0), FOV, create_t_vector2(NEAR, FAR));
	result.physic_engine = initialize_t_physic_engine();
	result.user_engine = initialize_t_user_engine();

	return (result);
}

t_engine	*initialize_t_engine()
{
	t_engine	*result;

	if (!(result = (t_engine *)malloc(sizeof(t_engine))))
		return (NULL);

	*result = create_t_engine();

	return (result);
}

void		free_t_engine(t_engine dest)
{
	delete_t_physic_engine(dest.physic_engine);
	delete_t_user_engine(dest.user_engine);
	delete_t_cam(dest.cam);
}

void		delete_t_engine(t_engine *dest)
{
	free_t_engine(*dest);
	free(dest);
}

void		t_engine_handle_camera(t_engine *p_engine)
{
	t_user_engine_handle_camera(p_engine->user_engine, p_engine->cam);
}

void		t_engine_draw_mesh(t_engine *p_engine, t_window *p_win)
{
	t_physic_engine_draw_mesh(p_engine->physic_engine, p_win, p_engine->cam);
}

void		t_engine_add_mesh(t_engine *engine, t_mesh p_mesh)
{
	t_physic_engine_add_mesh(engine->physic_engine, p_mesh);
}

void		t_engine_handle_event(t_engine *engine)
{
	static float size = 1.0;
	t_mesh	*mesh;
	int		i;

	if (t_user_engine_poll_event(engine->user_engine) > 0)
	{
		t_user_engine_handle_quit(engine->user_engine, &(engine->playing));
		if (engine->user_engine->event.type == SDL_KEYDOWN && engine->user_engine->event.key.keysym.sym == SDLK_u)
		{
			i = 0;
			while (i < engine->physic_engine->mesh_list->size)
			{
				mesh = t_mesh_list_get(engine->physic_engine->mesh_list, i);
				if (mesh->kinetic > 0)
					mesh->kinetic = 0;
				else
					mesh->kinetic = 100;
				i++;
			}
		}
		if (engine->user_engine->event.type == SDL_KEYDOWN && engine->user_engine->event.key.keysym.sym == SDLK_RETURN)
		{
			static int heigth = 2;
			static float rot_y = 34;
			float r = generate_nbr(0, 255);
			float g = generate_nbr(0, 255);
			float b = generate_nbr(0, 255);

			t_mesh mesh = create_primitive_cube(create_t_vector3(0, heigth, 0), create_t_vector3(size, size, size), NULL, 100);
			t_mesh_set_color(&mesh, create_t_color_from_int(r, g, b, 255));
			t_mesh_rotate_around_point(&mesh, create_t_vector3(0, rot_y, 0), create_t_vector3(-0.5, heigth, -0.5));

			heigth += size * 2;
			rot_y += 6;
			t_engine_add_mesh(engine, mesh);
		}
		if (engine->user_engine->event.type == SDL_KEYDOWN && engine->user_engine->event.key.keysym.sym == SDLK_r)
		{
			printf("Size increse !\n");
			size += 0.2;
		}
		if (engine->user_engine->event.type == SDL_KEYDOWN && engine->user_engine->event.key.keysym.sym == SDLK_t)
		{
			size -= 0.2;
			if (size <= 0.2)
				size = 0.2;
			printf("Size decrease !\n");
		}
	}
}

t_mesh		*t_engine_get_mesh(t_engine *p_engine, int index)
{
	return (t_physic_engine_get_mesh(p_engine->physic_engine, index));
}

void		t_engine_apply_physic(t_engine *engine)
{
	t_physic_engine_compute_vertices_in_world(engine->physic_engine);
	t_physic_engine_apply_velocity(engine->physic_engine);
}

void		t_engine_place_camera(t_engine *engine, t_vector3 p_new_pos)
{
	engine->cam->pos = p_new_pos;
}

void		t_engine_camera_look_at(t_engine *engine, t_vector3 target)
{
	t_camera_look_at_point(engine->cam, target);
	compute_t_camera(engine->cam);
}
