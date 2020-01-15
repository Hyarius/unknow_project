/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:25:39 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 11:25:39 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_vector4	substract_float_to_vector4(t_vector4 b, float a)
{
	t_vector4	result;

	result = create_t_vector4(b.x - a, b.y - a, b.z - a);
	return (result);
}

t_vector4	add_float_to_vector4(t_vector4 b, float a)
{
	t_vector4	result;

	result = create_t_vector4(b.x + a, b.y + a, b.z + a);
	return (result);
}

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
