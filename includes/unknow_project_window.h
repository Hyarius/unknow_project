#ifndef UNKNOW_PROJECT_WINDOW_H
# define UNKNOW_PROJECT_WINDOW_H

typedef struct	s_window
{
	SDL_DisplayMode
				current;
	SDL_Window	*window;
	int			size_x;
	int			size_y;
	GLuint 		vertex_array;
	SDL_GLContext
				context;
	GLuint		vertex_buffer;
	GLuint		color_buffer;
	GLuint		texture_buffer;
	GLuint		alpha_buffer;
	GLuint		program_color;
}				t_window;

#endif
