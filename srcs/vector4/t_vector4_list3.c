/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_list3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:01:06 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 11:09:16 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void			delete_t_vector4_list(t_vector4_list dest)
{
	free(dest.vector);
	dest.vector = NULL;
	dest.size = 0;
}

void			t_vector4_list_resize(t_vector4_list *dest, int new_size)
{
	t_vector4	*tmp;
	int			i;
	int			old_size;

	old_size = dest->size;
	tmp = dest->vector;
	if (!(dest->vector = (t_vector4 *)malloc(sizeof(t_vector4) * (new_size))))
		error_exit(-20, "Can't realloc a t_vector4 array");
	i = 0;
	while (i < dest->size && i < new_size && i < old_size)
	{
		dest->vector[i] = tmp[i];
		i++;
	}
	if (old_size != 0)
		free(tmp);
	dest->max_size = new_size;
	dest->size = i;
}

void			t_vector4_list_edit(t_vector4_list *dest, int index,
										t_vector4 p_vector)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vector4_list out of range");
	dest->vector[index] = p_vector;
}

void			t_vector4_list_set(t_vector4_list *dest, int index,
										t_vector4 *p_vector)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vector4_list out of range");
	dest->vector[index] = *p_vector;
}
