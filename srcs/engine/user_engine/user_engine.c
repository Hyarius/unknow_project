/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:09:52 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/09 15:10:49 by gboutin          ###   ########.fr       */
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

void			t_user_engine_handle_camera(t_engine *engine, t_camera *cam,
											t_window *p_win)
{
	t_mouse		*mouse;
	t_keyboard	*keyboard;

	keyboard = engine->user_engine->keyboard;
	mouse = engine->user_engine->mouse;
	get_t_mouse_info(mouse);
	handle_t_camera_view_by_mouse(cam, mouse);
	SDL_WarpMouseInWindow(p_win->window, WIN_X / 2, WIN_Y / 2);
	if (engine->playing == 1)
		handle_t_camera_mouvement_by_key(cam, keyboard, engine);
	if (engine->playing == 10)
		move_cam(cam, keyboard, engine);
	compute_t_camera(cam);
}

void			t_user_engine_handle_quit(t_user_engine *user_engine, int *play)
{
	if (get_key_state(user_engine->keyboard, SDL_SCANCODE_ESCAPE))
		*play = 0;
	if (user_engine->event.type == SDL_QUIT)
		*play = 0;
	if (user_engine->event.type == SDL_KEYDOWN
			&& user_engine->event.key.keysym.sym == SDLK_ESCAPE)
		*play = 0;
}

int				t_user_engine_poll_event(t_user_engine *engine)
{
	return (SDL_PollEvent(&(engine->event)));
}
