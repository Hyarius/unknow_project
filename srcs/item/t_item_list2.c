/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_item_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:03:10 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/20 13:09:56 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void			t_item_list_erase(t_item_list *dest, int index)
{
	free_t_item(t_item_list_get(dest, index));
	while (index < dest->size)
	{
		dest[index + 1] = dest[index];
		index++;
	}
}

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