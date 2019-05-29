#include "unknow_project.h"

void 		draw_line_color_cpu(t_window *p_win, t_line *p_line, t_color *p_color)
{
	t_vector2_int pixel;
	t_vector2_int a;
	t_vector2_int b;
	t_vector2_int_list point_list;
	float depth;
	float delta_depth;


	p_line->a = convert_opengl_to_vector3(p_win, &(p_line->a));
	p_line->b = convert_opengl_to_vector3(p_win, &(p_line->b));

	depth = p_line->a.z;
	delta_depth = (p_line->b.z - p_line->a.z) / (float)(point_list.size);

	a = create_t_vector2_int((int)(p_line->a.x), (int)(p_line->a.y));
	b = create_t_vector2_int((int)(p_line->b.x), (int)(p_line->b.y));
	point_list = calc_line(a, b);

	for (int i = 0; i < point_list.size; i++)
	{
		pixel = t_vector2_int_list_at(&point_list, i);

		if (p_win->depth_buffer[i] == 0 || depth == 0 || depth <= p_win->depth_buffer[i])
		{
			p_win->depth_buffer[i] = depth;
			draw_pixel(p_win, pixel.x, pixel.y, p_color);
		}
		depth += delta_depth;
	}
}
