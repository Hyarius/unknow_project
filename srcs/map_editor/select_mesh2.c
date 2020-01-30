/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_mesh2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:42:32 by adjouber          #+#    #+#             */
/*   Updated: 2020/01/29 15:25:41 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_mesh			create_mesh_elevator(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 9)
	{
		ret.name = "elevator";
		ret.size = new_vec4(2.0, 5.0, 2.0);
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	return (ret);
}

t_mesh			create_mesh_slope(int index, t_mesh mesh)
{
	t_mesh ret;

	ret = mesh;
	if (index == 10)
	{
		ret.name = "stair";
		ret.size = new_vec4(1.0, 0.2, 5.0);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.rotation = new_vec4(10.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	return (ret);
}

t_mesh			create_mesh_item(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 12 || index == 13 || index == 14)
	{
		if (index == 12)
			ret.name = "Healt_Pack";
		else if (index == 13)
			ret.name = "Armor_Pack";
		else if (index == 14)
			ret.name = "Jet_Pack";
		ret.size = new_vec4(0.2, 0.05, 0.2);
		ret.primitive = 1;
		ret.collectible = 1;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	return (ret);
}

t_mesh			create_mesh_ammo(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 15 || index == 16 || index == 17)
	{
		ret.name = "Ammo_Pack";
		ret.size = new_vec4(0.2, 0.05, 0.2);
		ret.primitive = 1;
		ret.collectible = 1;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		if (index == 15)
			ret.hp = -2;
		if (index == 16)
			ret.hp = -3;
		if (index == 17)
			ret.hp = -4;
		ret.kinetic = 0.0;
	}
	return (ret);
}

t_mesh			create_mesh_ladder_platform(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 18)
	{
		ret.name = "ladder";
		ret.size = new_vec4(1.0, 2.0, -0.01);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	else if (index == 19)
	{
		ret.name = "platform";
		ret.size = new_vec4(1.0, 0.2, 1.0);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	return (ret);
}
