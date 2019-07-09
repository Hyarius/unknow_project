/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:25:21 by gboutin           #+#    #+#             */
/*   Updated: 2019/07/09 11:01:23 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void**)alst);
	}
}
