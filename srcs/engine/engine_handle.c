/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:44:08 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/06 14:08:42 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		t_engine_handle_camera(t_engine *p_engine, t_window *p_win)
{
	t_user_engine_handle_camera(p_engine,
			t_visual_engine_get_main_camera(p_engine->visual_engine), p_win);
}

void		t_engine_handle_event(t_camera *main_camera, t_gui *gui,
														t_engine *engine)
{
	if (engine->playing == 2
		&& get_key_state(engine->user_engine->keyboard, SDL_SCANCODE_P) == 1)
	{
		engine->playing = 3;
		engine->menu_nbr = 4;
	}
	else if (engine->playing == 3
		&& get_key_state(engine->user_engine->keyboard, SDL_SCANCODE_P) == 1)
		engine->playing = 2;
	if (engine->playing != 2 && engine->playing != 4)
		t_user_engine_handle_menu(main_camera, gui, engine);
	else
		SDL_ShowCursor(SDL_DISABLE);
	if (t_user_engine_poll_event(engine->user_engine) > 0)
		t_user_engine_handle_quit(engine->user_engine, &(engine->playing));
}
