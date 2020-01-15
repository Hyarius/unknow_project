/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector2_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:48:20 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 12:19:24 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_vector2_int	create_t_vector2_int(int p_x, int p_y)
{
	t_vector2_int	result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}
