#include "unknow_project.h"

t_faces create_t_faces()
{
	t_faces face;

	if (!(face.coords = (int *)malloc(sizeof(int) * 3 * PUSH_SIZE)))
		error_exit(-12, "Can't malloc a int array");
	face.size = 0;
	face.max_size = PUSH_SIZE;
	return (face);
}

t_faces *initialize_t_faces()
{
	t_faces *face;

	if (!(face = (t_faces *)malloc(sizeof(t_faces))))
		error_exit(-13, "Can't create a t_faces array");

	*face = create_t_faces();

	return (face);
}

void	t_faces_push_back(t_faces *dest, int *to_add)
{
	int *tmp;
	int i;
	int tmp_size;

	tmp_size = dest->size * 3;
	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->coords;
		if (!(dest->coords = (int *)malloc(sizeof(int) * 3 * (dest->size + 1 + PUSH_SIZE))))
			error_exit(-14, "Can't realloc a int array");
		i = 0;
		while (i < tmp_size)
		{
			dest->coords[i] = tmp[i];
			i++;
		}
		free(tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->coords[tmp_size + 0] = to_add[0];
	dest->coords[tmp_size + 1] = to_add[1];
	dest->coords[tmp_size + 2] = to_add[2];
	dest->size++;
}

void	free_t_faces(t_faces dest)
{
	free(dest.coords);
	dest.coords = NULL;
	dest.size = 0;
}

void	delete_t_faces(t_faces *dest)
{
	free_t_faces(*dest);
	free(dest);
}

void	clean_t_faces(t_faces *dest)
{
	dest->size = 0;
}

int		*t_faces_at(t_faces *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-22, "Segfault : t_faces out of range");
	return (&(dest->coords[index * 3]));
}

void	t_faces_resize(t_faces *dest, int new_size)
{
	int *tmp;
	int i;
	int tmp_size;

	tmp_size = dest->size * 3;
	tmp = dest->coords;
	if (!(dest->coords = (int *)malloc(sizeof(int) * 3 * (new_size))))
		error_exit(-20, "Can't realloc a int array");
	i = 0;
	while (i < tmp_size && i < new_size * 3)
	{
		dest->coords[i] = tmp[i];
		i++;
	}
	if (tmp_size != 0)
		free(tmp);
	dest->max_size = new_size;
	dest->size = i / 3;
}
