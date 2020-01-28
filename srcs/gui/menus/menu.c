/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:51:42 by gboutin           #+#    #+#             */
<<<<<<< HEAD:srcs/gui/menu_pause/menu.c
/*   Updated: 2020/01/27 10:00:29 by spuisais         ###   ########.fr       */
=======
/*   Updated: 2020/01/27 14:02:42 by gboutin          ###   ########.fr       */
>>>>>>> e3e816daa40f85036bb8de54e56662bbeac2b09e:srcs/gui/menus/menu.c
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	t_user_engine_handle_menu(t_camera *main_camera, t_gui *gui,
											t_engine *engine)
{
	if (engine->playing == 2)
		main_menu(engine, &engine->playing);
	else if (engine->playing == 3)
		settings_menu(main_camera, gui, engine);
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
		save_pause(engine);
	else if (engine->playing == -1)
		pause_menu(engine);
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
	}
	else
		engine->user_engine->mouse->clicked_left = BOOL_FALSE;
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
