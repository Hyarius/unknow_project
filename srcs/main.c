#include "unknow_project.h"

int main(int argc, char **argv)
{
	TTF_Font    *police;
	SDL_Surface *font = NULL;
	SDL_Color color = {0, 0, 0};
	int i = 1;

	if (argc != 1)
		error_exit(-1, "Bad argument");
	start_sdl(); //initialisation de la SDL

	t_window *win;
	win = initialize_t_window(argv[0], WIN_X, WIN_Y);	//creation et initialisation de la window

	t_texture *texture2[4];
	texture2[0] = png_load("ressources/assets/texture/pistol_ammo.png");
	texture2[1] = png_load("ressources/assets/texture/ar_ammo.png");
	texture2[2] = png_load("ressources/assets/texture/rifle_ammo.png");
	texture2[3] = png_load("ressources/assets/texture/shotgun_ammo.png");
	t_texture *texture = png_load("ressources/assets/texture/cube_test.png");
	t_texture *skybox = png_load("ressources/assets/texture/skybox.png");

	t_engine	*engine = initialize_t_engine(win);
	t_gui		*gui;

	gui = initialize_t_gui(0.10, 30);

	load_menu(gui);
	TTF_Init();
	set_t_gui_texte(gui);

	t_mesh		mesh;
	t_camera	*main_camera;

	main_camera = t_camera_list_get(engine->visual_engine->camera_list, 0);
	t_engine_place_camera(engine, 0, create_t_vector3(5.0, 5.0, 0.0));
	t_camera_look_at_point(main_camera, create_t_vector3(0, 0, 0));
	t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(0.0, 0.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
	resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(300, 240));
	move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(WIN_X - 300, 0));
	t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(0.0, 0.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
	resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(300, 240));
	move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(300, 0));

	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, create_t_vector2_int(2, 2));


	mesh = create_primitive_cube(create_t_vector3(2.0, 2.0, 2.0), create_t_vector3(0.3, 0.6, 0.3), NULL, 0.0, "Player");
	t_mesh_set_color(&mesh, create_t_color(1.5, 0.4, 1.5, 1.0));
	t_engine_add_mesh(engine, mesh);
	link_t_camera_to_t_mesh(main_camera, t_engine_get_mesh(engine, 0), 100);


	mesh = create_primitive_plane(create_t_vector3(0.0, 0, 0.0), create_t_vector3(10.0, 0.0, 10.0), NULL, 0.0);
	// t_mesh_rotate(&mesh, create_t_vector3(45.0, 0.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.5, 0.5 ,1.0));
	t_engine_add_mesh(engine, mesh);

	engine->user_engine->player = initialize_t_player(main_camera, mesh);
	t_engine_add_mesh(engine, engine->user_engine->player->hitbox);

	mesh = create_primitive_cube(create_t_vector3(1.0, 0.0, 2.0), create_t_vector3(1.0, 1.0, 1.0), NULL, 0.0, "cube texture");
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.8 ,1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 0.0, "mur bleu");
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.8 ,1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, -5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 0.0, "mur rose");
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(1.0, 0.6, 0.8 ,1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 0.0, "mur violet");
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.0, 0.8 ,1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 0.0, "mur vert");
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(1.0, 0.0, 5.0), create_t_vector3(2.0, 2.0, 2), NULL, 0.0, "Enemy");
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.0, 0.0, 0.0 ,1.0));
	t_engine_add_mesh(engine, mesh);

	// mesh = create_primitive_cube(create_t_vector3(0.0, 0.0, 0.0), create_t_vector3(5.0, 5.0, 5.0), NULL, 100.0);
	// t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
	// t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
	// t_engine_add_mesh(engine, mesh);
	// mesh = create_primitive_cube(create_t_vector3(2.0, 0.0, 2.0), create_t_vector3(0.2, 0.0001, 0.2), NULL, 0.0, "tp1");
	// t_mesh_set_color(&mesh, create_t_color(0.0, 0.0, 1.0, 1.0));
	// t_engine_add_mesh(engine, mesh);

	// mesh = create_primitive_cube(create_t_vector3(12.0, 0.0, 12.0), create_t_vector3(0.2, 0.0001, 0.2), NULL, 0.0, "tp2");
	// t_mesh_set_color(&mesh, create_t_color(0.0, 0.0, 1.0, 1.0));
	// t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(-0.5, 0.0, 5.0), create_t_vector3(1.0, 2.0, 0.1), NULL, 0.0, "door_close");
	t_mesh_set_color(&mesh, create_t_color(0.0, 0.0, 1.0, 1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 0.5), create_t_vector3(1.0, 2.0, 0.1), NULL, 0.0, "door_close");
	t_mesh_set_color(&mesh, create_t_color(0.0, 0.0, 1.0, 1.0));
	t_mesh_rotate_around_point(&mesh, create_t_vector3(0.0, 90.0, 0.0), mesh.pos);
	t_engine_add_mesh(engine, mesh);

	t_rectangle rec = create_t_rectangle(create_t_vector2(-1, 1), create_t_vector2(2, -2));

	// mesh = read_obj_file("pawn.obj", create_t_vector3(-3.0, 1.0, 2.0), create_t_vector3(0.1, 0.11, 0.1), 10.0);
	// t_mesh_set_color(&mesh, create_t_color(0.3, 0.3, 1.0, 1.0));
	// t_engine_add_mesh(engine, mesh);

	t_item_list	*item_list = initialize_t_item_list();

	t_item health_pack = create_health_pack(create_t_vector3(0.0, 0.0, 0.0), engine);
	t_item_list_push_back(item_list, health_pack);

	t_item ammo_pack = create_ammo_pack(create_t_vector3(1.0, 0.0, 0.0), engine, 1);
	t_item_list_push_back(item_list, ammo_pack);
	ammo_pack = create_ammo_pack(create_t_vector3(2.0, 0.0, 0.0), engine, 2);
	t_item_list_push_back(item_list, ammo_pack);
	ammo_pack = create_ammo_pack(create_t_vector3(3.0, 0.0, 0.0), engine, 3);
	t_item_list_push_back(item_list, ammo_pack);
	ammo_pack = create_ammo_pack(create_t_vector3(4.0, 0.0, 0.0), engine, 4);
	t_item_list_push_back(item_list, ammo_pack);

	t_item armor_pack = create_armor_pack(create_t_vector3(-1.0, 0.0, 0.0), engine);
	t_item_list_push_back(item_list, armor_pack);

	armor_pack = create_armor_pack(create_t_vector3(-2.0, 0.0, 0.0), engine);
	t_item_list_push_back(item_list, armor_pack);
	engine->physic_engine->item_list = item_list;

	// t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(3.5, 1.5, 0.25), 70, create_t_vector2(NEAR, FAR)));
	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(400, 340));
	// move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(0, 0));
	// t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 2), create_t_vector3(0, 0, 0));

	t_mesh *target;
	// link_t_camera_to_t_mesh(main_camera, t_engine_get_mesh(engine, 0), 100);

	// t_item *target;
	// t_mesh *test;


	t_color color2 = create_t_color(1.0, 0.0, 1.0, 1.0);

	mesh = create_primitive_skybox(main_camera->pos, create_t_vector3(1.0, 1.0, 1.0), skybox);
	// t_mesh_set_color(&mesh, create_t_color(0.0, 1.0, 0.0, 0.5));

	while (engine->playing != 0)
	{
		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f));
		t_engine_prepare_camera(engine);

		if (engine->playing <= -1)
		{
			t_engine_draw_mesh(engine);
			t_engine_render_camera(engine);
			drawing_front_pause(main_camera, gui);
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
			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[4]);
		}
		if (engine->playing == 6)
		{
			draw_rectangle_texture_cpu(main_camera->view_port, rec, gui->menu[3]);
		}
		if (engine->playing == 1)
		{
			// mesh.pos = main_camera->pos;

			// draw_skybox(win, main_camera, &mesh); // skybox
			// t_engine_render_camera(engine);
			t_engine_apply_physic(engine);

			t_engine_handle_camera(engine);
			t_engine_prepare_camera(engine);

			t_engine_draw_mesh(engine);

			t_engine_render_camera(engine);
			change_weapon(engine->user_engine->keyboard, engine->user_engine->player);
			reload_weapon(engine->user_engine->keyboard, engine->user_engine->player);
			shoot_weapon(engine);
			drawing_front_hp(main_camera, engine);
			drawing_front_mun(main_camera, gui, texture2, engine->user_engine->player);
			draw_minimap(main_camera, engine, win);
			print_info_bar(main_camera, engine->user_engine->player, gui);
			
		}
		t_engine_handle_event(main_camera, gui, engine);
		render_screen(win); // affiche la fenetre
	}
	TTF_Quit();
	return (0);
}
