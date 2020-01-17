/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_triangle_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:25:39 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/17 11:31:36 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_triangle	t_triangle_add_vector4(t_triangle triangle, t_vector4 to_add)
{
	t_triangle	result;

	result.a = add_vector4_to_vector4(triangle.a, to_add);
	result.b = add_vector4_to_vector4(triangle.b, to_add);
	result.c = add_vector4_to_vector4(triangle.c, to_add);
	return (result);
}

t_triangle	mult_triangle_by_vector4(t_triangle triangle, t_vector4 to_add)
{
	t_triangle	result;

	result.a = mult_vector4_by_vector4(triangle.a, to_add);
	result.b = mult_vector4_by_vector4(triangle.b, to_add);
	result.c = mult_vector4_by_vector4(triangle.c, to_add);
	return (result);
}

void		t_triangle_get_min_max_value(t_triangle *triangle, t_vector4 *min,
																t_vector4 *max)
{
	max->x = get_big_float(triangle->a.x, triangle->b.x, triangle->c.x);
	max->y = get_big_float(triangle->a.y, triangle->b.y, triangle->c.y);
	max->z = get_big_float(triangle->a.z, triangle->b.z, triangle->c.z);
	min->x = get_short_float(triangle->a.x, triangle->b.x, triangle->c.x);
	min->y = get_short_float(triangle->a.y, triangle->b.y, triangle->c.y);
	min->z = get_short_float(triangle->a.z, triangle->b.z, triangle->c.z);
}

int			t_triangle_is_bigger(t_triangle a, t_triangle b)
{
	float	point[8];
	float	s[2];

	point[0] = calc_dist_vector4_to_vector4(a.a, a.b);
	point[1] = calc_dist_vector4_to_vector4(a.a, a.c);
	point[2] = calc_dist_vector4_to_vector4(a.b, a.c);
	point[3] = calc_dist_vector4_to_vector4(b.a, b.b);
	point[4] = calc_dist_vector4_to_vector4(b.a, b.c);
	point[5] = calc_dist_vector4_to_vector4(b.b, b.c);
	point[6] = point[0] + point[1] + point[2];
	point[7] = point[3] + point[4] + point[5];
	s[0] = sqrt(point[6] * (point[6] - point[0]) * (point[6] - point[1])
													* (point[6] * point[2]));
	s[1] = sqrt(point[7] * (point[7] - point[3]) * (point[7] - point[4])
													* (point[7] * point[5]));
	if (s[0] >= s[1])
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}

int			t_triangle_equal(t_triangle a, t_triangle b)
{
	sort_t_triangle_points(&a);
	sort_t_triangle_points(&b);
	if (t_vector4_equal(a.a, b.a) == BOOL_FALSE ||
		t_vector4_equal(a.b, b.b) == BOOL_FALSE ||
		t_vector4_equal(a.c, b.c) == BOOL_FALSE)
		return (BOOL_FALSE);
	return (BOOL_TRUE);
}
