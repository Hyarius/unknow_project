/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:11:38 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/06 15:45:46 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_sound_engine	new_sound_engine(void)
{
	t_sound_engine	result;

	result.music = load_music();
	result.sounds = load_sounds();
	return (result);
}

t_sound_engine	*initialize_t_sound_engine(void)
{
	t_sound_engine	*result;

	if (!(result = (t_sound_engine	*)ft_memalloc(sizeof(t_sound_engine))))
		return (NULL);
	*result = new_sound_engine();
	return (result);
}

void			free_t_sound_engine(t_sound_engine **dest)
{
	int	i;

	i = 0;
	Mix_FreeMusic((*dest)->music[0]);
	(*dest)->music[0] = NULL;
	while (i < 28)
	{
		Mix_FreeChunk((*dest)->sounds[i]);
		(*dest)->sounds[i] = NULL;
		i++;
	}
	ft_memdel((void**)&(*dest)->sounds);
	ft_memdel((void**)&(*dest)->music);
	ft_memdel((void**)dest);
}
