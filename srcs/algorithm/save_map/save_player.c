/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:06:57 by adjouber          #+#    #+#             */
/*   Updated: 2019/12/02 14:08:24 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	save_card(t_engine *engine, int fd, char *str)
{
	str = ft_strjoinf(str, ft_itoa(engine->user_engine->player->red_card), 3);
	str = ft_strjoinf(str, " ", 1);
	str = ft_strjoinf(str, ft_itoa(engine->user_engine->player->blue_card), 3);
	str = ft_strjoinf(str, " ", 1);
	str = ft_strjoinf(str, ft_itoa(engine->user_engine->player->green_card), 3);
	write(fd, str, ft_strlen(str));
	free(str);
	write(fd, "\n", 1);
}

void	save_ammo(t_engine *en, int fd, char *st)
{
	st = ft_strjoinf(st, ft_itoa(en->user_engine->player->weapons[0].ammo), 3);
	st = ft_strjoinf(st, " ", 1);
	st = ft_strjoinf(st, ft_itoa(en->user_engine->player->weapons[0].total), 3);
	st = ft_strjoinf(st, " ", 1);
	st = ft_strjoinf(st, ft_itoa(en->user_engine->player->weapons[1].ammo), 3);
	st = ft_strjoinf(st, " ", 1);
	st = ft_strjoinf(st, ft_itoa(en->user_engine->player->weapons[1].total), 3);
	st = ft_strjoinf(st, " ", 1);
	st = ft_strjoinf(st, ft_itoa(en->user_engine->player->weapons[2].ammo), 3);
	st = ft_strjoinf(st, " ", 1);
	st = ft_strjoinf(st, ft_itoa(en->user_engine->player->weapons[2].total), 3);
	st = ft_strjoinf(st, " ", 1);
	st = ft_strjoinf(st, ft_itoa(en->user_engine->player->weapons[3].ammo), 3);
	st = ft_strjoinf(st, " ", 1);
	st = ft_strjoinf(st, ft_itoa(en->user_engine->player->weapons[3].total), 3);
	st = ft_strjoinf(st, " ", 1);
	st = ft_strjoinf(st, ft_itoa(en->user_engine->player->weapons[4].ammo), 3);
	st = ft_strjoinf(st, " ", 1);
	st = ft_strjoinf(st, ft_itoa(en->user_engine->player->weapons[4].total), 3);
	st = ft_strjoinf(st, " ", 1);
	save_card(en, fd, st);
}

void	save_status(t_engine *engine, t_mesh cu, int fd, char *test)
{
	test = ft_strjoinf(test, ft_ftoa(cu.kinetic), 1);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(cu.rotation.x), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(cu.rotation.y), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(cu.rotation.z), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(t_face_list_get(cu.faces, 0)->color.r), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(t_face_list_get(cu.faces, 0)->color.g), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(t_face_list_get(cu.faces, 0)->color.b), 3);
	test = ft_strjoinf(test, " 1.0 ", 1);
	test = ft_strjoinf(test, ft_itoa(engine->user_engine->player->hp), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_itoa(engine->user_engine->player->armor), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_itoa(engine->user_engine->player->fuel), 3);
	test = ft_strjoinf(test, " ", 1);
	save_ammo(engine, fd, test);
}

void	save_player(t_engine *engine, t_mesh current, int fd)
{
	char	*test;

	test = ft_strdup("player: Player ");
	test = ft_strjoinf(test, ft_ftoa(current.pos.x), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(current.pos.y), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(current.pos.z), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(current.size.x), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(current.size.y), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, ft_ftoa(current.size.z), 3);
	test = ft_strjoinf(test, " ", 1);
	test = ft_strjoinf(test, "NULL ", 1);
	save_status(engine, current, fd, test);
}
