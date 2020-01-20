/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:44:15 by adjouber          #+#    #+#             */
/*   Updated: 2020/01/20 11:43:30 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

float	round_float(float x, unsigned int round)
{
	int		i;
	float	ret;

	i = 1;
	if (round == 0)
		return (0);
	while (round > 1)
	{
		i = i * 10;
		round--;
	}
	ret = x * i;
	ret = roundf(ret);
	ret = ret / i;
	return (ret);
}

t_vec4	round_t_vec4(t_vec4 a, unsigned int round)
{
	a.x = round_float(a.x, round);
	a.y = round_float(a.y, round);
	a.z = round_float(a.z, round);
	return (a);
}
