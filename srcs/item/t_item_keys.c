/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_item_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:42:14 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/31 10:47:33 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

int		red_card(t_player *player)
{
	player->red_card = 1;
	return (BOOL_TRUE);
}

int		blue_card(t_player *player)
{
	player->blue_card = 1;
	return (BOOL_TRUE);
}

int		green_card(t_player *player)
{
	player->green_card = 1;
	return (BOOL_TRUE);
}

t_item	create_color_card(int type)
{
	t_item		item;

	item.name = NULL;
	if (type == 1)
	{
		item.name = ft_strjoin("Card_", "red");
		item.pf = red_card;
	}
	else if (type == 2)
	{
		item.name = ft_strjoin("Card_", "blue");
		item.pf = blue_card;
	}
	else if (type == 3)
	{
		item.name = ft_strjoin("Card_", "green");
		item.pf = green_card;
	}
	return (item);
}
