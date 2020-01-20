/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_list2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:01:09 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/20 10:39:37 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void			free_t_vec4_list(t_vec4_list *dest)
{
	delete_t_vec4_list(*dest);
	free(dest);
}

void			clean_t_vec4_list(t_vec4_list *dest)
{
	dest->size = 0;
}

t_vec4		t_vec4_list_at(t_vec4_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vec4_list out of range");
	return (dest->vector[index]);
}

t_vec4		*t_vec4_list_get(t_vec4_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vec4_list out of range");
	return (&dest->vector[index]);
}

float			*t_vec4_list_obtain(t_vec4_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vec4_list out of range");
	return (&dest->value[index * 3]);
}
