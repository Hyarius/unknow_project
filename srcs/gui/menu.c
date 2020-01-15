# include "unknow_project.h"

void            t_user_engine_handle_menu(t_camera *main_camera, t_gui *gui, t_engine *engine, t_window *win)
{
    if (engine->playing == 2)
        main_menu(main_camera, gui, engine, &engine->playing);
    else if (engine->playing == 3)
        settings_menu(main_camera, gui, engine, &engine->playing);
    else if (engine->playing == 4)
        controls_menu(main_camera, gui, engine, &engine->playing);
    else if (engine->playing == 5)
        credits_menu(main_camera, gui, engine, &engine->playing);
	else if (engine->playing == 6)
		play_menu(main_camera, engine, &engine->playing);
	else if (engine->playing == 11)
		set_player_editing(main_camera, gui, engine, &engine->playing);
	else if (engine->playing == 12)
		set_weapon_editing(main_camera, gui, engine, &engine->playing);
	else if (engine->playing == 13 || engine->playing == -3)
		save_pause(main_camera, gui, engine, win);
    else if (engine->playing == -1)
        pause_menu(main_camera, gui, engine, win);
    else if (engine->playing == -2)
        settings_pause_menu(main_camera, gui, engine, &engine->playing);
}

void			play_menu(t_camera *main_camera, t_engine *engine, int *play)
{
	t_mouse			*mouse;
	t_keyboard		*keyboard;
	t_vec2_int	pos;
	char			*path;

	keyboard = engine->user_engine->keyboard;
	mouse = engine->user_engine->mouse;
	get_t_mouse_info(mouse);
	pos = create_vec2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
	if (pos.x > 37 && pos.x < 61 && t_mouse_state(mouse) == 2)
	{
		Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		if (pos.y > 61 && pos.y < 69)
		{
			*play = 10;
			path = ft_strdup("ressources/map/save4.map");
		}
		if (pos.y > 71 && pos.y < 79)
			*play = 2;
	}
	if (pos.x > 6 && pos.x < 24 && t_mouse_state(mouse) == 2)
	{
		Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		if (pos.y > 29 && pos.y < 37)
		{
			*play = 1;
			path = ft_strdup("ressources/map/fichier_map.map");
		}
		if (pos.y > 39 && pos.y < 47)
		{
			*play = 1;
			path = ft_strdup("ressources/map/fichier_map2.map");
		}
	}
	if (pos.x > 82 && pos.x < 95 && t_mouse_state(mouse) == 2)
	{
		Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		if (pos.y > 29 && pos.y < 37)
		{
			*play = 1;
			path = ft_strdup("ressources/map/save1.map");
		}
		if (pos.y > 39 && pos.y < 47)
		{
			*play = 1;
			path = ft_strdup("ressources/map/save2.map");
		}
		if (pos.y > 49 && pos.y < 57)
		{
			*play = 1;
			path = ft_strdup("ressources/map/save3.map");
		}
		if (pos.y > 59 && pos.y < 67)
		{
			*play = 1;
			path = ft_strdup("ressources/map/save4.map");
		}
		if (pos.y > 69 && pos.y < 77)
		{
			*play = 1;
			path = ft_strdup("ressources/map/save5.map");
		}
	}
	if (*play == 10 || *play == 1)
	{
		load_map(main_camera, engine, path);
		if (*play == 1)
			link_camera_to_mesh(engine, 0, t_engine_get_mesh(engine, 0));
		free(path);
	}
}

void			main_menu(t_camera *main_camera, t_gui *gui, t_engine *engine, int *play)
{
	t_mouse *mouse = engine->user_engine->mouse;
	t_keyboard *keyboard = engine->user_engine->keyboard;
    t_vec2_int pos;

	get_t_mouse_info(mouse);
    pos = create_vec2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
    if (pos.x > 43 && pos.x < 56)
    {
		if (t_mouse_state(mouse) == 2)
        {
			if (pos.y > 56 && pos.y < 61)
		        *play = 6;
			else if (pos.y > 63 && pos.y < 68)
				*play = 3;
			else if (pos.y > 70 && pos.y < 75)
				*play = 5;
			else if (pos.y > 76 && pos.y < 82)
				*play = 0;
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		}
    }
    else
        engine->user_engine->mouse->clicked_left = BOOL_FALSE;
}

void			pause_menu(t_camera *main_camera, t_gui *gui, t_engine *engine, t_window *win)
{
	t_mouse			*mouse = engine->user_engine->mouse;
	t_keyboard		*keyboard = engine->user_engine->keyboard;
    t_vec2_int	pos;

	get_t_mouse_info(mouse);
    pos = create_vec2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
    if (pos.x > 39 && pos.x < 61)
    {
		if (t_mouse_state(mouse) == 2)
		{
			if (pos.y > 26 && pos.y < 32)
				engine->playing = 1;
			else if (pos.y > 36 && pos.y < 41)
				engine->playing = -2;
			else if (pos.y > 45 && pos.y < 50)
				engine->playing = -3;
			else if (pos.y > 54 && pos.y < 59)
			{
				free_t_mesh_list(engine->physic_engine->mesh_list);
				engine->physic_engine->mesh_list = initialize_t_mesh_list();
				engine->playing = 2;
			}
			else if (pos.y > 64 && pos.y < 70)
				engine->playing = 0;
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		}
    }
    else
        engine->user_engine->mouse->clicked_left = BOOL_FALSE;
}

void			settings_pause_menu(t_camera *main_camera, t_gui *gui, t_engine *engine, int *play)
{
	t_mouse *mouse = engine->user_engine->mouse;
	t_keyboard *keyboard = engine->user_engine->keyboard;
    t_vec2_int pos;

	get_t_mouse_info(mouse);
    pos = create_vec2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
    if (pos.x > 34 && pos.x < 64)
    {
		if (t_mouse_state(mouse) == 2)
		{
			if (pos.y > 26 && pos.y < 32)
				printf("Mute\n");
			if (pos.y > 42 && pos.y < 46)
				printf("Sens +\n");
			if (pos.y > 55 && pos.y < 60)
				printf("Sens -\n");
			if (pos.y > 69 && pos.y < 75)
				*play = -1;
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		}
    }
    else
        engine->user_engine->mouse->clicked_left = BOOL_FALSE;
}

void        settings_menu(t_camera *main_camera, t_gui *gui, t_engine *engine, int *play)
{

    t_mouse *mouse = engine->user_engine->mouse;
    t_keyboard *keyboard = engine->user_engine->keyboard;
    t_vec2_int pos;

	get_t_mouse_info(mouse);
    pos = create_vec2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
    t_view_port_clear_buffers(main_camera->view_port);
    draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.7, 0.4), create_vec2(-0.6, -0.94)), gui->menu[gui->idx]);
    if (pos.x > 16 && pos.x < 29)
    {
		if (t_mouse_state(mouse) == 2)
		{
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
			if (pos.y > 23 && pos.y < 26)
				// Mix_Volume
			if (pos.y > 27 && pos.y < 30)
				printf("Mute music\n");
			if (pos.y > 32 && pos.y < 35)
				printf("Mute sounds\n");
			t_view_port_clear_buffers(main_camera->view_port);
			if (pos.y > 44 && pos.y < 47)
			{
				draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.7, 0.4), create_vec2(-0.6, -0.94)), gui->menu[8]);
					gui->idx = 8;
			}
			if (pos.y > 48 && pos.y < 52)
			{
				draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.7, 0.4), create_vec2(-0.6, -0.94)), gui->menu[9]);
					gui->idx = 9;
			}
			if (pos.y > 53 && pos.y < 56)
			{
				draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.7, 0.4), create_vec2(-0.6, -0.94)), gui->menu[10]);
					gui->idx = 10;
			}
			if (pos.y > 72 && pos.y < 76)
				*play = 4;
		}
    }
    else if (pos.x > 43 && pos.x < 56)
    {
        if (t_mouse_state(mouse) == 2)
	    {
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
			*play = 2;
		}
    }
    else
        engine->user_engine->mouse->clicked_left = BOOL_FALSE;
}

void        controls_menu(t_camera *main_camera, t_gui *gui, t_engine *engine, int *play)
{
    t_mouse *mouse = engine->user_engine->mouse;
    t_keyboard *keyboard = engine->user_engine->keyboard;
    t_vec2_int pos;

	get_t_mouse_info(mouse);
    pos = create_vec2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
    if (gui->key_press != 2)
    {
		if (t_mouse_state(mouse) == 2)
        {
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
			if (pos.x > 23 && pos.x < 44)
			{
				if (pos.y > 28 && pos.y < 32)
					gui->key_change = SDL_SCANCODE_W;
				else if (pos.y > 39 && pos.y < 44)
					gui->key_change = SDL_SCANCODE_S;
				else if (pos.y > 51 && pos.y < 57)
					gui->key_change = SDL_SCANCODE_A;
				else if (pos.y > 64 && pos.y < 69)
					gui->key_change = SDL_SCANCODE_D;
				else
					engine->user_engine->mouse->clicked_left = BOOL_FALSE;
				gui->key_press = 2;
			}
			if (pos.x > 64 && pos.x < 76)
			{
				if (pos.y > 28 && pos.y < 32)
					gui->key_change = SDL_SCANCODE_LCTRL;
				else if (pos.y > 39 && pos.y < 44)
					gui->key_change = SDL_SCANCODE_SPACE;
				else if (pos.y > 51 && pos.y < 57)
					gui->key_change = SDL_SCANCODE_LSHIFT;
				else if (pos.y > 64 && pos.y < 69)
					gui->key_change = SDL_SCANCODE_F;
				else
					engine->user_engine->mouse->clicked_left = BOOL_FALSE;
				gui->key_press = 2;
			}
			if (pos.x > 43 && pos.x < 56)
				if (pos.y > 82 && pos.y < 86)
						*play = 3;
		}
    }
    else
		set_controls(main_camera, gui, engine->user_engine, gui->key_change);
}

void        sens_menu(t_camera *main_camera, t_gui *gui, t_engine *engine, int *play)
{
    int i;
    t_mouse *mouse = engine->user_engine->mouse;
    t_keyboard *keyboard = engine->user_engine->keyboard;
	get_t_mouse_info(mouse);
	if (t_mouse_state(mouse) == 2)
		Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
    if (mouse->pos.x >= 420 && mouse->pos.x <= 620 && mouse->pos.y >= 635 && mouse->pos.y <= 835)
    {
        i = 1;
        sens_bis(main_camera, gui, i);
        if (t_mouse_state(mouse) == 2)
            gui->sens = 1;
    }
    else if (mouse->pos.x >= 620 && mouse->pos.x <= 820 && mouse->pos.y >= 635 && mouse->pos.y <= 835)
    {
        i = 2;
        sens_bis(main_camera, gui, i);
        if (t_mouse_state(mouse) == 2)
            gui->sens = 2;
    }
    else if (mouse->pos.x >= 820 && mouse->pos.x <= 1020 && mouse->pos.y >= 635 && mouse->pos.y <= 835)
    {
        i = 3;
        sens_bis(main_camera, gui, i);
        if (t_mouse_state(mouse) == 2)
            gui->sens = 3;
    }
    else if (mouse->pos.x >= 1020 && mouse->pos.x <= 1220 && mouse->pos.y >= 635 && mouse->pos.y <= 835)
    {
        i = 4;
        sens_bis(main_camera, gui, i);
        if (t_mouse_state(mouse) == 2)
            gui->sens = 4;
    }
    else if (mouse->pos.x >= 1220 && mouse->pos.x <= 1420 && mouse->pos.y >= 635 && mouse->pos.y <= 835)
    {
        i = 5;
        sens_bis(main_camera, gui, i);
        if (t_mouse_state(mouse) == 2)
            gui->sens = 5;
    }
    else if (mouse->pos.x >= 790 && mouse->pos.x <= 1050 && mouse->pos.y >= 1090 && mouse->pos.y <= 1160)
    {
        draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.14, -0.83), create_vec2(0.05, 0.08)), gui->menu[7]);
        draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.06, -0.88), create_vec2(0.05, 0.08)), gui->menu[7]);
        draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.11, -0.92), create_vec2(0.05, 0.08)), gui->menu[7]);
        draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(0.02, -0.85), create_vec2(0.05, 0.08)), gui->menu[7]);
        sens_bis(main_camera, gui, gui->sens);
        if (t_mouse_state(mouse) == 2)
            *play = 3;
    }
    else
    {
        sens_bis(main_camera, gui, gui->sens);
        engine->user_engine->mouse->clicked_left = BOOL_FALSE;
    }
}

void    sens_bis(t_camera *main_camera, t_gui *gui, int sens)
{
    int i;

    i = 0;
    while (i < sens)
    {
        draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-0.5825 + i * 0.2175, -0.43), create_vec2(0.3, 0.5)), gui->menu[13]);
        i++;
    }
}

void    set_controls(t_camera *main_camera, t_gui *gui, t_user_engine *user_engine, int key)
{
    int scan_code;
    draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_vec2(-1, 1), create_vec2(2, -2)), gui->menu[11]);
    scan_code = user_engine->event.key.keysym.scancode;
    if (scan_code >= 4 && scan_code <= 231)
    {
        if (get_key_state(user_engine->keyboard, scan_code) == 1)
        {
            user_engine->keyboard->key[key] = scan_code;
            reset_key_state(user_engine->keyboard, scan_code);
            gui->key_press = 0;
        }
    }
}

void			credits_menu(t_camera *main_camera, t_gui *gui, t_engine *engine, int *play)
{
	t_mouse *mouse = engine->user_engine->mouse;
	t_keyboard *keyboard = engine->user_engine->keyboard;
    t_vec2_int pos;

	get_t_mouse_info(mouse);
    pos = create_vec2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
    if (pos.x > 43 && pos.x < 56)
    {
        if (pos.y > 82 && pos.y < 86)
        	if (t_mouse_state(mouse) == 2)
		    {
				Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
				*play = 2;
			}
    }
    else
        engine->user_engine->mouse->clicked_left = BOOL_FALSE;
}

void		set_player_editing(t_camera *main_camera, t_gui *gui, t_engine *engine, int *play)
{
	t_mouse			*mouse = engine->user_engine->mouse;
	t_keyboard		*keyboard = engine->user_engine->keyboard;
	t_player		*player;
    t_vec2_int	pos;

	player = engine->user_engine->player;
	get_t_mouse_info(mouse);
    pos = create_vec2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
	if (t_mouse_state(mouse) == 2)
	{
		if (ft_strcmp(player->hitbox.name, "Player") == 0)
		{
			if (pos.y > 12 && pos.y < 21)
			{
				if (pos.x > 27 && pos.x < 46)
					player->hitbox.kinetic = 20.0;
				if (pos.x > 54 && pos.x < 72)
					player->hitbox.kinetic = 100.0;
			}
			if (pos.y > 34 && pos.y < 43)
			{
				if (pos.x > 54 && pos.x < 65)
					player->hp = 100;
				if (pos.x > 37 && pos.x < 45)
					player->hp = 50;
			}
			if (pos.y > 56 && pos.y < 65)
			{
				if (pos.x > 61 && pos.x < 71)
					player->armor = 100;
				if (pos.x > 46 && pos.x < 53)
					player->armor = 50;
				if (pos.x > 32 && pos.x < 37)
					player->armor = 0;
			}
			if (pos.y > 67 && pos.y < 76 && pos.x > 30 && pos.x < 70)
				*play = 12;
			if (pos.y > 78 && pos.y < 87 && pos.x > 37 && pos.x < 62)
				*play = 13;
			if (pos.y > 90 && pos.y < 99 && pos.x > 39 && pos.x < 60)
				*play = 10;
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		}
	}
}

void		set_weapon_editing(t_camera *main_camera, t_gui *gui, t_engine *engine, int *play)
{
	t_mouse			*mouse = engine->user_engine->mouse;
	t_keyboard		*keyboard = engine->user_engine->keyboard;
	t_player		*player;
    t_vec2_int	pos;

	player = engine->user_engine->player;
	get_t_mouse_info(mouse);
	pos = create_vec2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
	if (t_mouse_state(mouse) == 2)
	{
		if (pos.y > 11 && pos.y < 15)
		{
			if (pos.x > 44 && pos.x < 48)
				player->weapons[1].total_ammo = 0;
			if (pos.x > 50 && pos.x < 55)
				player->weapons[1].total_ammo = -1;
		}
		if (pos.y > 18 && pos.y < 22)
		{
			if (pos.x >= 52 && pos.x <= 54)
			{
				player->weapons[1].ammo = 0;
				player->weapons[1].total_ammo = 0;
			}
			if (pos.x >= 55 && pos.x <= 57)
			{
				player->weapons[1].ammo = 30;
				player->weapons[1].total_ammo = 0;
			}
			if (pos.x >= 58 && pos.x <= 60)
			{
				player->weapons[1].ammo = 30;
				player->weapons[1].total_ammo = 30;
			}
			if (pos.x >= 61 && pos.x <= 63)
			{
				player->weapons[1].ammo = 30;
				player->weapons[1].total_ammo = 60;
			}
			if (pos.x >= 64 && pos.x <= 66)
			{
				player->weapons[1].ammo = 30;
				player->weapons[1].total_ammo = 90;
			}
			if (pos.x >= 67 && pos.x <= 69)
			{
				player->weapons[1].ammo = 30;
				player->weapons[1].total_ammo = 120;
			}
		}
		if (pos.y > 32 && pos.y < 36)
		{
			if (pos.x > 44 && pos.x < 48)
				player->weapons[3].total_ammo = 0;
			if (pos.x > 50 && pos.x < 55)
				player->weapons[3].total_ammo = -1;
		}
		if (pos.y > 39 && pos.y < 43)
		{
			if (pos.x >= 52 && pos.x <= 54)
			{
				player->weapons[3].ammo = 0;
				player->weapons[3].total_ammo = 0;
			}
			if (pos.x >= 55 && pos.x <= 57)
			{
				player->weapons[3].ammo = 8;
				player->weapons[3].total_ammo = 0;
			}
			if (pos.x >= 58 && pos.x <= 60)
			{
				player->weapons[3].ammo = 8;
				player->weapons[3].total_ammo = 8;
			}
			if (pos.x >= 61 && pos.x <= 63)
			{
				player->weapons[3].ammo = 8;
				player->weapons[3].total_ammo = 16;
			}
			if (pos.x >= 64 && pos.x <= 66)
			{
				player->weapons[3].ammo = 8;
				player->weapons[3].total_ammo = 24;
			}
			if (pos.x >= 67 && pos.x <= 69)
			{
				player->weapons[3].ammo = 8;
				player->weapons[3].total_ammo = 32;
			}
		}
		if (pos.y > 53 && pos.y < 57)
		{
			if (pos.x > 44 && pos.x < 48)
				player->weapons[2].total_ammo = 0;
			if (pos.x > 50 && pos.x < 55)
				player->weapons[2].total_ammo = -1;
		}
		if (pos.y > 60 && pos.y < 64)
		{
			if (pos.x >= 52 && pos.x <= 54)
			{
				player->weapons[2].ammo = 0;
				player->weapons[2].total_ammo = 0;
			}
			if (pos.x >= 55 && pos.x <= 57)
			{
				player->weapons[2].ammo = 10;
				player->weapons[2].total_ammo = 0;
			}
			if (pos.x >= 58 && pos.x <= 60)
			{
				player->weapons[2].ammo = 10;
				player->weapons[2].total_ammo = 10;
			}
			if (pos.x >= 61 && pos.x <= 63)
			{
				player->weapons[2].ammo = 10;
				player->weapons[2].total_ammo = 20;
			}
			if (pos.x >= 64 && pos.x <= 66)
			{
				player->weapons[2].ammo = 10;
				player->weapons[2].total_ammo = 30;
			}
			if (pos.x >= 67 && pos.x <= 69)
			{
				player->weapons[2].ammo = 10;
				player->weapons[2].total_ammo = 40;
			}
		}
		if (pos.y > 74 && pos.y < 78)
		{
			if (pos.x > 44 && pos.x < 48)
				player->weapons[4].total_ammo = 0;
			if (pos.x > 50 && pos.x < 55)
				player->weapons[4].total_ammo = -1;
		}
		if (pos.y > 81 && pos.y < 85)
		{
			if (pos.x >= 52 && pos.x <= 54)
			{
				player->weapons[4].ammo = 0;
				player->weapons[4].total_ammo = 0;
			}
			if (pos.x >= 55 && pos.x <= 57)
			{
				player->weapons[4].ammo = 1;
				player->weapons[4].total_ammo = 0;
			}
			if (pos.x >= 58 && pos.x <= 60)
			{
				player->weapons[4].ammo = 1;
				player->weapons[4].total_ammo = 1;
			}
			if (pos.x >= 61 && pos.x <= 63)
			{
				player->weapons[4].ammo = 1;
				player->weapons[4].total_ammo = 2;
			}
			if (pos.x >= 64 && pos.x <= 66)
			{
				player->weapons[4].ammo = 1;
				player->weapons[4].total_ammo = 3;
			}
			if (pos.x >= 67 && pos.x <= 69)
			{
				player->weapons[4].ammo = 1;
				player->weapons[4].total_ammo = 4;
			}
		}
		if (pos.y > 91 && pos.y < 98 && pos.x > 40 && pos.x < 61)
			*play = 11;
		Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
	}
}

void		save_pause(t_camera *main_camera, t_gui *gui, t_engine *engine, t_window *win)
{
	t_mouse			*mouse = engine->user_engine->mouse;
	t_keyboard		*keyboard = engine->user_engine->keyboard;
	t_vec2_int	pos;

	get_t_mouse_info(mouse);
	pos = create_vec2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
	if (pos.x > 40 && pos.x < 61)
	{
		if (t_mouse_state(mouse) == 2)
		{
			if (pos.y > 10 && pos.y < 18)
			{
				save_map(engine, 1);
				if (engine->playing == 13)
					engine->playing = 2;
				if (engine->playing == -3)
					engine->playing = -1;
			}
			if (pos.y > 26 && pos.y < 34)
			{
				save_map(engine, 2);
				if (engine->playing == 13)
					engine->playing = 2;
				if (engine->playing == -3)
					engine->playing = -1;
			}
			if (pos.y > 41 && pos.y < 49)
			{
				save_map(engine, 3);
				if (engine->playing == 13)
					engine->playing = 2;
				if (engine->playing == -3)
					engine->playing = -1;
			}
			if (pos.y > 57 && pos.y < 65)
			{
				save_map(engine, 4);
				if (engine->playing == 13)
					engine->playing = 2;
				if (engine->playing == -3)
					engine->playing = -1;
			}
			if (pos.y > 72 && pos.y < 80)
			{
				save_map(engine, 5);
				if (engine->playing == 13)
					engine->playing = 2;
				if (engine->playing == -3)
					engine->playing = -1;
			}
			if (pos.y > 91 && pos.y < 98)
			{
				if (engine->playing == 13)
					engine->playing = 11;
				if (engine->playing == -3)
					engine->playing = -1;
			}
			Mix_PlayChannel(-1, engine->sound_engine->sounds[0], 0);
		}
	}
	// if (engine->playing == 2)
	// {
	// 	free_t_physic_engine(engine->physic_engine);
	// 	free_t_visual_engine(engine->visual_engine);
	// 	engine->physic_engine = initialize_t_physic_engine();
	// 	engine->visual_engine = initialize_t_visual_engine(win);
	// }
}