/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:25:39 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/22 15:16:59 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_vec4	add_vec4(t_vec4 a, t_vec4 b)
{
	t_vec4	result;

	result = new_vec4(a.x + b.x, a.y + b.y, a.z + b.z);
	return (result);
}

t_vec4	substract_vec4(t_vec4 a, t_vec4 b)
{
	t_vec4	result;

	result = new_vec4(a.x - b.x, a.y - b.y, a.z - b.z);
	return (result);
}

t_vec4	mult_2_vec4(t_vec4 a, t_vec4 b)
{
	t_vec4	result;

	result = new_vec4(a.x * b.x, a.y * b.y, a.z * b.z);
	return (result);
}

t_vec4	mult_vec4_by_float(t_vec4 a, float b)
{
	t_vec4	result;

	result = new_vec4(a.x * b, a.y * b, a.z * b);
	return (result);
}

t_vec4	divide_vec4_by_float(t_vec4 a, float b)
{
	t_vec4	result;

	result.x = a.x / b;
	result.y = a.y / b;
	result.z = a.z / b;
	result.w = a.w;
	return (result);
}
