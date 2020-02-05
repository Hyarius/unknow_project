/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:44:25 by jubeal            #+#    #+#             */
/*   Updated: 2020/02/05 10:14:37 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_void_list	new_void_list(void)
{
	t_void_list	list;

	if (!(list.data = (void **)ft_memalloc(sizeof(void *) * PUSH_SIZE)))
		error_exit(-15, "Can't ft_memalloc a void * array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_void_list	*initialize_t_void_list(void)
{
	t_void_list	*list;

	if (!(list = (t_void_list *)ft_memalloc(sizeof(t_void_list))))
		error_exit(-16, "Can't create a t_void_list array");
	*list = new_void_list();
	return (list);
}

void		delete_t_void_list(t_void_list dest)
{
	ft_memdel((void**)&dest.data);
	dest.size = 0;
}

void		free_t_void_list(t_void_list **dest)
{
	delete_t_void_list(**dest);
	ft_memdel((void**)dest);
}

void		clean_t_void_list(t_void_list *dest)
{
	dest->size = 0;
}
