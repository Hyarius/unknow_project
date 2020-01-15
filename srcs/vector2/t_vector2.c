/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:48:24 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 12:13:19 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_vector2	create_t_vector2(float p_x, float p_y)
{
	t_vector2	result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}

t_vector2	add_vector2_to_vector2(t_vector2 v1, t_vector2 v2)
{
	t_vector2	result;

	result = create_t_vector2(v1.x + v2.x, v1.y + v2.y);
	return (result);
}
