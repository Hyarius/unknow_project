/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:55:48 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/15 16:23:46 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	drawing_front_hp(t_camera *cam, t_player *player)
{
	static t_color	*col_back = NULL;
	static t_color	*col_hp = NULL;
	static t_color	*col_armor = NULL;
	static t_color	*col_jet = NULL;

	if (col_back == NULL && col_hp == NULL && col_armor == NULL)
	{
		col_back = initialize_t_color(0.7, 0.7, 0.7, 1.0);
		col_hp = initialize_t_color(1.0, 0.3, 0.3, 1.0);
		col_armor = initialize_t_color(0.3, 0.3, 1.0, 1.0);
		col_jet = initialize_t_color(1.0, 1.0, 0.3, 1.0);
	}
	t_view_port_clear_buffers(cam->view_port);
	draw_hud_rect(cam->view_port, create_t_rectangle(
		create_vec2(-0.90, -1), create_vec2(0.44, 0.22)), col_back);
	t_view_port_clear_buffers(cam->view_port);
	draw_hud_rect(cam->view_port, create_t_rectangle(create_vec2(-0.88, -0.98),
		create_vec2(0.4 * (float)(player->hp) / 100, 0.08)), col_hp);
	draw_hud_rect(cam->view_port, create_t_rectangle(create_vec2(-0.88, -0.88),
		create_vec2(0.4 * (float)(player->armor) / 100, 0.08)), col_armor);
	draw_hud_rect(cam->view_port, create_t_rectangle(create_vec2(-0.90, -0.77),
		create_vec2(0.2 * (float)(player->fuel) / 100, 0.08)), col_jet);
	draw_hud_rect(cam->view_port, create_t_rectangle(
		create_vec2(0.0, 0.0), create_vec2(0.005, 0.01)), col_hp);
}

void	drawing_front_mun(t_camera *cam, t_texture **texture, t_player *player)
{
	int				weapon;
	static t_color	*color = NULL;

	if (color == NULL)
		color = initialize_t_color(0.7, 0.7, 0.7, 1.0);
	if (ft_strcmp(player->current_weapon->name, "pistol") == 0)
		weapon = 0;
	else if (ft_strcmp(player->current_weapon->name, "ar") == 0)
		weapon = 1;
	else if (ft_strcmp(player->current_weapon->name, "rifle") == 0)
		weapon = 2;
	else if (ft_strcmp(player->current_weapon->name, "shotgun") == 0)
		weapon = 3;
	else if (ft_strcmp(player->current_weapon->name, "rpg") == 0)
		weapon = 4;
	else if (ft_strcmp(player->current_weapon->name, "bb") == 0)
		weapon = 5;
	draw_rectangle_color_cpu(cam->view_port, create_t_rectangle(
					create_vec2(0.75, -1.0), create_vec2(0.25, 0.20)),
					color);
	t_view_port_clear_buffers(cam->view_port);
	draw_rectangle_texture_cpu(cam->view_port, create_t_rectangle(
					create_vec2(1.0, -0.8), create_vec2(-0.2, -0.2)),
					texture[weapon]);
}

void	drawing_front_weapons(t_camera *cam, t_texture **texture,
															t_player *player)
{
	int		weapon;

	if (ft_strcmp(player->current_weapon->name, "pistol") == 0)
		weapon = 0;
	else if (ft_strcmp(player->current_weapon->name, "ar") == 0)
		weapon = 1;
	else if (ft_strcmp(player->current_weapon->name, "rifle") == 0)
		weapon = 2;
	else if (ft_strcmp(player->current_weapon->name, "shotgun") == 0)
		weapon = 3;
	else if (ft_strcmp(player->current_weapon->name, "rpg") == 0)
		weapon = 4;
	else if (ft_strcmp(player->current_weapon->name, "bb") == 0)
		weapon = 5;
	t_view_port_clear_buffers(cam->view_port);
	draw_rectangle_texture_cpu(cam->view_port, create_t_rectangle(
					create_vec2(-0.65, -0.1), create_vec2(1.3, -0.9)),
					texture[weapon]);
}
