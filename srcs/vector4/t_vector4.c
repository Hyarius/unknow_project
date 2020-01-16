/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:24:08 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/16 11:55:33 by gboutin          ###   ########.fr       */
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

void		print_t_vector4(t_vector4 vector, char *str) // A SUPPRIMER
{
	printf("%s : %0.4f / %0.4f / %0.4f / %0.4f\n", str, vector.x, vector.y, vector.z, vector.w);
}
