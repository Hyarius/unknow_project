/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:03:52 by gboutin           #+#    #+#             */
/*   Updated: 2019/12/02 15:34:13 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

// static int			fill_with_rest(char **to_fill, t_list_fd **current)
// {
// 	int			i;

// 	i = 0;
// 	while ((*current)->rest[i] && (*current)->rest[i] != '\n')
// 		i++;
// 	if (!(*to_fill = ft_strnew(i)))
// 		return (-1);
// 	i = 0;
// 	while ((*current)->rest[i])
// 	{
// 		if ((*current)->rest[i] == '\n')
// 		{
// 			(*to_fill)[i] = '\0';
// 			if ((*current)->rest + i + 1)
// 				(*current)->rest = (*current)->rest + i + 1;
// 			else
// 				(*current)->rest = NULL;
// 			return (0);
// 		}
// 		(*to_fill)[i] = (*current)->rest[i];
// 		i++;
// 	}
// 	(*current)->rest = NULL;
// 	return (1);
// }

// static int			fill_final(long car_read, char **final,
// 			char buff[BUFF_SIZE + 1])
// {
// 	char		*tmp;

// 	if (car_read == -1)
// 		return (-1);
// 	if (car_read)
// 	{
// 		tmp = *final;
// 		if (!(*final = ft_strnew(ft_strlen(tmp) + ft_strlen(buff))))
// 			return (-1);
// 		ft_strcpy(*final, tmp);
// 		ft_strcat(*final, buff);
// 		free(tmp);
// 	}
// 	return (0);
// }

// static int			process(char **final, t_list_fd **current, int test)
// {
// 	long		car_read;
// 	char		*buff;
// 	long		i;

// 	car_read = BUFF_SIZE;
// 	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
// 		return (-1);
// 	while (car_read == BUFF_SIZE && test)
// 	{
// 		if ((car_read = read((*current)->fd, buff, BUFF_SIZE)) == -1)
// 			return (-1);
// 		buff[car_read] = '\0';
// 		i = 0;
// 		while (buff[i] != '\0' && buff[i] != '\n')
// 			i++;
// 		if (buff[i] == '\n' && i == car_read - 1 && !(--test))
// 			buff[i] = '\0';
// 		if (buff[i] == '\n' && i < car_read && !(--test) && !(buff[i] = '\0'))
// 			(*current)->rest = ft_strdup(buff + i + 1);
// 		if (fill_final(car_read, final, buff) == -1)
// 			return (-1);
// 	}
// 	free(buff);
// 	return (car_read > 0 ? 1 : car_read);
// }

// static t_list_fd	*pick_up_good_one(int fd, t_list_fd **current)
// {
// 	if (!(*current))
// 	{
// 		if (!(*current = (t_list_fd *)malloc(sizeof(t_list_fd))))
// 			return (NULL);
// 		(*current)->rest = NULL;
// 		(*current)->fd = fd;
// 		(*current)->next = NULL;
// 		return (*current);
// 	}
// 	if (fd == (*current)->fd)
// 		return (*current);
// 	return (pick_up_good_one(fd, &((*current)->next)));
// }

// int					get_next_line(const int fd, char **line)
// {
// 	char				*final;
// 	static t_list_fd	*rest;
// 	int					ret;
// 	t_list_fd			*current;

// 	if (BUFF_SIZE < 1 || fd < 0 || !line ||
// 			!(current = pick_up_good_one(fd, &rest)))
// 		return (-1);

// 	if (!current->rest)
// 	{
// 		if (!(final = (char *)malloc(sizeof(char))))
// 			return (-1);
// 		final[0] = '\0';
// 	}
// 	ft_get_leaks("UNKNOW_PROJECT", "GNL");
// 	else if (!fill_with_rest(&final, &current) && (*line = final))
// 		return (1);
// 	if (final == NULL || (ret = process(&final, &current, 1)) == -1)
// 		return (-1);
// 	*line = final;
// 	if ((*line)[0] == '\0' && !ret)
// 		return (0);
// 	return (1);
// }

static int			get_errors(int fd, char **line)
{
	char b[BUFF_SIZE + 1];

	if ((fd < 0 || read(fd, b, 0) < 0 || BUFF_SIZE <= 0 || line == NULL))
		return (1);
	return (0);
}


static char			*get_read(const int fd, char *str, char *buff)
{
	int				ret;

	if (str == NULL && (!(str = ft_strnew(0))))
		return (NULL);
	while (!(ft_strchr(str, '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoinf(str, buff, 1);
	}
	ft_strdel(&buff);
	return (str);
}

static t_list_fd		*ft_check_fd(const int fd, t_list_fd **begin)
{
	t_list_fd			*tmp;
	t_list_fd			*new;

	tmp = *begin;
	new = NULL;
	while (tmp)
	{
		if ((int)tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(new = (t_list_fd*)malloc(sizeof(t_list_fd))))
		return (NULL);
	new->rest = NULL;
	new->fd = fd;
	ft_lstadd(begin, new);
	return (new);
}

static int		end_of_gnl(t_list_fd **begin)
{
	ft_lstdel(begin, &ft_del_cont);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_list_fd	*begin = NULL;
	char			*tmp;
	char			*buff;
	int				endline;
	t_list_fd			*current;

	*line = NULL;
	if (get_errors(fd, line) == 1 || !(current = ft_check_fd(fd, &begin)))
		return (-1);
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	current->rest = get_read(fd, (char*)current->rest, buff);
	if ((ft_strcmp((char*)current->rest, "") == 0) && (read(fd, buff, BUFF_SIZE) == 0))
		return (end_of_gnl(&begin));
	else if ((char*)current->rest)
	{
		endline = ft_get_end_line((char*)current->rest);
		*line = ft_strsub((char*)current->rest, 0, endline);
		if (((char*)current->rest)[endline] == '\0')
			tmp = ft_strdup(((char*)current->rest) + endline);
		else
			tmp = ft_strdup(((char*)current->rest) + endline + 1);
		ft_strdel((char**)&current->rest);
		current->rest = tmp;
	}
	// ft_get_leaks("UNKNOW_PROJECT", "GNL");
	return (1);
}