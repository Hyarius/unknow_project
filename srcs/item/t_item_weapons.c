/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_item_weapons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:40:31 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/20 14:02:29 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

int		refill_pistol(t_player *player)
{
	int	to_fill;

	to_fill = player->weapons[0].mag_size;
	if (player->weapons[0].total_ammo < player->weapons[0].max_ammo)
	{
		while (to_fill-- > 0
			&& player->weapons[0].total_ammo < player->weapons[0].max_ammo)
			player->weapons[0].total_ammo++;
		return (BOOL_TRUE);
	}
	else
		return (BOOL_FALSE);
}

int		refill_ar(t_player *player)
{
	int	to_fill;

	to_fill = player->weapons[1].mag_size;
	if (player->weapons[1].total_ammo < player->weapons[1].max_ammo)
	{
		while (to_fill-- > 0
			&& player->weapons[1].total_ammo < player->weapons[1].max_ammo)
			player->weapons[1].total_ammo++;
		return (BOOL_TRUE);
	}
	else
		return (BOOL_FALSE);
}

int		refill_rifle(t_player *player)
{
	int	to_fill;

	to_fill = player->weapons[2].mag_size;
	if (player->weapons[2].total_ammo < player->weapons[2].max_ammo)
	{
		while (to_fill-- > 0
			&& player->weapons[2].total_ammo < player->weapons[2].max_ammo)
			player->weapons[2].total_ammo++;
		return (BOOL_TRUE);
	}
	else
		return (BOOL_FALSE);
}

int		refill_shotgun(t_player *player)
{
	int	to_fill;

	to_fill = player->weapons[3].mag_size;
	if (player->weapons[3].total_ammo < player->weapons[3].max_ammo)
	{
		while (to_fill-- > 0
			&& player->weapons[3].total_ammo < player->weapons[3].max_ammo)
			player->weapons[3].total_ammo++;
		return (BOOL_TRUE);
	}
	else
		return (BOOL_FALSE);
}

int		refill_rpg(t_player *player)
{
	int	to_fill;

	to_fill = player->weapons[4].mag_size;
	if (player->weapons[4].total_ammo < player->weapons[4].max_ammo)
	{
		while (to_fill-- > 0
			&& player->weapons[4].total_ammo < player->weapons[4].max_ammo)
			player->weapons[4].total_ammo++;
		return (BOOL_TRUE);
	}
	else
		return (BOOL_FALSE);
}

t_item		create_ammo_pack(int type)
{
	static int	num = 1;
	t_item		item;

	item.name = ft_strjoinf("Ammo_Pack_", ft_itoa(num), 2);
	num++;
	if (type == 1)
		item.pf = refill_pistol;
	else if (type == 2)
		item.pf = refill_ar;
	else if (type == 3)
		item.pf = refill_rifle;
	else if (type == 4)
		item.pf = refill_shotgun;
	else if (type == 5)
		item.pf = refill_rpg;
	return (item);
}
