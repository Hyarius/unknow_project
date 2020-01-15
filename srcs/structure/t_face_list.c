/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_face_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:50:25 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 15:03:23 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_face_list	create_t_face_list(void)
{
	t_face_list	list;

	if (!(list.face = (t_face *)malloc(sizeof(t_face) * PUSH_SIZE)))
		error_exit(-25, "Can't malloc a t_face array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_face_list	*initialize_t_face_list(void)
{
	t_face_list	*list;

	if (!(list = (t_face_list *)malloc(sizeof(t_face_list))))
		error_exit(-26, "Can't create a t_face_list array");
	*list = create_t_face_list();
	return (list);
}

void		t_face_list_push_back(t_face_list *dest, t_face to_add)
{
	t_face	*tmp;
	int		i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->face;
		if (!(dest->face = (t_face *)malloc(sizeof(t_face) \
							* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-27, "Can't realloc a t_face array");
		i = -1;
		while (++i < dest->size)
			dest->face[i] = tmp[i];
		free(tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->face[dest->size] = to_add;
	dest->size++;
}

t_face		t_face_list_at(t_face_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-28, "Segfault : t_face_list out of range");
	return (dest->face[index]);
}

t_face		*t_face_list_get(t_face_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-28, "Segfault : t_face_list out of range");
	return (&dest->face[index]);
}
