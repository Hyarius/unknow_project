#include "unknow_project.h"

void draw_triangle_color(t_window *p_win, t_triangle *p_t, t_color *p_color)
{
	t_triangle triangle;
	t_vector2 coord[3];

	coord[0] = convert_screen_to_opengl(p_win, (int)(p_t->a.x), (int)(p_t->a.y));
	coord[1] = convert_screen_to_opengl(p_win, (int)(p_t->b.x), (int)(p_t->b.y));
	coord[2] = convert_screen_to_opengl(p_win, (int)(p_t->c.x), (int)(p_t->c.y));

	triangle = create_t_triangle(coord[0], coord[1], coord[2]);

	draw_triangle_color_opengl(p_win, &triangle, p_color);
}

void draw_triangle_texture(t_window *p_win, t_triangle *p_t, t_uv *p_uv)
{
	t_triangle triangle;
	t_vector2 coord[3];

	coord[0] = convert_screen_to_opengl(p_win, (int)(p_t->a.x), (int)(p_t->a.y));
	coord[1] = convert_screen_to_opengl(p_win, (int)(p_t->b.x), (int)(p_t->b.y));
	coord[2] = convert_screen_to_opengl(p_win, (int)(p_t->c.x), (int)(p_t->c.y));

	triangle = create_t_triangle(coord[0], coord[1], coord[2]);

	draw_triangle_texture_opengl(p_win, &triangle, p_uv);
}
