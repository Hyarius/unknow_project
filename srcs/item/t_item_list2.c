/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_item_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:03:10 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/04 17:16:12 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void			delete_t_item_list(t_item_list dest)
{
	ft_memdel((void**)&dest.item);
}

void			free_t_item_list(t_item_list **dest)
{
	delete_t_item_list(**dest);
	ft_memdel((void**)dest);
}

void			clean_t_item_list(t_item_list *dest)
{
	dest->size = 0;
}
