#include "unknow_project.h"

/*

1) Constructeur
2) Malloceur

*/

void			start_sdl()
{
	//initialisation SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//version SDL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	//utilasation de la carte graphique
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	//Limitation de l'utilisation d'OpenGL (decrepated functions)
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	//doublebuffering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//profondeur du buffer
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

	//initialisation du ramdom et du TTF
	srand(time(NULL));
	TTF_Init();
}

t_window		create_t_window(char *p_name, int p_size_x, int p_size_y)
{
	t_window	win;

	// creation de la fenetre
	win.window = SDL_CreateWindow(p_name, // nom de la fenetre
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // position de la fentre sur l'ecran
					p_size_x, p_size_y, // taille de la fenetre
					SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL); //parametre de la fenetre

	// stockage de la taille de la fenetre dans win.size_x et win.size_y
	SDL_GetWindowSize(win.window, &win.size_x, &win.size_y);

	// creation du context
	win.context = SDL_GL_CreateContext(win.window);

	// generation du VAO (vertex array object)
	glGenVertexArrays(1, &win.vertex_array);

	// bind le VAO
	glBindVertexArray(win.vertex_array);

	// generation des VBO (vertex buffer object)
	glGenBuffers(1, &win.vertex_buffer);
	glGenBuffers(1, &win.color_buffer);
	glGenBuffers(1, &win.texture_buffer);
	glGenBuffers(1, &win.alpha_buffer);

	// bind VAO
	glBindVertexArray(win.vertex_array);

	// create shader program
	win.program_color = load_shaders("ressources/shader/color_shader.vert", "ressources/shader/color_shader.frag");

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);
	SDL_GL_SetSwapInterval(0);

	return (win);
}

t_window		*initialize_t_window(char *name, int size_x, int size_y)
{
	t_window	*win;

	if (!(win = (t_window *)malloc(sizeof(t_window))))
		return (NULL);

	*win = create_t_window(name, size_x, size_y);

	return (win);
}

void				prepare_screen(t_color color)
{
	//Set background color
	glClearColor((GLclampf)color.r, (GLclampf)color.g, (GLclampf)color.b, 0.0f);

	//Clear la profondeur et la couleur du buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void				render_screen(t_window *win)
{
	check_frame();

	//Swap le buffer et l'ecran (Ca affiche la nouvelle image)
	SDL_GL_SwapWindow(win->window);
}
