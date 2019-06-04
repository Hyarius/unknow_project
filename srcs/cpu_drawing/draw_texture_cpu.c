#include "unknow_project.h"

static void 	draw_scan_line(t_window *p_win, t_vector3 left, t_vector3 right, t_uv *p_uv, t_color *darkness)
{
	t_color black = create_t_color(0.0, 0.0, 0.0, 1.0);
	int pixel_index;

	if (left.x > right.x)
	{
		swap_t_vector3(&left, &right);
	}
	if (left.x < 0)
		left.x = 0;
	if (right.x >= p_win->size_x)
		right.x = p_win->size_x - 1;

	float delta_z = (right.z - left.z) / (right.x - left.x);
	pixel_index = (int)(left.x) + ((int)(left.y) * p_win->size_x);
	while (left.x <= right.x)
	{
		if (left.x >= 0 && left.x < p_win->size_x && left.y >= 0 && left.y < p_win->size_y)
		{
			if (left.z < p_win->depth_buffer[pixel_index] || p_win->depth_buffer[pixel_index] == 0)
			{
				draw_pixel(p_win, (int)(left.x), (int)(left.y), &black);
				p_win->depth_buffer[pixel_index] = left.z;
			}
		}
		left.x++;
		left.z += delta_z;
		pixel_index++;
	}
}

static void	fill_down_flat_triangle(t_window *p_win, t_triangle *p_triangle, t_uv *p_uv, t_color *darkness)
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
		draw_scan_line(p_win, left, right, p_uv, darkness);
		left = substract_vector3_to_vector3(left, delta_left);
		right = substract_vector3_to_vector3(right, delta_right);
	}
}

static void	fill_top_flat_triangle(t_window *p_win, t_triangle *p_triangle, t_uv *p_uv, t_color *darkness)
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
		draw_scan_line(p_win, left, right, p_uv, darkness);
		left = add_vector3_to_vector3(left, delta_left);
		right = add_vector3_to_vector3(right, delta_right);
	}
}

static void 	parse_triangle(t_triangle *p_triangle, t_uv *p_uv)
{
	if (p_triangle->a.y > p_triangle->b.y || (p_triangle->a.y == p_triangle->b.y && p_triangle->a.x > p_triangle->b.x))
	{
		swap_t_vector3(&(p_triangle->a), &(p_triangle->b));
		swap_t_vector3(&(p_uv->uv->a), &(p_uv->uv->b));
	}
	if (p_triangle->b.y > p_triangle->c.y || (p_triangle->b.y == p_triangle->c.y && p_triangle->b.x > p_triangle->c.x))
	{
		swap_t_vector3(&(p_triangle->b), &(p_triangle->c));
		swap_t_vector3(&(p_uv->uv->b), &(p_uv->uv->c));
	}
	if (p_triangle->a.y > p_triangle->b.y || (p_triangle->a.y == p_triangle->b.y && p_triangle->a.x > p_triangle->b.x))
	{
		swap_t_vector3(&(p_triangle->a), &(p_triangle->b));
		swap_t_vector3(&(p_uv->uv->a), &(p_uv->uv->b));
	}
}

void	draw_triangle_texture_cpu(t_window *p_win, t_triangle *p_triangle, t_uv *p_uv, t_color *darkness)
{
	t_vector3	point_d_triangle;
	t_vector3	point_d_uv;

	t_triangle	tmp_triangle;
	t_uv		tmp_uv;

	p_triangle->a = convert_opengl_to_vector3(p_win, &(p_triangle->a));
	p_triangle->b = convert_opengl_to_vector3(p_win, &(p_triangle->b));
	p_triangle->c = convert_opengl_to_vector3(p_win, &(p_triangle->c));

	parse_triangle(p_triangle, p_uv);

	if (p_triangle->b.y == p_triangle->c.y)
		fill_down_flat_triangle(p_win, p_triangle, p_uv, darkness);
	else if (p_triangle->a.y == p_triangle->b.y || p_triangle->a.y == p_triangle->c.y)
		fill_top_flat_triangle(p_win, p_triangle, p_uv, darkness);
	else
	{
		point_d_triangle.x = p_triangle->a.x + ((p_triangle->b.y - p_triangle->a.y) / (p_triangle->c.y - p_triangle->a.y) * (p_triangle->c.x - p_triangle->a.x));
		point_d_triangle.y = p_triangle->b.y;
		point_d_triangle.z = p_triangle->a.z + ((p_triangle->b.y - p_triangle->a.y) / (p_triangle->c.y - p_triangle->a.y) * (p_triangle->c.z - p_triangle->a.z));

		tmp_triangle = create_t_triangle(p_triangle->b, point_d_triangle, p_triangle->c);

		p_triangle->c = tmp_triangle.b;

		point_d_uv.x = p_uv->uv->a.x + ((p_uv->uv->b.y - p_uv->uv->a.y) / (p_uv->uv->c.y - p_uv->uv->a.y) * (p_uv->uv->c.x - p_uv->uv->a.x));
		point_d_uv.y = p_uv->uv->b.y;
		point_d_uv.z = p_uv->uv->a.z + ((p_uv->uv->b.y - p_uv->uv->a.y) / (p_uv->uv->c.y - p_uv->uv->a.y) * (p_uv->uv->c.z - p_uv->uv->a.z));

		tmp_uv = *p_uv;

		*(tmp_uv.uv) = create_t_triangle(p_uv->uv->b, point_d_uv, p_uv->uv->c);

		p_uv->uv->c = tmp_uv.uv->b;

		fill_down_flat_triangle(p_win, p_triangle, p_uv, darkness);
		fill_top_flat_triangle(p_win, &tmp_triangle, &tmp_uv, darkness);
	}
}
