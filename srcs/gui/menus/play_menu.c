/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:12:31 by adjouber          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/29 13:25:19 by spuisais         ###   ########.fr       */
=======
/*   Updated: 2020/01/30 11:59:14 by jubeal           ###   ########.fr       */
>>>>>>> 7de4b513cbd9a3dcd2e8529f13fabd1c72c093f2
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	synopsis_menu(t_engine *engine)
{
	t_mouse			*mou;
	t_vec2_int		pos;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (t_mouse_state(mou) == 2)
		if ((pos.x > 85 && pos.x < 96) && (pos.y > 83 && pos.y < 96))
<<<<<<< HEAD
			*play = 1;
=======
			engine->playing = 2;
>>>>>>> 7de4b513cbd9a3dcd2e8529f13fabd1c72c093f2
}

void	open_scenario_or_editor(t_vec2_int pos, t_engine *engine, char **path)
{
	if (pos.x > 37 && pos.x < 61)
	{
		if (pos.y > 61 && pos.y < 69)
		{
			engine->playing = 4;
			*path = ft_strdup("ressources/map/save4.map");
		}
		if (pos.y > 71 && pos.y < 79)
			engine->menu_nbr = 0;
	}
	if (pos.x > 6 && pos.x < 24)
	{
		if (pos.y > 29 && pos.y < 37)
		{
			engine->menu_nbr = 17;
			*path = ft_strdup("ressources/map/save1.map");
		}
		if (pos.y > 39 && pos.y < 47)
		{
			engine->playing = 2;
			*path = ft_strdup("ressources/map/fichier_map2.map");
		}
	}
}

void	open_save2(t_vec2_int pos, int *play, char **path)
{
	if (pos.y > 59 && pos.y < 67)
	{
		*play = 2;
		*path = ft_strdup("ressources/map/save4.map");
	}
	if (pos.y > 69 && pos.y < 77)
	{
		*play = 2;
		*path = ft_strdup("ressources/map/save5.map");
	}
}

void	open_save(t_vec2_int pos, int *play, char **path)
{
	if (pos.x > 82 && pos.x < 95)
	{
		if (pos.y > 29 && pos.y < 37)
		{
			*play = 2;
			*path = ft_strdup("ressources/map/save1.map");
		}
		if (pos.y > 39 && pos.y < 47)
		{
			*play = 2;
			*path = ft_strdup("ressources/map/save2.map");
		}
		if (pos.y > 49 && pos.y < 57)
		{
			*play = 2;
			*path = ft_strdup("ressources/map/save3.map");
		}
		open_save2(pos, play, path);
	}
}

void	play_menu(t_camera *main_camera, t_engine *engine, int *play)
{
	t_mouse			*mou;
	t_vec2_int		pos;
	char			*path;

	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (t_mouse_state(mou) == 2)
	{
		open_scenario_or_editor(pos, engine, &path);
		open_save(pos, play, &path);
		Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
	}
	if (*play == 4 || *play == 2 || engine->menu_nbr == 17)
	{
		load_map(main_camera, engine, path);
		link_camera_to_mesh(engine, 0, t_engine_get_mesh(engine, 0));
		free(path);
	}
}
