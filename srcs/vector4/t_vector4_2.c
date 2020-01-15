/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:25:36 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 11:25:37 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project"

t_vector4	divide_vector4_by_vector4(t_vector4 a, t_vector4 b)
{
	t_vector4	result;

	result = create_t_vector4(a.x / b.x, a.y / b.y, a.z / b.z);
	return (result);
}

t_vector4	divide_vector4_by_float(t_vector4 a, float b)
{
	t_vector4	result;

	result.x = a.x / b;
	result.y = a.y / b;
	result.z = a.z / b;
	result.w = a.w;
	return (result);
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

void		swap_t_vector4(t_vector4 *a, t_vector4 *b)
{
	t_vector4	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
