#include "unknow_project.h"

float dist_max;
float dist_min;

void 	draw_scan_line_depth(t_window *p_win, t_vector3 left, t_vector3 right, t_color *p_color)
{
	float	ratio;
	int		pixel_index;
	t_color	tmp_color;

	if (left.x > right.x)
		swap_t_vector3(&left, &right);
	if (left.x < 0)
		left.x = 0;
	if (right.x >= p_win->size_x)
		right.x = p_win->size_x - 1;
	float delta_z = (right.z - left.z) / (right.x - left.x);
	pixel_index = left.x + (left.y * p_win->size_x);
	tmp_color = create_t_color(0.0, 0.0, 0.0, 1.0);
	while (left.x <= right.x)
	{
		if (left.x >= 0 && left.x < p_win->size_x && left.y >= 0 && left.y < p_win->size_y)
		{
			if (left.z < p_win->depth_buffer[pixel_index] || p_win->depth_buffer[pixel_index] == 0)
			{
				ratio = (left.z - dist_max) / (dist_min - dist_max);
				tmp_color.r = ratio;
				tmp_color.g = ratio;
				tmp_color.b = ratio;
				draw_pixel(p_win, (int)(left.x), (int)(left.y), &tmp_color);
				p_win->depth_buffer[pixel_index] = left.z;
			}
		}
		left.x++;
		left.z += delta_z;
		pixel_index++;
	}
}

void	fill_down_flat_triangle_depth(t_window *p_win, t_triangle *p_triangle, t_color *p_color)
{
	t_vector3	target;
	t_vector3	left;
	t_vector3	right;
	t_vector3	delta_left;
	t_vector3	delta_right;

	delta_left = create_t_vector3((p_triangle->a.x - p_triangle->b.x) / (p_triangle->a.y - p_triangle->b.y), 1.0, (p_triangle->a.z - p_triangle->b.z) / (p_triangle->a.y - p_triangle->b.y));
	delta_right = create_t_vector3((p_triangle->a.x - p_triangle->c.x) / (p_triangle->a.y - p_triangle->c.y), 1.0, (p_triangle->a.z - p_triangle->c.z) / (p_triangle->a.y - p_triangle->c.y));
	left = p_triangle->b;
	right = p_triangle->c;
	target = p_triangle->a;
	if (target.y < 0)
		target.y = 0;
	if (target.y >= p_win->size_y)
		target.y = p_win->size_y - 1;
	while (left.y >= p_win->size_y && target.y <= left.y)
	{
		left = substract_vector3_to_vector3(left, delta_left);
		right = substract_vector3_to_vector3(right, delta_right);
	}
	while (target.y <= left.y)
	{
		draw_scan_line_depth(p_win, left, right, p_color);
		left = substract_vector3_to_vector3(left, delta_left);
		right = substract_vector3_to_vector3(right, delta_right);
	}
}

void	fill_top_flat_triangle_depth(t_window *p_win, t_triangle *p_triangle, t_color *p_color)
{
	t_vector3	target;
	t_vector3	left;
	t_vector3	right;
	t_vector3	delta_left;
	t_vector3	delta_right;

	delta_left = create_t_vector3((p_triangle->c.x - p_triangle->a.x) / (p_triangle->c.y - p_triangle->a.y), 1.0, (p_triangle->c.z - p_triangle->a.z) / (p_triangle->c.y - p_triangle->a.y));
	delta_right = create_t_vector3((p_triangle->c.x - p_triangle->b.x) / (p_triangle->c.y - p_triangle->b.y), 1.0, (p_triangle->c.z - p_triangle->b.z) / (p_triangle->c.y - p_triangle->b.y));
	left = p_triangle->a;
	right = p_triangle->b;
	target = p_triangle->c;
	if (target.y < 0)
		target.y = 0;
	if (target.y >= p_win->size_y)
		target.y = p_win->size_y - 1;
	while (left.y < 0 && target.y >= left.y)
	{
		left = add_vector3_to_vector3(left, delta_left);
		right = add_vector3_to_vector3(right, delta_right);
	}
	while (target.y >= left.y)
	{
		draw_scan_line_depth(p_win, left, right, p_color);
		left = add_vector3_to_vector3(left, delta_left);
		right = add_vector3_to_vector3(right, delta_right);
	}
}

void	draw_triangle_depth_cpu(t_window *p_win, t_triangle *p_triangle, t_color *p_color)
{
	t_vector3	point_d;
	t_triangle	tmp;

	p_triangle->a = convert_opengl_to_vector3(p_win, p_triangle->a);
	p_triangle->b = convert_opengl_to_vector3(p_win, p_triangle->b);
	p_triangle->c = convert_opengl_to_vector3(p_win, p_triangle->c);

	sort_t_triangle_points(p_triangle);

	if (p_triangle->b.y == p_triangle->c.y)
		fill_down_flat_triangle_depth(p_win, p_triangle, p_color);
	else if (p_triangle->a.y == p_triangle->b.y || p_triangle->a.y == p_triangle->c.y)
		fill_top_flat_triangle_depth(p_win, p_triangle, p_color);
	else
	{
		point_d.x = p_triangle->a.x + ((p_triangle->b.y - p_triangle->a.y) / (p_triangle->c.y - p_triangle->a.y) * (p_triangle->c.x - p_triangle->a.x));
		point_d.y = p_triangle->b.y;
		point_d.z = p_triangle->a.z + ((p_triangle->b.y - p_triangle->a.y) / (p_triangle->c.y - p_triangle->a.y) * (p_triangle->c.z - p_triangle->a.z));

		tmp = create_t_triangle(p_triangle->b, point_d, p_triangle->c);
		p_triangle->c = tmp.b;
		fill_down_flat_triangle_depth(p_win, p_triangle, p_color);
		fill_top_flat_triangle_depth(p_win, &tmp, p_color);
	}
}
