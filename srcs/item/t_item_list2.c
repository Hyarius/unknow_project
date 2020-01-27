/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_item_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:03:10 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/27 14:54:39 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void			delete_t_item_list(t_item_list dest)
{
	free(dest.item);
}

void			free_t_item_list(t_item_list *dest)
{
	delete_t_item_list(*dest);
	free(dest);
}

void			clean_t_item_list(t_item_list *dest)
{
	dest->size = 0;
}
