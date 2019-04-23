#ifndef UNKNOW_PROJECT_H
# define UNKNOW_PROJECT_H

# include "unknow_project_includes.h"
# include "unknow_project_define.h"

# include "unknow_project_basic.h"
# include "unknow_project_structure.h"
# include "unknow_project_list.h"
# include "unknow_project_gui.h"
# include "unknow_project_game_engine.h"
# include "unknow_project_window.h"

GLuint		load_shaders(const char * vertex_file_path, const char * fragment_file_path);
void		start_sdl();
t_window	create_t_window(char *name, int size_x, int size_y);
t_window	*initialize_t_window(char *name, int size_x, int size_y);
void		prepare_screen(t_color color);
void		render_screen(t_window win);
t_color 	create_t_color(float r, float g, float b, float a);
t_color 	*initialize_t_color(float r, float g, float b, float a);
t_point		create_t_point(float p_x, float p_y, t_color p_color);
void		draw_triangle(t_window p_win, t_point p_a, t_point p_b, t_point p_c);
t_vector2 	create_t_vector2(float p_x, float p_y);
t_vector2	*initialize_t_vector2(float p_x, float p_y);
t_vector3 	create_t_vector3(float p_x, float p_y, float p_z);
t_vector3	*initialize_t_vector3(float p_x, float p_y, float p_z);
t_vector2	convert_screen_to_opengl(t_window p_win, t_vector2 source);
void		set_t_point_vector2(t_point *p_src, t_vector2 p_coord);
void		set_t_point_int(t_point *p_src, int p_x, int p_y);
void		set_t_point_float(t_point *p_src, float p_x, float p_y);
void 		draw_triangle_opengl(t_window p_win, t_point p_a, t_point p_b, t_point p_c);
void		draw_rectangle(t_window p_win, t_rect p_rect, t_color p_color);
t_rect		create_t_rect(float p_x, float p_y, float p_w, float p_h);


#endif
