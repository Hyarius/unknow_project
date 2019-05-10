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

	int nb = 1;

	t_color *color;
	t_vector2	*coord;
	t_triangle	*t;
	int delta = 800;

	color = (t_color *)malloc(sizeof(t_color) * nb);
	coord = (t_vector2 *)malloc(sizeof(t_vector2) * (nb * 3));
	t = (t_triangle *)malloc(sizeof(t_triangle) * nb);

	if (nb == 1)
	{
		color[0] = create_t_color(1.0, 0.0, 0.0, 1.0);
		coord[0] = create_t_vector2(50, 50);
		coord[1] = create_t_vector2(50 + delta, 50);
		coord[2] = create_t_vector2(50, 50 + delta);
		t[0] = create_t_triangle(coord[0], coord[1], coord[2]);
	}
	else
	{
		for (int i = 0; i < nb; i++)
		{
			int x = generate_nbr(50, win->size_x - 50 - delta);
			int y = generate_nbr(50, win->size_y - 50 - delta);
			coord[i * 3] = create_t_vector2(x, y);
			coord[i * 3 + 1] = create_t_vector2(x + delta, y);
			coord[i * 3 + 2] = create_t_vector2(x, y + delta);

			float r = (float)(generate_nbr(0, 255)) / 255.0f;
			float g = (float)(generate_nbr(0, 255)) / 255.0f;
			float b = (float)(generate_nbr(0, 255)) / 255.0f;
			color[i] = create_t_color(r, g, b, 1.0f);

			t[i] = create_t_triangle(coord[i * 3], coord[i * 3 + 1], coord[i * 3 + 2]);
		}
	}

	t_triangle t_sprite;

	t_sprite = create_t_triangle(create_t_vector2(0.0f, 0.0f), create_t_vector2(1.0f, 0.0f), create_t_vector2(0.0f, 1.0f));

	t_texture *texture = png_load("003.png");

	while (play == 1)
	{
		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f));

		for (int i = 0; i < nb; i++)
		{
			draw_triangle_color(win, &(t[i]), &(color[i]));
			draw_triangle_texture(win, &(t[i]), &t_sprite, texture, 1.0f);
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
		}
	}
	return (0);
}
