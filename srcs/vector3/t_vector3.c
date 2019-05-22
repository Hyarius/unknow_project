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

void print_t_vector3(t_vector3 vector, char *str)
{
	printf("%s%0.4f / %0.4f / %0.4f", str, vector.x, vector.y, vector.z);
}

t_vector3	add_vector3_to_vector3(t_vector3 a,t_vector3 b)
{
	t_vector3	result;

	result = create_t_vector3(a.x + b.x, a.y + b.y, a.z + b.z);

	return (result);
}

t_vector3	substract_vector3_to_vector3(t_vector3 a,t_vector3 b)
{
	t_vector3	result;

	result = create_t_vector3(a.x - b.x, a.y - b.y, a.z - b.z);

	return (result);
}

t_vector3	mult_vector3_to_vector3(t_vector3 a,t_vector3 b)
{
	t_vector3	result;

	result = create_t_vector3(a.x * b.x, a.y * b.y, a.z * b.z);

	return (result);
}

t_vector3	divide_vector3_to_vector3(t_vector3 a,t_vector3 b)
{
	t_vector3	result;

	result = create_t_vector3(a.x / b.x, a.y / b.y, a.z / b.z);

	return (result);
}