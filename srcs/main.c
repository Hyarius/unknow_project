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

	*mesh = create_primitive_cube(create_t_vector3(-1, -1, -1), create_t_vector3(2, 2, 2));

	t_camera *cam = initialize_t_camera(win, create_t_vector3(0, 0, -6), 70, create_t_vector2(0.1f, 50.0f));

	t_matrix	*mvp;
	mvp = initialize_t_matrix();
	*mvp = compute_t_camera(cam);

	while (play == 1)
	{
		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f));

		*mvp = compute_t_camera(cam);

		draw_t_mesh(win, mvp, mesh);

		render_screen(win);

		if (SDL_PollEvent(&event) == 1)
		{
			if (event.type == SDL_QUIT)
				play = 0;
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
				play = 0;
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_DOWN)
				cam->pos.z--;
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_UP)
				cam->pos.z++;
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_LEFT)
			{
				cam->pos.x += cam->right.x;
			}
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_RIGHT)
			{
				cam->pos.x -= cam->right.x;
			}
		}
	}
	return (0);
}
