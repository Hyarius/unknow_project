/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:51:42 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/21 15:05:58 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	t_user_engine_handle_menu(t_camera *main_camera, t_gui *gui,
											t_engine *engine, t_window *win)
{
	if (engine->playing == 2)
		main_menu(engine, &engine->playing);
	else if (engine->playing == 3)
		settings_menu(main_camera, gui, engine, &engine->playing);
	else if (engine->playing == 4)
		controls_menu(main_camera, gui, engine, &engine->playing);
	else if (engine->playing == 5)
		credits_menu(engine, &engine->playing);
	else if (engine->playing == 6)
		play_menu(main_camera, engine, &engine->playing);
	else if (engine->playing == 11)
		set_player_editing(engine, &engine->playing);
	else if (engine->playing == 12)
		set_weapon_editing(engine, &engine->playing);
	else if (engine->playing == 13 || engine->playing == -3)
		save_pause(engine, win);
	else if (engine->playing == -1)
		pause_menu(engine, win);
	else if (engine->playing == -2)
		settings_pause_menu(engine, &engine->playing);
}

void	main_menu(t_engine *engine, int *play)
{
	t_mouse		*mou;
	t_vec2_int	pos;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (pos.x > 43 && pos.x < 56)
	{
		if (t_mouse_state(mou) == 2)
		{
			if (pos.y > 56 && pos.y < 61)
				*play = 6;
			else if (pos.y > 63 && pos.y < 68)
				*play = 3;
			else if (pos.y > 70 && pos.y < 75)
				*play = 5;
			else if (pos.y > 76 && pos.y < 82)
				*play = 0;
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		}
<<<<<<< HEAD
    }
    else
        engine->user_engine->mouse->clicked_left = BOOL_FALSE;
}

void        settings_menu(t_camera *main_camera, t_gui *gui, t_engine *engine, int *play)
{

    t_mouse *mouse = engine->user_engine->mouse;
    t_keyboard *keyboard = engine->user_engine->keyboard;
    t_vec2_int pos;

	get_t_mouse_info(mouse);
    pos = create_vec2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
    t_view_port_clear_buffers(main_camera->view_port);
    draw_rectangle_texture_cpu(main_camera->view_port, new_rectangle(create_vec2(0.7, 0.4), create_vec2(-0.6, -0.94)), gui->menu[gui->idx]);
    if (pos.x > 16 && pos.x < 29)
    {
		if (t_mouse_state(mouse) == 2)
		{
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
			if (pos.y > 23 && pos.y < 26)
			{
				if (Mix_VolumeMusic(-1) == 0)
					Mix_VolumeMusic(MIX_MAX_VOLUME);
				else if (Mix_VolumeMusic(-1) == 128)
					Mix_VolumeMusic(0);
				if (Mix_Volume(-1, -1) == 0)
					Mix_Volume(-1, MIX_MAX_VOLUME);
				else if (Mix_Volume(-1, -1) == 128)
					Mix_Volume(-1, 0);
			}
			if (pos.y > 27 && pos.y < 30)
			{
				if (Mix_VolumeMusic(-1) == 0)
					Mix_VolumeMusic(MIX_MAX_VOLUME);
				else if (Mix_VolumeMusic(-1) == 128)
					Mix_VolumeMusic(0);
			}
			if (pos.y > 32 && pos.y < 35)
			{	
				if (Mix_Volume(-1, -1) == 0)
					Mix_Volume(-1, MIX_MAX_VOLUME);
				else if (Mix_Volume(-1, -1) == 128)
					Mix_Volume(-1, 0);
			}
			t_view_port_clear_buffers(main_camera->view_port);
			if (pos.y > 44 && pos.y < 47)
			{
				draw_rectangle_texture_cpu(main_camera->view_port, new_rectangle(create_vec2(0.7, 0.4), create_vec2(-0.6, -0.94)), gui->menu[8]);
					gui->idx = 8;
			}
			if (pos.y > 48 && pos.y < 52)
			{
				draw_rectangle_texture_cpu(main_camera->view_port, new_rectangle(create_vec2(0.7, 0.4), create_vec2(-0.6, -0.94)), gui->menu[9]);
					gui->idx = 9;
			}
			if (pos.y > 53 && pos.y < 56)
			{
				draw_rectangle_texture_cpu(main_camera->view_port, new_rectangle(create_vec2(0.7, 0.4), create_vec2(-0.6, -0.94)), gui->menu[10]);
					gui->idx = 10;
			}
			if (pos.y > 72 && pos.y < 76)
				*play = 4;
		}
    }
    else if (pos.x > 43 && pos.x < 56)
    {
        if (t_mouse_state(mouse) == 2)
	    {
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
			*play = 2;
		}
    }
    else
        engine->user_engine->mouse->clicked_left = BOOL_FALSE;
=======
	}
	else
		engine->user_engine->mouse->clicked_left = BOOL_FALSE;
>>>>>>> e921707eb7a5dff71d8c4097c59b3ff39acdb8d4
}

void	credits_menu(t_engine *engine, int *play)
{
	t_mouse		*mou;
	t_vec2_int	pos;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (pos.x > 43 && pos.x < 56)
	{
		if (pos.y > 82 && pos.y < 86)
			if (t_mouse_state(mou) == 2)
			{
				Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
				*play = 2;
			}
	}
	else
		engine->user_engine->mouse->clicked_left = BOOL_FALSE;
}

void	modif_player(t_vec2_int pos, t_player *player)
{
	if (pos.y > 12 && pos.y < 21)
	{
		if (pos.x > 27 && pos.x < 46)
			player->hitbox.kinetic = 20.0;
		if (pos.x > 54 && pos.x < 72)
			player->hitbox.kinetic = 100.0;
	}
	if (pos.y > 34 && pos.y < 43)
	{
		if (pos.x > 54 && pos.x < 65)
			player->hp = 100;
		if (pos.x > 37 && pos.x < 45)
			player->hp = 50;
	}
	if (pos.y > 56 && pos.y < 65)
	{
		if (pos.x > 61 && pos.x < 71)
			player->armor = 100;
		if (pos.x > 46 && pos.x < 53)
			player->armor = 50;
		if (pos.x > 32 && pos.x < 37)
			player->armor = 0;
	}
}

void	set_player_editing(t_engine *engine, int *play)
{
	t_mouse		*mou;
	t_player	*player;
	t_vec2_int	pos;

	mou = engine->user_engine->mouse;
	player = engine->user_engine->player;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (t_mouse_state(mou) == 2)
	{
		if (ft_strcmp(player->hitbox.name, "Player") == 0)
		{
			modif_player(pos, player);
			if (pos.y > 67 && pos.y < 76 && pos.x > 30 && pos.x < 70)
				*play = 12;
			if (pos.y > 78 && pos.y < 87 && pos.x > 37 && pos.x < 62)
				*play = 13;
			if (pos.y > 90 && pos.y < 99 && pos.x > 39 && pos.x < 60)
				*play = 10;
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		}
	}
}
