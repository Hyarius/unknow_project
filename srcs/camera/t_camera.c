/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:18:59 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/20 14:56:34 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		new_camera2(t_camera *result)
{
	result->model = new_matrix();
	t_camera_look_at(result);
	result->view = t_camera_compute_view(result);
	result->projection = compute_projection_matrix(result);
	result->sun_direction = normalize_t_vec4(new_vec4(0.2, -1, -0.4));
	result->triangle_color_list = new_triangle_list();
	result->color_list = new_color_list();
	result->triangle_texture_list = new_triangle_list();
	result->uv_list = new_uv_list();
	result->darkness_list = new_color_list();
}

t_camera	new_camera(t_window *window, t_vec4 p_pos, float p_fov,
															t_vec2 p_dist)
{
	t_camera	result;

	result.view_port = initialize_t_view_port(window,
				create_vec2_int(0, 0), create_vec2_int(window->size_x,
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
	new_camera2(&result);
	return (result);
}

t_camera	*initialize_t_camera(t_window *window, t_vec4 p_pos,
												float p_fov, t_vec2 p_dist)
{
	t_camera	*result;

	if (!(result = (t_camera *)malloc(sizeof(t_camera))))
		error_exit(-31, "Can't malloc a t_camera");
	*result = new_camera(window, p_pos, p_fov, p_dist);
	return (result);
}

void		handle_t_camera_mouvement_by_key(t_camera *camera, t_keyboard *p_keyboard, t_engine *engine)
{
	t_mesh		*target;
	t_vec4		tmp;
	t_vec4		mouvement;
	t_vec4		save;
	float		y;
	float		j;
	float		z;
	int			i;
	int			k;
	int			l;
	static int	in_air = 0;

	j = 0.0;
	i = 0;
	z = 0.0;
	mouvement = new_vec4(0, 0, 0);
	save = new_vec4(0, 0, 0);
	if (engine->user_engine->player->hitbox.kinetic == 0.0f)
	{
		camera->body->force = new_vec4(0.0, 0.0, 0.0);
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
		tmp = new_vec4(camera->speed * camera->running, z, camera->speed * camera->running);
	else
		tmp = new_vec4(camera->speed, z, camera->speed);
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_S]) == 1)
	{
		tmp = new_vec4(camera->speed / camera->slowing, z, camera->speed / camera->slowing);
		camera->body->force = add_vec4(mult_vec4_by_vec4(normalize_t_vec4(mult_vec4_by_vec4(camera->forward, new_vec4(-1.0, -1.0, -1.0))), tmp), mouvement);
		save = new_vec4(camera->body->force.x, camera->body->force.y, camera->body->force.z);
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_W]) == 1)
	{
		camera->body->force = add_vec4(mult_vec4_by_vec4(normalize_t_vec4(mult_vec4_by_vec4(camera->forward, new_vec4(1.0, 1.0, 1.0))), tmp), mouvement);
		if (save.x != 0 || save.y != 0 || save.z != 0)
			save = add_vec4(divide_vec4_by_float(camera->body->force, 2), divide_vec4_by_float(save, 2));
		else
			save = new_vec4(camera->body->force.x, camera->body->force.y, camera->body->force.z);
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_D]) == 1)
	{
		camera->body->force = add_vec4(mult_vec4_by_vec4(camera->right, tmp), mouvement);
		if (save.x != 0 || save.y != 0 || save.z != 0)
			save = add_vec4(divide_vec4_by_float(camera->body->force, 2), divide_vec4_by_float(save, 2));
		else
			save = new_vec4(camera->body->force.x, camera->body->force.y, camera->body->force.z);
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_A]) == 1)
	{
		camera->body->force = add_vec4(mult_vec4_by_vec4(inv_t_vec4(camera->right), tmp), mouvement);
		if (save.x != 0 || save.y != 0 || save.z != 0)
			save = add_vec4(divide_vec4_by_float(camera->body->force, 2), divide_vec4_by_float(save, 2));
		else
			save = new_vec4(camera->body->force.x, camera->body->force.y, camera->body->force.z);
	}
	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_LCTRL]) == 1)
	{
		j = 0.2;
		if (camera->crounch == 0)
		{
			t_mesh_resize(camera->body, new_vec4(0.0, -0.2, 0.0));
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
			if (camera->body != target && target->bubble_radius + camera->body->bubble_radius >= calc_dist_vec4(camera->body->center, target->center))
			{
				k++;
				if (camera->body->pos.y > target->pos.y || target->pos.y - camera->body->pos.y >= 0.49)
					l++;
			}
			i++;
		}
		if (k == l)
		{
			t_mesh_resize(camera->body, new_vec4(0.0, 0.2, 0.0));
			camera->crounch = 0;
			j = 0.0;
		}
		else
			j = 0.2;
	}
	if (y != 0.0f)
		camera->body->force = new_vec4(save.x, y, save.z);
	else
		camera->body->force = save;
	move_camera(camera, camera->body->force, engine, j);
	camera->body->force = mult_vec4_by_vec4(camera->body->force, new_vec4(0.0, 1.0, 0.0));
}
