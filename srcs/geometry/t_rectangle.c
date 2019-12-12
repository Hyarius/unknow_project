/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rectangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:16:08 by gboutin           #+#    #+#             */
/*   Updated: 2019/12/12 16:16:09 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_rectangle	create_t_rectangle(t_vector2 p_pos, t_vector2 p_size)
{
	t_rectangle	result;

	result.pos = p_pos;
	result.size = p_size;
	return (result);
}

t_rectangle	*initialize_t_rectangle(t_vector2 p_pos, t_vector2 p_size)
{
	t_rectangle	*result;

	if (!(result = (t_rectangle *)malloc(sizeof(t_rectangle))))
		error_exit(-31, "Can't malloc a t_rectangle");
	*result = create_t_rectangle(p_pos, p_size);
	return (result);
}
