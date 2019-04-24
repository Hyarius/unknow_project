#include "unknow_project.h"

void	draw_rectangle(t_window *p_win, t_rect p_rect, t_color p_color)
{
	t_point a;
	t_point b;
	t_point	c;
	t_point d;

	a = create_t_point(p_rect.x, p_rect.y, p_color);
	b = create_t_point(p_rect.x, p_rect.y + p_rect.h, p_color);
	c = create_t_point(p_rect.x + p_rect.w, p_rect.y + p_rect.h, p_color);
	d = create_t_point(p_rect.x + p_rect.w, p_rect.y, p_color);

	draw_triangle(p_win, a, b, c);
	draw_triangle(p_win, c, d, a);
}
