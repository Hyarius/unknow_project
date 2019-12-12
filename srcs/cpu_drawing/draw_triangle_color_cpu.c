#include "unknow_project.h"

t_triangle	convert_t_triangle(t_view_port *view_port, t_triangle *p_triangle)
{
	t_triangle	triangle;

	triangle.a = convert_opengl_to_vector4(view_port, p_triangle->a);
	triangle.b = convert_opengl_to_vector4(view_port, p_triangle->b);
	triangle.c = convert_opengl_to_vector4(view_port, p_triangle->c);
	triangle.a.w = 1.0 / triangle.a.w;
	triangle.b.w = 1.0 / triangle.b.w;
	triangle.c.w = 1.0 / triangle.c.w;
	return (triangle);
}

void		get_min_max_draw_triangle(t_view_port *view_port, t_vector4 *min,
																t_vector4 *max)
{
	if (min->x < 0)
		min->x = 0;
	if (min->y < 0)
		min->y = 0;
	if (max->x >= view_port->size.x)
		max->x = view_port->size.x - 1;
	if (max->y >= view_port->size.y)
		max->y = view_port->size.y - 1;
}

void		draw_triangle_color_cpu_next(t_view_port *view_port,
											t_color *p_color, t_fuck_norme data)
{
	data.pixel_sample = create_t_vector4(data.x, data.y, 0);
	data.w0 = edge_t_vector4(data.triangle.b, data.triangle.c,
												data.pixel_sample) / data.area;
	data.w1 = edge_t_vector4(data.triangle.c, data.triangle.a,
												data.pixel_sample) / data.area;
	data.w2 = edge_t_vector4(data.triangle.a, data.triangle.b,
												data.pixel_sample) / data.area;
	if (data.w0 >= 0 && data.w1 >= 0 && data.w2 >= 0)
	{
		data.one_over_z = (data.triangle.a.w * data.w0) +
				(data.triangle.b.w * data.w1) + (data.triangle.c.w * data.w2);
		data.z = 1 / data.one_over_z;
		if (data.z <= view_port->depth_buffer[data.pixel_index])
		{
			view_port->depth_buffer[data.pixel_index] = data.z;
			draw_pixel(view_port->window,
					(int)(data.pixel_sample.x + view_port->pos.x),
					(int)(data.pixel_sample.y + view_port->pos.y), *p_color);
		}
	}
}

void		draw_triangle_color_cpu(t_view_port *view_port,
									t_triangle *p_triangle, t_color *p_color)
{
	t_fuck_norme	data;

	data.triangle = convert_t_triangle(view_port, p_triangle);
	t_triangle_get_min_max_value(&data.triangle, &data.min, &data.max);
	get_min_max_draw_triangle(view_port, &data.min, &data.max);
	data.area = edge_t_vector4(data.triangle.a, data.triangle.b,
														data.triangle.c);
	data.y = data.min.y - 1;
	while (++data.y <= data.max.y)
	{
		data.pixel_index = (int)(data.min.x) + (data.y * view_port->size.x);
		data.x = data.min.x - 1;
		while (++data.x <= data.max.x)
		{
			draw_triangle_color_cpu_next(view_port, p_color, data);
			data.pixel_index++;
		}
	}
}
