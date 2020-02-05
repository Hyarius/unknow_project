/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mesh_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:30:47 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/05 11:50:35 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	t_mesh_set_texture(t_mesh *dest, t_texture *p_texture)
{
	dest->texture = p_texture;
}

void	t_mesh_set_color(t_mesh *dest, t_color p_color)
{
	int i;

	i = -1;
	while (++i < dest->faces->size)
		set_t_face_color(t_face_list_get(dest->faces, i), p_color);
}

void	t_mesh_set_visibility(t_mesh *dest, int new_state)
{
	dest->is_visible = new_state;
}

void	t_mesh_set_name(t_mesh *mesh, char *name)
{
	if (!(mesh->name = ft_strdup(name)))
		error_exit(-70, "ft_strdup failed.");
	if (ft_strcmp(mesh->name, "door") == 0
		|| ft_strcmp(mesh->name, "elevator") == 0
		|| ft_strcmp(mesh->name, "door_red") == 0
		|| ft_strcmp(mesh->name, "door_blue") == 0
		|| ft_strcmp(mesh->name, "door_green") == 0)
		mesh->door = new_door();
	else if (ft_strcmp(mesh->name, "Enemy") == 0
		|| ft_strcmp(mesh->name, "Enemy_boss") == 0)
		mesh->tick = 0;
}
