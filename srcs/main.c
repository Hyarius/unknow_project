#include "unknow_project.h"

// int main(int argc, char **argv)
// {
// 	if (argc != 1)
// 		error_exit(-1, "Bad argument");

// 	start_sdl(); //initialisation de la SDL

// 	t_window *win;
// 	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

// 	t_texture *texture = png_load("ressources/assets/texture/cube_number.png");

// 	t_vector3	coord[4];
// 	t_vector3	uv_coord[4];
// 	coord[0] = convert_screen_to_opengl(win, create_t_vector3(100, 200, 0));
// 	coord[1] = convert_screen_to_opengl(win, create_t_vector3(500, 100, 0));
// 	coord[2] = convert_screen_to_opengl(win, create_t_vector3(600, 500, 0));
// 	coord[3] = convert_screen_to_opengl(win, create_t_vector3(200, 600, 0));
// 	uv_coord[0] = create_t_vector3(0.0, 1.0, 0.0);
// 	uv_coord[1] = create_t_vector3(1.0, 1.0, 0.0);
// 	uv_coord[2] = create_t_vector3(1.0, 0.0, 0.0);
// 	uv_coord[3] = create_t_vector3(0.0, 0.0, 0.0);

// 	t_triangle	triangle = create_t_triangle(coord[0], coord[1], coord[2]);
// 	t_triangle	uv_triangle = create_t_triangle(uv_coord[0], uv_coord[1], uv_coord[2]);
// 	t_uv		uv = create_t_uv(uv_triangle, texture);

// 	t_triangle	triangle2 = create_t_triangle(coord[0], coord[2], coord[3]);
// 	t_triangle	uv_triangle2 = create_t_triangle(uv_coord[0], uv_coord[2], uv_coord[3]);
// 	t_uv		uv2 = create_t_uv(uv_triangle2, texture);

// 	t_color darkness = create_t_color(1.0, 1.0, 1.0, 1.0);

// 	SDL_Event event; //va retenir toute les entrees utilisateur (key and mouse)
// 	int play = 1;

// 	while (play == 1)
// 	{
// 		prepare_screen(win, NULL, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

// 		draw_triangle_texture_cpu(win, &triangle, &uv, &darkness);
// 		draw_triangle_texture_cpu(win, &triangle2, &uv2, &darkness);

// 		render_screen(win, NULL); // affiche la fenetre

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

int main(int argc, char **argv)
{
	if (argc != 1)
		error_exit(-1, "Bad argument");

	start_sdl(); //initialisation de la SDL

	t_window *win;
	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

	t_texture *texture = png_load("ressources/assets/texture/cube_number.png");

	t_mouse	*mouse = initialize_t_mouse(); //creation de l'evenement mouse, et set des variables mouse par default
	t_keyboard *keyboard = initialize_t_keyboard(); //creation du keyboard, preparaton aux tests des touches

	SDL_Event event; //va retenir toute les entrees utilisateur (key and mouse)
	int play = 1;

	t_mesh **mesh_list;
	int nb = 15; //nombre de mesh (cube)

	t_camera *cam = initialize_t_camera(win, create_t_vector3(1, 2, 4), 70, create_t_vector2(0.1f, 50.0f)); //creation et initialisation de la camera et des matrices liee a la camera

	mesh_list = (t_mesh **)malloc(sizeof(t_mesh *) * nb);
	float size = 1;
	int range = 4;
	for (int i = 0; i < nb; i++)
	{
		float x = (float)(generate_nbr(-range, range)) + 0.5f; //generer position aleatoire des cube
		float y = (float)(generate_nbr(-range, range)) + 0.5f;
		float z = (float)(generate_nbr(-range, range)) + 0.5f;

		mesh_list[i] = initialize_t_mesh(create_t_vector3(x, y, z)); //creation d'un mesh vide
		*(mesh_list[i]) = create_primitive_cube(create_t_vector3(x, y, z), create_t_vector3(size, size, size), texture); //creation du cube que l'on rentre dans mesh
	}

	while (play == 1)
	{
		// for (int i = 0; i < nb; i++)
		// 	rotate_t_mesh(mesh_list[i], create_t_vector3(0.25, 0.25, 0.25), create_t_vector3(1.5, 1.5, 1.5));
		compute_t_camera(cam); //calcul du mvp

		get_t_mouse_info(mouse); // recuperation des informations mouse (position, et boutton utiliser)
		if (mouse->button[MOUSE_LEFT] == BOOL_TRUE)
			handle_t_camera_view_by_mouse(cam, mouse); // calcul du mouvement de l'angle de la camera a la souris

		handle_t_camera_mouvement_by_key(cam, keyboard); // deplacement camera

		prepare_screen(win, cam, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

		for (int j = 0; j < nb; j++)
			draw_t_mesh(win, cam, mesh_list[j]); // dessine le cube

		render_screen(win, cam); // affiche la fenetre

		if (SDL_PollEvent(&event) == 1)
		{
			if (event.type == SDL_QUIT)
				play = 0;
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
				play = 0;
		}
		SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
	}
	return (0);
}
