/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:58:51 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/07 14:58:22 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_gui	new_gui(void)
{
	t_gui	result;
	int		idx;

	if (!(result.letter = (t_letter **)ft_memalloc(sizeof(t_letter*) * 94)))
		error_exit(-29, "Can't ft_memalloc a t_surface");
	if (!(result.menu = (t_texture **)ft_memalloc(sizeof(t_texture*) * 20)))
		error_exit(-29, "Can't ft_memalloc a t_surface");
	idx = -1;
	while (++idx < 94)
	{
		if (!(result.letter[idx] = (t_letter *)ft_memalloc(sizeof(t_letter))))
			error_exit(-29, "Can't ft_memalloc a t_surface");
		if (!(result.letter[idx]->let = (t_texture *)ft_memalloc(sizeof(t_texture))))
			error_exit(-29, "Can't ft_memalloc a t_surface");
		if (!(result.letter[idx]->let->surface =\
										(t_surface *)ft_memalloc(sizeof(t_surface))))
			error_exit(-29, "Can't ft_memalloc a t_surface");
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

	if (!(result = (t_gui *)ft_memalloc(sizeof(t_gui))))
		error_exit(-13, "Can't create a t_gui");
	*result = new_gui();
	return (result);
}

void	delete_t_surface(t_surface dest)
{
	ft_memdel((void**)&dest.pixels);
}

void	free_t_surface(t_surface **dest)
{
	printf("0.0\n");	
	delete_t_surface(**dest);
	printf("0.1\n");	
	ft_memdel((void**)dest);
	printf("0.2\n");	
}

void	delete_t_texture(t_texture *dest)
{
	if (dest->surface != NULL)
		free_t_surface(&dest->surface);
	printf("before\n");
	printf("ptr path = %p\n", &dest->path);
	printf("ptr path = %p\n", dest->path);
	ft_strdel(&dest->path);
	printf("after\n");
}

void	free_t_texture(t_texture **dest)
{
	delete_t_texture(*dest);
	ft_memdel((void**)dest);
}

void	delete_t_letter(t_letter *dest)
{
	if (dest->let != NULL)
		free_t_texture(&dest->let);
}

void	free_t_letter(t_letter **dest)
{
	delete_t_letter(*dest);
	ft_memdel((void**)dest);
}

void	delete_t_gui(t_gui dest)
{
	int	i;

	i = -1;
	while (++i < 94)
		free_t_letter(&dest.letter[i]);
	i = -1;
	while (++i < 20)
		free_t_texture(&dest.menu[i]);
	i = -1;
	while (++i < 16)
		free_t_texture(&dest.text_weap[i]);
	i = -1;
	while (++i < 6)
		free_t_texture(&dest.text_am[i]);
	free_t_texture(&dest.skybox);
}

void	free_t_gui(t_gui *dest)
{
	delete_t_gui(*dest);
	ft_memdel((void**)dest);
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
	ft_memdel((void**)&str);
	str = ft_itoa(player->hp);
	print_letter(main_camera, gui, str,
		new_rectangle(create_vec2(-0.70, -0.97), size));
	ft_memdel((void**)&str);
	if (player->current_weapon->index != 5)
	{
		str = ft_itoa(player->current_weapon->ammo);
		str = ft_strjoinf(str, " / ", 1);
		str = ft_strjoinf(str, ft_itoa(player->current_weapon->total_ammo), 3);
		print_letter(main_camera, gui, str,
					new_rectangle(create_vec2(0.78, -0.90),
										create_vec2(0.01, 0.05)));
		ft_memdel((void**)&str);
	}
}
