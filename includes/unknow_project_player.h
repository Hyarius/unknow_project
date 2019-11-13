#ifndef UNKNOW_PROJECT_PLAYER_H
# define UNKNOW_PROJECT_PLAYER_H
# define MAX_MAGS 5

#include "unknow_project_camera.h"

typedef struct  s_weapon
{
	char		*name;
	int			ammo;
	int			mag_size;
	int			total_ammo;
	int			max_ammo;
}               t_weapon;

typedef struct  s_player
{
	t_camera	*camera;
	t_mesh		hitbox;
	int			hp;
	int			armor;
	float		speed;
	t_weapon	weapons[4];
	t_weapon	*current_weapon;
}               t_player;

typedef struct  s_enemy
{
	t_mesh		hitbox;
	int			hp;
	float		speed;
	t_weapon	weapon;
}               t_enemy;

t_player		create_t_player(t_camera *cam, t_mesh hitbox);
t_enemy			create_t_enemy(t_mesh hitbox);
t_player		*initialize_t_player(t_camera *cam, t_mesh hitbox);
t_weapon		create_t_weapons(int index);

#endif