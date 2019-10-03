#include "unknow_project.h"

void		heal(t_player *player)
{
	int to_heal;

	to_heal = 20;
	if (player->hp < 100)
	{
		while (player->hp < 100 && to_heal-- > 0)
			player->hp += 1;
	}
}

void		refill(t_player *player)
{
	int to_refill;

	to_refill = 15;
	if (player->ammo.pistol_ammo < 999)
	{
		while (player->ammo.pistol_ammo < 999 && to_refill-- > 0)
			player->ammo.pistol_ammo += 1;
	}
}

void		protect(t_player *player)
{
	int to_protect;

	to_protect = 20;
	if (player->armor < 100)
	{
		while (player->armor < 100 && to_protect-- > 0)
			player->armor += 1;
	}
}

t_item		create_health_pack(t_vector3 pos, t_engine *engine)
{
	static int	num = 1;
	t_item		item;
	t_mesh		result;
	char 		*str;

	item.type = 0;
	str = ft_strnew(ft_strlen("Health Pack ") + ft_strlen(ft_itoa(num)));
	str = ft_strcpy(str, "Health Pack ");
	str = ft_strcat(str, ft_itoa(num++));
	item.name = str;
	result = create_primitive_cube(pos, create_t_vector3(0.2, 0.05, 0.2), NULL, 0.0, item.name);
	t_mesh_rotate(&result, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&result, create_t_color(0.8, 0.0, 0.0 ,1.0));
	result.collectible = BOOL_TRUE;
	item.mesh = &result;
	item.pf = heal;
	item.picked_up = 0;
	t_engine_add_mesh(engine, result);
	return (item);
}

t_item		create_ammo_pack(t_vector3 pos, t_engine *engine)
{
	static int	num = 1;
	t_item		item;
	t_mesh		result;
	char 		*str;

	item.type = 0;
	str = ft_strnew(ft_strlen("Ammo Pack ") + ft_strlen(ft_itoa(num)));
	str = ft_strcpy(str, "Ammo Pack ");
	str = ft_strcat(str, ft_itoa(num++));
	item.name = str;
	result = create_primitive_cube(pos, create_t_vector3(0.2, 0.05, 0.2), NULL, 0.0, item.name);
	t_mesh_rotate(&result, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&result, create_t_color(0.0, 0.8, 0.0 ,1.0));
	result.collectible = BOOL_TRUE;
	item.mesh = &result;
	item.pf = refill;
	item.picked_up = 0;
	t_engine_add_mesh(engine, result);
	return (item);
}

t_item		create_armor_pack(t_vector3 pos, t_engine *engine)
{
	static int	num = 1;
	t_item		item;
	t_mesh		result;
	char 		*str;

	item.type = 0;
	str = ft_strnew(ft_strlen("Armor Pack ") + ft_strlen(ft_itoa(num)));
	str = ft_strcpy(str, "Armor Pack ");
	str = ft_strcat(str, ft_itoa(num++));
	item.name = str;
	result = create_primitive_cube(pos, create_t_vector3(0.2, 0.05, 0.2), NULL, 0.0, item.name);
	t_mesh_rotate(&result, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&result, create_t_color(0.0, 0.0, 0.8 ,1.0));
	result.collectible = BOOL_TRUE;
	item.mesh = &result;
	item.pf = protect;
	item.picked_up = 0;
	t_engine_add_mesh(engine, result);
	return (item);
}

/*
Creer un item pour chaque condition bonne
*/
// void	is_collectible(t_engine *engine, t_mesh_list *mesh_list, t_item_list *item_list)
// {
// 	int i;
// 	t_item item;

// 	i = -1;
// 	while (++i < mesh_list->size)
// 	{
// 		if (ft_strcmp(mesh_list->mesh[i].name, "Health Pack") == 0 ||
// 			ft_strcmp(mesh_list->mesh[i].name, "Ammo Pack") == 0 ||
// 			ft_strcmp(mesh_list->mesh[i].name, "Armor Pack") == 0 )
// 			mesh_list->mesh[i].collectible = 1;
// 		// if (ft_strcmp(mesh_list->mesh[i].name, "Health Pack") == 0)
// 		// 	item = create_health_pack(create_t_vector3(0.0, 0.0, 0.0), engine);
// 		// else if (ft_strcmp(mesh_list->mesh[i].name, "Ammo Pack") == 0)
// 		// 	item = create_ammo_pack(create_t_vector3(0.0, 0.0, 0.0), engine);
// 		// else if (ft_strcmp(mesh_list->mesh[i].name, "Armor Pack") == 0)
// 		// 	item = create_armor_pack(create_t_vector3(0.0, 0.0, 0.0), engine);
// 	}
// 	// t_item_list_push_back(item_list, item);
// }
