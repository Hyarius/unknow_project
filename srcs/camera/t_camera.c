#include "unknow_project.h"

t_camera	create_t_camera(t_window *window, t_vector4 p_pos, float p_fov,
															t_vector2 p_dist)
{
	t_camera	result;

	result.view_port = initialize_t_view_port(window,
				create_t_vector2_int(0, 0), create_t_vector2_int(window->size_x,
				window->size_y));
	result.body = NULL;
	result.pos = p_pos;
	result.fov = p_fov;
	result.near = p_dist.x;
	result.far = p_dist.y;
	result.dist_max = 0.0f;
	result.yaw = 0.0f;
	result.pitch = 0.0f;
	result.speed = 0.1f;
	result.running = 1.8f;
	result.slowing = 1.0f;
	result.crounch = 0;
	result.f_press = 0;
	result.r_press = 0;
	result.model = create_t_matrix();
	t_camera_look_at(&result);
	result.view = t_camera_compute_view(&result);
	result.projection = compute_projection_matrix(&result);
	result.sun_direction = normalize_t_vector4(create_t_vector4(0.2, -1, -0.4));
	result.triangle_color_list = create_t_triangle_list();
	result.color_list = create_t_color_list();
	result.triangle_texture_list = create_t_triangle_list();
	result.uv_list = create_t_uv_list();
	result.darkness_list = create_t_color_list();
	return (result);
}

t_camera	*initialize_t_camera(t_window *window, t_vector4 p_pos,
												float p_fov, t_vector2 p_dist)
{
	t_camera	*result;

	if (!(result = (t_camera *)malloc(sizeof(t_camera))))
		error_exit(-31, "Can't malloc a t_camera");
	*result = create_t_camera(window, p_pos, p_fov, p_dist);
	return (result);
}

void		t_camera_set_view_port(t_camera *camera, t_vector2_int new_pos,
														t_vector2_int new_size)
{
	move_t_view_port(camera->view_port, new_pos);
	resize_t_view_port(camera->view_port, new_size);
}

void		t_camera_change_window(t_camera *camera, t_window *new_window)
{
	t_view_port_change_window(camera->view_port, new_window);
}

void		t_camera_change_view_port(t_camera *camera,
													t_view_port *new_view_port)
{
	free(camera->view_port);
	camera->view_port = new_view_port;
}

void		delete_t_cam(t_camera dest)
{
	delete_t_triangle_list(dest.triangle_color_list);
	delete_t_color_list(dest.color_list);
	delete_t_triangle_list(dest.triangle_texture_list);
	free(dest.uv_list.uvs);
	delete_t_color_list(dest.darkness_list);
	free(dest.view_port);
}

void		free_t_cam(t_camera *dest)
{
	delete_t_cam(*dest);
	free(dest);
}

void		t_camera_look_at_point(t_camera *cam, t_vector4 targ)
{
	t_vector4	result;

	if (targ.x == cam->pos.x && targ.y == cam->pos.y && targ.z == cam->pos.z)
		return ;
	result = normalize_t_vector4(substract_vector4_to_vector4(cam->pos, targ));
	cam->yaw = radius_to_degree(atan2(result.z, -result.x)) - 90;
	cam->pitch = radius_to_degree(atan2(result.y,
						sqrt(result.x * result.x + result.z * result.z)));
	cam->pitch = clamp_float_value(-89, cam->pitch, 89);
	t_camera_look_at(cam);
}

void		t_camera_look_at(t_camera *cam)
{
	t_vector4	xaxis;
	t_vector4	yaxis;
	t_vector4	zaxis;

	zaxis = normalize_t_vector4(create_t_vector4(
		cos(degree_to_radius(cam->pitch)) * sin(degree_to_radius(cam->yaw)),
		sin(degree_to_radius(cam->pitch)),
		cos(degree_to_radius(cam->pitch)) * cos(degree_to_radius(cam->yaw))));
	xaxis = normalize_t_vector4(create_t_vector4(
		sin(degree_to_radius(cam->yaw) - 3.14f / 2.0f), 0,
		cos(degree_to_radius(cam->yaw) - 3.14f / 2.0f)));
	yaxis = normalize_t_vector4(cross_t_vector4(xaxis, zaxis));
	cam->forward = inv_t_vector4(zaxis);
	cam->right = inv_t_vector4(xaxis);
	cam->up = yaxis;
}

t_matrix	t_camera_compute_view(t_camera *cam)
{
	t_matrix	result;

	result = create_t_matrix();
	result.value[0][0] = cam->right.x;
	result.value[1][0] = cam->right.y;
	result.value[2][0] = cam->right.z;
	result.value[3][0] = -(dot_t_vector4(cam->right, cam->pos));
	result.value[0][1] = cam->up.x;
	result.value[1][1] = cam->up.y;
	result.value[2][1] = cam->up.z;
	result.value[3][1] = -(dot_t_vector4(cam->up, cam->pos));
	result.value[0][2] = cam->forward.x;
	result.value[1][2] = cam->forward.y;
	result.value[2][2] = cam->forward.z;
	result.value[3][2] = -(dot_t_vector4(cam->forward, cam->pos));
	return (result);
}

void		t_camera_change_fov(t_camera *cam, float delta)
{
	if (delta > 1 && cam->fov >= 60)
		cam->fov /= delta;
	if (delta < 1 && cam->fov < 90)
		cam->fov /= delta;
}

t_matrix	compute_projection_matrix(t_camera *p_cam)
{
	t_matrix	result;
	float		n;
	float		r;
	float		f;
	float		t;

	result = create_t_matrix_empty();
	n = p_cam->near;
	r = 1.0 / (tan(degree_to_radius(p_cam->fov / 2.0)));
	f = p_cam->far;
	t = 1.0 / (tan(degree_to_radius(p_cam->fov / 2.0))) / (4.0 / 3.0);
	result.value[0][0] = t;
	result.value[1][1] = r;
	result.value[2][2] = f / (f - n);
	result.value[2][3] = 1.0;
	result.value[3][2] = -(2 * f * n) / (f - n);
	return (result);
}

void		compute_t_camera(t_camera *cam)
{
	cam->view = t_camera_compute_view(cam);
	cam->projection = compute_projection_matrix(cam);
}

t_vector4	apply_t_camera(t_vector4 *src, t_matrix *mat)
{
	t_vector4	result;

	result.x = src->x * mat->value[0][0] + src->y * mat->value[1][0]
								+ src->z * mat->value[2][0] + mat->value[3][0];
	result.y = src->x * mat->value[0][1] + src->y * mat->value[1][1]
								+ src->z * mat->value[2][1] + mat->value[3][1];
	result.z = src->x * mat->value[0][2] + src->y * mat->value[1][2]
								+ src->z * mat->value[2][2] + mat->value[3][2];
	result.w = src->x * mat->value[0][3] + src->y * mat->value[1][3]
								+ src->z * mat->value[2][3] + mat->value[3][3];
	if (result.w != 0)
	{
		result.x /= result.w;
		result.y /= result.w;
		result.z /= -result.w;
	}
	return (result);
}

void		t_camera_change_view(t_camera *cam, float pitch, float yaw)
{
	cam->pitch = clamp_float_value(-89, cam->pitch + pitch, 89);
	cam->yaw += yaw;
	t_camera_look_at(cam);
}

void		move_cam(t_camera *camera, t_keyboard *key, t_engine *engine)
{
	if (get_key_state(key, key->key[SDL_SCANCODE_W]) == 1)
		camera->pos = add_vector4_to_vector4(camera->pos,
				divide_vector4_by_float(camera->forward, 2.0));
	if (get_key_state(key, key->key[SDL_SCANCODE_S]) == 1)
		camera->pos = add_vector4_to_vector4(camera->pos,
				inv_t_vector4(divide_vector4_by_float(camera->forward, 2.0)));
	if (get_key_state(key, key->key[SDL_SCANCODE_D]) == 1)
		camera->pos = add_vector4_to_vector4(camera->pos,
				divide_vector4_by_float(camera->right, 2.0));
	if (get_key_state(key, key->key[SDL_SCANCODE_A]) == 1)
		camera->pos = add_vector4_to_vector4(camera->pos,
				inv_t_vector4(divide_vector4_by_float(camera->right, 2.0)));
	if (get_key_state(key, key->key[SDL_SCANCODE_SPACE]) == 1)
		camera->pos.y += 0.5;
	if (get_key_state(key, key->key[SDL_SCANCODE_LCTRL]) == 1)
		camera->pos.y -= 0.5;
}

void		move_camera(t_camera *camera, t_vector4 mouvement,
													t_engine *engine, float j)
{
	if (camera->body->no_hitbox == 1 && camera->body->is_visible == 0)
		t_mesh_move(camera->body, camera->body->force);
	else if (can_move(camera->body, engine) == BOOL_TRUE)
		t_mesh_move(camera->body, camera->body->force);
	t_physic_engine_apply_force(engine);
	camera->pos = add_vector4_to_vector4(camera->pos, camera->body->force);
	camera->pos = add_vector4_to_vector4(camera->body->pos,
					create_t_vector4(0.15, 0.45 - j, 0.15));
	engine->user_engine->player->hitbox.pos = camera->pos;
}

void		handle_t_camera_mouvement_by_key(t_camera *camera, t_keyboard *p_keyboard, t_engine *engine) // calcul du mouvement de la cameraera au clavier
{
	t_mesh			*target;
	t_vector4		tmp;
	t_vector4		mouvement;
	t_vector4		save;
	float			y;
	float			j;
	float			z;
	int				i;
	int				k;
	int				l;
	static int		in_air = 0;

	j = 0.0;
	i = 0;
	z = 0.0;
	mouvement = create_t_vector4(0, 0, 0);
	save = create_t_vector4(0, 0, 0);
	if (engine->user_engine->player->hitbox.kinetic == 0.0f)
	{
		camera->body->force = create_t_vector4(0.0, 0.0, 0.0);
		z = 0.1;
	}
	if (camera->body->force.y != 0.0)
		in_air = 1;
	if (camera->body->force.y > 0.02)
	{
		if (!Mix_Playing(3) && engine->user_engine->player->fuel > 0)
			Mix_PlayChannel(3, engine->sound_engine->sounds[3], 0);
		if (engine->user_engine->player->fuel == 0)
		{
			Mix_HaltChannel(3);
			Mix_PlayChannel(3, engine->sound_engine->sounds[4], 0);
		}
	}
	if (camera->body->force.y == 0.0)
	{
		if (in_air == 1)
		{
			in_air = 0;
			Mix_PlayChannel(4, engine->sound_engine->sounds[6], 0);
		}
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_SPACE]) == 1 && engine->user_engine->player->fuel > 0)
	{
		camera->body->force.y = 0.04;
		engine->user_engine->player->fuel--;
		if (!Mix_Playing(3))
			Mix_PlayChannel(3, engine->sound_engine->sounds[2], 0);
	}
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_SPACE]) == 1 && camera->body->force.y == 0)
	{
		Mix_PlayChannel(4, engine->sound_engine->sounds[1], 0 );
		camera->body->force.y = 0.04;
	}
	y = camera->body->force.y;
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_LSHIFT]) == 1 && camera->body->force.y == 0)
		tmp = create_t_vector4(camera->speed * camera->running, z, camera->speed * camera->running);
	else
		tmp = create_t_vector4(camera->speed, z, camera->speed);
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_S]) == 1)
	{
		tmp = create_t_vector4(camera->speed / camera->slowing, z, camera->speed / camera->slowing);
		camera->body->force = add_vector4_to_vector4(mult_vector4_by_vector4(normalize_t_vector4(mult_vector4_by_vector4(camera->forward, create_t_vector4(-1.0, -1.0, -1.0))), tmp), mouvement);
		save = create_t_vector4(camera->body->force.x, camera->body->force.y, camera->body->force.z);
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_W]) == 1)
	{
		camera->body->force = add_vector4_to_vector4(mult_vector4_by_vector4(normalize_t_vector4(mult_vector4_by_vector4(camera->forward, create_t_vector4(1.0, 1.0, 1.0))), tmp), mouvement);
		if (save.x != 0 || save.y != 0 || save.z != 0)
			save = add_vector4_to_vector4(divide_vector4_by_float(camera->body->force, 2), divide_vector4_by_float(save, 2));
		else
			save = create_t_vector4(camera->body->force.x, camera->body->force.y, camera->body->force.z);
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_D]) == 1)
	{
		camera->body->force = add_vector4_to_vector4(mult_vector4_by_vector4(camera->right, tmp), mouvement);
		if (save.x != 0 || save.y != 0 || save.z != 0)
			save = add_vector4_to_vector4(divide_vector4_by_float(camera->body->force, 2), divide_vector4_by_float(save, 2));
		else
			save = create_t_vector4(camera->body->force.x, camera->body->force.y, camera->body->force.z);
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_A]) == 1)
	{
		camera->body->force = add_vector4_to_vector4(mult_vector4_by_vector4(inv_t_vector4(camera->right), tmp), mouvement);
		if (save.x != 0 || save.y != 0 || save.z != 0)
			save = add_vector4_to_vector4(divide_vector4_by_float(camera->body->force, 2), divide_vector4_by_float(save, 2));
		else
			save = create_t_vector4(camera->body->force.x, camera->body->force.y, camera->body->force.z);
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_LCTRL]) == 1)
	{
		j = 0.2;
		if (camera->crounch == 0)
		{
			t_mesh_resize(camera->body, create_t_vector4(0.0, -0.2, 0.0));
			camera->crounch = 1;
		}
	}
	else if (camera->crounch == 1)
	{
		k = 0;
		l = 0;
		while (i < engine->physic_engine->mesh_list->size)
		{
			target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
			if (camera->body != target && target->bubble_radius + camera->body->bubble_radius >= calc_dist_vector4_to_vector4(camera->body->center, target->center))
			{
				k++;
				if (camera->body->pos.y > target->pos.y || target->pos.y - camera->body->pos.y >= 0.49)
					l++;
			}
			i++;
		}
		if (k == l)
		{
			t_mesh_resize(camera->body, create_t_vector4(0.0, 0.2, 0.0));
			camera->crounch = 0;
			j = 0.0;
		}
		else
			j = 0.2;
	}
	if (y != 0.0f)
		camera->body->force = create_t_vector4(save.x, y, save.z);
	else
		camera->body->force = save;
	move_camera(camera, camera->body->force, engine, j);
	camera->body->force = mult_vector4_by_vector4(camera->body->force, create_t_vector4(0.0, 1.0, 0.0));
}

void		handle_t_camera_view_by_mouse(t_camera *cam, t_mouse *p_mouse)
{
	float	delta_pitch;
	float	delta_yaw;

	delta_pitch = -(p_mouse->rel_pos.x / 10.0);
	delta_yaw = p_mouse->rel_pos.y / 10.0;
	t_camera_change_view(cam, delta_yaw, delta_pitch);
}

void		t_camera_calc_depth(t_camera *p_cam)
{
	t_triangle	triangle;
	int			i;

	i = -1;
	while (++i < p_cam->triangle_color_list.size)
	{
		triangle = t_triangle_list_at(&(p_cam->triangle_color_list), i);
		if (triangle.a.z > p_cam->dist_max)
			p_cam->dist_max = triangle.a.z;
		else if (triangle.b.z > p_cam->dist_max)
			p_cam->dist_max = triangle.b.z;
		else if (triangle.c.z > p_cam->dist_max)
			p_cam->dist_max = triangle.c.z;
	}
	i = -1;
	while (++i < p_cam->triangle_texture_list.size)
	{
		triangle = t_triangle_list_at(&(p_cam->triangle_texture_list), i);
		if (triangle.a.z > p_cam->dist_max)
			p_cam->dist_max = triangle.a.z;
		else if (triangle.b.z > p_cam->dist_max)
			p_cam->dist_max = triangle.b.z;
		else if (triangle.c.z > p_cam->dist_max)
			p_cam->dist_max = triangle.c.z;
	}
}

void		draw_depth_from_camera_on_screen(t_camera *p_cam)
{
	t_triangle	triangle;
	t_line		line1;
	t_line		line2;
	int			i;

	t_camera_calc_depth(p_cam);
	i = -1;
	while (++i < p_cam->triangle_color_list.size)
	{
		triangle = t_triangle_list_at(&(p_cam->triangle_color_list), i);
		draw_triangle_depth_cpu(p_cam->view_port, &triangle, p_cam->dist_max);
	}
	i = -1;
	while (++i < p_cam->triangle_texture_list.size)
	{
		triangle = t_triangle_list_at(&(p_cam->triangle_texture_list), i);
		draw_triangle_depth_cpu(p_cam->view_port, &triangle, p_cam->dist_max);
	}
}

void		draw_triangle_from_camera_on_screen(t_camera *p_cam)
{
	if (p_cam->triangle_color_list.size > 0)
		multithreading_draw_triangle_color_cpu(p_cam->view_port,
						&(p_cam->triangle_color_list), &(p_cam->color_list));
	if (p_cam->triangle_texture_list.size > 0)
		multithreading_draw_triangle_texture_cpu(p_cam->view_port,
						&(p_cam->triangle_texture_list), &(p_cam->uv_list));
}

void		clean_t_camera(t_camera *camera)
{
	clean_t_triangle_list(&(camera->triangle_color_list));
	(&(camera->color_list))->size = 0;
	clean_t_triangle_list(&(camera->triangle_texture_list));
	(&(camera->darkness_list))->size = 0;
	clean_t_uv_list(&(camera->uv_list));
	t_view_port_clear_buffers(camera->view_port);
}

void		link_camera_to_mesh(t_engine *engine, int index, t_mesh *mesh)
{
	t_camera	*camera;

	camera = t_camera_list_get(engine->visual_engine->camera_list, index);
	if (camera->body != NULL)
		camera->body->camera = NULL;
	camera->body = mesh;
	if (mesh != NULL)
		mesh->camera = camera;
}
