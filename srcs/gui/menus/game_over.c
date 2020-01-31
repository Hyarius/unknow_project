/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:57:13 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/31 14:11:09 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	game_over(t_engine *engine)
{
	t_mouse			*mou;
	t_vec2_int		pos;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (t_mouse_state(mou) == 2)
	{
		if ((pos.x > 38 && pos.x < 61) && (pos.y > 86 && pos.y < 92))
		{
			engine->playing = 1;
			engine->menu_nbr = 0;
			close_map(engine);
		}
	}
}

void	end_screen(t_engine *engine)
{
	t_mouse			*mou;
	t_vec2_int		pos;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (t_mouse_state(mou) == 2)
	{
		if ((pos.x > 85 && pos.x < 96) && (pos.y > 83 && pos.y < 96))
		{
			engine->playing = 1;
			engine->menu_nbr = 0;
			close_map(engine);
		}
	}
}

void	t_user_engine_handle_menu_next(t_engine *engine)
{
	if (engine->menu_nbr == 18)
		game_over(engine);
	else if (engine->menu_nbr == 19)
		end_screen(engine);
}
