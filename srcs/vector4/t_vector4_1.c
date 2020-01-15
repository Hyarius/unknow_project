/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:24:48 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 11:25:28 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

int			t_vector4_equal(t_vector4 a, t_vector4 b)
{
	if (a.x != b.x || a.y != b.y || a.z != b.z)
		return (BOOL_FALSE);
	return (BOOL_TRUE);
}

float		t_vector4_length(t_vector4 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

char		*vector4_str(t_vector4 vector)
{
	char *x;
	char *y;
	char *z;
	char *result;

	x = ft_ftoa_p(vector.x, 5);
	y = ft_ftoa_p(vector.y, 5);
	z = ft_ftoa_p(vector.z, 5);
	result = x;
	result = ft_strjoinf(result, " / ", 1);
	result = ft_strjoinf(result, y, 3);
	result = ft_strjoinf(result, " / ", 1);
	result = ft_strjoinf(result, z, 3);
	return (result);
}
