#ifndef UNKNOW_PROJECT_WINDOW_H
# define UNKNOW_PROJECT_WINDOW_H

# include "unknow_project_includes.h"
# include "unknow_project_define.h"
# include "unknow_project_list.h"

typedef struct		s_window
{
	SDL_DisplayMode	current; //ecran actuel de travail
	SDL_Window		*window; //la fenetre

	int				size_x; //taille en x de la fenetre
	int				size_y; // taille en y de la fenetre
	GLuint 			vertex_array; //adresse de la grosse boite des tube de peinture
	SDL_GLContext	context; //la toile du peintre

	GLuint			vertex_buffer; //le pot de peinture vertex
	GLuint			color_buffer; //le pot de peinture color
	GLuint			texture_buffer; //le pot de peinture texture
	GLuint			alpha_buffer; //le pot de peinture alpha

	GLuint			program_color; //le livre qui explique la couleur
	GLuint			program_texture; //le livre qui explique la texture

}					t_window;

//			fps_handler
void		check_frame();

//			window_handler
void		start_sdl();
t_window	*initialize_t_window(char *name, int size_x, int size_y);
void		prepare_screen(t_window *win, t_color color);
void		render_screen(t_window *win);

#endif
