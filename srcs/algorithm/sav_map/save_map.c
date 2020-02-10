/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:46:27 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/10 13:19:37 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	save_color(t_mesh cu, int fd, char **str)
{
	*str = ft_strjoinf(*str, ft_ftoa(cu.rotation.x), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(cu.rotation.y), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(cu.rotation.z), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(t_face_list_get(cu.faces, 0)->color.r), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(t_face_list_get(cu.faces, 0)->color.g), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(t_face_list_get(cu.faces, 0)->color.b), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_ftoa(t_face_list_get(cu.faces, 0)->color.a), 3);
	*str = ft_strjoinf(*str, " ", 1);
	*str = ft_strjoinf(*str, ft_itoa(cu.hp), 3);
	*str = ft_strjoinf(*str, " ", 1);
	if (cu.no_hitbox == 1)
		*str = ft_strjoinf(*str, "#\n", 1);
	else if (cu.is_visible == 0)
		*str = ft_strjoinf(*str, "*\n", 1);
	else
		*str = ft_strjoinf(*str, "\n", 1);
	write(fd, *str, ft_strlen(*str));
}

void	save_pos(t_mesh current, int fd, char *test)
{
	test = ft_strjoinf(test, ft_ftoa(current.pos.x), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(current.pos.y), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(current.pos.z), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(current.size.x), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(current.size.y), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(current.size.z), 3);
	test = ft_strjoinf(test, " ", 1);
	if (current.texture != NULL)
	{
		test = ft_strjoinf(test, current.texture->path, 1);
		test = ft_strjoinf(test, " ", 1);
	}
	else
		test = ft_strjoinf(test, "NULL ", 1);
	test = ft_strjoinf(test, ft_ftoa(current.kinetic), 3);
	test = ft_strjoinf(test, " ", 1);
	save_color(current, fd, &test);
}

void	save_name(t_mesh current, int fd)
{
	char	*test;

	test = NULL;
	if (ft_strcmp(current.name, "end") == 0)
	{
		test = ft_strdup("plane: ");
		current.size.y = 0.0;
	}
	else if (current.collectible == 1)
		test = ft_strdup("item: ");
	else if (current.primitive == 0)
		test = ft_strdup("plane: ");
	else if (current.primitive == 1)
		test = ft_strdup("cube: ");
	else if (current.primitive == 10)
	{
		test = ft_strdup("#");
		test = ft_strjoinf(test, current.name, 1);
		test = ft_strjoinf(test, " ", 1);
	}
	test = ft_strjoinf(test, current.name, 1);
	test = ft_strjoinf(test, " ", 1);
	save_pos(current, fd, test);
	ft_strdel(&test);
}

char	*command_system(int wich)
{
	char	*file;
	char	*command;

	file = ft_itoa(wich);
	command = ft_strjoin("ressources/map/save", file);
	command = ft_strjoinf(command, ".map", 1);
	remove((const char*)command);
	command = ft_strjoinf("touch ressources/map/save", file, 2);
	command = ft_strjoinf(command, ".map", 1);
	system(command);
	return (command);
}

void	save_map(t_engine *engine, int wich)
{
	char	*command;
	int		i;
	int		fd;
	t_mesh	current;

	command = command_system(wich);
	fd = open(command + 6, O_WRONLY);
	ft_strdel(&command);
	if (fd < 0)
		error_exit(-7001, "impossible fd");
	save_player(engine, fd);
	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		current = t_mesh_list_at(engine->physic_engine->mesh_list, i);
		if (current.primitive >= 0 && (current.is_visible
			|| !current.no_hitbox) && ft_strcmp(current.name, "Player") != 0)
			save_name(current, fd);
		i++;
	}
}
