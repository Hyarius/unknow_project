#include "unknow_project.h"

int main(int argc, char **argv)
{
	if (argc != 1)
		error_exit(-1, "Bad argument");

	// t_vector3 a;
	// t_vector3 b;
	// t_vector3 c;

	// a = create_t_vector3(2, 6, 4);
	// b = create_t_vector3(5, 8, 2);
	// c = substract_vector3_to_vector3(a, b);
	// print_t_vector3(a, "Calc = ");
	// print_t_vector3(b, " + ");
	// print_t_vector3(c, " = ");
	// endl();
	start_sdl();

	t_window *win;
	win = initialize_t_window(argv[0], 1840, 1220);
	t_mouse	*mouse = initialize_t_mouse();

	SDL_Event event;
	int play = 1;

	t_mesh **mesh_list;
	int nb = 10;

	mesh_list = (t_mesh **)malloc(sizeof(t_mesh *) * nb);
	for (int i = 0; i < nb; i++)
	{
		float x = (float)(generate_nbr(-5, 5)) + 0.5f;
		float y = (float)(generate_nbr(-5, 5)) + 0.5f;
		float z = (float)(generate_nbr(-5, 5)) + 0.5f;
		mesh_list[i] = initialize_t_mesh();

		*(mesh_list[i]) = create_primitive_cube(create_t_vector3(x, y, z), create_t_vector3(1, 1, 1));
	}

	t_camera *cam = initialize_t_camera(win, create_t_vector3(0, 2, -8), 70, create_t_vector2(0.5f, 50.0f));

	t_matrix	*mvp;
	mvp = initialize_t_matrix();
	*mvp = compute_t_camera(cam);

	while (play == 1)
	{
		*mvp = compute_t_camera(cam);

		get_t_mouse_info(mouse);

		if (mouse->button[MOUSE_LEFT] == BOOL_TRUE)
			handle_t_camera_view_by_mouse(cam, mouse);


		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f));

		for (int i = 0; i < nb; i++)
			draw_t_mesh(win, mvp, mesh_list[i]);

		render_screen(win);

		if (SDL_PollEvent(&event) == 1)
		{
			if (event.type == SDL_QUIT)
				play = 0;
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
				play = 0;

			if (event.type == SDL_KEYUP)
			{
				handle_t_camera_mouvement_by_key(cam, (int)(event.key.keysym.sym));
				handle_t_camera_view_by_key(cam, (int)(event.key.keysym.sym));
			}
		}
	}

	return (0);
}
