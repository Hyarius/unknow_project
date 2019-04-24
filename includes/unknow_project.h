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

//
// ----------------- ALGORYTHMN -----------------
//
t_vector2_int_list
			calc_line(t_vector2_int start, t_vector2_int end);


//
// ----------------- CPU_DRAWING -----------------
//
//			Draw triangle cpu
void 		draw_triangle_cpu(t_window *p_win,
		t_point p_a, t_point p_b, t_point p_c);

//
// ----------------- DRAWING -----------------
//
//			Draw rectangle
void		draw_rectangle(t_window *p_win, t_rect p_rect, t_color p_color);

//			Draw triangle
void 		draw_triangle(t_window *p_win,
					t_point p_a, t_point p_b, t_point p_c);

//
// ----------------- OPENGL -----------------
//
//			Draw opengl
void 		draw_pixel_opengl(t_window *p_win, t_point *p_pixel, int size);
void 		draw_line_opengl(t_window *p_win, t_point *p_a, t_point *p_b);
void 		draw_triangle_opengl(t_window *p_win,
					t_point *p_a, t_point *p_b, t_point *p_c);

//			Shader - handler
GLuint		load_shaders(const char * p_vertex_file_path,
					const char * p_fragment_file_path);

//
// ----------------- STRUCTURE -----------------
//
//			t_color
t_color		create_t_color(float p_r, float p_g, float p_b, float p_a);
t_color		*initialize_t_color(float p_r, float p_g, float p_b, float p_a);
//			t_point
t_point		create_t_point(float p_x, float p_y, t_color p_color);
void 		t_point_swap(t_point *a, t_point *b);
//			t_rect
t_rect		create_t_rect(float p_x, float p_y, float p_w, float p_h);

//
// ----------------- VECTOR2 -----------------
//
//			vector2_int_list
t_vector2_int_list
			create_t_vector2_int_list(t_vector2_int src);
t_vector2_int_list
			*initialize_t_vector2_int_list(t_vector2_int src);
int			t_vector2_int_list_len(t_vector2_int_list *src);
void		t_vector2_int_list_push_back(t_vector2_int_list *dest, t_vector2_int to_add);
void		t_vector2_int_list_add(t_vector2_int_list *front, t_vector2_int_list *back);
void		free_t_vector2_int_list(t_vector2_int_list dest);
void		delete_t_vector2_int_list(t_vector2_int_list *dest);

//			vector2_int
t_vector2_int
			create_t_vector2_int(int p_x, int p_y);
t_vector2_int
			*initialize_t_vector2_int(int p_x, int p_y);
void 		t_vector2_int_swap(t_vector2_int *a, t_vector2_int *b);
void 		t_vector2_int_add(t_vector2_int *src, int delta_x, int delta_y);
void 		set_t_vector2_int(t_vector2_int *src, int p_x, int p_y);

//			vector2_list
t_vector2_list
			create_t_vector2_list(t_vector2 src);
t_vector2_list
			*initialize_t_vector2_list(t_vector2 src);
int			t_vector2_list_len(t_vector2_list *src);
void		t_vector2_list_push_back(t_vector2_list *dest, t_vector2 to_add);
void		t_vector2_list_add(t_vector2_list *front, t_vector2_list *back);
void		free_t_vector2_list(t_vector2_list dest);
void		delete_t_vector2_list(t_vector2_list *dest);

//			vector2
t_vector2 	create_t_vector2(float p_x, float p_y);
t_vector2	*initialize_t_vector2(float p_x, float p_y);
void 		t_vector2_swap(t_vector2 *a, t_vector2 *b);
void 		t_vector2_add(t_vector2 *src, float delta_x, float delta_y);
void 		set_t_vector2(t_vector2 *src, float p_x, float p_y);

//
// ----------------- VECTOR3 -----------------
//
//			vector3_int_list
t_vector3_int_list
			create_t_vector3_int_list(t_vector3_int src);
t_vector3_int_list
			*initialize_t_vector3_int_list(t_vector3_int src);
int			t_vector3_int_list_len(t_vector3_int_list *src);
void		t_vector3_int_list_push_back(t_vector3_int_list *dest, t_vector3_int to_add);
void		t_vector3_int_list_add(t_vector3_int_list *front, t_vector3_int_list *back);
void		free_t_vector3_int_list(t_vector3_int_list dest);
void		delete_t_vector3_int_list(t_vector3_int_list *dest);

//			vector3_int
t_vector3_int
			create_t_vector3_int(int p_x, int p_y, int p_z);
t_vector3_int
			*initialize_t_vector3_int(int p_x, int p_y, int p_z);
void 		t_vector3_int_swap(t_vector3_int *a, t_vector3_int *b);
void 		set_t_vector3_int(t_vector3_int *src, int p_x, int p_y, int p_z);

//			vector3_list
t_vector3_list
			create_t_vector3_list(t_vector3 src);
t_vector3_list
			*initialize_t_vector3_list(t_vector3 src);
int			t_vector3_list_len(t_vector3_list *src);
void		t_vector3_list_push_back(t_vector3_list *dest, t_vector3 to_add);
void		t_vector3_list_add(t_vector3_list *front, t_vector3_list *back);
void		free_t_vector3_list(t_vector3_list dest);
void		delete_t_vector3_list(t_vector3_list *dest);

//			vector3
t_vector3	create_t_vector3(float p_x, float p_y, float p_z);
t_vector3	*initialize_t_vector3(float p_x, float p_y, float p_z);
void		t_vector3_swap(t_vector3 *a, t_vector3 *b);
void		set_t_vector3(t_vector3 *src, float p_x, float p_y, float p_z);

//
// ----------------- WINDOW -----------------
//
//			convert
t_vector2	convert_screen_to_opengl(t_window *p_win, t_vector2_int source);
void		convert_point_to_opengl(t_window *p_win, t_point *source);

//			fps_handler
void		check_frame();

//			window_handler
void		start_sdl();
t_window	create_t_window(char *p_name, int p_size_x, int p_size_y);
t_window	*initialize_t_window(char *name, int size_x, int size_y);
void		prepare_screen(t_color color);
void		render_screen(t_window *win);

#endif
