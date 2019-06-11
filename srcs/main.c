#include "unknow_project.h"

int main(int argc, char **argv)
{
	if (argc != 1)
		error_exit(-1, "Bad argument");

	start_sdl(); //initialisation de la SDL

	t_window *win;
	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

	t_texture *texture = png_load("ressources/assets/texture/cube_test.png");

	t_mouse	*mouse = initialize_t_mouse(); //creation de l'evenement mouse, et set des variables mouse par default
	t_keyboard *keyboard = initialize_t_keyboard(); //creation du keyboard, preparaton aux tests des touches

	SDL_Event event; //va retenir toute les entrees utilisateur (key and mouse)
	int play = 1;

	t_camera *cam = initialize_t_camera(create_t_vector3(20, 20, 200), 70, create_t_vector2(0.1f, 50.0f)); //creation et initialisation de la camera et des matrices liee a la camera
	t_mesh mesh = read_obj_file("rat.obj", create_t_vector3(0.0, 0.0, 0.0), create_t_vector3(1, 1, 1));
	t_mesh_set_color(&(mesh), create_t_color(1.0, 0.0, 0.4, 1.0));
	t_mesh_rotate(&mesh, create_t_vector3(0, 90, 0));

	while (play == 1)
	{
		t_mesh_apply_velocity(&mesh);

		//rotate_t_mesh(&mesh, create_t_vector3(0, 0.75, 0), create_t_vector3(0, 0, 0));
		compute_t_camera(cam); //calcul du mvp

		get_t_mouse_info(mouse); // recuperation des informations mouse (position, et boutton utiliser)
		if (mouse->button[MOUSE_LEFT] == BOOL_TRUE)
			handle_t_camera_view_by_mouse(cam, mouse); // calcul du mouvement de l'angle de la camera a la souris

		handle_t_camera_mouvement_by_key(cam, keyboard); // deplacement cameras

		prepare_screen(win, cam, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

		draw_t_mesh(win, cam, &mesh); // dessine le cube

		render_screen(win, cam); // affiche la fenetre

		if (SDL_PollEvent(&event) == 1)
		{
			if (event.type == SDL_QUIT)
				play = 0;
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
				play = 0;
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_z)
				t_mesh_add_velocity(&mesh, create_t_vector3(0.1, 0.0, 0.0));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_x)
				t_mesh_add_velocity(&mesh, create_t_vector3(-0.1, 0.0, 0.0));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_c)
				t_mesh_add_velocity(&mesh, create_t_vector3(0.0, 0.1, 0.0));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_v)
				t_mesh_add_velocity(&mesh, create_t_vector3(0.0, -0.1, 0.0));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_b)
				t_mesh_add_velocity(&mesh, create_t_vector3(0.0, 0.0, 0.1));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_n)
				t_mesh_add_velocity(&mesh, create_t_vector3(0.0, 0.0, -0.1));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_m)
				t_mesh_set_velocity(&mesh, create_t_vector3(0.0, 0.0, 0.0));

			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_t)
				t_mesh_move(&mesh, create_t_vector3(0.1, 0.0, 0.0));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_g)
				t_mesh_move(&mesh, create_t_vector3(-0.1, 0.0, 0.0));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_r)
				t_mesh_move(&mesh, create_t_vector3(0.0, 0.1, 0.0));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_y)
				t_mesh_move(&mesh, create_t_vector3(0.0, -0.1, 0.0));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_f)
				t_mesh_move(&mesh, create_t_vector3(0.0, 0.0, -0.1));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_h)
				t_mesh_move(&mesh, create_t_vector3(0.0, 0.0, 0.1));

			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_i)
				t_mesh_translate(&mesh, create_t_vector3(6, 0.0, 0.0));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_k)
				t_mesh_translate(&mesh, create_t_vector3(-6, 0.0, 0.0));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_j)
				t_mesh_translate(&mesh, create_t_vector3(0.0, 0.0, -6));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_l)
				t_mesh_translate(&mesh, create_t_vector3(0.0, 0.0, 6));

			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_u)
				t_mesh_rotate(&mesh, create_t_vector3(0.0, -1, 0));
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_o)
				t_mesh_rotate(&mesh, create_t_vector3(0.0, 1, 0));

			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_9)
				t_mesh_add_velocity(&mesh, create_t_vector3(0.0, 2.0, 0));
		}
		SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
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