/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:44:08 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/17 11:44:32 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void		t_engine_handle_camera(t_engine *p_engine, t_window *p_win)
{
	t_user_engine_handle_camera(p_engine,
			t_visual_engine_get_main_camera(p_engine->visual_engine), p_win);
}

void		t_engine_handle_event(t_camera *main_camera, t_gui *gui,
											t_engine *engine, t_window *win)
{
	static float	size = 0.45;
	t_mesh			*mesh;
	int				i;

	if (engine->playing == 1
		&& get_key_state(engine->user_engine->keyboard, SDL_SCANCODE_P) == 1)
		engine->playing = -1;
	else if (engine->playing <= -1
		&& get_key_state(engine->user_engine->keyboard, SDL_SCANCODE_P) == 1)
		engine->playing = 1;
	t_user_engine_handle_menu(main_camera, gui, engine, win);
	if (t_user_engine_poll_event(engine->user_engine) > 0)
		t_user_engine_handle_quit(engine->user_engine, &(engine->playing));
}
