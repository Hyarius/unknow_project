#include "unknow_project.h"

float	dist_max;

void	draw_triangle_depth_cpu(t_window *p_win, t_triangle *p_triangle)
{
	t_color			test = create_t_color(1.0, 1.0, 1.0, 1.0);
	t_vector3		min;
	t_vector3		max;
	t_vector3		current;
	t_rasterizer	ab;
	t_rasterizer	ac;
	float			alpha;
	float			beta;
	float			gamma;

	p_triangle->a = convert_opengl_to_vector3(p_win, p_triangle->a);
	p_triangle->b = convert_opengl_to_vector3(p_win, p_triangle->b);
	p_triangle->c = convert_opengl_to_vector3(p_win, p_triangle->c);

	ab = create_t_rasterizer(p_triangle->a, p_triangle->b, p_triangle->c);
	ac = create_t_rasterizer(p_triangle->a, p_triangle->c, p_triangle->b);

	t_triangle_get_min_max_value(*p_triangle, &min, &max);

	if (min.x < 0)
		min.x = 0;
	if (min.y < 0)
		min.y = 0;
	if (max.x >= p_win->size_x)
		max.x = p_win->size_x - 1;
	if (max.y >= p_win->size_y)
		max.y = p_win->size_y - 1;

	current = min;
	while (current.x <= max.x)
	{
		current.y = min.y;
		while (current.y <= max.y)
		{
			alpha = calc_rasterizer(&ab, (int)(current.x), (int)(current.y));
			beta = calc_rasterizer(&ac, (int)(current.x), (int)(current.y));
			gamma = 1 - alpha - beta;
			if (alpha >= 0 && beta >= 0 && gamma >= 0)
				draw_pixel(p_win, (int)(current.x), (int)(current.y), &test);
			current.y++;
		}
		current.x++;
	}
}
