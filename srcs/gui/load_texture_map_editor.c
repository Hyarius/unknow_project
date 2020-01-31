/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_map_editor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:05:11 by adjouber          #+#    #+#             */
/*   Updated: 2020/01/31 16:17:43 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	load_texture_key_elevator(t_visual_engine *engine)
{
	engine->len[6] = 1;
	if (!(engine->path[6] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[6][0] = ft_strdup("ressources/assets/textures/key_red.png");
	engine->len[7] = 1;
	if (!(engine->path[7] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[7][0] = ft_strdup("ressources/assets/textures/key_blue.png");
	engine->len[8] = 1;
	if (!(engine->path[8] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[8][0] = ft_strdup("ressources/assets/textures/key_green.png");
	engine->len[9] = 1;
	if (!(engine->path[9] = (char**)malloc(sizeof(char*) * 3)))
		error_exit(2, "error malloc");
	engine->path[9][0] = ft_strdup("ressources/assets/textures/iron.png");
}

void	load_texture_slope_pack(t_visual_engine *engine)
{
	engine->len[10] = 3;
	if (!(engine->path[10] = (char**)malloc(sizeof(char*) * 3)))
		error_exit(2, "error malloc");
	engine->path[10][0] = ft_strdup("ressources/assets/textures/iron.png");
	engine->path[10][1] = ft_strdup("ressources/assets/textures/brick.png");
	engine->path[10][2] = ft_strdup("ressources/assets/textures/wood.png");
	engine->len[11] = 0;
	engine->path[11] = NULL;
	engine->len[12] = 1;
	if (!(engine->path[12] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[12][0] = ft_strdup("ressources/assets/textures/health.png");
	engine->len[13] = 1;
	if (!(engine->path[13] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[13][0] = ft_strdup("ressources/assets/textures/armor.png");
	engine->len[14] = 1;
	if (!(engine->path[14] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[14][0] = ft_strdup("ressources/assets/textures/fuel.png");
}

void	load_texture_ammo_ladder(t_visual_engine *engine)
{
	engine->len[15] = 1;
	if (!(engine->path[15] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[15][0] = ft_strdup("ressources/assets/textures/ar.png");
	engine->len[16] = 1;
	if (!(engine->path[16] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[16][0] = ft_strdup("ressources/assets/textures/rifle.png");
	engine->len[17] = 1;
	if (!(engine->path[17] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[17][0] = ft_strdup("ressources/assets/textures/shotgun.png");
	engine->len[18] = 1;
	if (!(engine->path[18] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[18][0] = ft_strdup("ressources/assets/textures/echelle.png");
}

void	load_texture_platform_plane(t_visual_engine *engine)
{
	engine->len[19] = 3;
	if (!(engine->path[19] = (char**)malloc(sizeof(char*) * 3)))
		error_exit(2, "error malloc");
	engine->path[19][0] = ft_strdup("ressources/assets/textures/iron.png");
	engine->path[19][1] = ft_strdup("ressources/assets/textures/brick.png");
	engine->path[19][2] = ft_strdup("ressources/assets/textures/wood.png");
	engine->len[20] = 3;
	if (!(engine->path[20] = (char**)malloc(sizeof(char*) * 3)))
		error_exit(2, "error malloc");
	engine->path[20][0] = ft_strdup("ressources/assets/textures/metal_f.png");
	engine->path[20][1] = ft_strdup("ressources/assets/textures/grille.png");
	engine->path[20][2] = ft_strdup("ressources/assets/textures/metal_s.png");
}

void	load_texture_end(t_visual_engine *engine)
{
	engine->len[21] = 1;
	if (!(engine->path[21] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[21][0] = ft_strdup("ressources/assets/textures/enemy.png");
	engine->len[22] = 1;
	if (!(engine->path[22] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[22][0] = ft_strdup("ressources/assets/textures/window.png");
	engine->len[23] = 1;
	if (!(engine->path[23] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[23][0] = ft_strdup("ressources/assets/textures/cube_test.png");
	engine->len[24] = 1;
	if (!(engine->path[24] = (char**)malloc(sizeof(char*) * 1)))
		error_exit(2, "error malloc");
	engine->path[24][0] = ft_strdup("ressources/assets/textures/cube_test.png");
}
