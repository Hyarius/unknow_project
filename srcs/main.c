#include "unknow_project.h"

// int main(int argc, char **argv)
// {

// 	if (argc != 1)
// 		error_exit(-1, "Bad argument");

// 	start_sdl(); //initialisation de la SDL

// 	t_window *win;
// 	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

// 	t_engine *engine = initialize_t_engine();

// 	t_color		list_color[8];

// 	list_color[0] = create_t_color(0.2, 0.2, 0.2, 1.0);
// 	list_color[1] = create_t_color(0.2, 0.9, 0.9, 1.0);
// 	list_color[2] = create_t_color(0.9, 0.2, 0.9, 1.0);
// 	list_color[3] = create_t_color(0.9, 0.9, 0.2, 1.0);
// 	list_color[4] = create_t_color(0.2, 0.2, 0.9, 1.0);
// 	list_color[5] = create_t_color(0.2, 0.9, 0.2, 1.0);
// 	list_color[6] = create_t_color(0.9, 0.2, 0.2, 1.0);
// 	list_color[7] = create_t_color(0.9, 0.9, 0.9, 1.0);

// 	t_engine_add_mesh(engine, create_primitive_plane(create_t_vector3(0, -1, 0), create_t_vector3(60, 0, 60), NULL, 0.0));

// 	int nb = 800; //nombre de mesh (cube)
// 	float size = 1;
// 	int range = 50;
// 	for (int i = 0; i < nb; i++)
// 	{
// 		float x = (float)(generate_nbr(-range, range)) + 0.5f; //generer position aleatoire des cube
// 		float y = (float)(generate_nbr(range, range * 2)) + 0.5f;
// 		float z = (float)(generate_nbr(-range, range)) + 0.5f;
// 		int	color = generate_nbr(0, 8);

// 		t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(x, y, z), create_t_vector3(size, size, size), NULL, 100.0));
// 		t_mesh *mesh = t_engine_get_mesh(engine, i + 1);
// 		t_mesh_set_color(mesh, list_color[color]);
// 	}

// 	while (engine->playing == 1)
// 	{
// 		//t_engine_apply_physic(engine);

// 		t_engine_handle_camera(engine);

// 		prepare_screen(win, engine->cam, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

// 		t_engine_draw_mesh(engine, win);

// 		render_screen(win, engine->cam); // affiche la fenetre

// 		t_engine_handle_event(engine);
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

	t_engine *engine = initialize_t_engine();
	t_engine_place_camera(engine, create_t_vector3(0, 0, 0));
	//t_engine_camera_look_at(engine, create_t_vector3(0, 0, 0));


	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(0, 0, 5), create_t_vector3(1, 1, 1), NULL, 0.0));
	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(5, 0, 0), create_t_vector3(1, 1, 1), NULL, 0.0));
	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(5, 0, 5), create_t_vector3(1, 1, 1), NULL, 0.0));
	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-5, 0, -5), create_t_vector3(1, 1, 1), NULL, 0.0));
	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(0, 0, -5), create_t_vector3(1, 1, 1), NULL, 0.0));
	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-5, 0, 0), create_t_vector3(1, 1, 1), NULL, 0.0));
	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-5, 0, 5), create_t_vector3(1, 1, 1), NULL, 0.0));
	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(5, 0, -5), create_t_vector3(1, 1, 1), NULL, 0.0));
	t_mesh *mesh;
	t_color color[8];
	color[0] = create_t_color_from_int(255, 255, 255, 255);
	color[1] = create_t_color_from_int(0, 0, 0, 255);
	color[2] = create_t_color_from_int(255, 0, 0, 255);
	color[3] = create_t_color_from_int(0, 255, 0, 255);
	color[4] = create_t_color_from_int(0, 0, 255, 255);
	color[5] = create_t_color_from_int(255, 0, 255, 255);
	color[6] = create_t_color_from_int(0, 255, 255, 255);
	color[7] = create_t_color_from_int(255, 255, 0, 255);

	for (int i = 0; i < 8; i++)
	{
		mesh = t_engine_get_mesh(engine, i);
		t_mesh_set_color(mesh, color[i]);
	}

	/*

	713
	602
	458

	*/

	// t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-0.5, 15, -4), create_t_vector3(1.5, 1.5, 1.5), NULL, 0.0));
	// t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-0.5, 30, -4), create_t_vector3(3, 3, 3), NULL, 0.0));
	// t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-0.5, 45, -4), create_t_vector3(2.5, 2.5, 2.5), NULL, 0.0));
	// t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-0.5, 60, -4), create_t_vector3(2, 2, 2), NULL, 0.0));
	// t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-0.5, 75, -4), create_t_vector3(1.5, 1.5, 1.5), NULL, 0.0));
	// t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-0.5, 90, -4), create_t_vector3(1, 1, 1), NULL, 0.0));
	// t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-0.5, 105, -4), create_t_vector3(4, 1, 4), NULL, 0.0));
	// t_mesh *mesh = t_engine_get_mesh(engine, 1);
	// t_mesh_set_color(mesh, create_t_color(1.0, 0.2, 0.6, 1.0));
	// mesh = t_engine_get_mesh(engine, 2);
	// t_mesh_set_color(mesh, create_t_color(0.2, 0.2, 1.0, 1.0));
	// mesh = t_engine_get_mesh(engine, 3);
	// t_mesh_set_color(mesh, create_t_color(0.2, 1.2, 1.0, 1.0));
	// mesh = t_engine_get_mesh(engine, 4);
	// t_mesh_set_color(mesh, create_t_color(1.2, 0.2, 1.0, 1.0));
	// mesh = t_engine_get_mesh(engine, 5);
	// t_mesh_set_color(mesh, create_t_color(0.2, 0.2, 0.2, 1.0));

	int state = 0;

	while (engine->playing == 1)
	{

		if (get_key_state(engine->user_engine->keyboard, SDL_SCANCODE_R))
		{
			printf("State = %d\n", state);
			mesh = t_engine_get_mesh(engine, state);

			t_engine_camera_look_at(engine, mesh->pos);

			//state = (state + 1) % 8;
			reset_key_state(engine->user_engine->keyboard, SDL_SCANCODE_R);
		}

		t_engine_apply_physic(engine);

		t_engine_handle_camera(engine);

		prepare_screen(win, engine->cam, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

		t_engine_draw_mesh(engine, win);

		render_screen(win, engine->cam); // affiche la fenetre

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

// 	t_texture *texture = png_load("ressources/assets/texture/cube_test.png");

// 	t_mouse	*mouse = initialize_t_mouse(); //creation de l'evenement mouse, et set des variables mouse par default
// 	t_keyboard *keyboard = initialize_t_keyboard(); //creation du keyboard, preparaton aux tests des touches

// 	SDL_Event event; //va retenir toute les entrees utilisateur (key and mouse)
// 	int play = 1;

// 	t_mesh **mesh_list;
// 	int nb = 100; //nombre de mesh (cube)
// 	t_camera *cam = initialize_t_camera(create_t_vector3(1, 2, 4), 70, create_t_vector2(0.1f, 50.0f)); //creation et initialisation de la camera et des matrices liee a la camera

// 	mesh_list = (t_mesh **)malloc(sizeof(t_mesh *) * nb);
// 	float size = 1;
// 	int range = 20;
// 	for (int i = 0; i < nb; i++)
// 	{
// 		float x = (float)(generate_nbr(-range, range)) + 0.5f; //generer position aleatoire des cube
// 		float y = (float)(generate_nbr(-2, 3)) + 0.5f;
// 		float z = (float)(generate_nbr(-range, range)) + 0.5f;

// 		mesh_list[i] = initialize_t_mesh(create_t_vector3(x, y, z)); //creation d'un mesh vide
// 		*(mesh_list[i]) = create_primitive_cube(create_t_vector3(x, y, z), create_t_vector3(size, size, size), NULL); //creation du cube que l'on rentre dans mesh
// }

// 	while (play == 1)
// 	{
// 		// for (int i = 0; i < nb; i++)
// 		// 	rotate_t_mesh(mesh_list[i], create_t_vector3(0.25, 0.25, 0.25), create_t_vector3(1.5, 1.5, 1.5));
// 		compute_t_camera(cam); //calcul du mvp

// 		get_t_mouse_info(mouse); // recuperation des informations mouse (position, et boutton utiliser)
// 		if (mouse->button[MOUSE_LEFT] == BOOL_TRUE)
// 			handle_t_camera_view_by_mouse(cam, mouse); // calcul du mouvement de l'angle de la camera a la souris

// 		handle_t_camera_mouvement_by_key(cam, keyboard); // deplacement camera

// 		prepare_screen(win, cam, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

// 		for (int k = 0; k < nb; k++)
// 			draw_t_mesh(win, cam, mesh_list[k]); // dessine le cube

// 		render_screen(win, cam); // affiche la fenetre

// 		if (SDL_PollEvent(&event) == 1)
// 		{
// 			if (event.type == SDL_QUIT)
// 				play = 0;
// 			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
// 				play = 0;
// 		}
// 		SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
// 	}
// 	return (0);
// }
