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
t_image *png_load(char *path);

//
// ----------------- CPU_DRAWING -----------------
//
//			buffer handler
void 		add_pixel_to_screen(t_window *p_win, int index, int p_coord, t_color *color);
void 		clean_buffers(t_window *p_win);

void 		set_variable(t_triangle *p_t, int *value, float *base, t_vector2 *delta);

//			Draw color cpu
void 		calc_triangle_color_cpu(t_window *p_win, int index, t_triangle *p_t, t_color *p_color);

//			Draw texture CPU
void		calc_triangle_texture_cpu(t_window *p_win, int index, t_triangle *p_t, t_uv *uvs);

//			Multithread_color
void 		draw_triangle_color_cpu(t_window *p_win, t_triangle_list *p_t, t_color_list *p_color);
void 		draw_triangle_texture_cpu(t_window *p_win, t_triangle *p_t_screen, t_triangle *p_t_uv, t_image *p_texture, float alpha);

//			T_rasterizer
int			apply_formula(t_rasterizer *rast, int x, int y);
void		set_rasterizer(t_rasterizer *rast, t_vector2 *s, t_vector2 *e, t_vector2 *ext);
float		calc_rasterizer(t_rasterizer *rast, int x, int y);
int			get_short(int a, int b, int c);
int			get_big(int a, int b, int c);

//
// ----------------- DRAWING -----------------
//
//			Draw rectangle

//			Draw triangle
void 		draw_triangle_color(t_window *p_win, t_triangle_list *p_t, t_color_list *p_color);
void		draw_triangle_texture(t_window *p_win, t_triangle *p_t_screen, t_triangle *p_t_uv, t_image *p_texture, float alpha);

//
// ----------------- OPENGL -----------------
//
//			Draw opengl
void 		draw_pixel_opengl(t_window *p_win, t_vector3 *p_coord, t_color *p_color);
void 		draw_point_opengl(t_window *p_win, t_vector2 *p_point, t_color *p_color, int size);
void 		draw_line_color_opengl(t_window *p_win, t_line *p_line, t_color *p_color);
void 		draw_triangle_color_opengl(t_window *p_win, t_triangle *p_triangle, t_color *p_color);
void		draw_triangle_texture_opengl(t_window *p_win, t_triangle *p_triangle_screen, t_triangle *p_triangle_uv, t_image *p_texture, float p_alpha);
void		draw_buffer_opengl(t_window *p_win);

//			Shader - handler
GLuint		load_shaders(const char * p_vertex_file_path,
						const char * p_fragment_file_path);

//
// ----------------- STRUCTURE -----------------
//

//			t_rect
t_rect		create_t_rect(float p_x, float p_y, float p_w, float p_h);

//			t_uv
t_uv		create_t_uv(t_triangle *p_triangle, t_image *p_image);
t_uv		*initialize_t_uv(t_triangle *p_triangle, t_image *p_image);

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
void 		t_vector2_int_list_set(t_vector2_int_list *dest, int index, t_vector2_int *vector);
int			*t_vector2_int_list_obtain(t_vector2_int_list *dest, int index);
void		t_vector2_int_list_resize(t_vector2_int_list *dest, int new_size);

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
void 		t_vector2_list_set(t_vector2_list *dest, int index, t_vector2 *vector);
float		*t_vector2_list_obtain(t_vector2_list *dest, int index);
void		t_vector2_list_resize(t_vector2_list *dest, int new_size);

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
void 		t_vector3_int_list_set(t_vector3_int_list *dest, int index, t_vector3_int *vector);
int			*t_vector3_int_list_obtain(t_vector3_int_list *dest, int index);
void		t_vector3_int_list_resize(t_vector3_int_list *dest, int new_size);

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
void 		t_vector3_list_set(t_vector3_list *dest, int index, t_vector3 *vector);
float		*t_vector3_list_obtain(t_vector3_list *dest, int index);

//			vector3
t_vector3	create_t_vector3(float p_x, float p_y, float p_z);
t_vector3	*initialize_t_vector3(float p_x, float p_y, float p_z);
void 		t_vector3_swap(t_vector3 *a, t_vector3 *b);
void 		t_vector3_add(t_vector3 *src, float delta_x, float delta_y);
void 		set_t_vector3(t_vector3 *src, float p_x, float p_y, float p_z);
void 		print_t_vector3(t_vector3 vector, char *str);
void		t_vector3_list_resize(t_vector3_list *dest, int new_size);

//
// ----------------- VOID_LIST --------------
//
//
t_void_list create_t_void_list();
t_void_list *initialize_t_void_list();
void		t_void_list_add_back(t_void_list *dest, int nb, ...);
void		t_void_list_push_back(t_void_list *dest, void *to_add);
void		free_t_void_list(t_void_list dest);
void		delete_t_void_list(t_void_list *dest);
void		clean_t_void_list(t_void_list *dest);
void		*t_void_list_at(t_void_list *dest, int index);
void		**t_void_list_get(t_void_list *dest, int index);

//
// ----------------- COLOR ------------------
//
//			t_color
t_color		create_t_color(float p_r, float p_g, float p_b, float p_a);
t_color		*initialize_t_color(float p_r, float p_g, float p_b, float p_a);
t_color 	create_t_color_from_int(int p_r, int p_g, int p_b, int p_a);
t_color 	*initialize_t_color_from_int(int p_r, int p_g, int p_b, int p_a);

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
void 		t_color_list_set(t_color_list *dest, int index, t_color *color);
float		*t_color_list_obtain(t_color_list *dest, int index);
void		t_color_list_resize(t_color_list *dest, int new_size);

//
// ----------------- T_TRIANGLE -----------------
//
//			t_triangle_list
t_triangle_list create_t_triangle_list();
t_triangle_list *initialize_t_triangle_list();
void	t_triangle_list_push_back(t_triangle_list *dest, t_triangle to_add);
void	t_triangle_list_add_back(t_triangle_list *dest, t_triangle *to_add);
void	free_t_triangle_list(t_triangle_list dest);
void	delete_t_triangle_list(t_triangle_list *dest);
void	clean_t_triangle_list(t_triangle_list *dest);
t_triangle	t_triangle_list_at(t_triangle_list *dest, int index);
t_triangle	*t_triangle_list_get(t_triangle_list *dest, int index);
void			t_triangle_list_resize(t_triangle_list *dest, int new_size);

//			t_triangle
t_triangle	create_t_triangle(t_vector2 p_a, t_vector2 p_b, t_vector2 p_c);
t_triangle	*initialize_t_triangle(t_vector2 p_a, t_vector2 p_b, t_vector2 p_c);

//
// ----------------- WINDOW -----------------
//
//			convert
t_vector2	convert_screen_to_opengl(t_window *p_win, int p_x, int p_y);
void		convert_vector2_to_opengl(t_window *p_win, t_vector2 *source);
t_vector2_int
				convert_vector2_to_vector2_int(t_vector2 *base);
t_vector3_int
				convert_vector3_to_vector3_int(t_vector3 *base);

//			fps_handler
void		check_frame();

//			window_handler
void		start_sdl();
t_window	*initialize_t_window(char *name, int size_x, int size_y);
void		prepare_screen(t_window *win, t_color color);
void		render_screen(t_window *win);

#endif
