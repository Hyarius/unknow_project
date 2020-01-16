/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:19:50 by adjouber          #+#    #+#             */
/*   Updated: 2020/01/16 14:16:15 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_mesh		create_mesh_editing(int index, char *path)
{
	t_mesh	mesh;

	if (index == 0)
	{
		mesh.name = "cube";
		mesh.size = create_t_vector4(1.0, 1.0, 1.0);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 1)
	{
		mesh.name = "wall";
		mesh.size = create_t_vector4(3.0, 2.0, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 2 || index == 3 || index == 4 || index == 5)
	{
		if (index == 2)
			mesh.name = "door";
		else if (index == 3)
			mesh.name = "door_red";
		else if (index == 4)
			mesh.name = "door_blue";
		else if (index == 5)
			mesh.name = "door_green";
		mesh.size = create_t_vector4(1.0, 2.0, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 6 || index == 7 || index == 8)
	{
		if (index == 6)
			mesh.name = "Card_red";
		else if (index == 7)
			mesh.name = "Card_blue";
		else if (index == 8)
			mesh.name = "Card_green";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 9)
	{
		mesh.name = "elevator";
		mesh.size = create_t_vector4(2.0, 5.0, 2.0);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 10)
	{
		mesh.name = "stair";
		mesh.size = create_t_vector4(1.0, 0.2, 5.0);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(10.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 11)
	{
		mesh.name = "stair";
		mesh.size = create_t_vector4(1.0, 0.2, 5.0);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(10.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 12 || index == 13 || index == 14)
	{
		if (index == 12)
			mesh.name = "Healt_Pack";
		else if (index == 13)
			mesh.name = "Armor_Pack";
		else if (index == 14)
			mesh.name = "Jet_Pack";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 15)
	{
		mesh.name = "Ammo_Pack";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -2;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 16)
	{
		mesh.name = "Ammo_Pack";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -3;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 17)
	{
		mesh.name = "Ammo_Pack";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -4;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 18)
	{
		mesh.name = "ladder";
		mesh.size = create_t_vector4(1.0, 2.0, -0.01);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 19)
	{
		mesh.name = "platform";
		mesh.size = create_t_vector4(1.0, 0.2, 1.0);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 20)
	{
		mesh.name = "plane";
		mesh.size = create_t_vector4(1.0, 0.0, 1.0);
		mesh.primitive = 0;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 21)
	{
		mesh.name = "Enemy";
		mesh.size = create_t_vector4(0.3, 0.5, 0.3);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 22)
	{
		mesh.name = "window";
		mesh.size = create_t_vector4(2.0, 2.0, 0.3);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 24)
	{
		mesh.name = "end";
		mesh.size = create_t_vector4(0.3, 0.1, 0.3);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 0.0;
	}
	else if (index == 23)
	{
		mesh.name = "Player";
		mesh.size = create_t_vector4(0.3, 0.5, 0.3);
		mesh.primitive = -1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = 100;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = path;
		mesh.kinetic = 100.0;
	}
	return (mesh);
}

t_mesh		select_mesh(t_keyboard *key, t_vector4 pos, char **path)
{
	t_mesh		mesh;
	static int	press = 0;

	if (get_key_state(key, key->key[SDL_SCANCODE_1]) == 1 && press == 0)
	{
		key->i--;
		if (key->i < 0)
			key->i = 24;
		press = 1;
	}
	else if (get_key_state(key, key->key[SDL_SCANCODE_2]) == 1 && press == 0)
	{
		key->i++;
		if (key->i > 24)
			key->i = 0;
		press = 1;
	}
	else if (get_key_state(key, key->key[SDL_SCANCODE_1]) == 0
						&& get_key_state(key, key->key[SDL_SCANCODE_2]) == 0)
		press = 0;
	mesh = create_mesh_editing(key->i, path[key->i]);
	mesh.pos = pos;
	return (mesh);
}
