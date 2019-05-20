#ifndef UNKNOW_PROJECT_DRAWING_H
# define UNKNOW_PROJECT_DRAWING_H

# include "unknow_project_window.h"

//
// ----------------- CPU_DRAWING -----------------
//
//			buffer handler
void 		add_pixel_to_screen(t_window *p_win, int p_coord, t_color *color);
void 		clean_buffers(t_window *p_win, t_color color);
void		clean_z_buffer(t_window *p_win);
void 		set_variable(t_triangle *p_t, int *value, float *base, t_vector2 *delta);

//			Draw color cpu
void 		calc_triangle_color_cpu(t_window *p_win, int index, t_triangle *p_t, t_color *p_color);

//			Draw texture CPU
void		calc_triangle_texture_cpu(t_window *p_win, int index, t_triangle *p_t, t_uv *uvs);

//			Multithread_color
void 		draw_triangle_color_cpu(t_window *p_win, t_triangle_list *p_t, t_color_list *p_color);
void 		draw_triangle_texture_cpu(t_window *p_win, t_triangle_list *p_triangle, t_uv_list *p_uvs);

//
// ----------------- DRAWING -----------------
//

//			Draw triangle
void 		draw_triangle_color(t_window *p_win, t_triangle_list *p_t, t_color_list *p_color);
void		draw_triangle_texture(t_window *p_win, t_triangle_list *p_t, t_uv_list *p_uv);

//
// ----------------- OPENGL -----------------
//
//			Draw opengl
void 		draw_pixel_opengl(t_window *p_win, t_vector3 *p_coord, t_color *p_color);
void 		draw_point_opengl(t_window *p_win, t_vector2 *p_point, t_color *p_color, int size);
void 		draw_line_color_opengl(t_window *p_win, t_line *p_line, t_color *p_color);
void 		draw_triangle_color_opengl(t_window *p_win, t_triangle *p_triangle, t_color *p_color);
void		draw_triangle_texture_opengl(t_window *p_win, t_triangle *p_triangle_screen, t_uv *us);
void		draw_buffer_opengl(t_window *p_win);

void		draw_t_mesh(t_window *p_win, t_vector3 camera, t_mesh *mesh);

#endif
