/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:18:14 by adjouber          #+#    #+#             */
/*   Updated: 2020/02/10 10:27:31 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	ft_freetab(char ***tab)
{
	int	i;
	int len;

	i = -1;
	len = ft_tablen(*tab);
	while (++i < len)
		ft_strdel(&(*tab)[i]);
	ft_memdel((void**)tab);
}

char	*ft_strjoinf(char *s1, char *s2, int c)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (c == 1 || c == 3)
		ft_strdel(&s1);
	if (c == 2 || c == 3)
		ft_strdel(&s2);
	return (str);
}
