#include "unknow_project.h"

t_vector2 create_t_vector2(float p_x, float p_y)
{
	t_vector2 result;

	result.x = p_x;
	result.y = p_y;

	return (result);
}

t_vector2	*initialize_t_vector2(float p_x, float p_y)
{
	t_vector2 *result;

	if (!(result = (t_vector2 *)malloc(sizeof(t_vector2))))
		return (NULL);

	*result = create_t_vector2(p_x, p_y);

	return (result);
}

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
