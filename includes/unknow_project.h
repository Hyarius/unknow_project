#ifndef UNKNOW_PROJECT_H
# define UNKNOW_PROJECT_H

# include "unknow_project_includes.h"
# include "unknow_project_define.h"

# include "unknow_project_basic.h"
# include "unknow_project_structure.h"
# include "unknow_project_list.h"
# include "unknow_project_window.h"
# include "unknow_project_png_reader.h"

//
// ----------------- ALGORYTHMN -----------------
//
//			Bresenham
t_vector2_int_list
			calc_line(t_vector2_int start, t_vector2_int end);

//			PNG reader
t_texture	*png_load(char *path);

//
// ----------------- CPU_DRAWING -----------------
//
//			buffer handler
void 		add_pixel_to_screen(t_window *p_win, int p_coord, t_color *color);
void 		clean_buffers(t_window *p_win);

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
void 		draw_pixel_opengl(t_window *p_win, t_vector2 *p_coord, t_color *p_color);
void 		draw_point_opengl(t_window *p_win, t_point *p_point, int size);
void 		draw_line_opengl(t_window *p_win, t_point *p_a, t_point *p_b);
void 		draw_triangle_opengl(t_window *p_win,
					t_point *p_a, t_point *p_b, t_point *p_c);
void		draw_buffer_opengl(t_window *p_win);

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
			create_t_vector2_int_list();
t_vector2_int_list
			*initialize_t_vector2_int_list();
void		t_vector2_int_list_push_back(t_vector2_int_list *dest, t_vector2_int to_add);
void		t_vector2_int_list_add_back(t_vector2_int_list *dest, t_vector2_int *to_add);
void		free_t_vector2_int_list(t_vector2_int_list dest);
void		delete_t_vector2_int_list(t_vector2_int_list *dest);
void		clean_t_vector2_int_list(t_vector2_int_list *dest);
t_vector2_int
			t_vector2_int_list_at(t_vector2_int_list *dest, int index);
t_vector2_int
			*t_vector2_int_list_get(t_vector2_int_list *dest, int index);
int			*t_vector2_int_list_obtain(t_vector2_int_list *dest, int index);

//			vector2_int
t_vector2_int
			create_t_vector2_int(int p_x, int p_y);
t_vector2_int
			*initialize_t_vector2_int(int p_x, int p_y);
void 		t_vector2_int_swap(t_vector2_int *a, t_vector2_int *b);
void 		t_vector2_int_add(t_vector2_int *src, int delta_x, int delta_y);
void 		set_t_vector2_int(t_vector2_int *src, int p_x, int p_y);
void 		print_t_vector2_int(t_vector2_int vector, char *str);

//			vector2_list
t_vector2_list
			create_t_vector2_list();
t_vector2_list
			*initialize_t_vector2_list();
void		t_vector2_list_push_back(t_vector2_list *dest, t_vector2 to_add);
void		t_vector2_list_add_back(t_vector2_list *dest, t_vector2 *to_add);
void		free_t_vector2_list(t_vector2_list dest);
void		delete_t_vector2_list(t_vector2_list *dest);
void		clean_t_vector2_list(t_vector2_list *dest);
t_vector2	t_vector2_list_at(t_vector2_list *dest, int index);
t_vector2	*t_vector2_list_get(t_vector2_list *dest, int index);
float		*t_vector2_list_obtain(t_vector2_list *dest, int index);

//			vector2
t_vector2	create_t_vector2(float p_x, float p_y);
t_vector2	*initialize_t_vector2(float p_x, float p_y);
void 		t_vector2_swap(t_vector2 *a, t_vector2 *b);
void 		t_vector2_add(t_vector2 *src, float delta_x, float delta_y);
void 		set_t_vector2(t_vector2 *src, float p_x, float p_y);
void 		print_t_vector2(t_vector2 vector, char *str);

//
// ----------------- VECTOR3 -----------------
//
//			vector3_int_list
t_vector3_int_list
			create_t_vector3_int_list();
t_vector3_int_list
			*initialize_t_vector3_int_list();
void		t_vector3_int_list_push_back(t_vector3_int_list *dest, t_vector3_int to_add);
void		t_vector3_int_list_add_back(t_vector3_int_list *dest, t_vector3_int *to_add);
void		free_t_vector3_int_list(t_vector3_int_list dest);
void		delete_t_vector3_int_list(t_vector3_int_list *dest);
void		clean_t_vector3_int_list(t_vector3_int_list *dest);
t_vector3_int
			t_vector3_int_list_at(t_vector3_int_list *dest, int index);
t_vector3_int
			*t_vector3_int_list_get(t_vector3_int_list *dest, int index);
int			*t_vector3_int_list_obtain(t_vector3_int_list *dest, int index);

//			vector3_int
t_vector3_int
			create_t_vector3_int(int p_x, int p_y, int p_z);
t_vector3_int
			*initialize_t_vector3_int(int p_x, int p_y, int p_z);
void 		t_vector3_int_swap(t_vector3_int *a, t_vector3_int *b);
void 		t_vector3_int_add(t_vector3_int *src, int delta_x, int delta_y);
void 		set_t_vector3_int(t_vector3_int *src, int p_x, int p_y, int p_z);
void 		print_t_vector3_int(t_vector3_int vector, char *str);

//			vector3_list
t_vector3_list
			create_t_vector3_list();
t_vector3_list
			*initialize_t_vector3_list();
void		t_vector3_list_push_back(t_vector3_list *dest, t_vector3 to_add);
void		t_vector3_list_add_back(t_vector3_list *dest, t_vector3 *to_add);
void		free_t_vector3_list(t_vector3_list dest);
void		delete_t_vector3_list(t_vector3_list *dest);
void		clean_t_vector3_list(t_vector3_list *dest);
t_vector3	t_vector3_list_at(t_vector3_list *dest, int index);
t_vector3	*t_vector3_list_get(t_vector3_list *dest, int index);
float		*t_vector3_list_obtain(t_vector3_list *dest, int index);

//			vector3
t_vector3	create_t_vector3(float p_x, float p_y, float p_z);
t_vector3	*initialize_t_vector3(float p_x, float p_y, float p_z);
void 		t_vector3_swap(t_vector3 *a, t_vector3 *b);
void 		t_vector3_add(t_vector3 *src, float delta_x, float delta_y);
void 		set_t_vector3(t_vector3 *src, float p_x, float p_y, float p_z);
void 		print_t_vector3(t_vector3 vector, char *str);

//
// ----------------- COLOR ------------------
//
//
t_color_list
			create_t_color_list();
t_color_list
			*initialize_t_color_list();
void		t_color_list_push_back(t_color_list *dest, t_color to_add);
void		t_color_list_add_back(t_color_list *dest, t_color *to_add);
void		free_t_color_list(t_color_list dest);
void		delete_t_color_list(t_color_list *dest);
void		clean_t_color_list(t_color_list *dest);
t_color		t_color_list_at(t_color_list *dest, int index);
t_color		*t_color_list_get(t_color_list *dest, int index);
float		*t_color_list_obtain(t_color_list *dest, int index);

//
// ----------------- WINDOW -----------------
//
//			convert
t_vector2	convert_screen_to_opengl(t_window *p_win, t_vector2_int source);
void		convert_point_to_opengl(t_window *p_win, t_point *source);
void		convert_coord_to_opengl(t_window *p_win, t_vector2 *source);

//			fps_handler
void		check_frame();

//			window_handler
void		start_sdl();
t_window	*initialize_t_window(char *name, int size_x, int size_y);
void		prepare_screen(t_window *win, t_color color);
void		render_screen(t_window *win);

#endif
