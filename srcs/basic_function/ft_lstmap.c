/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:55:38 by gboutin           #+#    #+#             */
/*   Updated: 2019/07/09 11:01:33 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;

	if (!lst)
		return (NULL);
	new = f(lst);
	if (new == NULL)
		return (NULL);
	temp = new;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = f(lst);
		if (temp->next == NULL)
			return (NULL);
		temp = temp->next;
	}
	return (new);
}
