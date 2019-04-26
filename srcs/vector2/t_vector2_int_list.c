#include "unknow_project.h"

t_vector2_int_list create_t_vector2_int_list()
{
	t_vector2_int_list list;

	if (!(list.vector = (t_vector2_int *)malloc(sizeof(t_vector2_int) * PUSH_SIZE)))
		error_exit(-9, "Can't malloc a t_vector2_int array");
	list.size = 0;
	return (list);
}

t_vector2_int_list *initialize_t_vector2_int_list()
{
	t_vector2_int_list *list;

	if (!(list = (t_vector2_int_list *)malloc(sizeof(t_vector2_int_list))))
		error_exit(-10, "Can't create a t_vector2_int_list array");

	*list = create_t_vector2_int_list();

	return (list);
}

void	t_vector2_int_list_push_back(t_vector2_int_list *dest, t_vector2_int to_add)
{
	t_vector2_int *tmp;
	int i;

	if ((dest->size + 1) % PUSH_SIZE == 0)
	{
		tmp = dest->vector;
		if (!(dest->vector = (t_vector2_int *)malloc(sizeof(t_vector2_int) * (dest->size + 1 + PUSH_SIZE))))
			error_exit(-11, "Can't realloc a t_vector2_int array");
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

void	free_t_vector2_int_list(t_vector2_int_list dest)
{
	free(dest.vector);
	dest.vector = NULL;
	dest.size = 0;
}

void	delete_t_vector2_int_list(t_vector2_int_list *dest)
{
	free_t_vector2_int_list(*dest);
	free(dest);
}

void	clean_t_vector2_int_list(t_vector2_int_list *dest)
{
	free(dest->vector);
	dest->size = 0;
	if (!(dest->vector = (t_vector2_int *)malloc(sizeof(t_vector2_int) * PUSH_SIZE)))
		error_exit(-9, "Can't malloc a t_vector2_int array");
}

t_vector2_int	t_vector2_int_list_at(t_vector2_int_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-21, "Segfault : t_vector2_int_list out of range");
	return (dest->vector[index]);
}

t_vector2_int	*t_vector2_int_list_get(t_vector2_int_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-21, "Segfault : t_vector2_int_list out of range");
	return (&dest->vector[index]);
}

int				*t_vector2_int_list_obtain(t_vector2_int_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-23, "Segfault : t_vector3_int_list out of range");
	return (&dest->value[index * 2]);
}
