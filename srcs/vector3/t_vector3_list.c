#include "unknow_project.h"

t_vector3_list create_t_vector3_list()
{
	t_vector3_list list;

	if (!(list.vector = (t_vector3 *)malloc(sizeof(t_vector3) * PUSH_SIZE)))
		error_exit(-18, "Can't malloc a t_vector3 array");
	list.size = 0;
	return (list);
}

t_vector3_list *initialize_t_vector3_list()
{
	t_vector3_list *list;

	if (!(list = (t_vector3_list *)malloc(sizeof(t_vector3_list))))
		error_exit(-19, "Can't create a t_vector3_list array");

	*list = create_t_vector3_list();

	return (list);
}

void	t_vector3_list_push_back(t_vector3_list *dest, t_vector3 to_add)
{
	t_vector3 *tmp;
	int i;

	if ((dest->size + 1) % PUSH_SIZE == 0)
	{
		tmp = dest->vector;
		if (!(dest->vector = (t_vector3 *)malloc(sizeof(t_vector3) * (dest->size + 1 + PUSH_SIZE))))
			error_exit(-20, "Can't realloc a t_vector3 array");
		i = 0;
		while (i < dest->size)
		{
			dest->vector[i] = tmp[i];
			i++;
		}
		free(tmp);
	}
	dest->vector[dest->size] = to_add;
	dest->size++;
}

void	free_t_vector3_list(t_vector3_list dest)
{
	free(dest.vector);
	dest.vector = NULL;
	dest.size = 0;
}

void	delete_t_vector3_list(t_vector3_list *dest)
{
	free_t_vector3_list(*dest);
	free(dest);
}

void	clean_t_vector3_list(t_vector3_list *dest)
{
	free(dest->vector);
	dest->size = 0;
	if (!(dest->vector = (t_vector3 *)malloc(sizeof(t_vector3) * PUSH_SIZE)))
		error_exit(-18, "Can't malloc a t_vector3 array");
}

t_vector3	t_vector3_list_at(t_vector3_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vector3_list out of range");
	return (dest->vector[index]);
}

t_vector3	*t_vector3_list_get(t_vector3_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vector3_list out of range");
	return (&dest->vector[index]);
}

float			*t_vector3_list_obtain(t_vector3_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-23, "Segfault : t_vector3_int_list out of range");
	return (&dest->value[index * 3]);
}
