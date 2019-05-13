#ifndef UNKNOW_PROJECT_WINDOW_H
# define UNKNOW_PROJECT_WINDOW_H

#include "unknow_project_basic.h"


typedef struct		s_window
{
	SDL_DisplayMode	current;
	SDL_Window		*window;

	t_vector3		*coord_data;

	pthread_t		threads[NB_THREAD];
	t_void_list		data[NB_THREAD];

	t_vector3_list	vertex_buffer_data[NB_THREAD];
	t_color_list	color_buffer_data[NB_THREAD];

	int				size_x;
	int				size_y;
	GLuint 			vertex_array;
	SDL_GLContext	context;

	GLuint			vertex_buffer;
	GLuint			color_buffer;
	GLuint			texture_buffer;
	GLuint			alpha_buffer;

	GLuint			program_color;
	GLuint			program_texture;
	t_vector2		pixel_delta;
}					t_window;

#endif
