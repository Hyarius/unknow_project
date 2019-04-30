#include "unknow_project.h"

void *thread_draw_cpu(void *arg)
{
	t_void_list *data = (t_void_list *)(arg);

	draw_triangle_color_cpu(data->data[0], data->data[1], data->data[2]);

	pthread_exit(NULL);
}

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

	int nb = 100;

	t_color *color;
	t_vector2	*coord;
	t_triangle	*t;
	int delta = 250;

	color = (t_color *)malloc(sizeof(t_color) * nb);
	coord = (t_vector2 *)malloc(sizeof(t_vector2) * (nb * 3));
	t = (t_triangle *)malloc(sizeof(t_triangle) * nb);

	for (int i = 0; i < nb; i++)
	{
		int x = generate_nbr(50, win->size_x - 50 - delta);
		int y = generate_nbr(50, win->size_y - 50 - delta);
		coord[i * 3] = create_t_vector2(x, y);
		coord[i * 3 + 1] = create_t_vector2(x + delta, y);
		coord[i * 3 + 2] = create_t_vector2(x - 50, y + delta);

		t[i] = create_t_triangle(coord[i * 3], coord[i * 3 + 1], coord[i * 3 + 2]);

		float r = (float)(generate_nbr(0, 255)) / 255.0f;
		float g = (float)(generate_nbr(0, 255)) / 255.0f;
		float b = (float)(generate_nbr(0, 255)) / 255.0f;
		color[i] = create_t_color(r, g, b, 1.0f);
	}

	while (play == 1)
	{
		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f));

		for (int i = 0; i < nb; i++)
		{
			draw_triangle_color_cpu(win, &(t[i]), &(color[i]));
		}

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
