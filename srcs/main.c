#include "unknow_project.h"

// int main(int argc, char **argv)
// {
// 	if (argc != 1)
// 		error_exit(-1, "Bad argument");

// 	start_sdl(); //initialisation de la SDL

// 	t_window *win;
// 	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window
// 	int play = 0;
// 	SDL_Event event;

// 	t_vector3 point[4];
// 	point[0] = create_t_vector3(300.0, 100.0, 0.0);
// 	point[1] = create_t_vector3(100.0, 200.0, 0.0);
// 	point[2] = create_t_vector3(300.0, 300.0, 0.0);
// 	t_triangle triangle = create_t_triangle(convert_screen_to_opengl(win, point[0]), convert_screen_to_opengl(win, point[1]), convert_screen_to_opengl(win, point[2]));

// 	t_triangle uv_triangle = create_t_triangle(create_t_vector3(0, 0, 0), create_t_vector3(1, 0, 0), create_t_vector3(0, 1, 0));
// 	t_texture *texture = png_load("ressources/assets/texture/cube_number.png");
// 	t_uv uv = create_t_uv(uv_triangle, texture);

// 	t_color color = create_t_color(1.0, 0.0, 0.0, 1.0);

// 	while (play == 0)
// 	{
// 		prepare_screen(win, NULL, create_t_color(0.2, 0.2, 0.2, 1.0));

// 		test_draw(win, &triangle, &color);

// 		render_screen(win, NULL);
// 		if (SDL_PollEvent(&event) == 1)
// 		{
// 			if (event.type == SDL_QUIT)
// 				play = 1;
// 			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
// 				play = 1;
// 		}

// 	}
// 	return (0);
// }

int main(int argc, char **argv)
{
	if (argc != 1)
		error_exit(-1, "Bad argument");

	start_sdl(); //initialisation de la SDL

	t_window *win;
	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

	t_texture *texture = png_load("ressources/assets/texture/cube_number.png");


	t_engine	*engine = initialize_t_engine(win);
	//resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, create_t_vector2_int(2, 2));

	t_mesh mesh = create_primitive_plane(create_t_vector3(0.0, 0, 0.0), create_t_vector3(10.0, 0.0, 10.0), NULL, 0.0);
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.5, 0.5 ,1.0));
	t_engine_add_mesh(engine, mesh);



	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0);
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.8 ,1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, -5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0);
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(1.0, 0.6, 0.8 ,1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0);
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.0, 0.8 ,1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0);
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
	t_engine_add_mesh(engine, mesh);

	// mesh = create_primitive_cube(create_t_vector3(0.0, 0.0, 0.0), create_t_vector3(5.0, 5.0, 5.0), NULL, 100.0);
	// t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
	// t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
	// t_engine_add_mesh(engine, mesh);



	mesh = read_obj_file("pawn.obj", create_t_vector3(2.9, 10.0, 2.9), create_t_vector3(0.1, 0.11, 0.1), 100.0);
	t_mesh_set_color(&mesh, create_t_color(0.4, 0.3, 0.3, 1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = read_obj_file("pawn.obj", create_t_vector3(0.0, 0.1, 2.0), create_t_vector3(0.1, 0.11, 0.1), 10.0);
	t_mesh_set_color(&mesh, create_t_color(0.3, 0.3, 1.0, 1.0));
	t_engine_add_mesh(engine, mesh);




	t_engine_place_camera(engine, 0, create_t_vector3(0, 6.0, -6.5));
	t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 0), create_t_vector3(0, 0, 0));


	// t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(0.0, 11.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(400, 340));
	// move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(1440, 0));
	// t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 1), create_t_vector3(0, 0, 0));



	// t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(3.5, 1.5, 0.25), 70, create_t_vector2(NEAR, FAR)));
	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(400, 340));
	// move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(0, 0));
	// t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 2), create_t_vector3(0, 0, 0));

	while (engine->playing == 1)
	{
		t_engine_apply_physic(engine);

		t_engine_handle_camera(engine);

		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

		t_engine_prepare_camera(engine);

		t_engine_draw_mesh(engine, win);

		t_engine_render_camera(engine);

		render_screen(win); // affiche la fenetre

		t_engine_handle_event(engine);
	}
	return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 1)
// 		error_exit(-1, "Bad argument");

// 	start_sdl(); //initialisation de la SDL

// 	t_window *win;
// 	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

// 	t_texture *texture = png_load("ressources/assets/texture/cube_number.png");


// 	t_engine	*engine = initialize_t_engine(win);
// 	//resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, create_t_vector2_int(2, 2));

// 	t_mesh_list *mesh_list = initialize_t_mesh_list();
// 	*mesh_list = read_map_file("fichier_map.map");
// 	int i = -1;
// 	while (++i < mesh_list->size)
// 		t_engine_add_mesh(engine, *t_mesh_list_get(mesh_list, i));

// 	t_engine_place_camera(engine, 0, create_t_vector3(0, 6.0, -6.5));
// 	t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 0), create_t_vector3(0, 0, 0));

// 	t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(0.25, 1.5, 3.5), 70, create_t_vector2(NEAR, FAR)));
// 	resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(400, 340));
// 	move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(1440, 0));
// 	t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 1), create_t_vector3(0, 0, 0));

// 	while (engine->playing == 1)
// 	{
// 		t_engine_apply_physic(engine);

// 		t_engine_handle_camera(engine);

// 		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

// 		t_engine_prepare_camera(engine);

// 		t_engine_draw_mesh(engine, win);

// 		t_engine_render_camera(engine);

// 		render_screen(win); // affiche la fenetre

// 		t_engine_handle_event(engine);
// 	}
// 	return (0);
// }