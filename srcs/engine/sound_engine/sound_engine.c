/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:11:38 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/15 15:41:56 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_sound_engine	create_t_sound_engine(void)
{
	t_sound_engine	result;

	result.music = load_music();
	result.sounds = load_sounds();
	return (result);
}

t_sound_engine	*initialize_t_sound_engine(void)
{
	t_sound_engine	*result;

	if (!(result = (t_sound_engine	*)malloc(sizeof(t_sound_engine))))
		return (NULL);
	*result = create_t_sound_engine();
	return (result);
}

void			delete_t_sound_engine(t_sound_engine dest)
{
	free(dest.music);
	free(dest.sounds);
}

void			free_t_sound_engine(t_sound_engine *dest)
{
	delete_t_sound_engine(*dest);
	free(dest);
}
