/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:12:31 by adjouber          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/29 10:15:47 by spuisais         ###   ########.fr       */
=======
/*   Updated: 2020/01/28 12:59:48 by gboutin          ###   ########.fr       */
>>>>>>> 54b23eab35bf6d72a34aad2de392d71fd2a0af89
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	synopsis_menu(t_engine *engine, int *play)
{
<<<<<<< HEAD
	t_mouse			*mou;
	t_vec2_int		pos;
	
	printf("play = %d\n", *play);
	mou = engine->user_engine->mouse;
	get_t_mouse_info(mou);
	pos = create_vec2_int(mou->pos.x * 100 / WIN_X, mou->pos.y * 100 / WIN_Y);
	if (t_mouse_state(mou) == 2)
		if (pos.x > 85 && pos.x < 96)
			if (pos.y > 83 && pos.y < 96)
				*play = 1;
}

void	open_scenario_or_editor(t_vec2_int pos, int *play, char **path)
=======
	static int			tmp = 0;
	static t_texture	*img = NULL;

	if (img == NULL)
		img = png_load("ressources/assets/imgs/synopsis.png");
	if (tmp == 0)
		tmp = engine->tick;
	t_view_port_clear_buffers(camera->view_port);
	draw_rectangle_texture_cpu(camera->view_port, new_rectangle(
					create_vec2(-1.0, -1.0), create_vec2(2.0, 2.0)),
					img);
	if (engine->tick - tmp == 100)
	{
		t_view_port_clear_buffers(camera->view_port);
		return ;
	}
}

void	open_scenario_or_editor(t_vec2_int pos, int *play, char **path,
										t_engine *engine, t_camera *camera)
>>>>>>> 54b23eab35bf6d72a34aad2de392d71fd2a0af89
{
	if (pos.x > 37 && pos.x < 61)
	{
		if (pos.y > 61 && pos.y < 69)
		{
			*play = 10;
			*path = ft_strdup("ressources/map/save4.map");
		}
		if (pos.y > 71 && pos.y < 79)
			*play = 2;
	}
	if (pos.x > 6 && pos.x < 24)
	{
		if (pos.y > 29 && pos.y < 37)
		{
			*play = 15;
			*path = ft_strdup("ressources/map/save1.map");
			printf("path = %s\n", *path);
		}	
		if (pos.y > 39 && pos.y < 47)
		{
			*play = 1;
			*path = ft_strdup("ressources/map/fichier_map2.map");
		}
	}
}

void	open_save2(t_vec2_int pos, int *play, char **path)
{
	if (pos.y > 59 && pos.y < 67)
	{
		*play = 1;
		*path = ft_strdup("ressources/map/save4.map");
	}
	if (pos.y > 69 && pos.y < 77)
	{
		*play = 1;
		*path = ft_strdup("ressources/map/save5.map");
	}
}

void	open_save(t_vec2_int pos, int *play, char **path)
{
	if (pos.x > 82 && pos.x < 95)
	{
		if (pos.y > 29 && pos.y < 37)
		{
			*play = 1;
			*path = ft_strdup("ressources/map/save1.map");
		}
		if (pos.y > 39 && pos.y < 47)
		{
			*play = 1;
			*path = ft_strdup("ressources/map/save2.map");
		}
		if (pos.y > 49 && pos.y < 57)
		{
			*play = 1;
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
		open_scenario_or_editor(pos, play, &path);
		open_save(pos, play, &path);
		Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
	}
	if (*play == 10 || *play == 1)
	{
		load_map(main_camera, engine, path);
		if (*play == 1)
			link_camera_to_mesh(engine, 0, t_engine_get_mesh(engine, 0));
		free(path);
	}
}
