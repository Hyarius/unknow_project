/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:09:52 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/29 11:48:45 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_user_engine	new_user_engine(void)
{
	t_user_engine	result;

	result.mouse = initialize_t_mouse();
	result.keyboard = initialize_t_keyboard();
	result.player = NULL;
	return (result);
}

t_user_engine	*initialize_t_user_engine(void)
{
	t_user_engine	*result;

	if (!(result = (t_user_engine *)malloc(sizeof(t_user_engine))))
		return (NULL);
	*result = new_user_engine();
	return (result);
}

void			delete_t_user_engine(t_user_engine dest)
{
	free(dest.mouse);
	free(dest.keyboard);
}

void			free_t_user_engine(t_user_engine *dest)
{
	delete_t_user_engine(*dest);
	free(dest);
}
