/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_item.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:23:52 by spuisais          #+#    #+#             */
/*   Updated: 2019/08/09 13:23:44 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		heal(t_player player)
{
	printf("Current hp = %d\n", player.hp);
	int to_heal;

	to_heal = 20;
	if (player.hp < 100)
	{
		while (player.hp < 100 && to_heal > 0)
			player.hp += to_heal--;
	}
	printf("Now = %d\n", player.hp);
}

void		refill(t_player player)
{
	// int to_refill;

	// to_refill = 15;
	// if (player.ammo.pistol_ammo < 999)
	// {
	// 	while (player.hp < 100)
	// 		player.hp += to_refill--;
	// }
}

void		protect(t_player player)
{
	// int to_heal;

	// to_heal = 20;
	// if (player.hp < 100)
	// {
	// 	while (player.hp < 100)
	// 		player.hp += to_heal--;
	// }
}

t_item		create_health_pack(t_vector3 pos, t_engine *engine)
{
	t_item	item;
	t_mesh	result;
	
	item.type = 0;
	item.name = "Health Pack";
	result = create_primitive_cube(pos, create_t_vector3(0.2, 0.05, 0.2), NULL, 100.0, item.name);
	t_mesh_rotate(&result, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&result, create_t_color(0.8, 0.0, 0.0 ,1.0));
	t_engine_add_mesh(engine, result);
	item.mesh = &result;
	item.pf = heal;
	return (item);
}

t_item		create_ammo_pack(t_vector3 pos, t_engine *engine)
{
	t_item	item;
	t_mesh	result;
	
	item.type = 0;
	item.name = "Ammo Pack";
	result = create_primitive_cube(pos, create_t_vector3(0.2, 0.05, 0.2), NULL, 100.0, item.name);
	t_mesh_rotate(&result, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&result, create_t_color(0.8, 0.0, 0.0 ,1.0));
	t_engine_add_mesh(engine, result);
	item.mesh = &result;
	item.pf = refill;
	return (item);
}

t_item		create_armor_pack(t_vector3 pos, t_engine *engine)
{
	t_item	item;
	t_mesh	result;
	
	item.type = 0;
	item.name = "Armor Pack";
	result = create_primitive_cube(pos, create_t_vector3(0.2, 0.05, 0.2), NULL, 100.0, item.name);
	t_mesh_rotate(&result, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&result, create_t_color(0.8, 0.0, 0.0 ,1.0));
	t_engine_add_mesh(engine, result);
	item.mesh = &result;
	item.pf = protect;
	return (item);
}