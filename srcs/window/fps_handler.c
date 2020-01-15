/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:00:18 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 11:26:56 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		check_frame(t_engine *engine)
{
	static int		nb_frame = 0;
	static int		beginsecond = 0;
	int				frame_actual;
	static Uint32	framestart;

	frame_actual = SDL_GetTicks();
	if (beginsecond == 0)
		beginsecond = frame_actual;
	if (frame_actual - beginsecond > 1000)
	{
		engine->tick++;
		printf("nb_frame = %d\n", nb_frame);
		nb_frame = 0;
		beginsecond = 0;
	}
	else
		nb_frame++;
	framestart = SDL_GetTicks();
}
