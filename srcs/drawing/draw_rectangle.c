#include "unknow_project.h"

void	draw_rectangle_color(t_window *p_win, t_rect p_rect, t_color p_color)
{
	t_triangle triangle[2];
	t_vector2 coord[4];

	coord[0] = create_t_vector2(p_rect.x, p_rect.y);
	coord[1] = create_t_vector2(p_rect.x, p_rect.y + p_rect.h);
	coord[2] = create_t_vector2(p_rect.x + p_rect.w, p_rect.y + p_rect.h);
	coord[3] = create_t_vector2(p_rect.x + p_rect.w, p_rect.y);

	triangle[0] = create_t_triangle(coord[0], coord[1], coord[2]);
	triangle[1] = create_t_triangle(coord[2], coord[3], coord[0]);

	draw_triangle_color(p_win, &triangle[0], &p_color);
	draw_triangle_color(p_win, &triangle[1], &p_color);
}
