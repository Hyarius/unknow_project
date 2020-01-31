/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_player.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:46:16 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/30 17:30:28 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_PLAYER_H
# define UNKNOW_PROJECT_PLAYER_H
# define MAX_MAGS 5

# include "unknow_project_camera.h"

typedef struct	s_weapon
{
	char		*name;
	int			ammo;
	int			mag_size;
	int			total_ammo;
	int			max_ammo;
	int			dmg;
	int			tick_shoot;
	int			tick_reload;
	int			index;
}				t_weapon;

typedef struct	s_player
{
	t_camera	*camera;
	t_mesh		hitbox;
	int			hp;
	int			armor;
	int			fuel;
	float		speed;
	t_weapon	weapons[6];
	t_weapon	*current_weapon;
	int			red_card;
	int			blue_card;
	int			green_card;
	int			shoot_time;
	int			reload_time;
	float		difficulty;
}				t_player;

t_player		new_player(t_camera *cam);
t_player		*initialize_t_player(t_camera *cam);
void			read_player(char **split, t_player *player);
t_weapon		new_weapons(int index, int ammo, int total_ammo);
t_mesh_list		*read_map_file(int fd, t_player *player);
void			change_weapon(t_keyboard *p_keyboard, t_player *player);

#endif
