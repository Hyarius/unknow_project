#include "unknow_project.h"

void	draw_triangle_color_cpu(t_window *p_win, t_triangle *p_triangle, t_color *p_color)
{
	t_color			red = create_t_color(1.0, 0, 0, 1);
	t_triangle		triangle;
	t_vector3		min;
	t_vector3		max;
	t_vector3		current;
	t_rasterizer	ab;
	t_rasterizer	ac;
	t_rasterizer	bc;
	float			alpha;
	float			beta;
	float			gamma;
	int				pixel_index;

	triangle.a = convert_opengl_to_vector3(p_win, p_triangle->a);
	triangle.b = convert_opengl_to_vector3(p_win, p_triangle->b);
	triangle.c = convert_opengl_to_vector3(p_win, p_triangle->c);

	ab = create_t_rasterizer(triangle.a, triangle.b, triangle.c);
	ac = create_t_rasterizer(triangle.a, triangle.c, triangle.b);
	bc = create_t_rasterizer(triangle.b, triangle.c, triangle.a);

	t_triangle_get_min_max_value(triangle, &min, &max);

	if (min.x < 0)
		min.x = 0;
	if (min.y < 0)
		min.y = 0;
	if (max.x >= p_win->size_x)
		max.x = p_win->size_x - 1;
	if (max.y >= p_win->size_y)
		max.y = p_win->size_y - 1;

	triangle.a.z = 1.0 / triangle.a.z;
	triangle.b.z = 1.0 / triangle.b.z;
	triangle.c.z = 1.0 / triangle.c.z;

	current = min;
	while (current.y <= max.y)
	{
		pixel_index = (int)(current.x) + ((int)(current.y) * p_win->size_x);
		while (current.x <= max.x)
		{
			alpha = calc_rasterizer(&ab, current.x, current.y);
			beta = calc_rasterizer(&ac, current.x, current.y);
			gamma = calc_rasterizer(&bc, current.x, current.y);
			if (alpha >= 0 && beta >= 0 && gamma >= 0)
			{
				float z = 1.0f / ((triangle.a.z * gamma) + (triangle.b.z * beta) + (triangle.c.z * alpha));

				if (z < p_win->depth_buffer[pixel_index] || p_win->depth_buffer[pixel_index] == -1)
				{
					draw_pixel(p_win, (int)(current.x), (int)(current.y), p_color);
					p_win->depth_buffer[pixel_index] = z;
				}
			}
			current.x++;
			pixel_index++;
		}
		current.x = min.x;
		current.y++;
	}
	// int size = 5;
	// for (int i = -size; i < size; i++)
	// {
	// 	for (int j = -size; j < size; j++)
	// 	{
	// 		draw_pixel(p_win, (int)(triangle.a.x + i), (int)(triangle.a.y + j), &red);
	// 		draw_pixel(p_win, (int)(triangle.b.x + i), (int)(triangle.b.y + j), &red);
	// 		draw_pixel(p_win, (int)(triangle.c.x + i), (int)(triangle.c.y + j), &red);
	// 	}
	// }
}
