/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rectangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:16:08 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/15 16:05:05 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_rectangle	create_t_rectangle(t_vec2 p_pos, t_vec2 p_size)
{
	t_rectangle	result;

	result.pos = p_pos;
	result.size = p_size;
	return (result);
}

t_rectangle	*initialize_t_rectangle(t_vec2 p_pos, t_vec2 p_size)
{
	t_rectangle	*result;

	if (!(result = (t_rectangle *)malloc(sizeof(t_rectangle))))
		error_exit(-31, "Can't malloc a t_rectangle");
	*result = create_t_rectangle(p_pos, p_size);
	return (result);
}
