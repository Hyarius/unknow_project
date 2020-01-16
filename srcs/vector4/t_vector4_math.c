/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:25:39 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/16 11:55:03 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_vector4	add_vector4_to_vector4(t_vector4 a, t_vector4 b)
{
	t_vector4	result;

	result = create_t_vector4(a.x + b.x, a.y + b.y, a.z + b.z);
	return (result);
}

t_vector4	substract_vector4_to_vector4(t_vector4 a, t_vector4 b)
{
	t_vector4	result;

	result = create_t_vector4(a.x - b.x, a.y - b.y, a.z - b.z);
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

t_vector4	divide_vector4_by_float(t_vector4 a, float b)
{
	t_vector4	result;

	result.x = a.x / b;
	result.y = a.y / b;
	result.z = a.z / b;
	result.w = a.w;
	return (result);
}
