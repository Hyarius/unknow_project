#include "unknow_project.h"

int main(int argc, char **argv)
{
	TTF_Font    *police;
	SDL_Surface *font = NULL;
	SDL_Color color = {0, 0, 0};

	if (argc != 1)
		error_exit(-1, "Bad argument");

	start_sdl(); //initialisation de la SDL

	t_window *win;
	win = initialize_t_window(argv[0], WIN_X, WIN_Y);	//creation et initialisation de la window

	t_texture *texture2 = png_load("ressources/assets/texture/ammo.png");
	t_texture *texture = png_load("ressources/assets/texture/cube_number.png");


	t_engine	*engine = initialize_t_engine(win);
	t_gui		*gui;

	gui = initialize_t_gui(0.10, 30);

	load_menu(gui);
	TTF_Init();
	set_t_gui_texte(gui);
	//resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, create_t_vector2_int(2, 2));

	t_mesh mesh = create_primitive_plane(create_t_vector3(0.0, 0, 0.0), create_t_vector3(10.0, 0.0, 10.0), NULL, 0.0);
	// t_mesh_rotate(&mesh, create_t_vector3(45.0, 0.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.5, 0.5 ,1.0));
	t_engine_add_mesh(engine, mesh);



	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 0.0, NULL);
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.8 ,1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, -5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 0.0, NULL);
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(1.0, 0.6, 0.8 ,1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 0.0, NULL);
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.0, 0.8 ,1.0));
	t_engine_add_mesh(engine, mesh);

	mesh = create_primitive_cube(create_t_vector3(5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 0.0, NULL);
	t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
	t_engine_add_mesh(engine, mesh);

	// mesh = create_primitive_cube(create_t_vector3(0.0, 0.0, 0.0), create_t_vector3(5.0, 5.0, 5.0), NULL, 100.0);
	// t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
	// t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
	// t_engine_add_mesh(engine, mesh);


	t_rectangle rec = create_t_rectangle(create_t_vector2(-1, 1), create_t_vector2(2, -2));
	mesh = read_obj_file("pawn.obj", create_t_vector3(2.9, 10.0, 2.9), create_t_vector3(0.1, 0.11, 0.1), 100.0);
	t_mesh_set_color(&mesh, create_t_color(0.4, 0.3, 0.3, 1.0));
	t_engine_add_mesh(engine, mesh);

	// mesh = read_obj_file("pawn.obj", create_t_vector3(-3.0, 1.0, 2.0), create_t_vector3(0.1, 0.11, 0.1), 10.0);
	// t_mesh_set_color(&mesh, create_t_color(0.3, 0.3, 1.0, 1.0));
	// t_engine_add_mesh(engine, mesh);


	t_camera *main_camera = t_camera_list_get(engine->visual_engine->camera_list, 0);

	t_engine_place_camera(engine, 0, create_t_vector3(5.0, 5.0, 0.0));
	t_camera_look_at_point(main_camera, create_t_vector3(0, 0, 0));
	t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(0.0, 0.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
	resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(300, 240));
	move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(WIN_X - 300, 0));


	// t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(3.5, 1.5, 0.25), 70, create_t_vector2(NEAR, FAR)));
	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(400, 340));
	// move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(0, 0));
	// t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 2), create_t_vector3(0, 0, 0));

	//t_mesh *target;

	while (engine->playing != 0)
	{
		//target = NULL;
		//target = cast_ray(engine, main_camera->pos, main_camera->forward);
		// if (target != NULL)
		// {
		// 	// printf("Object hit : \n");
		// 	t_mesh_set_color(target, create_t_color(1, 0, 0, 1));
		// }
		//draw_minimap(main_camera, engine, win);
		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f));
		t_engine_prepare_camera(engine);

		if (engine->playing <= -1)
		{
			t_engine_draw_mesh(engine, win);
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
			t_engine_apply_physic(engine);

			t_engine_handle_camera(engine);

			t_engine_draw_mesh(engine, win);


			//draw_rectangle_color_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(-1, 1), create_t_vector2(2, -2)), initialize_t_color(0.2, 0.2, 0.3, 1.0));
			t_engine_render_camera(engine);
			drawing_front_hp(main_camera, gui);
			drawing_front_mun(main_camera, gui, texture2);
			draw_minimap(main_camera, engine, win, texture);
			print_info_bar(main_camera, gui);
		}

		t_engine_handle_event(main_camera, gui, engine);
		render_screen(win); // affiche la fenetre
	}
	TTF_Quit();
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
// 	t_mesh 		mesh;
// 	//resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, create_t_vector2_int(2, 2));

// 	// t_mesh mesh = create_primitive_plane(create_t_vector3(0.0, 0, 0.0), create_t_vector3(10.0, 0.0, 10.0), NULL, 0.0);
// 	// t_mesh_set_color(&mesh, create_t_color(0.5, 0.5, 0.5 ,1.0));
// 	// t_engine_add_mesh(engine, mesh);



// 	// mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0);
// 	// t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
// 	// t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.8 ,1.0));
// 	// // t_mesh_set_texture(&mesh, texture);
// 	// t_engine_add_mesh(engine, mesh);

// 	// mesh = create_primitive_cube(create_t_vector3(1.0, 10.0, 1.5), create_t_vector3(1.0, 1.0, 1.0), NULL, 10.0);
// 	// t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
// 	// t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.8 ,1.0));
// 	// // t_mesh_set_texture(&mesh, texture);
// 	// t_engine_add_mesh(engine, mesh);

// 	// mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, -5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0);
// 	// t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
// 	// t_mesh_set_color(&mesh, create_t_color(1.0, 0.6, 0.8 ,1.0));
// 	// t_engine_add_mesh(engine, mesh);

// 	// mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0, NULL);
// 	// t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
// 	// t_mesh_set_color(&mesh, create_t_color(0.5, 0.0, 0.8 ,1.0));
// 	// t_engine_add_mesh(engine, mesh);

// 	// mesh = create_primitive_cube(create_t_vector3(5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0, NULL);
// 	// t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
// 	// t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
// 	// t_engine_add_mesh(engine, mesh);

// 	mesh = create_primitive_cube(create_t_vector3(5.0000 , 5.0000 , 5.0), create_t_vector3(5.0, 5.0, 5.0), NULL, 0.0, NULL);
// 	// erreur de 1.0005 / 1.0005 / 2.0990
// 	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
// 	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
// 	t_engine_add_mesh(engine, mesh);


// 	// mesh = read_obj_file("pawn.obj", create_t_vector3(1.0, 0.0, 1.0), create_t_vector3(0.1, 0.11, 0.1), 100.0);
// 	// t_mesh_set_color(&mesh, create_t_color(0.4, 0.3, 0.3, 1.0));
// 	// t_engine_add_mesh(engine, mesh);

// 	// t_mesh mesh = read_obj_file("pawn.obj", create_t_vector3(3.0, 1.0, 2.0), create_t_vector3(0.1, 0.11, 0.1), 0.0);
// 	// t_mesh_set_color(&mesh, create_t_color(0.3, 0.3, 1.0, 1.0));
// 	// t_engine_add_mesh(engine, mesh);


// 	t_camera *main_camera = t_camera_list_get(engine->visual_engine->camera_list, 0);

// 	t_engine_place_camera(engine, 0, create_t_vector3(5.0, 15.0, -10.5));
// 	t_camera_look_at_point(main_camera, create_t_vector3(5.0, 15.0, 1.0));
// 	// t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(0.0, 15.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
// 	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(400, 340));
// 	// move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(1440, 0));
// 	// t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 1), create_t_vector3(0, 0, 0));



// 	// t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(3.5, 1.5, 0.25), 70, create_t_vector2(NEAR, FAR)));
// 	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(400, 340));
// 	// move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(0, 0));
// 	// t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 2), create_t_vector3(0, 0, 0));

// 	// t_mesh_compute_vertices_in_world(&mesh);

// 	// for (int i = 0; i < mesh.faces->size; i++)
// 	// {
// 	// 	t_face *face = t_face_list_get(mesh.faces, i);
// 	// 	t_triangle test;

// 	// 	test = compose_t_triangle_from_t_mesh(&mesh, face->index_vertices);
// 	// 	print_t_triangle(test, "Face");
// 	// }

// 	t_color color = create_t_color(1.0, 0.0, 1.0, 1.0);
// 	t_mesh *target;

// 	// target = cast_ray(engine, main_camera->pos, main_camera->forward);

// 	// t_mesh *tmp = t_mesh_list_get(engine->physic_engine->mesh_list, 6);
// 	while (engine->playing == 1)
// 	{

// 		// print_t_vector3(main_camera->forward, "--------------\ncam->forward");
// 		// print_t_vector3(main_camera->right, "right");
// 		// print_t_vector3(main_camera->up, "up");
// 		// print_t_vector3(t_engine_get_mesh(engine, 0)->pos, "mesh->pos");
// 		// print_t_vector3(main_camera->pos, "pos");

// 		target = cast_ray(engine, main_camera->pos, main_camera->forward);
// 		if (target != NULL)
// 		{
// 			// printf("Object %s \n", target->name);
// 			// print_t_vector3(target->pos, "hit at pos:");
// 			t_mesh_set_color(target, create_t_color(0, 1, 0, 1));
// 		}
// 		t_engine_apply_physic(engine);

// 		t_engine_handle_camera(engine);

// 		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par defaut

// 		t_engine_prepare_camera(engine);

// 		t_engine_draw_mesh(engine, win);


// 		// draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(-1, 1), create_t_vector2(2, -2)), texture);
// 		t_engine_render_camera(engine);

// 		t_view_port_clear_buffers(main_camera->view_port);
// 		draw_rectangle_color_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(0, 0), create_t_vector2(0.003, 0.004)), &color);

// 		render_screen(win); // affiche la fenetre

// 		t_engine_handle_event(engine);
// 	}
// 	return (0);
// }

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

// 	t_mesh mesh = create_primitive_plane(create_t_vector3(0.0, 0, 0.0), create_t_vector3(10.0, 0.0, 10.0), NULL, 0.0);
// 	t_mesh_set_color(&mesh, create_t_color(0.5, 0.5, 0.5 ,1.0));
// 	t_engine_add_mesh(engine, mesh);



// 	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0, NULL);
// 	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
// 	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.8 ,1.0));
// 	t_engine_add_mesh(engine, mesh);

// 	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, -5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0, NULL);
// 	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
// 	t_mesh_set_color(&mesh, create_t_color(1.0, 0.6, 0.8 ,1.0));
// 	t_engine_add_mesh(engine, mesh);

// 	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0, NULL);
// 	t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
// 	t_mesh_set_color(&mesh, create_t_color(0.5, 0.0, 0.8 ,1.0));
// 	t_engine_add_mesh(engine, mesh);

// 	mesh = create_primitive_cube(create_t_vector3(5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0, NULL);
// 	t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
// 	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
// 	t_engine_add_mesh(engine, mesh);

// 	// mesh = create_primitive_cube(create_t_vector3(0.0, 0.0, 0.0), create_t_vector3(5.0, 5.0, 5.0), NULL, 100.0);
// 	// t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
// 	// t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
// 	// t_engine_add_mesh(engine, mesh);



// 	mesh = read_obj_file("pawn.obj", create_t_vector3(2.9, 10.0, 2.9), create_t_vector3(0.1, 0.11, 0.1), 100.0);
// 	t_mesh_set_color(&mesh, create_t_color(0.4, 0.3, 0.3, 1.0));
// 	t_engine_add_mesh(engine, mesh);

// 	mesh = read_obj_file("pawn.obj", create_t_vector3(-3.0, 1.0, 2.0), create_t_vector3(0.1, 0.11, 0.1), 10.0);
// 	t_mesh_set_color(&mesh, create_t_color(0.3, 0.3, 1.0, 1.0));
// 	t_engine_add_mesh(engine, mesh);


// 	t_camera *main_camera = t_camera_list_get(engine->visual_engine->camera_list, 0);

// 	t_engine_place_camera(engine, 0, create_t_vector3(0.0, 5.0, -10.5));
// 	t_camera_look_at_point(main_camera, create_t_vector3(0, 0, 0));


// 	// t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(0.0, 11.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
// 	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(400, 340));
// 	// move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(1440, 0));
// 	// t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 1), create_t_vector3(0, 0, 0));



// 	// t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(3.5, 1.5, 0.25), 70, create_t_vector2(NEAR, FAR)));
// 	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(400, 340));
// 	// move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(0, 0));
// 	// t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 2), create_t_vector3(0, 0, 0));

// 	t_mesh *target;

// 	mesh = create_primitive_skybox(main_camera->pos, create_t_vector3(1.0, 1.0, 1.0), texture);
// 	t_mesh_set_color(&mesh, create_t_color(0.0, 1.0, 0.0, 0.5));

// 	t_color color = create_t_color(1.0, 0.0, 1.0, 1.0);
// 	while (engine->playing == 1)
// 	{
// 		target = NULL;
// 		target = cast_ray(engine, main_camera->pos, main_camera->forward);
// 		if (target != NULL)
// 		{
// 			// printf("Object hit : \n");
// 			t_mesh_set_color(target, create_t_color(0, 1, 0, 1));
// 		}
// 		t_engine_apply_physic(engine);

// 		t_engine_handle_camera(engine);

// 		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par defaut

// 		t_engine_prepare_camera(engine);

// 		t_engine_draw_mesh(engine, win);

// 		// draw_rectangle_texture_cpu(main_camera->view_port, create_t_vector2(-1, 1), create_t_vector2(2, -2), texture);
// 		t_engine_render_camera(engine);
// 		t_view_port_clear_buffers(main_camera->view_port);
// 		draw_rectangle_color_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(0, 0), create_t_vector2(0.003, 0.004)), &color);
// 		render_screen(win); // affiche la fenetre

// 		t_engine_handle_event(engine);
// 	}
// 	return (0);
// }

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

// 	t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(0, 5, 0), 70, create_t_vector2(NEAR, FAR)));
// 	resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(300, 200));
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

// int main(int argc, char **argv)
// {
// 	if (argc != 1)
// 		error_exit(-1, "Bad argument");
//
// 	start_sdl(); //initialisation de la SDL
//
// 	t_window *win;
// 	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window
//
// 	t_texture *texture = png_load("ressources/assets/texture/cube_number.png");
//
// 	printf("segfault\n");
//
// 	t_engine	*engine = initialize_t_engine(win);
// 	//resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 0)->view_port, create_t_vector2_int(2, 2));
//
// 	t_mesh mesh = create_primitive_plane(create_t_vector3(0.0, 0, 0.0), create_t_vector3(10.0, 0.0, 10.0), NULL, 0.0);
// 	t_mesh_set_color(&mesh, create_t_color(0.5, 0.5, 0.5 ,1.0));
// 	t_engine_add_mesh(engine, mesh);
//
//
//
// 	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0, NULL);
// 	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
// 	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.8 ,1.0));
// 	t_engine_add_mesh(engine, mesh);
//
// 	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, -5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0, NULL);
// 	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
// 	t_mesh_set_color(&mesh, create_t_color(1.0, 0.6, 0.8 ,1.0));
// 	t_engine_add_mesh(engine, mesh);
//
// 	mesh = create_primitive_cube(create_t_vector3(-5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0, NULL);
// 	t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
// 	t_mesh_set_color(&mesh, create_t_color(0.5, 0.0, 0.8 ,1.0));
// 	t_engine_add_mesh(engine, mesh);
//
// 	mesh = create_primitive_cube(create_t_vector3(5.0, 0.0, 5.0), create_t_vector3(10.0, 2.0, 0.1), NULL, 100.0, NULL);
// 	t_mesh_rotate(&mesh, create_t_vector3(0.0, 90.0, 0.0));
// 	t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
// 	t_engine_add_mesh(engine, mesh);
//
// 	mesh = create_primitive_cube(create_t_vector3(0.0, 0.0, 0.0), create_t_vector3(1.0, 1.0, 1.0), texture, 100.0, NULL);
// 	t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
// 	//t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
// 	t_engine_add_mesh(engine, mesh);
//
// 	// mesh = create_primitive_cube(create_t_vector3(0.0, 0.0, 0.0), create_t_vector3(5.0, 5.0, 5.0), NULL, 100.0);
// 	// t_mesh_rotate(&mesh, create_t_vector3(0.0, 0.0, 0.0));
// 	// t_mesh_set_color(&mesh, create_t_color(0.5, 0.6, 0.0 ,1.0));
// 	// t_engine_add_mesh(engine, mesh);
//
//
//
// 	mesh = read_obj_file("pawn.obj", create_t_vector3(2.9, 10.0, 2.9), create_t_vector3(0.1, 0.11, 0.1), 100.0);
// 	t_mesh_set_color(&mesh, create_t_color(0.4, 0.3, 0.3, 1.0));
// 	t_engine_add_mesh(engine, mesh);
//
// 	mesh = read_obj_file("pawn.obj", create_t_vector3(-3.0, 1.0, 2.0), create_t_vector3(0.1, 0.11, 0.1), 10.0);
// 	t_mesh_set_color(&mesh, create_t_color(0.3, 0.3, 1.0, 1.0));
// 	t_engine_add_mesh(engine, mesh);
//
//
// 	t_camera *main_camera = t_camera_list_get(engine->visual_engine->camera_list, 0);
//
// 	t_engine_place_camera(engine, 0, create_t_vector3(0.0, 5.0, -10.5));
// 	t_camera_look_at_point(main_camera, create_t_vector3(0, 0, 0));
//
//
// 	// t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(0.0, 11.0, 0.0), 70, create_t_vector2(NEAR, FAR)));
// 	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(400, 340));
// 	// move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 1)->view_port, create_t_vector2_int(1440, 0));
// 	// t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 1), create_t_vector3(0, 0, 0));
//
//
//
// 	// t_engine_add_camera(engine, create_t_camera(win, create_t_vector3(3.5, 1.5, 0.25), 70, create_t_vector2(NEAR, FAR)));
// 	// resize_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(400, 340));
// 	// move_t_view_port(t_camera_list_get(engine->visual_engine->camera_list, 2)->view_port, create_t_vector2_int(0, 0));
// 	// t_camera_look_at_point(t_camera_list_get(engine->visual_engine->camera_list, 2), create_t_vector3(0, 0, 0));
//
// 	// t_mesh *target;
//
// 	//printf("nb of meshes = %d\n", t_engine_return_mesh_len(engine));
//
// 	// mesh = create_primitive_skybox(main_camera->pos, create_t_vector3(1.0, 1.0, 1.0), NULL);
// 	// t_mesh_set_color(&mesh, create_t_color(0.2, 0.2, 0.2, 0.5));
// 	// t_engine_add_mesh(engine, mesh);
// 	mesh = create_primitive_skybox(main_camera->pos, create_t_vector3(1.0, 1.0, 1.0), texture);
// 	t_mesh_set_color(&mesh, create_t_color(0.0, 1.0, 0.0, 0.5));
//
// 	while (engine->playing == 1)
// 	{
// 		// target = NULL;
// 		// target = cast_ray(engine, main_camera->pos, main_camera->forward);
// 		// if (target != NULL)
// 		// {
// 		// 	// printf("Object hit : \n");
// 		// 	t_mesh_set_color(target, create_t_color(1, 0, 0, 1));
// 		// }
//
// 		mesh.pos = main_camera->pos;
//
// 		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par defaut
//
// 		t_engine_prepare_camera(engine);
//
// 		draw_skybox(win, main_camera, &mesh); // skybox
//
// 		t_engine_render_camera(engine);
//
// 		t_engine_apply_physic(engine);
//
// 		t_engine_handle_camera(engine);
//
// 		t_engine_prepare_camera(engine);
//
// 		t_engine_draw_mesh(engine, win);
//
// 		t_engine_render_camera(engine);
//
// 		render_screen(win); // affiche la fenetre
//
// 		t_engine_handle_event(engine);
// 	}
// 	return (0);
// }
