/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:40:28 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/15 11:05:17 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_mesh			init_primitive(char **line_split, char *texture_path)
{
	t_mesh		mesh;
	t_vector4	vec[2];

	vec[0] = create_t_vector4(ft_atof(line_split[2]),
							ft_atof(line_split[3]), ft_atof(line_split[4]));
	vec[1] = create_t_vector4(ft_atof(line_split[5]),
							ft_atof(line_split[6]), ft_atof(line_split[7]));
	if (ft_strcmp(line_split[0], "plane:") == 0)
		mesh = create_primitive_plane(vec[0], vec[1],
					texture_path, ft_atof(line_split[9]));
	else if (ft_strcmp(line_split[0], "cube:") == 0)
		mesh = create_primitive_cube(vec[0], vec[1],
					texture_path, ft_atof(line_split[9]));
	else if (ft_strcmp(line_split[0], "item:") == 0)
	{
		mesh = create_primitive_cube(vec[0], vec[1],
					texture_path, ft_atof(line_split[9]));
		mesh.collectible = 1;
	}
	else if (line_split[0][0] == '#')
		mesh = read_obj_file(&line_split[0][1], vec[0], vec[1],
							texture_path);
	t_mesh_activate_gravity(&mesh, ft_atof(line_split[9]));
	return (mesh);
}

t_mesh			init_texture(char **line_split)
{
	t_mesh		mesh;
	char		*texture_path;
	t_color		color;

	texture_path = NULL;
	if (ft_strcmp(line_split[8], "NULL") != 0)
		texture_path = ft_strdup(line_split[8]);
	else
		color = create_t_color(ft_atof(line_split[13]),
			ft_atof(line_split[14]),
			ft_atof(line_split[15]),
			ft_atof(line_split[16]));
	mesh = init_primitive(line_split, texture_path);
	if (texture_path == NULL)
		t_mesh_set_color(&mesh, color);
	return (mesh);
}

void			set_mesh(t_mesh *mesh, char **line_split)
{
	t_mesh_rotate(mesh, create_t_vector4(ft_atof(line_split[10]),
				ft_atof(line_split[11]), ft_atof(line_split[12])));
	mesh->hp = ft_atoi(line_split[17]);
	if (ft_strcmp(line_split[ft_tablen(line_split) - 1], "*") == 0)
		t_mesh_set_visibility(mesh, BOOL_FALSE);
	if (ft_strcmp(line_split[ft_tablen(line_split) - 1], "#") == 0)
		mesh->no_hitbox = 1;
	else
		mesh->no_hitbox = 0;
	mesh->kinetic = ft_atof(line_split[9]);
	if (mesh->primitive == 10)
		t_mesh_set_name(mesh, &line_split[0][1]);
	else
		t_mesh_set_name(mesh, line_split[1]);
}

void			read_map(t_mesh mesh, t_mesh_list *r, char **s, t_player *p)
{
	if (ft_strcmp(s[0], "player:") == 0)
		read_player(s, p);
	else if (ft_strcmp(s[0], "plane:") == 0 || s[0][0] == '#'
	|| ft_strcmp(s[0], "item:") == 0 || ft_strcmp(s[0], "cube:") == 0)
	{
		mesh = init_texture(s);
		set_mesh(&mesh, s);
		t_mesh_list_push_back(r, mesh);
	}
}

t_mesh_list		*read_map_file(int fd, t_player *player)
{
	t_mesh		mesh;
	t_mesh_list	*result;
	char		*line;
	char		**s;
	int			i;

	i = 0;
	result = initialize_t_mesh_list();
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) != 0)
		{
			s = ft_strsplit(line, ' ');
			read_map(mesh, result, s, player);
			ft_freetab(s);
		}
		free(line);
	}
	free(line);
	return (result);
}
