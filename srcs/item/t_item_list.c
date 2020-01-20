/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_item_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:32:28 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/20 13:04:04 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_item_list		new_item_list(void)
{
	t_item_list	list;

	if (!(list.item = (t_item *)malloc(sizeof(t_item) * PUSH_SIZE)))
		error_exit(-18, "Can't malloc a t_item array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_item_list		*initialize_t_item_list(void)
{
	t_item_list *list;

	if (!(list = (t_item_list *)malloc(sizeof(t_item_list))))
		error_exit(-19, "Can't create a t_item_list array");
	*list = new_item_list();
	return (list);
}

void			t_item_list_push_back(t_item_list *dest, t_item to_add)
{
	t_item	*tmp;
	int		i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->item;
		if (!(dest->item = (t_item *)malloc(sizeof(t_item)
		* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-20, "Can't realloc a t_item array");
		i = 0;
		while (i < dest->size)
		{
			dest->item[i] = tmp[i];
			i++;
		}
		free(tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->item[dest->size] = to_add;
	(dest->size)++;
}

t_item			t_item_list_at(t_item_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_item_list out of range");
	return (dest->item[index]);
}

t_item			*t_item_list_get(t_item_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_item_list out of range");
	return (&(dest->item[index]));
}
