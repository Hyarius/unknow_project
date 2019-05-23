#include "unknow_project.h"

t_face create_t_face(int a, int b, int c)
{
	t_face result;

	result.index[0] = a;
	result.index[1] = b;
	result.index[2] = c;
	result.normale = create_t_vector3(0, 0, 0);

	return (result);
}

t_face *initialize_t_face(int a, int b, int c)
{
	t_face *result;

	if (!(result = (t_face *)malloc(sizeof(t_face))))
		error_exit(-13, "Can't create a t_face");

	*result = create_t_face(a, b, c);

	return (result);
}
