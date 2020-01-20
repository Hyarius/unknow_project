/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_item.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:32:33 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/20 13:38:06 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

int		heal(t_player *player)
{
	int to_heal;

	to_heal = 20;
	if (player->hp < 100)
	{
		while (player->hp < 100 && to_heal-- > 0)
			player->hp += 1;
		return (BOOL_TRUE);
	}
	return (BOOL_FALSE);
}

int		protect(t_player *player)
{
	int to_protect;

	to_protect = 20;
	if (player->armor < 100)
	{
		while (player->armor < 100 && to_protect-- > 0)
			player->armor += 1;
		return (BOOL_TRUE);
	}
	return (BOOL_FALSE);
}

t_item	create_health_pack(void)
{
	static int	num = 1;
	t_item		item;

	item.name = ft_strjoinf("Health_Pack_", ft_itoa(num), 2);
	num++;
	item.pf = heal;
	return (item);
}

t_item	create_armor_pack(void)
{
	static int	num = 1;
	t_item		item;

	item.name = ft_strjoinf("Armor_Pack_", ft_itoa(num), 2);
	num++;
	item.pf = protect;
	return (item);
}
