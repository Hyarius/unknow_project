/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:48:24 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 16:04:30 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_vec2	create_vec2(float p_x, float p_y)
{
	t_vec2	result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}

t_vec2	add_vector2_to_vector2(t_vec2 v1, t_vec2 v2)
{
	t_vec2	result;

	result = create_vec2(v1.x + v2.x, v1.y + v2.y);
	return (result);
}
