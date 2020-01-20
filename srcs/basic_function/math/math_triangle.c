/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:03:34 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/20 11:44:52 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

int		is_triangle_parallele(t_triangle p_a, t_triangle p_b)
{
	t_vec4	normal_a;
	t_vec4	normal_b;
	float	dot;

	normal_a = cross_t_vec4(substract_vec4(p_a.b, p_a.a),
			substract_vec4(p_a.c, p_a.a));
	normal_b = cross_t_vec4(substract_vec4(p_b.b, p_b.a),
			substract_vec4(p_b.c, p_b.a));
	dot = dot_t_vec4(normal_a, normal_b);
	if (dot == 1 || dot == -1)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}

int		intersect_triangle_by_segment(t_triangle p_triangle, t_line line,
														t_vec4 *intersection)
{
	t_vec4	t_v[6];
	float	f[11];

	t_v[0] = substract_vec4(p_triangle.b, p_triangle.a);
	t_v[1] = substract_vec4(p_triangle.c, p_triangle.a);
	t_v[2] = cross_t_vec4(t_v[0], t_v[1]);
	if (t_v[2].x == 0.0 && t_v[2].y == 0.0 && t_v[2].z == 0.0)
		return (-1);
	t_v[3] = substract_vec4(line.b, line.a);
	t_v[4] = substract_vec4(line.a, p_triangle.a);
	f[1] = -dot_t_vec4(t_v[2], t_v[4]);
	f[2] = dot_t_vec4(t_v[2], t_v[3]);
	if (fabs(f[2]) < 0.00000001f)
	{
		if (f[1] == 0)
			return (2);
		else
			return (0);
	}
	f[0] = (f[1] / f[2]);
	if (f[0] < 0.0f || f[0] > 1.0f)
		return (0);
	*intersection = add_vec4(
								mult_vec4_by_float(t_v[3], f[0]), line.a);
	f[3] = dot_t_vec4(t_v[0], t_v[0]);
	f[4] = dot_t_vec4(t_v[0], t_v[1]);
	f[5] = dot_t_vec4(t_v[1], t_v[1]);
	t_v[5] = substract_vec4(*intersection, p_triangle.a);
	f[6] = dot_t_vec4(t_v[5], t_v[0]);
	f[7] = dot_t_vec4(t_v[5], t_v[1]);
	f[8] = f[4] * f[4] - f[3] * f[5];
	f[9] = (f[4] * f[7] - f[5] * f[6]) / f[8];
	if (f[9] < 0.0f || f[9] > 1.0f)
		return (0);
	f[10] = (f[4] * f[6] - f[3] * f[7]) / f[8];
	if (f[10] < 0.0f || (f[9] + f[10]) > 1.0f)
		return (0);
	return (1);
}

int		is_point_on_triangle(t_triangle a, t_vec4 point)
{
	if (same_side(point, a.a, a.b, a.c) == BOOL_TRUE
		&& same_side(point, a.b, a.c, a.a) == BOOL_TRUE
		&& same_side(point, a.c, a.a, a.b) == BOOL_TRUE)
		return (BOOL_TRUE);
	else
		return (BOOL_FALSE);
}

float	calc_distance_to_triangle(t_triangle p_triangle, t_vec4 point)
{
	float	sb;
	float	sn;
	float	sd;
	t_vec4	normal;

	normal = cross_t_vec4(substract_vec4(p_triangle.b,
				p_triangle.a), substract_vec4(p_triangle.c,
														p_triangle.a));
	sn = -dot_t_vec4(normal,
			substract_vec4(point, p_triangle.a));
	sd = dot_t_vec4(normal, normal);
	sb = sn / sd;
	return (sb);
}

int		is_triangle_in_triangle(t_triangle p_a, t_triangle p_b)
{
	if (is_triangle_parallele(p_a, p_b) == BOOL_FALSE)
		return (BOOL_FALSE);
	if (calc_distance_to_triangle(p_a, p_b.a) != 0)
		return (BOOL_FALSE);
	if (is_point_on_triangle(p_a, p_b.a) == BOOL_TRUE ||
		is_point_on_triangle(p_a, p_b.b) == BOOL_TRUE ||
		is_point_on_triangle(p_a, p_b.c) == BOOL_TRUE)
		return (BOOL_TRUE);
	if (is_point_on_triangle(p_b, p_a.a) == BOOL_TRUE ||
		is_point_on_triangle(p_b, p_a.b) == BOOL_TRUE ||
		is_point_on_triangle(p_b, p_a.c) == BOOL_TRUE)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}
