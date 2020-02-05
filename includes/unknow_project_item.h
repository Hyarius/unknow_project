/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_item.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:58:23 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/04 17:23:41 by gboutin          ###   ########.fr       */
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

t_item			create_health_pack(char *str);
t_item			create_ammo_pack(int type, char *str);
t_item			create_armor_pack(char *str);
t_item			create_jet_pack(char *str);
t_item			create_color_card(int type);
int				refill_pistol(t_player *player);
int				refill_ar(t_player *player);
int				refill_rifle(t_player *player);
int				refill_shotgun(t_player *player);
int				refill_rpg(t_player *player);

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
void			free_t_item_list(t_item_list **dest);
void			clean_t_item_list(t_item_list *dest);
t_item			t_item_list_at(t_item_list *dest, int index);
t_item			*t_item_list_get(t_item_list *dest, int index);

t_item_list		*load_items(t_mesh_list *meshs);

#endif
