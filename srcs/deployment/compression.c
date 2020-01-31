/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:40:10 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/30 14:48:28 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	tar_ressources(void)
{
	char *command;

	command = ft_strdup("tar -jcf ressources.tar.bz2 ressources");
	system(command);
	free(command);
	command = ft_strdup("rm -rf ressources");
	system(command);
	free(command);
}

void	untar_ressources(void)
{
	char	*command;

	command = ft_strdup("tar -jxf ressources.tar.bz2");
	system(command);
	free(command);
}
