#include "unknow_project.h"

t_player		create_t_player(t_camera *cam, t_mesh hitbox)
{
	t_player 	result;

	result.camera = cam;
	result.hitbox = hitbox;
	t_mesh_set_color(&result.hitbox, create_t_color(0.5, 0.6, 0.0 ,1.0));
	result.hp = 100;
	result.armor = 0;
	result.speed = 1.0;
	result.weapons[0] = create_t_weapons(0);
	result.weapons[1] = create_t_weapons(1);
	result.weapons[2] = create_t_weapons(2);
	result.weapons[3] = create_t_weapons(3);
	result.current_weapon = result.weapons[0];
	return (result);
}

t_player			*initialize_t_player(t_camera *cam, t_mesh hitbox)
{
	t_player *result;

	if (!(result = (t_player *)malloc(sizeof(t_player))))
		error_exit(-13, "Can't create a t_player array");

	*result = create_t_player(cam, hitbox);

	return(result);
}

t_weapon		create_t_weapons(int index)
{
	t_weapon	result[4];

	result[0].name = "pistol";
	result[0].ammo = 15;
	result[0].mags = 0;
	result[0].mag_size = 15;

	result[1].name = "ar";
	result[1].ammo = 0;
	result[1].mags = 0;
	result[1].mag_size = 30;

	result[2].name = "rifle";
	result[2].ammo = 0;
	result[2].mags = 0;
	result[2].mag_size = 10;

	result[3].name = "shotgun";
	result[3].ammo = 0;
	result[3].mags = 0;
	result[3].mag_size = 8;
	return (result[index]);
}


void			change_weapon(t_keyboard *p_keyboard, t_player *player)
{
	static int test = 0;

	if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_1]) == 1)
		test = 0;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_2]) == 1)
		test = 1;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_3]) == 1)
		test = 2;
	else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_4]) == 1)
		test = 3;
	player->current_weapon = player->weapons[test];
}

void			reload_weapon(t_keyboard *p_keyboard, t_player *player)
{
	// if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_1]) == 1)
	// {
	// 	player->current_weapon = player->weapons.pistol.name;
	// }	
	// else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_2]) == 1)
	// {
	// 	player->current_weapon = player->weapons.ar.name;
	// }	
	// else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_3]) == 1)
	// {
	// 	player->current_weapon = player->weapons.rifle.name;
	// }	
	// else if (get_key_state(p_keyboard, p_keyboard->key[SDL_SCANCODE_4]) == 1)
	// {
	// 	player->current_weapon = player->weapons.shotgun.name;
	// }
}