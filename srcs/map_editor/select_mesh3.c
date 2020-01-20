/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_mesh3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:45:19 by adjouber          #+#    #+#             */
/*   Updated: 2020/01/20 12:46:05 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_mesh			create_mesh_plane_enemy(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 20)
	{
		ret.name = "plane";
		ret.size = new_vec4(1.0, 0.0, 1.0);
		ret.primitive = 0;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	else if (index == 21)
	{
		ret.name = "Enemy";
		ret.size = new_vec4(0.3, 0.5, 0.3);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	return (ret);
}

t_mesh			create_mesh_window_player(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 22)
	{
		ret.name = "window";
		ret.size = new_vec4(2.0, 2.0, 0.3);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	else if (index == 23)
	{
		ret.name = "Player";
		ret.size = new_vec4(0.3, 0.5, 0.3);
		ret.primitive = -1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = 100;
		ret.kinetic = 100.0;
	}
	return (ret);
}

t_mesh			create_mesh_end(int index, t_mesh mesh)
{
	t_mesh	ret;

	ret = mesh;
	if (index == 24)
	{
		ret.name = "end";
		ret.size = new_vec4(0.3, 0.1, 0.3);
		ret.primitive = 1;
		ret.collectible = 0;
		ret.rotation = new_vec4(0.0, 0.0, 0.0);
		ret.hp = -1;
		ret.kinetic = 0.0;
	}
	return (ret);
}
