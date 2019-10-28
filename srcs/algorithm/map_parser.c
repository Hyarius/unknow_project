#include "unknow_project.h"

t_item			create_t_item(t_mesh mesh)
{
	t_item		item;

	if (ft_strcmp(mesh.name, "Ammo_Pack") == '_')
		item = create_ammo_pack(mesh.hp * -1);
	else if (ft_strcmp(mesh.name, "Health_Pack") == '_')
		item = create_health_pack();
	else if (ft_strcmp(mesh.name, "Armor_Pack") == '_')
		item = create_armor_pack();
	else if (ft_strcmp(mesh.name, "Jet_Pack") == '_')
		item = create_jet_pack();
	else if (ft_strcmp(mesh.name, "Card") == '_')
		item = create_color_card(mesh.hp * -1);
	return (item);
}

t_item_list		*load_items(t_mesh_list *meshs)
{
	t_item_list	*result;
	t_item		item;
	int			i;

	i = 0;
	result = initialize_t_item_list();
	while(i < meshs->size)
	{
		if (t_mesh_list_at(meshs, i).collectible == 1)
		{
			item = create_t_item(t_mesh_list_at(meshs, i));
			t_item_list_push_back(result, item);
		}
		i++;
	}
	return (result);
}

t_player		*read_player(char *path, t_camera *main_camera)
{
	t_player	*player;
	t_mesh		mesh;
	char		*line;
	char		**line_split;
	t_vector3	vector[3];
	int			fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(-7000, "imposible fd");
	player = initialize_t_player(main_camera);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) != 0)
		{
			line_split = ft_strsplit(line, ' ');
			if (ft_strcmp(line_split[0], "player:") == 0)
			{
				vector[0] = create_t_vector3(ft_atof(line_split[2]),
											ft_atof(line_split[3]) + 0.2,
											ft_atof(line_split[4]));
				vector[1] = create_t_vector3(ft_atof(line_split[5]),
											ft_atof(line_split[6]),
											ft_atof(line_split[7]));
				vector[2] = create_t_vector3(ft_atof(line_split[10]),
											ft_atof(line_split[11]),
											ft_atof(line_split[12]));
				// if (ft_strcmp(line_split[8 + i], "NULL") != 0)
				// 	texture_path = line_split[8 + i];
				// else
				// 	color = create_t_color(ft_atof(line_split[13 + i]), ft_atof(line_split[14 + i]), ft_atof(line_split[15 + i]), ft_atof(line_split[16 + i]));
				mesh = create_primitive_cube(vector[0], vector[1], NULL, ft_atof(line_split[9]));
				t_mesh_rotate(&mesh, vector[2]);
				mesh.hp = ft_atoi(line_split[17]);
				mesh.no_hitbox = 0;
				mesh.primitive = -1;
				t_mesh_set_name(&mesh, line_split[1]);
				player->hitbox = mesh;
				t_mesh_set_color(&player->hitbox, create_t_color(0.5, 0.6, 0.0 ,1.0));
				player->hp = ft_atoi(line_split[17]);
				player->armor = ft_atoi(line_split[18]);
				player->fuel = ft_atoi(line_split[19]);
				player->weapons[0] = create_t_weapons(0, ft_atoi(line_split[20]), ft_atoi(line_split[21]));
				player->weapons[1] = create_t_weapons(1, ft_atoi(line_split[22]), ft_atoi(line_split[23]));
				player->weapons[2] = create_t_weapons(2, ft_atoi(line_split[24]), ft_atoi(line_split[25]));
				player->weapons[3] = create_t_weapons(3, ft_atoi(line_split[26]), ft_atoi(line_split[27]));
				player->weapons[4] = create_t_weapons(4, ft_atoi(line_split[28]), ft_atoi(line_split[29]));
				printf("here\n");
				player->red_card = ft_atoi(line_split[30]);
				printf("here\n");
				player->blue_card = ft_atoi(line_split[31]);
				printf("here\n");
				player->green_card = ft_atoi(line_split[32]);
				player->current_weapon = &player->weapons[0];
			}
			ft_freetab(line_split);
		}
		free(line);
	}
	free(line);
	close(fd);
	return (player);
}

t_mesh_list		*read_map_file(char *path)
{
	t_mesh		mesh;
	t_mesh_list	*result;
	char		*line;
	char		**line_split;
	char		*texture_path;
	int			fd;
	t_vector3	vector[3];
	int			i;
	t_color 	color;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	 	error_exit(-7000, "impossible fd");
	result = initialize_t_mesh_list();
	while (get_next_line(fd, &line) > 0)
	{
		texture_path = NULL;
		if (ft_strlen(line) != 0)
		{
			line_split = ft_strsplit(line, ' ');
			i = 0;
			if (ft_strcmp(line_split[0], "#") == 0)
				i++;

			if (ft_strcmp(line_split[0], "plane:") == 0 || ft_strcmp(line_split[0], "cube:") == 0 || ft_strcmp(line_split[0], "item:") == 0 || i > 0)
			{
				vector[0] = create_t_vector3(ft_atof(line_split[2 + i]),
											ft_atof(line_split[3 + i]),
											ft_atof(line_split[4 + i]));
				vector[1] = create_t_vector3(ft_atof(line_split[5 + i]),
											ft_atof(line_split[6 + i]),
											ft_atof(line_split[7 + i]));
				vector[2] = create_t_vector3(ft_atof(line_split[10 + i]),
											ft_atof(line_split[11 + i]),
											ft_atof(line_split[12 + i]));

				if (ft_strcmp(line_split[8 + i], "NULL") != 0)
					texture_path = line_split[8 + i];
				else
					color = create_t_color(ft_atof(line_split[13 + i]), ft_atof(line_split[14 + i]), ft_atof(line_split[15 + i]), ft_atof(line_split[16 + i]));
				if (ft_strcmp(line_split[0], "plane:") == 0)
					mesh = create_primitive_plane(vector[0], vector[1], texture_path, ft_atof(line_split[9 + i]));
				else if (ft_strcmp(line_split[0], "cube:") == 0)
					mesh = create_primitive_cube(vector[0], vector[1], texture_path, ft_atof(line_split[9 + i]));
				else if (ft_strcmp(line_split[0], "item:") == 0)
				{
					mesh = create_primitive_cube(vector[0], vector[1], texture_path, ft_atof(line_split[9 + i]));
					mesh.collectible = 1;
				}
				else if (i > 0)
					mesh = read_obj_file(line_split[1], vector[0], vector[1], ft_atof(line_split[10 + i]));
				if (texture_path == NULL)
					t_mesh_set_color(&mesh, color);
				t_mesh_rotate(&mesh, vector[2]);
				mesh.hp = ft_atoi(line_split[17 + i]);
				if (ft_strcmp(line_split[ft_tablen(line_split) - 1], "*") == 0)
					t_mesh_set_visibility(&mesh, BOOL_FALSE);
				if (ft_strcmp(line_split[ft_tablen(line_split) - 1], "#") == 0)
					mesh.no_hitbox = 1;
				else
					mesh.no_hitbox = 0;
				t_mesh_set_name(&mesh, line_split[1 + i]);
				t_mesh_list_push_back(result, mesh);
			}
			ft_freetab(line_split);
		}
		free(line);
	}
	free(line);
	close(fd);
	return(result);
}
