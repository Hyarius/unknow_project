#include "unknow_project.h"

t_vector3 create_t_vector3(float p_x, float p_y, float p_z)
{
	t_vector3 result;

	result.x = p_x;
	result.y = p_y;
	result.z = p_z;

	return (result);
}

t_vector3	*initialize_t_vector3(float p_x, float p_y, float p_z)
{
	t_vector3 *result;

	if (!(result = (t_vector3 *)malloc(sizeof(t_vector3))))
		return (NULL);

	*result = create_t_vector3(p_x, p_y, p_z);

	return (result);
}

void t_vector3_swap(t_vector3 *a, t_vector3 *b)
{
	t_vector3 tmp;

	tmp.x = a->x;
	tmp.y = a->y;
	tmp.z = a->z;
	a->x = b->x;
	a->y = b->y;
	a->z = b->z;
	b->x = tmp.x;
	b->y = tmp.y;
	b->z = tmp.z;
}

void set_t_vector3(t_vector3 *src, float p_x, float p_y, float p_z)
{
	src->x = p_x;
	src->y = p_y;
	src->z = p_z;
}

void print_t_vector3(t_vector3 vector, char *str)
{
	printf("%s = %0.4f / %0.4f / %0.4f\n", str, vector.x, vector.y, vector.z);
}
