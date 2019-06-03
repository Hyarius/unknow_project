#include "unknow_project.h"

float dist_max;
float dist_min;

void 	draw_scan_line_depth(t_window *p_win, t_vector3 left, t_vector3 right, t_color *p_color)
{
	float	ratio;
	int pixel_index;
	t_color	tmp_color;

	if (left.x > right.x)
		swap_t_vector3(&left, &right);
	float delta_z = (right.z - left.z) / (right.x - left.x);
	while (left.x <= right.x)
	{
		if (left.x >= 0 && left.x < p_win->size_x && left.y >= 0 && left.y < p_win->size_y)
		{
			pixel_index = left.x + (left.y * p_win->size_x);
			if (left.z < p_win->depth_buffer[pixel_index] || p_win->depth_buffer[pixel_index] == 0)
			{
				ratio = (left.z - dist_max) / (dist_min - dist_max);
				tmp_color = create_t_color(ratio, ratio, ratio, 1.0);
				draw_pixel(p_win, (int)(left.x), (int)(left.y), p_color);
				p_win->depth_buffer[pixel_index] = left.z;
			}
		}
		left.x++;
		left.z += delta_z;
	}
}

void	fill_down_flat_triangle_depth(t_window *p_win, t_triangle *p_triangle, t_color *p_color)
{
	t_vector3	left;
	t_vector3	right;
	t_vector3	delta_left;
	t_vector3	delta_right;

	delta_left = create_t_vector3((p_triangle->a.x - p_triangle->b.x) / (p_triangle->a.y - p_triangle->b.y), 1.0, (p_triangle->a.z - p_triangle->b.z) / (p_triangle->a.y - p_triangle->b.y));
	delta_right = create_t_vector3((p_triangle->a.x - p_triangle->c.x) / (p_triangle->a.y - p_triangle->c.y), 1.0, (p_triangle->a.z - p_triangle->c.z) / (p_triangle->a.y - p_triangle->c.y));
	left = p_triangle->b;
	right = p_triangle->c;
	while (p_triangle->a.y <= left.y)
	{
		draw_scan_line_depth(p_win, left, right, p_color);
		left = substract_vector3_to_vector3(left, delta_left);
		right = substract_vector3_to_vector3(right, delta_right);
	}
}

void	fill_top_flat_triangle_depth(t_window *p_win, t_triangle *p_triangle, t_color *p_color)
{
	t_vector3	left;
	t_vector3	right;
	t_vector3	delta_left;
	t_vector3	delta_right;

	delta_left = create_t_vector3((p_triangle->c.x - p_triangle->a.x) / (p_triangle->c.y - p_triangle->a.y), 1.0, (p_triangle->c.z - p_triangle->a.z) / (p_triangle->c.y - p_triangle->a.y));
	delta_right = create_t_vector3((p_triangle->c.x - p_triangle->b.x) / (p_triangle->c.y - p_triangle->b.y), 1.0, (p_triangle->c.z - p_triangle->b.z) / (p_triangle->c.y - p_triangle->b.y));
	left = p_triangle->a;
	right = p_triangle->b;
	while (p_triangle->c.y >= left.y)
	{
		draw_scan_line_depth(p_win, left, right, p_color);
		left = add_vector3_to_vector3(left, delta_left);
		right = add_vector3_to_vector3(right, delta_right);
	}
}

void	draw_triangle_depth_cpu(t_window *p_win, t_triangle *p_triangle, t_color *p_color)
{
	float		p_x;
	float		p_y;
	float		p_z;
	t_triangle	tmp;

	p_triangle->a = convert_opengl_to_vector3(p_win, &(p_triangle->a));
	p_triangle->b = convert_opengl_to_vector3(p_win, &(p_triangle->b));
	p_triangle->c = convert_opengl_to_vector3(p_win, &(p_triangle->c));

	sort_t_triangle_points(p_triangle);

	if (p_triangle->b.y == p_triangle->c.y)
		fill_down_flat_triangle_depth(p_win, p_triangle, p_color);
	else if (p_triangle->a.y == p_triangle->b.y || p_triangle->a.y == p_triangle->c.y)
		fill_top_flat_triangle_depth(p_win, p_triangle, p_color);
	else
	{
		p_x = p_triangle->a.x + ((p_triangle->b.y - p_triangle->a.y) / (p_triangle->c.y - p_triangle->a.y) * (p_triangle->c.x - p_triangle->a.x));
		p_y = p_triangle->b.y;
		p_z = p_triangle->a.z + ((p_triangle->b.y - p_triangle->a.y) / (p_triangle->c.y - p_triangle->a.y) * (p_triangle->c.z - p_triangle->a.z));

		tmp = create_t_triangle(p_triangle->b, create_t_vector3(p_x, p_y, p_z), p_triangle->c);
		p_triangle->c = tmp.b;
		fill_down_flat_triangle_depth(p_win, p_triangle, p_color);
		fill_top_flat_triangle_depth(p_win, &tmp, p_color);
	}
}
