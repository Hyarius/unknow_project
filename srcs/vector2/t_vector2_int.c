/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector2_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:48:20 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/20 09:30:31 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_vec2_int	create_vec2_int(int p_x, int p_y)
{
	t_vec2_int	result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}
