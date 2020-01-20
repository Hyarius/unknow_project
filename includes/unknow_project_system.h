/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_system.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:38:53 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/20 15:39:48 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_SYSTEM_H
# define UNKNOW_PROJECT_SYSTEM_H

# include "unknow_project_define.h"
# include "unknow_project_vector.h"

typedef struct	s_mouse
{
	t_vec2_int	old_pos;
	t_vec2_int	pos;
	t_vec2_int	rel_pos;
	int			button[MOUSE_BUTTON];
	char		clicked_left;
	char		clicked_right;
}				t_mouse;

t_mouse			new_mouse();
t_mouse			*initialize_t_mouse();
void			get_t_mouse_info(t_mouse *mouse);
void			print_t_mouse(t_mouse *mouse);
int				get_mouse_state(t_mouse *mouse, int type);

typedef struct	s_keyboard
{
	int			key[232];
	char		clicked;
	int			i;
	const Uint8	*state;
}				t_keyboard;

t_keyboard		new_keyboard();
t_keyboard		*initialize_t_keyboard();
int				get_key_state(t_keyboard *keyboard, int scan_code);
void			reset_key_state(t_keyboard *keyboard, int scan_code);

#endif
