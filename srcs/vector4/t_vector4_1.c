/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:25:39 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 12:17:57 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_vector4	mult_vector4_by_vector4(t_vector4 a, t_vector4 b)
{
	t_vector4	result;

	result = create_t_vector4(a.x * b.x, a.y * b.y, a.z * b.z);
	return (result);
}

t_vector4	mult_vector4_by_float(t_vector4 a, float b)
{
	t_vector4	result;

	result = create_t_vector4(a.x * b, a.y * b, a.z * b);
	return (result);
}

int			t_vector4_equal(t_vector4 a, t_vector4 b)
{
	if (a.x != b.x || a.y != b.y || a.z != b.z)
		return (BOOL_FALSE);
	return (BOOL_TRUE);
}

void		swap_t_vector4(t_vector4 *a, t_vector4 *b)
{
	t_vector4	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_vector4	inv_t_vector4(t_vector4 src)
{
	t_vector4	result;

	result.x = -1 * src.x;
	result.y = -1 * src.y;
	result.z = -1 * src.z;
	result.w = -1 * src.w;
	return (result);
}
