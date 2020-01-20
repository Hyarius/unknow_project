/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_jetpack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:39:48 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/20 13:39:50 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

int		jetpack(t_player *player)
{
	int	to_fill;

	to_fill = 50;
	if (player->fuel < 300)
	{
		while (player->fuel < 300 && to_fill-- > 0)
			player->fuel += 1;
		return (BOOL_TRUE);
	}
	return (BOOL_FALSE);
}

t_item	create_jet_pack(void)
{
	static int	num = 1;
	t_item		item;

	item.name = ft_strjoinf("Jet_Pack_", ft_itoa(num), 2);
	num++;
	item.pf = jetpack;
	return (item);
}