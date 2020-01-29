/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:19:50 by adjouber          #+#    #+#             */
/*   Updated: 2020/01/29 15:26:54 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_mesh			create_mesh_cube_wall(int index)
{
	t_mesh	ret;

	ret.name = "cube";
	ret.size = new_vec4(1.0, 1.0, 1.0);
	ret.primitive = 1;
	ret.collectible = 0;
	ret.rotation = new_vec4(0.0, 0.0, 0.0);
	ret.hp = -1;
	ret.kinetic = 0.0;
	if (index == 1)
	{
		ret.name = "wall";
		ret.size = new_vec4(3.0, 2.0, 0.2);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	return (ret);
}

t_mesh			create_mesh_door(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 2 || index == 3 || index == 4 || index == 5)
	{
		if (index == 2)
			ret.name = "door";
		else if (index == 3)
			ret.name = "door_red";
		else if (index == 4)
			ret.name = "door_blue";
		else if (index == 5)
			ret.name = "door_green";
		ret.size = new_vec4(1.0, 2.0, 0.2);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	return (ret);
}

t_mesh			create_mesh_card(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 6 || index == 7 || index == 8)
	{
		if (index == 6)
			ret.name = "Card_red";
		else if (index == 7)
			ret.name = "Card_blue";
		else if (index == 8)
			ret.name = "Card_green";
		ret.size = new_vec4(0.2, 0.05, 0.2);
		ret.primitive = 1;
		ret.collectible = 1;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	return (ret);
}

t_mesh_editing	create_mesh_editing(int index, char *path)
{
	t_mesh_editing	ret;

	ret.path = path;
	ret.mesh = create_mesh_cube_wall(index);
	ret.mesh = create_mesh_door(index, ret.mesh);
	ret.mesh = create_mesh_card(index, ret.mesh);
	ret.mesh = create_mesh_elevator(index, ret.mesh);
	ret.mesh = create_mesh_slope(index, ret.mesh);
	ret.mesh = create_mesh_item(index, ret.mesh);
	ret.mesh = create_mesh_ammo(index, ret.mesh);
	ret.mesh = create_mesh_ladder_platform(index, ret.mesh);
	ret.mesh = create_mesh_plane_enemy(index, ret.mesh);
	ret.mesh = create_mesh_window_player(index, ret.mesh);
	ret.mesh = create_mesh_end(index, ret.mesh);
	return (ret);
}

t_mesh_editing	select_mesh(t_keyboard *key, t_vec4 pos, char **path)
{
	t_mesh_editing	mesh;
	static int		press = 0;

	if (get_key_state(key, key->key[SDL_SCANCODE_1]) == 1 && press == 0)
	{
		key->i = (key->i == 12) ? key->i - 2 : key->i - 1;
		if (key->i < 0)
			key->i = 24;
		press = 1;
	}
	else if (get_key_state(key, key->key[SDL_SCANCODE_2]) == 1 && press == 0)
	{
		key->i = (key->i == 10) ? key->i + 2 : key->i + 1;
		if (key->i > 24)
			key->i = 0;
		press = 1;
	}
	else if (get_key_state(key, key->key[SDL_SCANCODE_1]) == 0
						&& get_key_state(key, key->key[SDL_SCANCODE_2]) == 0)
		press = 0;
	mesh = create_mesh_editing(key->i, path[key->i]);
	mesh.mesh.pos = pos;
	return (mesh);
}
