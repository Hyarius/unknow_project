/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:44:25 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/15 15:44:26 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_void_list	create_t_void_list(void)
{
	t_void_list	list;

	if (!(list.data = (void **)malloc(sizeof(void *) * PUSH_SIZE)))
		error_exit(-15, "Can't malloc a void * array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_void_list	*initialize_t_void_list(void)
{
	t_void_list	*list;

	if (!(list = (t_void_list *)malloc(sizeof(t_void_list))))
		error_exit(-16, "Can't create a t_void_list array");
	*list = create_t_void_list();
	return (list);
}

void		delete_t_void_list(t_void_list dest)
{
	free(dest.data);
	dest.data = NULL;
	dest.size = 0;
}

void		free_t_void_list(t_void_list *dest)
{
	delete_t_void_list(*dest);
	free(dest);
}

void		clean_t_void_list(t_void_list *dest)
{
	dest->size = 0;
}
