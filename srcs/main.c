#include "unknow_project.h"

int main(int argc, char **argv)
{
	if (argc != 1)
		error_exit(-1, "Bad argument");

	start_sdl();

	t_window win;
	win = create_t_window(argv[0], 600, 480);

	SDL_Event event;
	int play;
	play = 1;

	int saved_button = -1;
	int		index[4] = {1, 0, 2, -1};
	t_color	color[3];
	color[0] = create_t_color(1.0, 0.0, 0.0, 1.0);
	color[1] = create_t_color(0.0, 1.0, 0.0, 1.0);
	color[2] = create_t_color(0.0, 0.0, 1.0, 1.0);
	t_rect	rect[3];
	rect[0] = create_t_rect(125, 130, 75, 80);
	rect[1] = create_t_rect(100, 100, 50, 100);
	rect[2] = create_t_rect(400, 251, 150, 40);

	while (play == 1)
	{
		prepare_screen(create_t_color(0.0f, 0.0f, 0.0f, 0.0f));

		int i = 0;
		while (index[i] != -1)
		{
			draw_rectangle(win, rect[index[i]], color[index[i]]);
			i++;
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
			//Detecter le clic de sourie
			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			{
				int j = 0;
				while (j < 3)
				{
					// detecte la position de la sourie
					if (event.button.x >= rect[j].x && event.button.y >= rect[j].y &&
						event.button.x < rect[j].x + rect[j].w && event.button.y < rect[j].y + rect[j].w )
						saved_button = j;
					j++;
				}
			}
			// detecte le relachement du clic sourie
			if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
			{
				saved_button = -1;
			}
			// detecte les mouvement de la sourie
			if (event.type == SDL_MOUSEMOTION)
			{
				if (saved_button != -1)
				{
					// xrel yrel sont la position relative par rapport a la frame precedente
					rect[saved_button].x += event.motion.xrel;
					rect[saved_button].y += event.motion.yrel;
				}
			}
		}
	}

	return (0);
}
