/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_list2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:01:09 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 11:06:09 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void			free_t_vector4_list(t_vector4_list *dest)
{
	delete_t_vector4_list(*dest);
	free(dest);
}

void			clean_t_vector4_list(t_vector4_list *dest)
{
	dest->size = 0;
}

t_vector4		t_vector4_list_at(t_vector4_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vector4_list out of range");
	return (dest->vector[index]);
}

t_vector4		*t_vector4_list_get(t_vector4_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vector4_list out of range");
	return (&dest->vector[index]);
}

float			*t_vector4_list_obtain(t_vector4_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vector4_list out of range");
	return (&dest->value[index * 3]);
}
