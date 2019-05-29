#include "unknow_project.h"

void draw_triangle_color(t_window *p_win, t_triangle *p_t, t_color *p_color)
{
	t_triangle triangle;
	t_vector3 coord[3];

	coord[0] = convert_screen_to_opengl(p_win, &(p_t->a));
	coord[1] = convert_screen_to_opengl(p_win, &(p_t->b));
	coord[2] = convert_screen_to_opengl(p_win, &(p_t->c));

	triangle = create_t_triangle(coord[0], coord[1], coord[2]);

	draw_triangle_color_opengl(p_win, &triangle, p_color);
}

void draw_triangle_texture(t_window *p_win, t_triangle *p_t, t_uv *p_uv)
{
	t_triangle triangle;
	t_vector3 coord[3];

	coord[0] = convert_screen_to_opengl(p_win, &(p_t->a));
	coord[1] = convert_screen_to_opengl(p_win, &(p_t->b));
	coord[2] = convert_screen_to_opengl(p_win, &(p_t->c));

	triangle = create_t_triangle(coord[0], coord[1], coord[2]);

	draw_triangle_texture_opengl(p_win, &triangle, p_uv);
}
