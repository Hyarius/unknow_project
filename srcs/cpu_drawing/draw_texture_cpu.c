#include "unknow_project.h"

void	draw_triangle_texture_cpu(t_view_port *p_view_port, t_triangle *p_triangle, t_uv *p_uv)
{
	t_texture		*texture;
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
	t_color			color;
	t_vector3 		pixel;
	t_triangle 		uv;
	float			z;

	texture = p_uv->texture;


	triangle.a = convert_opengl_to_vector3(p_view_port, p_triangle->a);
	triangle.b = convert_opengl_to_vector3(p_view_port, p_triangle->b);
	triangle.c = convert_opengl_to_vector3(p_view_port, p_triangle->c);

	p_uv->uv.a.z = triangle.a.z;
	p_uv->uv.b.z = triangle.b.z;
	p_uv->uv.c.z = triangle.c.z;

	if (triangle.a.z != 0)
		triangle.a.z = 1.0 / triangle.a.z;
	if (triangle.b.z != 0)
		triangle.b.z = 1.0 / triangle.b.z;
	if (triangle.c.z != 0)
		triangle.c.z = 1.0 / triangle.c.z;


	ab = create_t_rasterizer(triangle.a, triangle.b, triangle.c);
	ac = create_t_rasterizer(triangle.a, triangle.c, triangle.b);
	bc = create_t_rasterizer(triangle.b, triangle.c, triangle.a);

	t_triangle_get_min_max_value(&triangle, &min, &max);
	t_triangle_get_min_max_value(&triangle, &min, &max);

	if (min.x < 0)
		min.x = 0;
	if (min.y < 0)
		min.y = 0;
	if (max.x >= p_view_port->size.x)
		max.x = p_view_port->size.x - 1;
	if (max.y >= p_view_port->size.y)
		max.y = p_view_port->size.y - 1;

	current = min;
	while (current.y <= max.y)
	{
		pixel_index = (int)(current.x) + ((int)(current.y) * p_view_port->size.x);

		while (current.x <= max.x)
		{
			alpha = calc_rasterizer(&ab, current.x, current.y);
			beta = calc_rasterizer(&ac, current.x, current.y);
			gamma = 1.0 - alpha - beta;

			if (alpha >= 0 && beta >= 0 && gamma >= 0)
			{
				z = 1.0;
				if (triangle.a.z != 0 || triangle.b.z != 0 || triangle.c.z != 0)
					z = 1.0f / ((triangle.a.z * gamma) + (triangle.b.z * beta) + (triangle.c.z * alpha));

				pixel.x = alpha * p_uv->uv.c.x + beta * p_uv->uv.b.x + gamma * p_uv->uv.a.x;
                pixel.y = 1.0 - (alpha * p_uv->uv.c.y + beta * p_uv->uv.b.y + gamma * p_uv->uv.a.y);
				pixel.x *= z;
				pixel.y *= z;
				pixel.x *= texture->surface->w;
				pixel.y *= texture->surface->h;
				if (z <= p_view_port->depth_buffer[pixel_index] || p_view_port->depth_buffer[pixel_index] == -1)
				{
					color = get_pixel_color(texture, (int)(pixel.x - EPSILON), (int)(pixel.y - EPSILON));
					draw_pixel(p_view_port->window, (int)(current.x), (int)(current.y), color);
					p_view_port->depth_buffer[pixel_index] = z;
				}
			}
			current.x++;
			pixel_index++;
		}
		current.x = min.x;
		current.y++;
	}
}

// void	draw_triangle_texture_cpu(t_view_port *p_view_port, t_triangle *p_triangle, t_uv *p_uv)
// {
// 	t_triangle	v;
// 	t_triangle	c;
//
// 	v = create_t_triangle(create_t_vector3(0.0, 0.0, 0.0), create_t_vector3(0.0, 0.0, 0.0), create_t_vector3(0.0, 0.0, 0.0));
// 	c = create_t_triangle(create_t_vector3(1.0, 0.0, 0.0), create_t_vector3(0.0, 1.0, 0.0), create_t_vector3(0.0, 0.0, 1.0));
//
// 	v.a.x = p_triangle->a.x / p_triangle->a.z;
// 	v.a.y = p_triangle->a.y / p_triangle->a.z;
// 	v.b.x = p_triangle->b.x / p_triangle->b.z;
// 	v.b.y = p_triangle->b.y / p_triangle->b.z;
// 	v.c.x = p_triangle->c.x / p_triangle->c.z;
// 	v.c.y = p_triangle->c.y / p_triangle->c.z;
//
// 	v.a.x = (1 + v.a.x) * 0.5 * p_view_port->window->size_x;
// 	v.a.y = (1 + v.a.y) * 0.5 * p_view_port->window->size_y;
// 	v.b.x = (1 + v.b.x) * 0.5 * p_view_port->window->size_x;
// 	v.b.y = (1 + v.b.y) * 0.5 * p_view_port->window->size_y;
// 	v.c.x = (1 + v.c.x) * 0.5 * p_view_port->window->size_x;
// 	v.c.y = (1 + v.c.y) * 0.5 * p_view_port->window->size_y;
//
// 	c.a.x /= p_triangle->a.z;
// 	c.a.y /= p_triangle->a.z;
// 	c.a.z /= p_triangle->a.z;
// 	c.b.x /= p_triangle->b.z;
// 	c.b.y /= p_triangle->b.z;
// 	c.b.z /= p_triangle->b.z;
// 	c.c.x /= p_triangle->c.z;
// 	c.c.y /= p_triangle->c.z;
// 	c.c.z /= p_triangle->c.z;
//
// 	v.a.z = 1 / v.a.z;
// 	v.b.z = 1 / v.b.z;
// 	v.c.z = 1 / v.c.z;
//
// 	t_color	color;
// 	color = create_t_color(1.0, 0.0, 0.0, 1.0);
// 	t_vector3	p;
// 	p = create_t_vector3(0.0, 0.0, 0.0);
// 	t_vector3	w;
// 	w = create_t_vector3(0.0, 0.0, 0.0);
// 	float		z;
// 	z = 0.0;
//
// 	float area = edge_t_vector3(v.a, v.b, v.c);
// 	int j = 0;
// 	while (j < p_view_port->window->size_y)
// 	{
// 		int i = 0;
// 		while (i < p_view_port->window->size_x)
// 		{
// 			p.x = (float)(i + 0.5);
// 			p.y = (float)(p_view_port->window->size_y - j + 0.5);
// 			p.z = 0.0;
// 			w.x = edge_t_vector3(v.b, v.c, p);
// 			w.y = edge_t_vector3(v.c, v.a, p);
// 			w.z = edge_t_vector3(v.a, v.b, p);
// 			if (w.x >= 0.0 && w.y >= 0.0 && w.z >= 0.0)
// 			{
// 				w.x /= area;
// 				w.y /= area;
// 				w.z /= area;
// 				color.r = w.x * c.a.x + w.y * c.b.x + w.z * c.c.x;
// 				color.g = w.x * c.a.y + w.y * c.b.y + w.z * c.c.y;
// 				color.b = w.x * c.a.z + w.y * c.b.z + w.z * c.c.z;
// 				// print_t_vector3(w, "vector w = ");
// 				// color = get_pixel_color(p_uv->texture, (int)w.x, (int)w.y);
// 				z = 1 / (w.x * v.a.z + w.y * v.b.z + w.z * v.c.z);
// 				// printf("%f\n", 1 / (w.x * v.a.z + w.y * v.b.z + w.z * v.c.z));
// 				color.r *= z;
// 				color.g *= z;
// 				color.b *= z;
// 				draw_pixel(p_view_port->window, i, j, color);
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
//
// }

void	*thread_draw_texture_cpu(void *void_list)
{
	t_void_list 	*data;
	int				i;
	int				start;
	int				len;
	t_view_port 	*p_view_port;
	t_triangle_list	*triangle_list;
	t_uv_list	*uv_list;
	t_triangle		*triangle;
	t_uv		*uv;

	data = (t_void_list *)(void_list);
	start = (int)(t_void_list_at(data, 0));
	len = (int)(t_void_list_at(data, 1));
	p_view_port = (t_view_port *)(t_void_list_at(data, 2));
	triangle_list = (t_triangle_list *)(t_void_list_at(data, 3));
	uv_list = (t_uv_list *)(t_void_list_at(data, 4));
	i = 0;
	while (i < len && (start + i) < triangle_list->size)
	{
		triangle = t_triangle_list_get(triangle_list, start + i);
		uv = t_uv_list_get(uv_list, start + i);
		draw_triangle_texture_cpu(p_view_port, triangle, uv);
		i++;
	}
	pthread_exit(NULL);
}

void	multithreading_draw_triangle_texture_cpu(t_view_port *p_view_port, t_triangle_list *p_triangle_list, t_uv_list *p_uv_list)
{
	int start;
	int	modulo;
	int len;
	int i;
	int nb_thread;


	start = 0;
	modulo = p_triangle_list->size % NB_THREAD_MAX;
	i = 0;
	nb_thread = p_triangle_list->size / (NB_TRIANGLE_MAX);
	if (nb_thread == 0)
		nb_thread++;
	if (nb_thread >= NB_THREAD_MAX)
		nb_thread = NB_THREAD_MAX;
	while (i < nb_thread)
	{
		len = p_triangle_list->size / nb_thread;
		if (i < modulo)
			len++;
		clean_t_void_list(&(p_view_port->window->data[i]));
		t_void_list_add_back(&p_view_port->window->data[i], 5, (long)start, (long)len, p_view_port, p_triangle_list, p_uv_list);
		pthread_create(&(p_view_port->window->threads[i]), NULL, thread_draw_texture_cpu, &(p_view_port->window->data[i]));
		i++;
		start += len;
	}
	i = 0;
	while (i < nb_thread)
	{
		pthread_join(p_view_port->window->threads[i], NULL); // join et free des threads
		i++;
	}
}

void    draw_rectangle_texture_cpu(t_view_port *p_view_port, t_rectangle p_rec, t_texture *p_texture)
{
	draw_triangle_texture_cpu(p_view_port, initialize_t_triangle(create_t_vector3(p_rec.pos.x, p_rec.pos.y, 0.0),
										create_t_vector3(p_rec.pos.x + p_rec.size.x, p_rec.pos.y, 0.0),
										create_t_vector3(p_rec.pos.x, p_rec.pos.y + p_rec.size.y, 0.0)),
										initialize_t_uv(create_t_triangle(create_t_vector3(0, 0, 0), create_t_vector3(1, 0, 0), create_t_vector3(0, 1, 0)), p_texture));

	draw_triangle_texture_cpu(p_view_port, initialize_t_triangle(create_t_vector3(p_rec.pos.x + p_rec.size.x, p_rec.pos.y + p_rec.size.y, 0.0),
										create_t_vector3(p_rec.pos.x + p_rec.size.x, p_rec.pos.y, 0.0),
										create_t_vector3(p_rec.pos.x, p_rec.pos.y + p_rec.size.y, 0.0)),
										initialize_t_uv(create_t_triangle(create_t_vector3(1, 1, 0), create_t_vector3(1, 0, 0), create_t_vector3(0, 1, 0)), p_texture));
}