/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_door.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:29:31 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/20 11:21:46 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_door		new_door(void)
{
	t_door	result;

	result.tick = 0;
	result.state = 0;
	result.move = 0;
	return (result);
}

t_door		*initialize_t_door(void)
{
	t_door	*result;

	if (!(result = (t_door *)malloc(sizeof(t_door))))
		return (NULL);
	*result = new_door();
	return (result);
}
