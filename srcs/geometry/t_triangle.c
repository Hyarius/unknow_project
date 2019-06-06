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
	if (p_triangle->a.y > p_triangle->b.y || (p_triangle->a.y == p_triangle->b.y && p_triangle->a.x > p_triangle->b.x))
	{
		swap_t_vector3(&(p_triangle->a), &(p_triangle->b));
	}
	if (p_triangle->b.y > p_triangle->c.y || (p_triangle->b.y == p_triangle->c.y && p_triangle->b.x > p_triangle->c.x))
	{
		swap_t_vector3(&(p_triangle->b), &(p_triangle->c));
	}
	if (p_triangle->a.y > p_triangle->b.y || (p_triangle->a.y == p_triangle->b.y && p_triangle->a.x > p_triangle->b.x))
	{
		swap_t_vector3(&(p_triangle->a), &(p_triangle->b));
	}
}

void		print_t_triangle(t_triangle p_triangle, char *triangle_name)
{
	printf("Triangle Name : %s\n", triangle_name);
	print_t_vector3(p_triangle.a, "A : ");endl();
	print_t_vector3(p_triangle.b, "B : ");endl();
	print_t_vector3(p_triangle.c, "C : ");endl();
}