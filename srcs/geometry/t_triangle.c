/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_triangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:31:26 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/17 11:31:05 by gboutin          ###   ########.fr       */
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

void		print_t_triangle(t_triangle p_triangle, char *triangle_name) // a supprimer
{
	printf("%s\n", triangle_name);
	print_t_vector4(p_triangle.a, "A : ");
	print_t_vector4(p_triangle.b, "B : ");
	print_t_vector4(p_triangle.c, "C : ");
}
