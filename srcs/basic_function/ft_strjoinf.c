/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:16:08 by gboutin           #+#    #+#             */
/*   Updated: 2019/07/09 11:06:17 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

char	*ft_strjoinf(char **s1, char **s2, int c)
{
	char	*str;

	str = ft_strjoin(*s1, *s2);
	if (c == 1 || c == 3)
		free(*s1);
	if (c == 2 || c == 3)
		free(*s2);
	return (str);
}
