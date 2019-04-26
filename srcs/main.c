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
	t_color color = create_t_color(1.0, 0.0, 0.0, 1.0);
	t_color color2 = create_t_color(1.0, 1.0, 0.0, 1.0);
	t_point a = create_t_point(50, 100, color);
	t_point b = create_t_point(100, 150, color);
	t_point c = create_t_point(100, 50, color);
	t_point d = create_t_point(250, 100, color2);
	t_point e = create_t_point(300, 150, color2);
	t_point f = create_t_point(300, 50, color2);

	t_texture *texture = png_load("003.png");

	printf("Color = %d / %d / %d / %d\n", texture->surface->pixels[0], texture->surface->pixels[1], texture->surface->pixels[2], texture->surface->pixels[3]);

	while (play == 1)
	{
		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f));

		draw_triangle_cpu(win, a, b, c);
		draw_triangle_cpu(win, b, a, e);
		draw_triangle_cpu(win, e, f, c);
		draw_triangle_cpu(win, f, c, d);
		draw_triangle_cpu(win, d, b, c);

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
