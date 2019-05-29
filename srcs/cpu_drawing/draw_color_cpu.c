#include "unknow_project.h"

void 	draw_scan_line(t_window *p_win, t_vector3 left, t_vector3 right, t_color *p_color)
{
	int delta;
	int i;

	i = left.x + left.y * p_win->size_x;
	delta = (left.x > right.x ? -1 : 1);
	while ((int)(left.x) != (int)(right.x))
	{
		if (left.x >= 0 && left.x < p_win->size_x &&
			left.y >= 0 && left.y < p_win->size_y)
		{
			p_win->color_data[i] = *p_color;
		}
		left.x += delta;
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
	delta[0].y = 1.0;
	delta[1].y = 1.0;
	delta[0].z = (p_triangle->b.z - p_triangle->a.z) / (p_triangle->b.y - p_triangle->a.y);
	delta[1].z = (p_triangle->c.z - p_triangle->a.z) / (p_triangle->c.y - p_triangle->a.y);
	left = p_triangle->a;
	right = p_triangle->a;
	scan_line = p_triangle->a.y;
	while (scan_line <= p_triangle->b.y)
	{
		draw_scan_line(p_win, left, right, p_color);
		left = add_vector3_to_vector3(left, delta[0]);
		right = add_vector3_to_vector3(right, delta[1]);
		scan_line += delta[0].y;
	}
}

void fill_top_flat_triangle(t_window *p_win, t_triangle *p_triangle, t_color *p_color)
{
	t_vector3	delta[2];
	t_vector3	left;
	t_vector3	right;
	int			scan_line;

	delta[0].x = (p_triangle->c.x - p_triangle->a.x) / (p_triangle->c.y - p_triangle->a.y);
	delta[1].x = (p_triangle->c.x - p_triangle->b.x) / (p_triangle->c.y - p_triangle->b.y);
	delta[0].y = 1.0;
	delta[1].y = 1.0;
	delta[0].z = (p_triangle->c.z - p_triangle->a.z) / (p_triangle->c.y - p_triangle->a.y);
	delta[1].z = (p_triangle->c.z - p_triangle->b.z) / (p_triangle->c.y - p_triangle->b.y);
	left = p_triangle->c;
	right = p_triangle->c;
	scan_line = p_triangle->c.y;
	while (scan_line > p_triangle->a.y)
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
