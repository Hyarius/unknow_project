#include "unknow_project.h"

int main(int argc, char **argv)
{
	if (argc != 1)
		error_exit(-1, "Bad argument");

	start_sdl(); //initialisation de la SDL

	t_window *win;
	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

	t_mouse	*mouse = initialize_t_mouse(); //creation de l'evenement mouse, et set des variables mouse par default

	SDL_Event event; //va retenir toute les entrees utilisateur (key and mouse)
	int play = 1;

	t_mesh **mesh_list;
	int nb = 1; //nombre de mesh (cube)

	mesh_list = (t_mesh **)malloc(sizeof(t_mesh *) * nb);
	for (int i = 0; i < nb; i++)
	{
		// float x = (float)(generate_nbr(-5, 5)) + 0.5f; //generer position aleatoire des cube
		// float y = (float)(generate_nbr(-5, 5)) + 0.5f;
		// float z = (float)(generate_nbr(-5, 5)) + 0.5f;
		float x = 0;
		float y = 0;
		float z = 0;

		mesh_list[i] = initialize_t_mesh(create_t_vector3(x, y, z)); //creation d'un mesh vide
		*(mesh_list[i]) = create_primitive_cube(create_t_vector3(x, y, z), create_t_vector3(3, 3, 3)); //creation du cube que l'on rentre dans mesh
	}

	t_camera *cam = initialize_t_camera(win, create_t_vector3(0, 1, 8), 70, create_t_vector2(0.5f, 50.0f)); //creation et initialisation de la camera et des matrices liee a la camera

	while (play == 1)
	{
		rotate_t_mesh(mesh_list[0], create_t_vector3(0.25, 0.25, 0.25), create_t_vector3(1.5, 1.5, 1.5));
		compute_t_camera(cam); //calcul du mvp

		get_t_mouse_info(mouse); // recuperation des informations mouse (position, et boutton utiliser)
		if (mouse->button[MOUSE_LEFT] == BOOL_TRUE)
			handle_t_camera_view_by_mouse(cam, mouse); // calcul du mouvement de l'angle de la camera a la souris

		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

		for (int i = 0; i < nb; i++)
			draw_t_mesh(win, cam, mesh_list[i]); // dessine le cube

		render_screen(win); // affiche la fenetre

		if (SDL_PollEvent(&event) == 1)
		{
			if (event.type == SDL_QUIT)
				play = 0;
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
				play = 0;

			if (event.type == SDL_KEYUP) //recupere evenement clavier
			{
				handle_t_camera_mouvement_by_key(cam, (int)(event.key.keysym.sym)); // deplacement camera
				handle_t_camera_view_by_key(cam, (int)(event.key.keysym.sym)); // mouvement de l'amgle de view de la camera
			}
		}
	}
	return (0);
}
