/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:40:10 by jubeal            #+#    #+#             */
/*   Updated: 2020/02/06 10:20:47 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	tar_ressources(void)
{
	char *command;

	if (!(command = ft_strdup("tar -jcf ressources.tar.bz2 ressources && \
							rm -rf ressources")))
		error_exit(-70, "ft_strdup failed");
	system(command);
	ft_strdel(&command);
}

void	untar_ressources(void)
{
	char	*command;

	if (!(command = ft_strdup("tar -jxf ressources.tar.bz2")))
		error_exit(-70, "ft_strdup failed");
	system(command);
	ft_strdel(&command);
}
