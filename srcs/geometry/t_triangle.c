#include "unknow_project.h"

t_triangle create_t_triangle(t_vector3 p_a, t_vector3 p_b, t_vector3 p_c)
{
	t_triangle result;

	result.a = p_a;
	result.b = p_b;
	result.c = p_c;

	return (result);
}

t_triangle	*initialize_t_triangle(t_vector3 p_a, t_vector3 p_b, t_vector3 p_c)
{
	t_triangle *result;

	if (!(result = (t_triangle *)malloc(sizeof(t_triangle))))
		error_exit(-31, "Can't malloc a t_triangle");

	*result = create_t_triangle(p_a, p_b, p_c);

	return (result);
}

void 		sort_t_triangle_points(t_triangle *p_triangle)
{
	t_vector3 tmp;

	if (p_triangle->a.y > p_triangle->b.y || (p_triangle->a.y == p_triangle->b.y && p_triangle->a.x > p_triangle->b.x))
	{
		tmp = p_triangle->a;
		p_triangle->a = p_triangle->b;
		p_triangle->b = tmp;
	}
	if (p_triangle->b.y > p_triangle->c.y || (p_triangle->b.y == p_triangle->c.y && p_triangle->b.x > p_triangle->c.x))
	{
		tmp = p_triangle->b;
		p_triangle->b = p_triangle->c;
		p_triangle->c = tmp;
	}
	if (p_triangle->a.y > p_triangle->b.y || (p_triangle->a.y == p_triangle->b.y && p_triangle->a.x > p_triangle->b.x))
	{
		tmp = p_triangle->a;
		p_triangle->a = p_triangle->b;
		p_triangle->b = tmp;
	}
}
