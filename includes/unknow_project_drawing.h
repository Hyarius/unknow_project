/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_drawing.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:53:35 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/20 15:59:02 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_DRAWING_H
# define UNKNOW_PROJECT_DRAWING_H

# include "unknow_project_window.h"
# include "unknow_project_camera.h"
# include "unknow_project_mesh.h"

/*
** ----------------- OPENGL -----------------
*/
void		draw_buffer_opengl(t_window *p_win, t_color *color_data);

/*
** ----------------- CPU_DRAWING -----------------
*/

t_vec4		calc_w(t_fuck_norme data);
void		get_min_max_draw_triangle(t_view_port *view_port, t_vec4 *min,
																t_vec4 *max);

/*
** ---------------- draw color cpu ----------------
*/

void		draw_triangle_color_cpu(t_view_port *p_view_port,
									t_triangle *p_triangle, t_color *p_color);
void		multithreading_draw_triangle_color_cpu(t_view_port *p_view_port,
				t_triangle_list *p_triangle_list, t_color_list *p_color_list);
void		draw_rectangle_color_cpu(t_view_port *p_view_port,
										t_rectangle p_rec, t_color *p_color);
void		draw_hud_rect(t_view_port *p_view_port, t_rectangle p_rec,
															t_color *p_color);

/*
** ---------------- draw_texture cpu ----------------
*/

void		draw_triangle_texture_cpu(t_view_port *p_view_port,
											t_triangle *p_triangle, t_uv *p_uv);
void		*thread_draw_texture_cpu(void *void_list);
void		multithreading_draw_triangle_texture_cpu(t_view_port *p_view_port,
						t_triangle_list *p_triangle_list, t_uv_list *p_uv_list);
void		draw_rectangle_texture_cpu(t_view_port *p_view_port,
									t_rectangle p_rec, t_texture *p_texture);

void		draw_t_mesh(t_camera *p_cam, t_mesh *mesh);
void		init_points_uv(t_mesh *mesh, t_face face, t_vec4 *points_uv);
void		init_points(t_mesh *mesh, t_face face, t_vec4 *points);
t_triangle	init_triangle_clipped(t_mesh *mesh, t_camera *p_cam, int j);
void		apply_darkness_on_mesh_with_texture(t_mesh *mesh, t_camera *p_cam,
								t_color darkness_color, t_triangle triangle);
void		apply_darkness_on_mesh_without_texture(t_camera *p_cam, t_face face,
								t_color darkness_color, t_triangle triangle);
void		find_darkness(t_mesh *mesh, t_face face, t_camera *p_cam,
																int nb_clip);
void		how_many_points_clipped(t_mesh *mesh, t_face face, t_camera *p_cam);

#endif
