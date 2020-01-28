/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:21:49 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/24 13:21:19 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_H
# define UNKNOW_PROJECT_H

# include "unknow_project_includes.h"
# include "unknow_project_define.h"
# include "unknow_project_basic.h"
# include "unknow_project_math.h"
# include "unknow_project_drawing.h"
# include "unknow_project_system.h"
# include "unknow_project_engine.h"
# include "unknow_project_list.h"
# include "unknow_project_algorithm.h"
# include "unknow_project_gui.h"
# include "unknow_project_player.h"
# include "unknow_project_item.h"

t_texture		*png_load(char *path);
GLuint			load_shaders(const char *p_vertex_file_path,
						const char *p_fragment_file_path);
t_vec4			convert_screen_to_opengl(t_view_port *p_view_port,
										t_vec4 source);
t_vec4			convert_opengl_to_vec4(t_view_port *p_view_port, t_vec4 source);
float			degree_to_radius(float angle);
float			radius_to_degree(float radian);
t_uv			convert_t_uv_to_texture(t_uv *source);
void			prepare_screen(t_window *win, t_color color);
void			check_frame(t_engine *engine);
void			render_screen(t_window *win, t_engine *engine);
void			clear_buffers(t_window *win);
void			draw_pixel(t_window *p_win, int x, int y, t_color color);
t_triangle		compose_t_triangle_from_t_mesh(t_mesh *src, int *index);
t_triangle		compose_t_triangle_from_t_vertices(t_vec4_list *src,
													int *index);
void			ft_get_leaks(char *prog_name, char *msg);
void			tar_ressources(void);
void			untar_ressources(void);
void			display_tittle_screen(t_camera *main_camera, t_gui *gui,
									t_engine *engin, t_window *win);
void			game_playing(t_camera *main_camera, t_gui *gui,
									t_engine *engine, t_window *win);
void			game_pausing(t_camera *main_camera, t_gui *gui,
									t_engine *engin, t_window *win);
void			level_editing(t_camera *main_camera, t_gui *gui,
									t_engine *engin, t_window *win);
void			level_editing_pausing(t_camera *main_camera, t_gui *gui,
									t_engine *engin, t_window *win);

#endif
