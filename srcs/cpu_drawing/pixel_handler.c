#include "unknow_project.h"

void	draw_pixel(t_window *p_win, int x, int y, t_color *p_color)
{
	int i;

	if (x >= 0 && x < p_win->size_x &&
		y >= 0 && y < p_win->size_y)
	{
		i = x + y * p_win->size_x;
		p_win->color_data[i] = *p_color;
	}
}
