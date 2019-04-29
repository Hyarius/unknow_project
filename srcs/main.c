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
	int state = 0;
	t_color color1 = create_t_color(1.0, 0.0, 0.0, 1.0);
	t_color color2 = create_t_color(0.0, 1.0, 0.0, 1.0);

	t_triangle t1 = create_t_triangle(create_t_vector2(50, 50), create_t_vector2(win->size_x - 50, 50), create_t_vector2(50, win->size_y - 50));
	t_triangle t2 = create_t_triangle(create_t_vector2(win->size_x - 50, 50), create_t_vector2(50, win->size_y - 50), create_t_vector2(win->size_x - 50, win->size_y - 50));

	while (play == 1)
	{
		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f));

		draw_triangle_color_cpu(win, &t1, &color1);
		draw_triangle_color_cpu(win, &t2, &color2);

		render_screen(win);

		//Regarde si il y a un evenement, met dans event la liste des evenements arrives, 0 si aucun, 1 si evenement
		if (SDL_PollEvent(&event) == 1)
		{
			// la croix rouge
			if (event.type == SDL_QUIT)
				play = 0;
			//Appuyer sur echap et le relacher
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
				play = 0;
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_q)
				state = (state + 1) % 2;
		}
	}
	return (0);
}
