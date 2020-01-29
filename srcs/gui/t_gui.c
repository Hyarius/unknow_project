/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:58:51 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/29 14:10:50 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_gui	new_gui(void)
{
	t_gui	result;
	int		idx;

	if (!(result.letter = (t_letter **)malloc(sizeof(t_letter*) * 96)))
		error_exit(-29, "Can't malloc a t_surface");
	if (!(result.menu = (t_texture **)malloc(sizeof(t_texture*) * 18)))
		error_exit(-29, "Can't malloc a t_surface");
	idx = -1;
	while (++idx <= 94)
	{
		if (!(result.letter[idx] = (t_letter *)malloc(sizeof(t_letter))))
			error_exit(-29, "Can't malloc a t_surface");
		if (!(result.letter[idx]->let = (t_texture *)malloc(sizeof(t_texture))))
			error_exit(-29, "Can't malloc a t_surface");
		if (!(result.letter[idx]->let->surface =\
										(t_surface *)malloc(sizeof(t_surface))))
			error_exit(-29, "Can't malloc a t_surface");
	}
	result.idx = 8;
	result.sens = 2;
	result.key_press = 0;
	result.info_print = 0;
	return (result);
}

t_gui	*initialize_t_gui(void)
{
	t_gui	*result;

	if (!(result = (t_gui *)malloc(sizeof(t_gui))))
		error_exit(-13, "Can't create a t_gui");
	*result = new_gui();
	return (result);
}

void	set_t_gui_texte(t_gui *gui)
{
	int		i;
	char	letter[2];

	i = 0;
	letter[0] = ' ';
	letter[1] = '\0';
	while (i < 94)
	{
		load_letter(gui, letter, i);
		i++;
		letter[0]++;
	}
}

void	print_letter(t_camera *main_cam, t_gui *gui, char *str, t_rectangle rec)
{
	int		i;
	int		len;
	int		idx;
	int		len;

	i = -1;
	len = ft_strlen(str);
	t_view_port_clear_buffers(main_cam->view_port);
	while (++i < len)
	{
		idx = -1;
		while (++idx <= 94)
		{
			if (str[i] == gui->letter[idx]->let->letter)
			{
				draw_rectangle_texture_cpu(main_cam->view_port, rec,
											gui->letter[idx]->let);
				rec.pos = add_vector2_to_vector2(rec.pos,
											create_vec2(rec.size.x, 0.0));
				break ;
			}
		}
	}
}

void	print_info_bar(t_camera *main_camera, t_player *player, t_gui *gui)
{
	char	*str;
	t_vec2	size;

	size = create_vec2(0.02, 0.07);
	str = ft_itoa(player->armor);
	print_letter(main_camera, gui, str,
		new_rectangle(create_vec2(-0.70, -0.87), size));
	free(str);
	str = ft_itoa(player->hp);
	print_letter(main_camera, gui, str,
		new_rectangle(create_vec2(-0.70, -0.97), size));
	free(str);
	if (player->current_weapon->index != 5)
	{
		str = ft_itoa(player->current_weapon->ammo);
		str = ft_strjoinf(str, " / ", 1);
		str = ft_strjoinf(str, ft_itoa(player->current_weapon->total_ammo), 3);
		print_letter(main_camera, gui, str,
					new_rectangle(create_vec2(0.78, -0.90),
										create_vec2(0.01, 0.05)));
		free(str);
	}
}
