/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:17:25 by adjouber          #+#    #+#             */
/*   Updated: 2020/01/23 16:28:26 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		check_mesh_player(t_engine *engine, t_mesh mesh)
{
	int			i;
	t_mesh		*target;

	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(target->name, "Player") == 0)
		{
			target->is_visible = 0;
			target->no_hitbox = 1;
			t_mesh_set_name(target, "mesh");
		}
		i++;
	}
	engine->user_engine->player->hitbox = mesh;
}

void		place_mesh_bis(t_engine *engine, t_mesh_editing edit, t_mesh *mesh)
{
	t_mesh_set_color(mesh, new_color(1.0, 1.0, 1.0, 1.0));
	t_mesh_set_name(mesh, edit.mesh.name);
	mesh->hp = edit.mesh.hp;
	t_mesh_rotate(mesh, edit.mesh.rotation);
	cast_mesh(engine, mesh);
	mesh->pos.x = round_float(mesh->pos.x, 2);
	mesh->pos.y = round_float(mesh->pos.y, 2);
	mesh->pos.z = round_float(mesh->pos.z, 2);
	if (ft_strcmp(mesh->name, "Player") == 0)
		check_mesh_player(engine, *mesh);
}

// t_mesh		place_stair()

void		place_mesh(t_engine *engine, t_mesh_editing edit)
{
	t_mesh		mesh;

	if (t_mouse_state(engine->user_engine->mouse) == 2)
	{
		if (edit.mesh.primitive == 1 || edit.mesh.primitive == -1)
		{
			if (edit.mesh.primitive == -1)
			{
				mesh = create_primitive_cube(edit.mesh.pos,
					edit.mesh.size, edit.path, edit.mesh.kinetic);
				mesh.primitive = -1;
			}
			else
				mesh = create_primitive_cube(edit.mesh.pos,
					edit.mesh.size, edit.path, edit.mesh.kinetic);
		}
		else if (edit.mesh.primitive == 0)
			mesh = create_primitive_plane(edit.mesh.pos,
				edit.mesh.size, edit.path, edit.mesh.kinetic);
		// else if (edit.mesh.primitive == 5)
			// mesh = place_stair();
		place_mesh_bis(engine, edit, &mesh);
		t_engine_add_mesh(engine, mesh);
	}
}
