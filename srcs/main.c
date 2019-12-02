#include "unknow_project.h"

int main(int argc, char **argv)
{
	TTF_Font    *police;
	SDL_Surface *font = NULL;
	SDL_Color color = {0, 0, 0};

	if (argc != 1)
		error_exit(-1, "Bad argument");

	Mix_Init(MIX_INIT_OGG);
	// printf("%s\n", Mix_GetError());
	start_sdl(); //initialisation de la SDL

	t_window *win;
	win = initialize_t_window(argv[0], WIN_X, WIN_Y);	//creation et initialisation de la window

	t_texture *texture2[4];
	texture2[0] = png_load("ressources/assets/textures/pistol_ammo.png");
	texture2[1] = png_load("ressources/assets/textures/ar_ammo.png");
	texture2[2] = png_load("ressources/assets/textures/rifle_ammo.png");
	texture2[3] = png_load("ressources/assets/textures/shotgun_ammo.png");
	t_texture *texture = png_load("ressources/assets/textures/cube_test.png");
	t_texture *skybox = png_load("ressources/assets/textures/skybox.png");

	t_engine	*engine;
	t_gui		*gui;

	engine = initialize_t_engine(win);
	gui = initialize_t_gui(0.10, 30);

	load_menu(gui);
	TTF_Init();
	set_t_gui_texte(gui);
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 1, 1024) == -1)
		printf("%s\n", Mix_GetError());

	t_mesh		mesh;
	t_camera	*main_camera;
	Mix_Music	*musique;

	musique = Mix_LoadMUS("ressources/assets/sound/mega_man_test.ogg");
	main_camera = t_camera_list_get(engine->visual_engine->camera_list, 0);
	t_engine_place_camera(engine, 0, create_t_vector4(5.0, 5.0, 0.0));
	t_camera_look_at_point(main_camera, create_t_vector4(0, 0, 0));
	t_engine_add_camera(engine, create_t_camera(win, create_t_vector4(0.0, 0.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
	resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(300, 240));
	move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(WIN_X - 300, 0));
	t_engine_add_camera(engine, create_t_camera(win, create_t_vector4(0.0, 0.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
	resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(300, 240));
	move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(300, 0));
	t_player *player;
	int		fd;

	player = initialize_t_player(main_camera);
	fd = open("ressources/map/fichier_map.map", O_RDONLY);
	// fd = open("ressources/map/test_gravity.map", O_RDONLY);
	// fd = open("ressources/map/save1.map", O_RDONLY);
	// fd = open("ressources/map/editing_map1.map", O_RDONLY);
	if (fd < 0)
		error_exit(-7000, "imposible fd");
	t_mesh_list *meshs = read_map_file(fd, player);
	t_item_list *item_list = load_items(meshs);
	close(fd);
	engine->user_engine->player = player;
	if (player->hitbox.name != NULL)
	{
		t_engine_add_mesh(engine, engine->user_engine->player->hitbox);
	}


	int i = 0;
	int	j = 0;
	int k = 0;
	while (i < meshs->size)
	{
		if (t_mesh_list_at(meshs, i).collectible == 1)
		{
			t_engine_add_item(engine, t_item_list_at(item_list, j));
			j++;
		}
		if (t_mesh_list_at(meshs, i).texture != NULL)
			printf("%s\n", t_mesh_list_at(meshs, i).texture->path);
		t_engine_add_mesh(engine, t_mesh_list_at(meshs, i));
		if (ft_strcmp(t_mesh_list_at(meshs, i).name, "Enemy") == 0)
		{
			if (k != 0)
			{
				t_engine_add_camera(engine, create_t_camera(win, create_t_vector4(0.0, 0.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
				resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2 + k)->view_port, create_t_vector2_int(1, 1));
				move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2 + k)->view_port, create_t_vector2_int(0, 0));
			}
			link_t_camera_to_t_mesh(engine, 2 + k, t_engine_get_mesh(engine, i));
			k++;
		}
		i++;
	}
	engine->playing = 2;

	t_rectangle rec = create_t_rectangle(create_t_vector2(-1, 1), create_t_vector2(2, -2));

	t_mesh	mesh_editing;
	char	**path;
	path = load_path_texture();
	mesh_editing = create_mesh_editing(0, engine->user_engine->player->camera->pos, path[engine->user_engine->keyboard->i]);
	mesh = create_primitive_skybox(main_camera->pos, create_t_vector4(1.0, 1.0, 1.0), skybox);
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	Mix_PlayMusic(musique, -1);
	while (engine->playing != 0)
	{
		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f));
		t_engine_prepare_camera(engine);
		if (engine->playing != 1 || engine->playing != 10)
		{
			SDL_ShowCursor(SDL_ENABLE);
		}
		if (engine->playing <= -1)
		{
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
   			t_view_port_clear_buffers(main_camera->view_port);
    		draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[4]);
		}
		if (engine->playing <= -2)
		{
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
   			t_view_port_clear_buffers(main_camera->view_port);
    		draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[5]);
		}
		if (engine->playing == 2)
		{
			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[0]);
		}
		if (engine->playing == 3)
		{
			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[1]);
		}
		if (engine->playing == 4)
		{
			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[2]);
		}
		if (engine->playing == 5)
		{
			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[3]);
		}

		else if (engine->playing == 1)
		{
			mesh.pos = main_camera->pos;

			draw_skybox(win, main_camera, &mesh); // skybox
			t_engine_render_camera(engine);
			SDL_ShowCursor(SDL_DISABLE);
			t_engine_apply_physic(engine);

			t_engine_handle_camera(engine, win);
			t_engine_prepare_camera(engine);

			t_engine_draw_mesh(engine);

			t_engine_render_camera(engine);
			player_action(main_camera, engine->user_engine->keyboard, engine);
			enemy_look(engine);
			// enemy_shoot(engine);
			drawing_front_hp(main_camera, engine);
			drawing_front_mun(main_camera, gui, texture2, engine->user_engine->player);
			draw_minimap(main_camera, engine, win);
			print_info_bar(main_camera, engine->user_engine->player, gui);
		}
		else if (engine->playing == 10)
		{
			mesh.pos = main_camera->pos;
			SDL_ShowCursor(SDL_DISABLE);
			t_engine_apply_physic(engine);
			t_engine_handle_camera(engine, win);
			t_engine_prepare_camera(engine);
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
			mesh_editing = select_mesh(mesh_editing, engine->user_engine->keyboard, engine->user_engine->player->camera->pos, path);
			map_editor(main_camera, gui, engine, mesh_editing);
		}
		else if (engine->playing == 11)
		{
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
   			t_view_port_clear_buffers(main_camera->view_port);
    		draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[14]);
			print_set_player(main_camera, gui, engine);
		}
		else if (engine->playing == 12)
		{
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
   			t_view_port_clear_buffers(main_camera->view_port);
    		draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[15]);
			print_set_weapon(main_camera, gui, engine);
		}
		else if (engine->playing == 13 || engine->playing == 9)
		{
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
   			t_view_port_clear_buffers(main_camera->view_port);
    		draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[16]);
			// print_set_player(main_camera, gui, engine);
		}
		t_engine_handle_event(main_camera, gui, engine);
		render_screen(win, engine); // affiche la fenetre
	}
	Mix_FreeMusic(musique);
	Mix_CloseAudio();
	TTF_Quit();
	return (0);
}
