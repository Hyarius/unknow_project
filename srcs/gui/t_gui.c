/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:58:51 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/09 16:03:56 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_gui	create_t_gui(void)
{
	t_gui	result;
	int		idx;

	if (!(result.letter = (t_letter **)malloc(sizeof(t_letter*) * 95)))
		error_exit(-29, "Can't malloc a t_surface");
	if (!(result.menu = (t_texture **)malloc(sizeof(t_texture*) * 17)))
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
	*result = create_t_gui();
	return (result);
}

void	set_t_gui_texte(t_gui *gui)
{
	int		i;
	char	letter;

	i = 32;
	letter = ' ';
	while (i <= 126)
	{
		load_letter(gui, &letter, i - 32);
		i++;
		letter++;
	}
}

void	print_letter(t_camera *main_cam, t_gui *gui, char *str, t_rectangle rec)
{
	int		i;
	int		idx;

	i = -1;
	t_view_port_clear_buffers(main_cam->view_port);
	while (++i < ft_strlen(str))
	{
		idx = -1;
		while (++idx <= 94)
		{
			if (str[i] == gui->letter[idx]->let->letter)
			{
				draw_rectangle_texture_cpu(main_cam->view_port, rec,
											gui->letter[idx]->let);
				rec.pos = add_vector2_to_vector2(rec.pos,
											create_t_vector2(rec.size.x, 0.0));
				break ;
			}
		}
	}
}

void	print_info_bar(t_camera *main_camera, t_player *player, t_gui *gui)
{
	char			*str;

	str = ft_itoa(player->armor);
	print_letter(main_camera, gui, ft_strcat(str, "%"),
				create_t_rectangle(create_t_vector2(-0.70, -0.87),
									create_t_vector2(0.02, 0.07)));
	free(str);
	str = ft_itoa(player->hp);
	print_letter(main_camera, gui, ft_strcat(str, "%"),
				create_t_rectangle(create_t_vector2(-0.70, -0.97),
									create_t_vector2(0.02, 0.07)));
	free(str);
	str = ft_itoa(player->current_weapon->ammo);
	str = ft_strjoinf(str, " / ", 1);
	str = ft_strjoinf(str, ft_itoa(player->current_weapon->total_ammo), 3);
	print_letter(main_camera, gui, str,
				create_t_rectangle(create_t_vector2(0.78, -0.90),
									create_t_vector2(0.01, 0.05)));
	free(str);
}
