/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_triangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:31:26 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/09 15:36:48 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_triangle	create_t_triangle(t_vector4 p_a, t_vector4 p_b, t_vector4 p_c)
{
	t_triangle	result;

	result.a = p_a;
	result.b = p_b;
	result.c = p_c;
	return (result);
}

t_triangle	*initialize_t_triangle(t_vector4 p_a, t_vector4 p_b, t_vector4 p_c)
{
	t_triangle	*result;

	if (!(result = (t_triangle *)malloc(sizeof(t_triangle))))
		error_exit(-31, "Can't malloc a t_triangle");
	*result = create_t_triangle(p_a, p_b, p_c);
	return (result);
}

void		sort_t_triangles(t_triangle *a, t_triangle *b)
{
	t_triangle	tmp;

	sort_t_triangle_points(a);
	sort_t_triangle_points(b);
	if (t_triangle_is_bigger(*a, *b) == BOOL_FALSE)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

void		sort_t_triangle_points(t_triangle *p_triangle)
{
	if (p_triangle->a.y > p_triangle->b.y || (p_triangle->a.y == p_triangle->b.y
										&& p_triangle->a.x > p_triangle->b.x))
		swap_t_vector4(&(p_triangle->a), &(p_triangle->b));
	if (p_triangle->b.y > p_triangle->c.y || (p_triangle->b.y == p_triangle->c.y
										&& p_triangle->b.x > p_triangle->c.x))
		swap_t_vector4(&(p_triangle->b), &(p_triangle->c));
	if (p_triangle->a.y > p_triangle->b.y || (p_triangle->a.y == p_triangle->b.y
										&& p_triangle->a.x > p_triangle->b.x))
		swap_t_vector4(&(p_triangle->a), &(p_triangle->b));
}

t_triangle	t_triangle_add_vector4(t_triangle triangle, t_vector4 to_add)
{
	t_triangle	result;

	result.a = add_vector4_to_vector4(triangle.a, to_add);
	result.b = add_vector4_to_vector4(triangle.b, to_add);
	result.c = add_vector4_to_vector4(triangle.c, to_add);
	return (result);
}

void		print_t_triangle(t_triangle p_triangle, char *triangle_name)
{
	printf("%s\n", triangle_name);
	print_t_vector4(p_triangle.a, "A : ");
	print_t_vector4(p_triangle.b, "B : ");
	print_t_vector4(p_triangle.c, "C : ");
}

t_triangle	mult_triangle_by_vector4(t_triangle triangle, t_vector4 to_add)
{
	t_triangle	result;

	result.a = mult_vector4_by_vector4(triangle.a, to_add);
	result.b = mult_vector4_by_vector4(triangle.b, to_add);
	result.c = mult_vector4_by_vector4(triangle.c, to_add);
	return (result);
}

t_triangle	compose_t_triangle_from_t_mesh(t_mesh *src, int *index)
{
	t_triangle	result;
	int			i;

	i = 0;
	while (i < 3)
	{
		if (src->vertices->size <= index[i])
			error_exit(-14, "can't compose a triangle");
		i++;
	}
	result.a = add_vector4_to_vector4(t_vector4_list_at(src->vertices,
														index[0]), src->pos);
	result.b = add_vector4_to_vector4(t_vector4_list_at(src->vertices,
														index[1]), src->pos);
	result.c = add_vector4_to_vector4(t_vector4_list_at(src->vertices,
														index[2]), src->pos);
	return (result);
}

t_triangle	compose_t_triangle_from_t_vertices(t_vector4_list *src, int *index)
{
	t_triangle	result;
	int			i;

	i = 0;
	while (i < 3)
	{
		if (src->size <= index[i])
			error_exit(-14, "can't compose a triangle");
		i++;
	}
	result.a = t_vector4_list_at(src, index[0]);
	result.b = t_vector4_list_at(src, index[1]);
	result.c = t_vector4_list_at(src, index[2]);
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

int			t_triangle_similarity(t_triangle p_a, t_triangle p_b)
{
	t_vector4	a[3];
	t_vector4	b[3];
	int			result;
	int			i;
	int			j;

	a[0] = p_a.a;
	a[1] = p_a.b;
	a[2] = p_a.c;
	b[0] = p_b.a;
	b[1] = p_b.b;
	b[2] = p_b.c;
	result = 0;
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (t_vector4_equal(a[i], b[j]) == BOOL_TRUE)
				result++;
	}
	return (result);
}

int			t_triangle_similarity_segment(t_triangle p_a, t_vector4 p_b,
																t_vector4 p_c)
{
	t_vector4	a[3];
	t_vector4	b[2];
	int			result;
	int			i;
	int			j;

	a[0] = p_a.a;
	a[1] = p_a.b;
	a[2] = p_a.c;
	b[0] = p_b;
	b[1] = p_c;
	result = 0;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 2)
		{
			if (t_vector4_equal(a[i], b[j]) == BOOL_TRUE)
				result++;
			j++;
		}
		i++;
	}
	return (result);
}

float		maximum_dist_triangles(t_triangle tri1, t_triangle tri2)
{
	float	ret;
	int		i;
	float	dists[9];

	dists[0] = size_line(create_t_line(tri1.a, tri2.a));
	dists[0] = size_line(create_t_line(tri1.a, tri2.b));
	dists[0] = size_line(create_t_line(tri1.a, tri2.c));
	dists[0] = size_line(create_t_line(tri1.b, tri2.a));
	dists[0] = size_line(create_t_line(tri1.b, tri2.b));
	dists[0] = size_line(create_t_line(tri1.b, tri2.c));
	dists[0] = size_line(create_t_line(tri1.c, tri2.a));
	dists[0] = size_line(create_t_line(tri1.c, tri2.b));
	dists[0] = size_line(create_t_line(tri1.c, tri2.c));
	i = 0;
	ret = 600;
	while (i < 9)
	{
		if (ret > dists[i])
			ret = dists[i];
		i++;
	}
	return (ret);
}

int			triangles_intersection(t_triangle tri1, t_triangle tri2)
{
	t_line		seg;
	t_vector4	intersection;

	seg = create_t_line(tri1.a, tri1.b);
	if (intersect_triangle_by_segment(tri2, seg, &intersection) > 0)
		return (BOOL_TRUE);
	seg = create_t_line(tri1.b, tri1.c);
	if (intersect_triangle_by_segment(tri2, seg, &intersection) > 0)
		return (BOOL_TRUE);
	seg = create_t_line(tri1.a, tri1.c);
	if (intersect_triangle_by_segment(tri2, seg, &intersection) > 0)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}
