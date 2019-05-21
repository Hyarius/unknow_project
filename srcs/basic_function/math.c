#include "unknow_project.h"

t_vector3		cross_vector3(t_vector3 *a, t_vector3 *b)
{
	t_vector3 result;

	result = create_t_vector3(a->y * b->z - a->z * b->y,
								a->z * b->x - a->x * b->z,
								a->x * b->y - a->y * b->x);

	return (result);
}
