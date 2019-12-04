/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:15:10 by adjouber          #+#    #+#             */
/*   Updated: 2019/12/03 15:37:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		ft_bzero(void *src, size_t nb_bytes)
{
	char	*p_src;
	size_t	i;

	i = 0;
	p_src = src;
	while (nb_bytes > i)
	{
		p_src[i] = 0;
		i++;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ssrc;
	unsigned char	*sdst;
	size_t			i;

	if (src == NULL)
		error_exit(12, "src is null");
	ssrc = (unsigned char *)src;
	if (ssrc == NULL)
		error_exit(13, "ssrc is null");
	sdst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		printf("i = %lu || ssrc = %c|\n", i, *ssrc);
		*sdst++ = *ssrc++;
		i++;
	}
	return (dst);
}

void	*ft_memalloc(size_t size)
{
	void	*zone_memoire;

	zone_memoire = malloc(size);
	if (zone_memoire)
	{
		ft_bzero(zone_memoire, size);
		return (zone_memoire);
	}
	else
		return (NULL);
}