/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:01:07 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/20 11:21:46 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_engine	new_engine(t_window *p_window)
{
	t_engine	result;

	result.playing = 2;
	result.tick = 0;
	result.visual_engine = initialize_t_visual_engine(p_window);
	result.physic_engine = initialize_t_physic_engine();
	result.user_engine = initialize_t_user_engine();
	result.sound_engine = initialize_t_sound_engine();
	return (result);
}

t_engine	*initialize_t_engine(t_window *p_window)
{
	t_engine	*result;

	if (!(result = (t_engine *)malloc(sizeof(t_engine))))
		return (NULL);
	*result = new_engine(p_window);
	return (result);
}

void		delete_t_engine(t_engine dest)
{
	free_t_physic_engine(dest.physic_engine);
	free_t_user_engine(dest.user_engine);
	free_t_visual_engine(dest.visual_engine);
	free_t_sound_engine(dest.sound_engine);
}

void		free_t_engine(t_engine *dest)
{
	delete_t_engine(*dest);
	free(dest);
}

void		t_engine_apply_physic(t_engine *engine)
{
	t_physic_engine_compute_vertices_in_world(engine->physic_engine);
	t_physic_engine_apply_force(engine);
}
