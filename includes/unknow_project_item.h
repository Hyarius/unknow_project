/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_item.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:58:23 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/20 16:09:32 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_ITEM_H
# define UNKNOW_PROJECT_ITEM_H

# include "unknow_project_player.h"

typedef struct	s_item
{
	char		*name;
	int			(*pf)(t_player*);
}				t_item;

t_item			create_health_pack(void);
t_item			create_ammo_pack(int type);
t_item			create_armor_pack(void);
t_item			create_jet_pack(void);
t_item			create_color_card(int type);

typedef struct	s_item_list
{
	t_item		*item;
	int			size;
	int			max_size;
}				t_item_list;

t_item_list		new_item_list(void);
t_item_list		*initialize_t_item_list(void);
void			t_item_list_push_back(t_item_list *dest, t_item to_add);
void			t_item_list_erase(t_item_list *dest, int index);
void			delete_t_item_list(t_item_list dest);
void			free_t_item_list(t_item_list *dest);
void			clean_t_item_list(t_item_list *dest);
t_item			t_item_list_at(t_item_list *dest, int index);
t_item			*t_item_list_get(t_item_list *dest, int index);

t_item_list		*load_items(t_mesh_list *meshs);

#endif
