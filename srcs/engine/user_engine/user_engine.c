/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:09:52 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/17 11:36:06 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_user_engine	create_t_user_engine(void)
{
	t_user_engine	result;

	result.mouse = initialize_t_mouse();
	result.keyboard = initialize_t_keyboard();
	return (result);
}

t_user_engine	*initialize_t_user_engine(void)
{
	t_user_engine	*result;

	if (!(result = (t_user_engine *)malloc(sizeof(t_user_engine))))
		return (NULL);
	*result = create_t_user_engine();
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
