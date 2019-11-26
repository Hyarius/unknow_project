#include "unknow_project.h"

t_mesh		create_mesh_editing(int index, t_vector4 pos)
{
	t_mesh	mesh;

	mesh.pos = pos;
	if (index == 0)
	{
		mesh.name = "cube";
		mesh.size = create_t_vector4(1.0, 1.0, 1.0);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 1)
	{
		mesh.name = "wall";
		mesh.size = create_t_vector4(3.0, 2.0, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 2)
	{
		mesh.name = "door";
		mesh.size = create_t_vector4(1.0, 2.0, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 3)
	{
		mesh.name = "door_red";
		mesh.size = create_t_vector4(1.0, 2.0, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 4)
	{
		mesh.name = "door_blue";
		mesh.size = create_t_vector4(1.0, 2.0, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 5)
	{
		mesh.name = "door_green";
		mesh.size = create_t_vector4(1.0, 2.0, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 6)
	{
		mesh.name = "Card_red";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 7)
	{
		mesh.name = "Card_blue";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 8)
	{
		mesh.name = "Card_green";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 9)
	{
		mesh.name = "elevator";
		mesh.size = create_t_vector4(2.0, 5.0, 2.0);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 10)
	{
		mesh.name = "stair";
		mesh.size = create_t_vector4(1.0, 0.2, 5.0);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(10.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 11)
	{
		mesh.name = "stair";
		mesh.size = create_t_vector4(1.0, 0.2, 5.0);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(10.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 12)
	{
		mesh.name = "Healt_Pack";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 13)
	{
		mesh.name = "Armor_Pack";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 14)
	{
		mesh.name = "Jet_Pack";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 15)
	{
		mesh.name = "Ammo_Pack";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -2;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 16)
	{
		mesh.name = "Ammo_Pack";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -3;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 17)
	{
		mesh.name = "Ammo_Pack";
		mesh.size = create_t_vector4(0.2, 0.05, 0.2);
		mesh.primitive = 1;
		mesh.collectible = 1;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -4;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 18)
	{
		mesh.name = "ladder";
		mesh.size = create_t_vector4(1.0, 2.0, -0.01);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 19)
	{
		mesh.name = "platform";
		mesh.size = create_t_vector4(1.0, 0.2, 1.0);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 20)
	{
		mesh.name = "plane";
		mesh.size = create_t_vector4(1.0, 0.0, 1.0);
		mesh.primitive = 0;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 21)
	{
		mesh.name = "Enemy";
		mesh.size = create_t_vector4(0.3, 0.5, 0.3);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 22)
	{
		mesh.name = "window";
		mesh.size = create_t_vector4(1.0, 2.0, 0.3);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 24)
	{
		mesh.name = "end";
		mesh.size = create_t_vector4(0.3, 0.1, 0.3);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = -1;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 0.0;
	}
	else if (index == 23)
	{
		mesh.name = "Player";
		mesh.size = create_t_vector4(0.3, 0.5, 0.3);
		mesh.primitive = 1;
		mesh.collectible = 0;
		mesh.rotation = create_t_vector4(0.0, 0.0, 0.0);
		mesh.hp = 100;
		mesh.texture = (t_texture*)malloc(sizeof(t_texture));
		mesh.texture->path = NULL;
		mesh.kinetic = 100.0;
	}
	return (mesh);
}

t_mesh		select_mesh(t_mesh mesh_editing, t_keyboard *key, t_vector4 pos)
{
	t_mesh	mesh;
	static int	press = 0;

	mesh = mesh_editing;
	mesh.pos = pos;
	if (get_key_state(key, key->key[SDL_SCANCODE_1]) == 1 && press == 0)
	{
		key->i--;
		if (key->i < 0)
			key->i = 24;
		mesh = create_mesh_editing(key->i, pos);
		press = 1;
	}
	else if (get_key_state(key, key->key[SDL_SCANCODE_2]) == 1 && press == 0)
	{
		key->i++;
		if (key->i > 24)
			key->i = 0;
		mesh = create_mesh_editing(key->i, pos);
		press = 1;
	}
	else if (get_key_state(key, key->key[SDL_SCANCODE_1]) == 0 && get_key_state(key, key->key[SDL_SCANCODE_2]) == 0)
		press = 0;
	return (mesh);
}

void		print_info_editing(t_camera *main_camera, t_keyboard *key, t_gui *gui)
{
	static int		r_press = 0;


	if (get_key_state(key, key->key[SDL_SCANCODE_R]) == 1 && r_press == 0)
	{
		if (gui->info_print == 0)
			gui->info_print = 1;
		else if (gui->info_print == 1)
			gui->info_print = 0;
		printf("%d\n", gui->info_print);
		r_press = 1;
	}
	else if (get_key_state(key, key->key[SDL_SCANCODE_R]) == 0)
		r_press = 0;
	if (gui->info_print == 1)
	{
		t_view_port_clear_buffers(main_camera->view_port);
		draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(-1.0, 1.0), create_t_vector2(2.0, -2.0)), gui->menu[12]);
		t_view_port_clear_buffers(main_camera->view_port);
		draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(-1.1, 0.86 - (0.079 * key->i)), create_t_vector2(0.7, 0.1)), gui->menu[13]);
	}
}

void		player_editing(t_camera *main_camera, t_engine *engine, t_gui *gui)
{
	static int	b_press = 0;
	static int	print = 0;

	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_B]) == 1 && b_press == 0)
	{
		if (print == 0)
			print = 1;
		else if (print == 1)
			print = 0;
		b_press = 1;
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_B]) == 0)
		b_press = 0;
	if (print == 1)
		engine->playing = 11;
}

void		print_set_player(t_camera *main_camera, t_gui *gui, t_engine *engine)
{
	int		i;
	t_mesh	*mesh;

	i = 0;
	mesh = t_mesh_list_get(engine->physic_engine->mesh_list, i);
	while (++i < engine->physic_engine->mesh_list->size && ft_strcmp(mesh->name, "Player") != 0)
		mesh = t_mesh_list_get(engine->physic_engine->mesh_list, i);
	if (ft_strcmp(mesh->name, "Player") == 0)
	{
		t_view_port_clear_buffers(main_camera->view_port);
		if (mesh->kinetic == 100.0f)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(-0.08, 0.55), create_t_vector2(0.7, 0.1)), gui->menu[13]);
		if (mesh->kinetic == 10.0f)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(-0.61, 0.55), create_t_vector2(0.7, 0.1)), gui->menu[13]);
	}
}


void		map_editor(t_camera *main_camera, t_gui *gui, t_engine *engine, t_mesh mesh_editing)
{
	t_mesh			*target;
	t_mesh			mesh;
	t_vector4		normal;
	static t_color	*color_armor = NULL;
	static int		l_press = 0;
	static int		i_press = 0;
	static int		b_press = 0;
	static int		left_press = 0;
	static int		right_press = 0;
	static int		up_press = 0;
	static int		down_press = 0;
	static int		equals_press = 0;
	static int		minus_press = 0;

	if (color_armor == NULL)
		color_armor = initialize_t_color(0.3, 0.3, 1.0, 1.0);

	t_view_port_clear_buffers(main_camera->view_port);
	draw_rectangle_color_cpu_front(main_camera->view_port, create_t_rectangle(create_t_vector2(0.0, 0.0), create_t_vector2(0.005, 0.01)), color_armor);
	print_info_editing(main_camera, engine->user_engine->keyboard, gui);
	player_editing(main_camera, engine, gui);
	if (t_mouse_state(engine->user_engine->mouse) == 2)
	{
		if (mesh_editing.primitive == 1)
			mesh = create_primitive_cube(mesh_editing.pos, mesh_editing.size, mesh_editing.texture->path, mesh_editing.kinetic);
		else if (mesh_editing.primitive == 0)
			mesh = create_primitive_plane(mesh_editing.pos, mesh_editing.size, mesh_editing.texture->path, mesh_editing.kinetic);
		t_mesh_set_color(&mesh, create_t_color(1.0, 1.0, 1.0, 1.0));
		t_mesh_set_name(&mesh, mesh_editing.name);
		mesh.hp = mesh_editing.hp;
		t_mesh_rotate(&mesh, mesh_editing.rotation);
		cast_mesh(engine, &mesh, "Player");
		mesh.pos.x = round_float(mesh.pos.x, 2);
		mesh.pos.y = round_float(mesh.pos.y, 2);
		mesh.pos.z = round_float(mesh.pos.z, 2);
		t_engine_add_mesh(engine, mesh);
	}
	else if (get_mouse_state(engine->user_engine->mouse, MOUSE_RIGHT) == BOOL_TRUE)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			t_mesh_set_visibility(target, BOOL_FALSE);
			target->no_hitbox = 1;
		}
	}
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_L]) == 1 && l_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			printf("here\n");
			if (target->no_hitbox == 0)
				target->no_hitbox = 1;
			else
				target->no_hitbox = 0;
			l_press = 1;
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_L]) == 0)
		l_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_I]) == 1 && i_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			printf("here\n");
			if (target->is_visible == 0)
				target->is_visible = 1;
			else
				target->is_visible = 0;
			i_press = 1;
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_I]) == 0)
		i_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_PERIOD]) == 1)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
			t_mesh_rotate(target, create_t_vector4(0.0, 10.0, 0.0));
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_COMMA]) == 1)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
			t_mesh_rotate(target, create_t_vector4(0.0, -10.0, 0.0));
	}
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_LEFT]) == 1 && left_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			left_press = 1;
			t_mesh_move(target, create_t_vector4(0.0, 0.0, 0.1));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_LEFT]) == 0)
		left_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_RIGHT]) == 1 && right_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			right_press = 1;
			t_mesh_move(target, create_t_vector4(0.0, 0.0, -0.1));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_RIGHT]) == 0)
		right_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_UP]) == 1 && up_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			up_press = 1;
			t_mesh_move(target, create_t_vector4(0.1, 0.0, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_UP]) == 0)
		up_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_DOWN]) == 1 && down_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			down_press = 1;
			t_mesh_move(target, create_t_vector4(-0.1, 0.0, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_DOWN]) == 0)
		down_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_EQUALS]) == 1 && equals_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			equals_press = 1;
			t_mesh_move(target, create_t_vector4(0.0, 0.1, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_EQUALS]) == 0)
		equals_press = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_MINUS]) == 1 && minus_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL)
		{
			minus_press = 1;
			t_mesh_move(target, create_t_vector4(0.0, -0.1, 0.0));
		}
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_MINUS]) == 0)
		minus_press = 0;
}
