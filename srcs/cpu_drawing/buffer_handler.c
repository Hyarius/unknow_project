#include "unknow_project.h"

void add_pixel_to_screen(t_window *p_win, int p_coord, t_color *color)
{
	p_win->color_buffer_data[p_coord * 4 + 0] = color->r;
	p_win->color_buffer_data[p_coord * 4 + 1] = color->g;
	p_win->color_buffer_data[p_coord * 4 + 2] = color->b;
	p_win->color_buffer_data[p_coord * 4 + 3] = color->a;
}

void clean_color_buffer(t_window *p_win, t_color *p_color)
{
	int	i;
	int	max;

	max = p_win->size_x * p_win->size_y;
	i = 0;
	while(i < max)
	{
		p_win->color_buffer_data[(i * 4)] = p_color->r;
		p_win->color_buffer_data[(i * 4) + 1] = p_color->g;
		p_win->color_buffer_data[(i * 4) + 2] = p_color->b;
		p_win->color_buffer_data[(i * 4) + 3] = p_color->a;
		i++;
	}
}
