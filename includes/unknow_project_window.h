#ifndef UNKNOW_PROJECT_WINDOW_H
# define UNKNOW_PROJECT_WINDOW_H

# include "unknow_project_includes.h"
# include "unknow_project_define.h"
# include "unknow_project_list.h"

typedef struct		s_window
{
	SDL_DisplayMode	current; //ecran actuel de travail
	SDL_Window		*window; //la fenetre

	int				*z_buffer; //Store la profondeur de l'image (CF jeremy pour l'explication)
	t_vector3		*coord_data; //contient 3 vecteur

	pthread_t		threads[NB_THREAD]; //pointeur pour le multithreading
	t_void_list		data[NB_THREAD]; //liste qui donne au thread les element dont il a besoin

	t_vector3_list	*vertex_buffer_data; //liste a 3 vecteurs
	t_color_list	*color_buffer_data; //liste des couleurs des triangle

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
	t_vector2		pixel_delta; //la difference entre le pixel 0;0 et le pixel 1;1
}					t_window;

//			fps_handler
void		check_frame();

//			window_handler
void		start_sdl();
t_window	*initialize_t_window(char *name, int size_x, int size_y);
void		prepare_screen(t_window *win, t_color color, int state);
void		render_screen(t_window *win, int state);

#endif
