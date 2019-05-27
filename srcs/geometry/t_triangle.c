#include "unknow_project.h"

t_triangle create_t_triangle(t_vector2 p_a, t_vector2 p_b, t_vector2 p_c)
{
	t_triangle result;

	result.a = p_a;
	result.b = p_b;
	result.c = p_c;

	return (result);
}

t_triangle	*initialize_t_triangle(t_vector2 p_a, t_vector2 p_b, t_vector2 p_c)
{
	t_triangle *result;

	if (!(result = (t_triangle *)malloc(sizeof(t_triangle))))
		error_exit(-31, "Can't malloc a t_triangle");

	*result = create_t_triangle(p_a, p_b, p_c);

	return (result);
}

t_3d_triangle create_t_3d_triangle(t_vector3 p_a, t_vector3 p_b, t_vector3 p_c)
{
	t_3d_triangle result;

	result.a = p_a;
	result.b = p_b;
	result.c = p_c;

	return (result);
}

t_3d_triangle	*initialize_t_3d_triangle(t_vector3 p_a, t_vector3 p_b, t_vector3 p_c)
{
	t_3d_triangle *result;

	if (!(result = (t_3d_triangle *)malloc(sizeof(t_3d_triangle))))
		error_exit(-31, "Can't malloc a t_3d_triangle");

	*result = create_t_3d_triangle(p_a, p_b, p_c);

	return (result);
}
