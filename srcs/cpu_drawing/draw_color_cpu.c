#include "unknow_project.h"

void 	draw_scan_line(t_window *p_win, t_vector3 left, t_vector3 right, t_color *p_color)
{
	float dist;
	float z_delta;
	t_vector3 tmp;
	int delta;
	int i;

	if (left.x > right.x)
	{
		i = left.x;
		left.x = right.x;
		right.x = i;
	}
	i = (int)(left.x) + (int)(left.y) * p_win->size_x;
	z_delta = (right.z - left.z) / (right.x - left.x);
	delta = 1;
	while ((int)(left.x) <= (int)(right.x))
	{
		if ((left.x) >= 0 && (left.x) < p_win->size_x &&
			(left.y) >= 0 && (left.y) < p_win->size_y)
		{
			if (p_win->depth_buffer[i] == 0)
			{
				p_win->depth_buffer[i] = 0;
				p_win->color_data[i] = *p_color;
			}
		}
		left.x += delta;
		left.z -= z_delta;
		i += delta;
	}
}

void fill_down_flat_triangle(t_window *p_win, t_triangle *p_triangle, t_color *p_color)
{
	t_vector3	delta[2];
	t_vector3	left;
	t_vector3	right;
	int			scan_line;

	delta[0].x = (p_triangle->b.x - p_triangle->a.x) / (p_triangle->b.y - p_triangle->a.y);
	delta[1].x = (p_triangle->c.x - p_triangle->a.x) / (p_triangle->c.y - p_triangle->a.y);
	delta[0].y = 1.0f;
	delta[1].y = 1.0f;
	delta[0].z = (p_triangle->b.z - p_triangle->a.z) / (p_triangle->b.y - p_triangle->a.y);
	delta[1].z = (p_triangle->c.z - p_triangle->a.z) / (p_triangle->c.y - p_triangle->a.y);
	left = p_triangle->a;
	right = p_triangle->a;
	scan_line = p_triangle->a.y;
	if (scan_line < 0)
	{
		left = add_vector3_to_vector3(left, mult_vector3_by_float(delta[0], -scan_line));
		right = add_vector3_to_vector3(right, mult_vector3_by_float(delta[1], -scan_line));
		scan_line = 0;
	}
	while (scan_line <= p_triangle->b.y && scan_line < p_win->size_y)
	{
		draw_scan_line(p_win, left, right, p_color);
		left = add_vector3_to_vector3(left, delta[0]);
		right = add_vector3_to_vector3(right, delta[1]);
		scan_line += delta[0].y;
	}
}

void fill_top_flat_triangle(t_window *p_win, t_triangle *p_triangle, t_color *p_color)
{
	int find = 0;
	t_vector3	delta[2];
	t_vector3	left;
	t_vector3	right;
	int			scan_line;

	delta[0].x = (p_triangle->c.x - p_triangle->a.x) / (p_triangle->c.y - p_triangle->a.y);
	delta[1].x = (p_triangle->c.x - p_triangle->b.x) / (p_triangle->c.y - p_triangle->b.y);
	delta[0].y = 1.0f;
	delta[1].y = 1.0f;
	delta[0].z = (p_triangle->c.z - p_triangle->a.z) / (p_triangle->c.y - p_triangle->a.y);
	delta[1].z = (p_triangle->c.z - p_triangle->b.z) / (p_triangle->c.y - p_triangle->b.y);
	left = p_triangle->c;
	right = p_triangle->c;
	scan_line = p_triangle->c.y;
	if (scan_line >= p_win->size_y)
	{
		left = add_vector3_to_vector3(left, mult_vector3_by_float(delta[0], (float)(p_win->size_y - scan_line)));
		right = add_vector3_to_vector3(right, mult_vector3_by_float(delta[1], (float)(p_win->size_y - scan_line)));
		scan_line = scan_line + (p_win->size_y - scan_line);
	}
	while (scan_line > p_triangle->a.y && scan_line >= 0)
	{
		draw_scan_line(p_win, left, right, p_color);
		left = substract_vector3_to_vector3(left, delta[0]);
		right = substract_vector3_to_vector3(right, delta[1]);
		scan_line -= delta[0].y;
	}
}

void draw_triangle_color_cpu(t_window *p_win, t_triangle *p_triangle, t_color *p_color)
{
	float	p_x;
	float	p_y;
	float	p_z;
	t_triangle tmp;

	p_triangle->a = convert_opengl_to_vector3(p_win, &(p_triangle->a));
	p_triangle->b = convert_opengl_to_vector3(p_win, &(p_triangle->b));
	p_triangle->c = convert_opengl_to_vector3(p_win, &(p_triangle->c));

	sort_t_triangle_points(p_triangle);

	if (p_triangle->b.y == p_triangle->c.y)
	{
		fill_down_flat_triangle(p_win, p_triangle, p_color);
	}
	if (p_triangle->a.y == p_triangle->b.y || p_triangle->a.y == p_triangle->c.y)
	{
		fill_top_flat_triangle(p_win, p_triangle, p_color);
	}
	else
	{
		p_x = p_triangle->a.x + ((p_triangle->b.y - p_triangle->a.y) / (p_triangle->c.y - p_triangle->a.y) * (p_triangle->c.x - p_triangle->a.x));
		p_y = p_triangle->b.y;
		p_z = p_triangle->a.z + ((p_triangle->b.y - p_triangle->a.y) / (p_triangle->c.y - p_triangle->a.y) * (p_triangle->c.z - p_triangle->a.z));

		tmp = create_t_triangle(p_triangle->b, create_t_vector3(p_x, p_y, p_z), p_triangle->c);

		p_triangle->c = tmp.b;

		fill_down_flat_triangle(p_win, p_triangle, p_color);
		fill_top_flat_triangle(p_win, &tmp, p_color);
	}
}
