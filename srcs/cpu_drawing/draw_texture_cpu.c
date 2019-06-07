#include "unknow_project.h"

static void 	draw_scan_line(t_window *p_win, t_vector3 left, t_vector3 right, t_vector3 uv_left, t_vector3 uv_right, t_texture *texture, t_color *darkness)
{
	t_vector3 current;
	t_vector3 target;
	t_color color;
	t_vector3 delta_uv;
	int pixel_index;
	int pixel_x;
	int pixel_y;

	if (left.x > right.x)
	{
		swap_t_vector3(&left, &right);
		swap_t_vector3(&uv_left, &uv_right);
	}
	current = left;
	target = right;
	delta_uv = create_t_vector3((uv_right.x - uv_left.x) / (right.x - left.x), (uv_right.y - uv_left.y) / (right.x - left.x), 0.0);

	if (current.x >= p_win->size_x || target.x < 0)
		return ;

	float delta_z = (target.z - current.z) / (target.x - current.x);
	pixel_index = (int)(current.x) + ((int)(current.y) * p_win->size_x);
	while ((int)(current.x) <= (int)(target.x))
	{
		if (current.x >= 0 && current.x < p_win->size_x && current.y >= 0 && current.y < p_win->size_y)
		{
			pixel_x = (int)(uv_left.x * (float)(texture->surface->w));
			pixel_y = (int)(uv_left.y * (float)(texture->surface->h));
			if ((current.z < p_win->depth_buffer[pixel_index] || p_win->depth_buffer[pixel_index] == 0) &&
				pixel_x >= 0 && pixel_x < texture->surface->w && pixel_y >= 0 && pixel_y < texture->surface->h)
			{
				color = get_pixel_color(texture, pixel_x, pixel_y);
				draw_pixel(p_win, (int)(current.x), (int)(current.y), &color);
				p_win->depth_buffer[pixel_index] = current.z;
			}
		}
		current.x++;
		current.z += delta_z;
		uv_left = add_vector3_to_vector3(uv_left, delta_uv);
		pixel_index++;
	}
}

static void	fill_down_flat_triangle(t_window *p_win, t_triangle *p_triangle, t_uv *p_uv, t_color *darkness)
{
	t_vector3	target;
	t_vector3	left;
	t_vector3	right;
	t_vector3	uv_left;
	t_vector3	uv_right;
	t_vector3	delta_left;
	t_vector3	delta_right;
	t_vector3	delta_uv_left;
	t_vector3	delta_uv_right;

	delta_left = create_t_vector3((p_triangle->a.x - p_triangle->b.x) / (p_triangle->a.y - p_triangle->b.y), 1.0, (p_triangle->a.z - p_triangle->b.z) / (p_triangle->a.y - p_triangle->b.y));
	delta_right = create_t_vector3((p_triangle->a.x - p_triangle->c.x) / (p_triangle->a.y - p_triangle->c.y), 1.0, (p_triangle->a.z - p_triangle->c.z) / (p_triangle->a.y - p_triangle->c.y));
	delta_uv_left = create_t_vector3((p_uv->uv.a.x - p_uv->uv.b.x) / (p_triangle->a.y - p_triangle->b.y), (p_uv->uv.a.y - p_uv->uv.b.y) / (p_triangle->a.y - p_triangle->b.y), 1.0);
	delta_uv_right = create_t_vector3((p_uv->uv.a.x - p_uv->uv.c.x) / (p_triangle->a.y - p_triangle->c.y), (p_uv->uv.a.y - p_uv->uv.c.y) / (p_triangle->a.y - p_triangle->c.y), 1.0);

	left = p_triangle->b;
	right = p_triangle->c;
	uv_left = p_uv->uv.b;
	uv_right = p_uv->uv.c;
	target = p_triangle->a;
	if (target.y < 0)
		target.y = 0;
	if (target.y >= p_win->size_y)
		target.y = p_win->size_y - 1;
	while (left.y >= p_win->size_y && target.y <= left.y)
	{
		left = substract_vector3_to_vector3(left, delta_left);
		right = substract_vector3_to_vector3(right, delta_right);
		uv_left = substract_vector3_to_vector3(uv_left, delta_uv_left);
		uv_right = substract_vector3_to_vector3(uv_right, delta_uv_right);
	}
	while (target.y <= left.y)
	{
		draw_scan_line(p_win, left, right, uv_left, uv_right, p_uv->image, darkness);
		uv_left = substract_vector3_to_vector3(uv_left, delta_uv_left);
		uv_right = substract_vector3_to_vector3(uv_right, delta_uv_right);
		left = substract_vector3_to_vector3(left, delta_left);
		right = substract_vector3_to_vector3(right, delta_right);
	}
}

static void	fill_top_flat_triangle(t_window *p_win, t_triangle *p_triangle, t_uv *p_uv, t_color *darkness)
{
	t_vector3	target;
	t_vector3	left;
	t_vector3	right;
	t_vector3	uv_left;
	t_vector3	uv_right;
	t_vector3	delta_left;
	t_vector3	delta_right;
	t_vector3	delta_uv_left;
	t_vector3	delta_uv_right;

	delta_left = create_t_vector3((p_triangle->c.x - p_triangle->a.x) / (p_triangle->c.y - p_triangle->a.y), 1.0, (p_triangle->c.z - p_triangle->a.z) / (p_triangle->c.y - p_triangle->a.y));
	delta_right = create_t_vector3((p_triangle->c.x - p_triangle->b.x) / (p_triangle->c.y - p_triangle->b.y), 1.0, (p_triangle->c.z - p_triangle->b.z) / (p_triangle->c.y - p_triangle->b.y));
	delta_uv_left = create_t_vector3((p_uv->uv.c.x - p_uv->uv.a.x) / (p_triangle->c.y - p_triangle->a.y), (p_uv->uv.c.y - p_uv->uv.a.y) / (p_triangle->c.y - p_triangle->a.y), 1.0);
	delta_uv_right = create_t_vector3((p_uv->uv.c.x - p_uv->uv.b.x) / (p_triangle->c.y - p_triangle->b.y), (p_uv->uv.c.y - p_uv->uv.b.y) / (p_triangle->c.y - p_triangle->b.y), 1.0);
	left = p_triangle->a;
	right = p_triangle->b;
	uv_left = p_uv->uv.a;
	uv_right = p_uv->uv.b;
	target = p_triangle->c;
	if (target.y < 0)
		target.y = 0;
	if (target.y >= p_win->size_y)
		target.y = p_win->size_y - 1;
	while (left.y < 0 && target.y >= left.y)
	{
		left = add_vector3_to_vector3(left, delta_left);
		right = add_vector3_to_vector3(right, delta_right);
		uv_left = add_vector3_to_vector3(uv_left, delta_uv_left);
		uv_right = add_vector3_to_vector3(uv_right, delta_uv_right);
	}
	while (target.y >= left.y)
	{
		draw_scan_line(p_win, left, right, uv_left, uv_right, p_uv->image, darkness);
		left = add_vector3_to_vector3(left, delta_left);
		right = add_vector3_to_vector3(right, delta_right);
		uv_left = add_vector3_to_vector3(uv_left, delta_uv_left);
		uv_right = add_vector3_to_vector3(uv_right, delta_uv_right);
	}
}

static void 	parse_triangle(t_triangle *p_triangle, t_uv *p_uv)
{
	if (p_triangle->a.y > p_triangle->b.y)
	{
		swap_t_vector3(&(p_triangle->a), &(p_triangle->b));
		swap_t_vector3(&(p_uv->uv.a), &(p_uv->uv.b));
	}
	if (p_triangle->b.y > p_triangle->c.y)
	{
		swap_t_vector3(&(p_triangle->b), &(p_triangle->c));
		swap_t_vector3(&(p_uv->uv.b), &(p_uv->uv.c));
	}
	if (p_triangle->a.y > p_triangle->b.y)
	{
		swap_t_vector3(&(p_triangle->a), &(p_triangle->b));
		swap_t_vector3(&(p_uv->uv.a), &(p_uv->uv.b));
	}
}

void	draw_triangle_texture_cpu(t_window *p_win, t_triangle *p_triangle, t_uv *p_uv, t_color *darkness)
{
	t_vector3	point_d_triangle;
	t_vector3	point_d_uv;
	t_triangle	base_triangle;
	t_triangle	tmp_triangle;
	t_uv		base_uv;
	t_uv		tmp_uv;

	base_triangle.a = convert_opengl_to_vector3(p_win, p_triangle->a);
	base_triangle.b = convert_opengl_to_vector3(p_win, p_triangle->b);
	base_triangle.c = convert_opengl_to_vector3(p_win, p_triangle->c);
	base_uv = *(p_uv);

	parse_triangle(&base_triangle, &base_uv);

	if (base_triangle.b.y == base_triangle.c.y)
	{
		fill_down_flat_triangle(p_win, &base_triangle, &base_uv, darkness);
	}
	else if (base_triangle.a.y == base_triangle.b.y || base_triangle.a.y == base_triangle.c.y)
	{
		fill_top_flat_triangle(p_win, &base_triangle, &base_uv, darkness);
	}
	else
	{
		point_d_triangle.x = base_triangle.a.x + ((base_triangle.b.y - base_triangle.a.y) / (base_triangle.c.y - base_triangle.a.y) * (base_triangle.c.x - base_triangle.a.x));
		point_d_triangle.y = base_triangle.b.y;
		point_d_triangle.z = base_triangle.a.z + ((base_triangle.b.y - base_triangle.a.y) / (base_triangle.c.y - base_triangle.a.y) * (base_triangle.c.z - base_triangle.a.z));

		point_d_uv = interpolate_vector3_over_line(interpolate_ratio(base_triangle.a.x, base_triangle.c.x, point_d_triangle.x),
													interpolate_ratio(base_triangle.a.y, base_triangle.c.y, point_d_triangle.y),
													base_uv.uv.a, base_uv.uv.c); // ((base_uv.uv.c.x - base_uv.uv.a.x) * ratio_x) + base_uv.uv.a.x;// * (p_uv->uv.c.x - p_uv->uv.a.x);

		tmp_triangle = create_t_triangle(base_triangle.b, point_d_triangle, base_triangle.c);
		tmp_uv = base_uv;
		tmp_uv.uv = create_t_triangle(base_uv.uv.b, point_d_uv, base_uv.uv.c);

		base_triangle.c = tmp_triangle.b;
		base_uv.uv.c = tmp_uv.uv.b;

		fill_down_flat_triangle(p_win, &base_triangle, &base_uv, darkness);
		fill_top_flat_triangle(p_win, &tmp_triangle, &tmp_uv, darkness);
	}
}
