/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:24:08 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 11:24:35 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_vector4	create_t_vector4(float p_x, float p_y, float p_z)
{
	t_vector4 result;

	result.x = p_x;
	result.y = p_y;
	result.z = p_z;
	result.w = 1.0;
	return (result);
}

t_vector4	*initialize_t_vector4(float p_x, float p_y, float p_z)
{
	t_vector4 *result;

	if (!(result = (t_vector4 *)malloc(sizeof(t_vector4))))
		return (NULL);
	*result = create_t_vector4(p_x, p_y, p_z);
	return (result);
}

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
