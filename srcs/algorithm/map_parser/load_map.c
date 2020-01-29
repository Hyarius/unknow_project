/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:40:38 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/28 10:06:22 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	link_enemy_to_camera(t_engine *engine, int k)
{
	t_engine_add_camera(engine,
		new_camera(t_camera_list_get(engine->visual_engine->camera_list,
		0)->view_port->window, new_vec4(0.0, 0.0, 0.0), 70,
		create_vec2(NEAR, FAR)));
	resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list,
		2 + k)->view_port, create_vec2_int(1, 1));
	move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list,
		2 + k)->view_port, create_vec2_int(0, 0));
}

void	set_map_in_engine(t_engine *engine, t_mesh_list *meshs,
							t_item_list *item_list)
{
	int i;
	int	j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < meshs->size)
	{
		if (t_mesh_list_at(meshs, i).collectible == 1)
		{
			t_engine_add_item(engine, t_item_list_at(item_list, j));
			j++;
		}
		t_engine_add_mesh(engine, t_mesh_list_at(meshs, i));
		if (ft_strcmp(t_engine_get_mesh(engine, i)->name, "Enemy") == 0
		|| ft_strcmp(t_engine_get_mesh(engine, i)->name, "Enemy_boss") == 0)
		{
			link_enemy_to_camera(engine, k);
			link_camera_to_mesh(engine, 2 + k, t_engine_get_mesh(engine, i));
			k++;
		}
		i++;
	}
}

void	load_map(t_camera *main_camera, t_engine *engine, char *path)
{
	t_item_list *item_list;
	t_mesh_list	*meshs;
	int			fd;

	engine->user_engine->player = initialize_t_player(main_camera);
	if ((fd = open(path, O_RDONLY)) < 0)
		error_exit(-7000, "imposible fd");
	meshs = read_map_file(fd, engine->user_engine->player);
	item_list = load_items(meshs);
	close(fd);
	t_engine_add_mesh(engine, engine->user_engine->player->hitbox);
	set_map_in_engine(engine, meshs, item_list);
	free_t_item_list(item_list);
	free_t_mesh_list(meshs);
}
