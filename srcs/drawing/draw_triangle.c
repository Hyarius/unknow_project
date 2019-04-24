#include "unknow_project.h"

void draw_triangle(t_window *p_win, t_point p_a, t_point p_b, t_point p_c)
{
	convert_point_to_opengl(p_win, &p_a);
	convert_point_to_opengl(p_win, &p_b);
	convert_point_to_opengl(p_win, &p_c);

	draw_triangle_opengl(p_win, &p_a, &p_b, &p_c);
}
