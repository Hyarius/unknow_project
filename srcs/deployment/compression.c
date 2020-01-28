/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:40:10 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/24 10:40:38 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	tar_ressources(void)
{
	char *command;

	command = ft_strdup("tar -cf ressources.tar ressources");
	system(command);
	free(command);
	command = ft_strdup("bzip2 ressources.tar");
	system(command);
	free(command);
	command = ft_strdup("rm -rf ressources");
	system(command);
	free(command);
}

void	untar_ressources(void)
{
	char	*command;

	command = ft_strdup("bunzip2 ressources.tar.bz2");
	system(command);
	free(command);
	command = ft_strdup("tar xf ressources.tar");
	system(command);
	free(command);
}
