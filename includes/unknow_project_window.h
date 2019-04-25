#ifndef UNKNOW_PROJECT_WINDOW_H
# define UNKNOW_PROJECT_WINDOW_H

#include "unknow_project_basic.h"

typedef struct	s_window
{
	SDL_DisplayMode
				current;
	SDL_Window	*window;
	GLfloat 	*vertex_buffer_data;
	GLfloat 	*color_buffer_data;
	char		*z_buffer;
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
	t_vector2	pixel_delta;
}				t_window;

#endif
