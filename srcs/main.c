#include "unknow_project.h"

int main(int argc, char **argv)
{
	if (argc != 1)
		error_exit(-1, "Bad argument");

	start_sdl();

	t_window *win;
	win = initialize_t_window(argv[0], 1840, 1220);

	SDL_Event event;
	int play = 1;

	t_mesh *mesh = initialize_t_mesh();

	t_mesh_add_point(mesh, create_t_vector3(0, 0, 0));
	t_mesh_add_point(mesh, create_t_vector3(1, 0, 0));
	t_mesh_add_point(mesh, create_t_vector3(1, 0, 1));

	t_mesh_add_face(mesh, 0, 1, 2);

	t_camera *cam = initialize_t_camera(win, create_t_vector3(0, -2, 0), 90, create_t_vector2(0.1f, 50.0f));

	print_t_matrix(&(cam->projection));
	/*t_matrix	*mvp;
	mvp = initialize_t_matrix();
	*mvp = compute_t_camera(cam);

	while (play == 1)
	{
		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f));

		draw_t_mesh(win, &(cam->projection), mesh);

		render_screen(win);

		if (SDL_PollEvent(&event) == 1)
		{
			if (event.type == SDL_QUIT)
				play = 0;
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
				play = 0;
		}
	}*/
	return (0);
}
