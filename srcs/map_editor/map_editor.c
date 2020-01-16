#include "unknow_project.h"

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
		draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-1.0, 1.0), create_vec2(2.0, -2.0)), gui->menu[12]);
		t_view_port_clear_buffers(main_camera->view_port);
		draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-1.1, 0.86 - (0.079 * key->i)), create_vec2(0.7, 0.1)), gui->menu[13]);
	}
}

void		player_editing(t_camera *main_camera, t_engine *engine, t_gui *gui)
{
	static int	b_press = 0;
	static int	print = 0;

	if (print == 1 && engine->playing == 10)
		print = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_B]) == 1 && b_press == 0)
	{
		print = 1;
		b_press = 1;
	}
	else if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_B]) == 0)
		b_press = 0;
	if (print == 1)
		engine->playing = 11;
}

void		print_set_player(t_camera *main_camera, t_gui *gui, t_engine *engine)
{
	t_player	*player;

	if (engine->user_engine->player->hitbox.name == NULL)
		return ;
	player = engine->user_engine->player;
	if (ft_strcmp(player->hitbox.name, "Player") == 0)
	{
		t_view_port_clear_buffers(main_camera->view_port);
		if (player->hitbox.kinetic == 100.0f)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.08, 0.55), create_vec2(0.7, 0.1)), gui->menu[13]);
		else if (player->hitbox.kinetic == 20.0f)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.61, 0.55), create_vec2(0.7, 0.1)), gui->menu[13]);
		if (player->hp == 100)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.0, 0.11), create_vec2(0.4, 0.1)), gui->menu[13]);
		else if (player->hp == 50)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.38, 0.11), create_vec2(0.4, 0.1)), gui->menu[13]);
		if (player->armor == 100)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.125, -0.33), create_vec2(0.4, 0.1)), gui->menu[13]);
		else if (player->armor == 50)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.145, -0.33), create_vec2(0.3, 0.1)), gui->menu[13]);
		else if (player->armor == 0)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.41, -0.33), create_vec2(0.2, 0.1)), gui->menu[13]);

	}
}

void		print_set_weapon(t_camera *main_camera, t_gui *gui, t_engine *engine)
{
	t_player	*player;

	if (engine->user_engine->player->hitbox.name == NULL)
		return ;
	player = engine->user_engine->player;
	if (ft_strcmp(player->hitbox.name, "Player") == 0)
	{
		t_view_port_clear_buffers(main_camera->view_port);
		if (player->weapons[1].total_ammo == -1)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.023, 0.65), create_vec2(0.18, 0.1)), gui->menu[13]);
		else
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.151, 0.65), create_vec2(0.15, 0.1)), gui->menu[13]);
		if (player->weapons[2].total_ammo == -1)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.023, -0.19), create_vec2(0.18, 0.1)), gui->menu[13]);
		else
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.151, -0.19), create_vec2(0.15, 0.1)), gui->menu[13]);
		if (player->weapons[3].total_ammo == -1)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.023, 0.23), create_vec2(0.18, 0.1)), gui->menu[13]);
		else
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.151, 0.23), create_vec2(0.15, 0.1)), gui->menu[13]);
		if (player->weapons[4].total_ammo == -1)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.023, -0.61), create_vec2(0.18, 0.1)), gui->menu[13]);
		else
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.151, -0.61), create_vec2(0.15, 0.1)), gui->menu[13]);
		if (player->weapons[1].total_ammo == 0 && player->weapons[1].ammo == 0)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.04, 0.52), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[1].total_ammo == 0 && player->weapons[1].ammo == 30)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.1, 0.52), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[1].total_ammo == 30 && player->weapons[1].ammo == 30)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.16, 0.52), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[1].total_ammo == 60 && player->weapons[1].ammo == 30)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.22, 0.52), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[1].total_ammo == 90 && player->weapons[1].ammo == 30)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.285, 0.52), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[1].total_ammo == 120 && player->weapons[1].ammo == 30)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.348, 0.52), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[3].total_ammo == 0 && player->weapons[3].ammo == 0)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.035, 0.095), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[3].total_ammo == 0 && player->weapons[3].ammo == 8)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.095, 0.095), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[3].total_ammo == 8 && player->weapons[3].ammo == 8)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.155, 0.095), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[3].total_ammo == 16 && player->weapons[3].ammo == 8)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.215, 0.095), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[3].total_ammo == 24 && player->weapons[3].ammo == 8)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.28, 0.095), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[3].total_ammo == 32 && player->weapons[3].ammo == 8)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.343, 0.095), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[2].total_ammo == 0 && player->weapons[2].ammo == 0)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.042, -0.33), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[2].total_ammo == 0 && player->weapons[2].ammo == 10)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.105, -0.33), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[2].total_ammo == 10 && player->weapons[2].ammo == 10)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.162, -0.33), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[2].total_ammo == 20 && player->weapons[2].ammo == 10)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.222, -0.33), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[2].total_ammo == 30 && player->weapons[2].ammo == 10)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.287, -0.33), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[2].total_ammo == 40 && player->weapons[2].ammo == 10)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.35, -0.33), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[4].total_ammo == 0 && player->weapons[4].ammo == 0)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.042, -0.755), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[4].total_ammo == 0 && player->weapons[4].ammo == 1)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.105, -0.755), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[4].total_ammo == 1 && player->weapons[4].ammo == 1)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.162, -0.755), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[4].total_ammo == 2 && player->weapons[4].ammo == 1)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.222, -0.755), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[4].total_ammo == 3 && player->weapons[4].ammo == 1)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.287, -0.755), create_vec2(0.08, 0.1)), gui->menu[13]);
		if (player->weapons[4].total_ammo == 4 && player->weapons[4].ammo == 1)
			draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.35, -0.755), create_vec2(0.08, 0.1)), gui->menu[13]);
	}
}

void		check_mesh_player(t_engine *engine, t_mesh mesh, t_camera *main_camera)
{
	int			i;
	t_mesh		*target;

	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(target->name, "Player") == 0)
		{
			target->is_visible = 0;
			target->no_hitbox = 1;
		}
		i++;
	}
	engine->user_engine->player->hitbox = mesh;
}

void		map_editor(t_camera *main_camera, t_gui *gui, t_engine *engine, t_mesh mesh_editing)
{
	t_mesh			*target;
	t_mesh			mesh;
	t_vector4		normal;
	static t_color	*color_armor = NULL;
	static int		click = 0;
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
	draw_hud_rect(main_camera->view_port, create_t_rectangle(create_vec2(0.0, 0.0), create_vec2(0.005, 0.01)), color_armor);
	print_info_editing(main_camera, engine->user_engine->keyboard, gui);
	player_editing(main_camera, engine, gui);
	if (t_mouse_state(engine->user_engine->mouse) == 2)
	{
		if (mesh_editing.primitive == 1 || mesh_editing.primitive == -1)
		{
			if (mesh_editing.primitive == -1)
			{
				mesh = create_primitive_cube(mesh_editing.pos, mesh_editing.size, mesh_editing.texture->path, mesh_editing.kinetic);
				mesh.primitive = -1;
			}
			else
				mesh = create_primitive_cube(mesh_editing.pos, mesh_editing.size, mesh_editing.texture->path, mesh_editing.kinetic);
		}
		else if (mesh_editing.primitive == 0)
			mesh = create_primitive_plane(mesh_editing.pos, mesh_editing.size, mesh_editing.texture->path, mesh_editing.kinetic);
		t_mesh_set_color(&mesh, create_t_color(1.0, 1.0, 1.0, 1.0));
		t_mesh_set_name(&mesh, mesh_editing.name);
		mesh.hp = mesh_editing.hp;
		t_mesh_rotate(&mesh, mesh_editing.rotation);
		cast_mesh(engine, &mesh);
		mesh.pos.x = round_float(mesh.pos.x, 2);
		mesh.pos.y = round_float(mesh.pos.y, 2);
		mesh.pos.z = round_float(mesh.pos.z, 2);
		if (ft_strcmp(mesh.name, "Player") == 0)
			check_mesh_player(engine, mesh, main_camera);
		t_engine_add_mesh(engine, mesh);
	}
	else if (get_mouse_state(engine->user_engine->mouse, MOUSE_RIGHT) == BOOL_TRUE && click == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL && ft_strcmp(target->name, "Player") != 0)
		{
			t_mesh_set_visibility(target, BOOL_FALSE);
			target->no_hitbox = 1;
		}
		click = 1;
	}
	else if (get_mouse_state(engine->user_engine->mouse, MOUSE_RIGHT) == BOOL_FALSE && click == 1)
		click = 0;
	if (get_key_state(engine->user_engine->keyboard, engine->user_engine->keyboard->key[SDL_SCANCODE_L]) == 1 && l_press == 0)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target != NULL && ft_strcmp(target->name, "Player") != 0)
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
		if (target != NULL && ft_strcmp(target->name, "Player") != 0)
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
