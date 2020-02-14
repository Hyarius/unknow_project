/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:13:04 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:30:52 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((char*)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_memalloc(size_t size)
{
	size_t	*dest;

	if (!(dest = (size_t*)malloc(sizeof(size_t) * size)))
		return (NULL);
	ft_memset(dest, 0, size);
	return (dest);
}
