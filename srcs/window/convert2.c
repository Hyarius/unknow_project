/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:58:50 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 11:27:24 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

float			degree_to_radius(float angle)
{
	return ((float)(((float)angle) * M_PI / (float)180));
}

float			radius_to_degree(float radian)
{
	return ((float)((float)(radian * 180) / M_PI));
}

t_uv			convert_t_uv_to_texture(t_uv *source)
{
	t_uv		result;

	result = *source;
	result.uv.a.y = 1 - result.uv.a.y;
	result.uv.b.y = 1 - result.uv.b.y;
	result.uv.c.y = 1 - result.uv.c.y;
	return (result);
}
