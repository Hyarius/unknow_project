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

t_window		*initialize_t_window(char *p_name, int p_size_x, int p_size_y)
{
	int			i;
	t_window	*win;
	t_vector2	coord[2];
	t_color		color;

	if (!(win = (t_window *)malloc(sizeof(t_window))))
		error_exit(-6, "Can't malloc a t_window");

	// creation de la fenetre
	win->window = SDL_CreateWindow(p_name, // nom de la fenetre
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // position de la fentre sur l'ecran
					p_size_x, p_size_y, // taille de la fenetre
					SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL); //parametre de la fenetre

	// stockage de la taille de la fenetre dans win->size_x et win->size_y
	SDL_GetWindowSize(win->window, &win->size_x, &win->size_y);

	// creation du context
	win->context = SDL_GL_CreateContext(win->window);

	// generation du VAO (vertex array object)
	glGenVertexArrays(1, &win->vertex_array);

	// bind le VAO
	glBindVertexArray(win->vertex_array);

	// generation des VBO (vertex buffer object)
	glGenBuffers(1, &win->vertex_buffer);
	glGenBuffers(1, &win->color_buffer);
	glGenBuffers(1, &win->texture_buffer);
	glGenBuffers(1, &win->alpha_buffer);

	// bind VAO
	glBindVertexArray(win->vertex_array);

	// create shader program
	win->program_color = load_shaders("ressources/shader/color_shader.vert", "ressources/shader/color_shader.frag");
	win->program_texture = load_shaders("ressources/shader/texture_shader.vert", "ressources/shader/texture_shader.frag");

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);
	SDL_GL_SetSwapInterval(0);

	coord[0] = convert_screen_to_opengl(win, 0, 0);
	coord[1] = convert_screen_to_opengl(win, 1, 1);
	win->pixel_delta = create_t_vector2(coord[1].x - coord[0].x, coord[1].y - coord[0].y);

	if (!(win->coord_data = (t_vector3 *)malloc(sizeof(t_vector3) * (win->size_x * win->size_y))))
		error_exit(-9, "Can't malloc a GLfloat array");

	win->vertex_buffer_data = create_t_vector3_list();
	win->color_buffer_data = create_t_color_list();

	i = 0;
	while (i < win->size_x * win->size_y)
	{
		win->coord_data[i].x = (((i % win->size_x) - win->size_x / 2) + 1) * win->pixel_delta.x;
		win->coord_data[i].y = (((i / win->size_x) - win->size_y / 2)) * win->pixel_delta.y;
		win->coord_data[i].z = 0.0f;
		i++;
	}
	return (win);
}

void				prepare_screen(t_window *win, t_color color)
{
	clean_buffers(win);

	//Set background color
	glClearColor((GLclampf)color.r, (GLclampf)color.g, (GLclampf)color.b, 0.0f);

	//Clear la profondeur et la couleur du buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void				render_screen(t_window *win)
{
	check_frame();

	draw_buffer_opengl(win);

	//Swap le buffer et l'ecran (Ca affiche la nouvelle image)
	SDL_GL_SwapWindow(win->window);
}
