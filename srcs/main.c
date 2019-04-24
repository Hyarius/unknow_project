#include "unknow_project.h"

int main(int argc, char **argv)
{
	if (argc != 1)
		error_exit(-1, "Bad argument");

	start_sdl();

	t_window win;
	win = create_t_window(argv[0], 600, 480);

	SDL_Event event;
	int play = 1;
	int state = 0;
	t_color color = create_t_color(1.0, 0.0, 0.0, 1.0);
	t_point a = create_t_point(50, 50, color);
	t_point b = create_t_point(350, 50, color);
	t_point c = create_t_point(50, 550, color);

	while (play == 1)
	{
		prepare_screen(create_t_color(1.0f, 1.0f, 1.0f, 1.0f));

		draw_triangle(&win, a, b, c);

		render_screen(&win);

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
