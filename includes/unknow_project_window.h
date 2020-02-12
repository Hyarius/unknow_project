/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_window.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:28:31 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/11 16:09:35 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_WINDOW_H
# define UNKNOW_PROJECT_WINDOW_H

# include "unknow_project_includes.h"
# include "unknow_project_define.h"
# include "unknow_project_basic_list.h"

typedef struct		s_window
{
	SDL_Window		*window;

	int				size_x;
	int				size_y;
	GLuint			vertex_array;
	SDL_GLContext	context;

	GLuint			vertex_buffer;
	GLuint			vertex_fixed_buffer;
	GLuint			color_buffer;
	GLuint			color_fixed_buffer;
	GLuint			texture_buffer;
	GLuint			alpha_buffer;

	GLuint			program_color;

	t_vector3		*vertex_data;
	t_color			*color_data;

	pthread_t		threads[NB_THREAD_MAX];
	t_void_list		data[NB_THREAD_MAX];

}					t_window;

void				start_sdl();
t_window			*initialize_t_window(char *name, int size_x, int size_y);
int					is_point_in_screen(t_window *p_win, t_vec4 p_point);
int					is_t_triangle_in_screen(t_window *p_win,
											t_triangle *p_triangle);
void				window_handler_clear_buffers(t_window *win);

typedef struct		s_view_port
{
	t_window		*window;

	t_vec2_int		pos;

	t_vec2_int		size;

	float			*depth_buffer;

}					t_view_port;

t_view_port			new_view_port(t_window *window, t_vec2_int pos,
									t_vec2_int size);
t_view_port			*initialize_t_view_port(t_window *window, t_vec2_int pos,
									t_vec2_int size);
void				move_t_view_port(t_view_port *view, t_vec2_int new_pos);
void				resize_t_view_port(t_view_port *view, t_vec2_int new_size);
void				t_view_port_change_window(t_view_port *view,
											t_window *p_window);
void				t_view_port_clear_buffers(t_view_port *view);
void				free_t_view_port(t_view_port **dest);

#endif
