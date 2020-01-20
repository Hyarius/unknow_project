/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physic_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:56:08 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/20 13:20:59 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_physic_engine	new_physic_engine(void)
{
	t_physic_engine	result;

	result.gravity_force = new_vec4(0, -GRAVITY * 3, 0);
	result.mesh_list = initialize_t_mesh_list();
	result.item_list = initialize_t_item_list();
	return (result);
}

t_physic_engine	*initialize_t_physic_engine(void)
{
	t_physic_engine	*result;

	if (!(result = (t_physic_engine	*)malloc(sizeof(t_physic_engine))))
		return (NULL);
	*result = new_physic_engine();
	return (result);
}

void			delete_t_physic_engine(t_physic_engine dest)
{
	free_t_mesh_list(dest.mesh_list);
}

void			free_t_physic_engine(t_physic_engine *dest)
{
	delete_t_physic_engine(*dest);
	free(dest);
}

void			t_physic_engine_draw_mesh(t_physic_engine *p_physic_engine,
											t_camera *p_cam)
{
	int			i;

	i = 0;
	while (i < p_physic_engine->mesh_list->size)
	{
		draw_t_mesh(p_cam, t_mesh_list_get(p_physic_engine->mesh_list, i));
		i++;
	}
}

void			t_physic_engine_add_mesh(t_physic_engine *physic_engine,
											t_mesh p_mesh)
{
	t_mesh_list_push_back(physic_engine->mesh_list, p_mesh);
}

void			t_physic_engine_add_item(t_physic_engine *physic_engine,
											t_item p_item)
{
	t_item_list_push_back(physic_engine->item_list, p_item);
}

t_mesh			*t_physic_engine_get_mesh(t_physic_engine *physic_engine,
											int index)
{
	return (t_mesh_list_get(physic_engine->mesh_list, index));
}

void			test_move_axis(t_mesh *mesh, float *force, t_vec4 axis, t_mesh *target)
{
	float	max;
	int		subdivision;
	int		i;
	float	delta;
	float	tmp;

	subdivision = 20;
	delta = *force / subdivision;
	max = *force;
	*force = 0;
	i = -1;
	while (++i < subdivision && is_t_mesh_intersecting(mesh, target) == BOOL_FALSE)
	{
		*force += delta;
		if (i == subdivision)
			*force = max;
		t_mesh_compute_next_vertices_in_world(mesh, axis);
		if (is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
		{
			if (axis.y == 0.0)
			{
				tmp = mesh->force.y;
				mesh->force.y = 0.001;
				axis.y = 1.0;
				while (mesh->force.y < 0.015)
				{
					t_mesh_compute_next_vertices_in_world(mesh, axis);
					if (is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
						break ;
					mesh->force.y += 0.001;
				}
				if (is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
				{
					mesh->force.y = tmp;
					*force -= delta;
				}
				i = subdivision;
				axis.y = 0.0;
			}
			else
				*force -= delta;
			if (ft_strcmp(target->name, "ladder") == 0 && axis.y == 0.0)
				mesh->force.y = 0.02;
		}
	}
	t_mesh_compute_next_vertices_in_world(mesh, axis);
}

int				can_move(t_mesh *mesh, t_engine *engine)
{
	t_mesh	*target;
	int		i;
	int		j;

	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (mesh != target && target->bubble_radius + mesh->bubble_radius >= calc_dist_vec4(mesh->center, target->center) && target->no_hitbox == 0)
		{
			if (target->collectible == 1 && is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
			{
				j = 0;
				while (j < engine->physic_engine->item_list->size)
				{
					if (ft_strcmp(target->name, t_item_list_get(engine->physic_engine->item_list, j)->name) == 0)
					{
						if (engine->physic_engine->item_list->item[j].pf(engine->user_engine->player) == BOOL_TRUE)
						{
							Mix_PlayChannel(-1, engine->sound_engine->sounds[23], 0);
							t_mesh_set_visibility(target, BOOL_FALSE);
							target->no_hitbox = 1;
						}
					}
					j++;
				}
			}
			// if (is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
			// 	printf("%s\n", target->name);
			if (is_t_mesh_intersecting(mesh, target) == BOOL_TRUE && ft_strcmp(target->name, "Enemy") == '_')
			{
				player_take_dmg(engine, 10);
				if (ft_strcmp(target->name, "Enemy_mine") == 0)
					destroy_mesh(target);
			}
			if (t_mesh_on_mesh(mesh, target) == 1 && ft_strcmp(target->name, "end") == 0)
				engine->playing = -1;
			if (is_t_mesh_intersecting(mesh, target) == BOOL_TRUE && ft_strcmp(target->name, "stair") == 0)
				mesh->force.y = 0.015;
			else if (target->collectible == 0)
			{
				test_move_axis(mesh, &(mesh->force.y), new_vec4(0, 1, 0), target);
				test_move_axis(mesh, &(mesh->force.x), new_vec4(1, 0, 0), target);
				test_move_axis(mesh, &(mesh->force.z), new_vec4(0, 0, 1), target);
				if (mesh->force.z != 0.0 && mesh->force.x != 0.0)
				{
					t_mesh_compute_next_vertices_in_world(mesh, new_vec4(1, 1, 1));
					if (is_t_mesh_intersecting(mesh, target) == BOOL_TRUE)
					{
						mesh->force.z = 0.0;
						mesh->force.x = 0.0;
					}
					t_mesh_compute_next_vertices_in_world(mesh, new_vec4(1, 1, 1));
				}
			}
		}
		i++;
	}
	return (BOOL_TRUE);
}

void			t_physic_engine_compute_vertices_in_world(t_physic_engine *physic_engine)
{
	int		i;

	i = 0;
	while (i < physic_engine->mesh_list->size)
	{
		t_mesh_compute_vertices_in_world(
				t_mesh_list_get(physic_engine->mesh_list, i));
		i++;
	}
}

void			t_physic_engine_apply_force(t_engine *engine)
{
	Uint32			actual_frame;
	static Uint32	last_frame = 0;
	int				i;
	float			time_passed;
	t_mesh			*mesh;

	actual_frame = SDL_GetTicks();
	time_passed = (actual_frame - last_frame) / 1000.0;
	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		mesh = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (mesh->kinetic > 0)
			mesh->force = add_vec4(mesh->force,
					mult_vec4_by_float(engine->physic_engine->gravity_force,
											mesh->kinetic * time_passed));
		if (mesh->force.x != 0 || mesh->force.y != 0 || mesh->force.z != 0)
			if (can_move(mesh, engine) == BOOL_TRUE)
				t_mesh_apply_force(mesh);
		i++;
	}
	last_frame = actual_frame;
}
