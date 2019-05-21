#include "unknow_project.h"

void draw_t_mesh(t_window *p_win, t_matrix *mvp, t_mesh *mesh)
{
	t_color color;
	t_line test;

	test = create_t_line(create_t_vector2(50, 50), create_t_vector2(348, 154));
	color = create_t_color_from_int(255, 255, 255, 255);

	draw_line(p_win, &test, &color);
}
