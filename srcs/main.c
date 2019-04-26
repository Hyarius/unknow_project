#include "unknow_project.h"

int main(int argc, char **argv)
{
	if (argc != 1)
		error_exit(-1, "Bad argument");

	/*start_sdl();

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

	png_load("003.png");

	while (play == 1)
	{
		prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f));

		draw_triangle_cpu(win, a, b, c);
		draw_triangle_cpu(win, d, e, f);
		draw_triangle_cpu(win, a, e, d);
		draw_triangle_cpu(win, c, b, d);
		draw_triangle_cpu(win, a, f, c);
		draw_triangle_cpu(win, c, d, e);
		draw_triangle_cpu(win, c, f, b);

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
	}*/

	t_vector2_list list = create_t_vector2_list();

	t_vector2_list_push_back(&list, create_t_vector2(1.0, 2.0));
	t_vector2_list_push_back(&list, create_t_vector2(2.0, 5.0));
	t_vector2_list_push_back(&list, create_t_vector2(12.5, 15.0));

	t_vector2 vector = t_vector2_list_at(&list, 2); // return l'element ou null si < 0 || > size

	print_t_vector2(vector, "test");

	float	*test = t_vector2_list_obtain(&list, 0);

	printf("test float = %0.4f / %0.4f\n", test[2], test[3]);

	return (0);
}
