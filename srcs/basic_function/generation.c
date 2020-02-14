/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:50:52 by adjouber          #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		generate_nbr(int min, int max)
{
	int	value;

	if (min < 0)
		max += -min;
	value = rand();
	value = value % max;
	value += min;
	return (value);
}

float	generate_float(float rmin, float rmax)
{
	return ((rand() / (float)RAND_MAX) * (rmax - rmin) + rmin);
}
