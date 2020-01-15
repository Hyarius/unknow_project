/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:24:08 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 12:19:52 by jubeal           ###   ########.fr       */
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

t_vector4	divide_vector4_by_float(t_vector4 a, float b)
{
	t_vector4	result;

	result.x = a.x / b;
	result.y = a.y / b;
	result.z = a.z / b;
	result.w = a.w;
	return (result);
}

void		print_t_vector4(t_vector4 vector, char *str) // A SUPPRIMER
{
	printf("%s : %0.4f / %0.4f / %0.4f / %0.4f\n", str, vector.x, vector.y, vector.z, vector.w);
}
