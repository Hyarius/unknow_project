/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:01:12 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 11:05:43 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_vector4_list	create_t_vector4_list(void)
{
	t_vector4_list list;

	if (!(list.vector = (t_vector4 *)malloc(sizeof(t_vector4) * PUSH_SIZE)))
		error_exit(-18, "Can't malloc a t_vector4 array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_vector4_list	*initialize_t_vector4_list(void)
{
	t_vector4_list *list;

	if (!(list = (t_vector4_list *)malloc(sizeof(t_vector4_list))))
		error_exit(-19, "Can't create a t_vector4_list array");
	*list = create_t_vector4_list();
	return (list);
}

void			t_vector4_list_push_back(t_vector4_list *dest, t_vector4 to_add)
{
	t_vector4	*tmp;
	int			i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->vector;
		if (!(dest->vector = (t_vector4 *)malloc(sizeof(t_vector4)
				* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-20, "Can't realloc a t_vector4 array");
		i = 0;
		while (i < dest->size)
		{
			dest->vector[i] = tmp[i];
			i++;
		}
		free(tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->vector[dest->size] = to_add;
	(dest->size)++;
}

void			t_vector4_list_add_back(t_vector4_list *dest, t_vector4 *to_add)
{
	t_vector4	*tmp;
	int			i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->vector;
		if (!(dest->vector = (t_vector4 *)malloc(sizeof(t_vector4)
			* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-20, "Can't realloc a t_vector4 array");
		i = 0;
		while (i < dest->size)
		{
			dest->vector[i] = tmp[i];
			i++;
		}
		free(tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->vector[dest->size].x = to_add->x;
	dest->vector[dest->size].y = to_add->y;
	dest->vector[dest->size].z = to_add->z;
	dest->vector[dest->size].w = to_add->w;
	(dest->size)++;
}
