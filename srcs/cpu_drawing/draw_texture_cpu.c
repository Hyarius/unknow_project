#include "unknow_project.h"

void	draw_triangle_texture_cpu(t_window *p_win, t_triangle *p_triangle, t_uv *p_uv)
{
	// t_color			red = create_t_color(1.0, 0.0, 0.0, 1.0);
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
	float			z;
	t_color			color;
	t_vector3		pixel;
	t_triangle		uv;

	texture = p_uv->texture;

	triangle.a = convert_opengl_to_vector3(p_win, p_triangle->a);
	triangle.b = convert_opengl_to_vector3(p_win, p_triangle->b);
	triangle.c = convert_opengl_to_vector3(p_win, p_triangle->c);

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

	if (min.x < 0)
		min.x = 0;
	if (min.y < 0)
		min.y = 0;
	if (max.x >= p_win->size_x)
		max.x = p_win->size_x - 1;
	if (max.y >= p_win->size_y)
		max.y = p_win->size_y - 1;

	float cx = p_uv->uv.c.x / p_uv->uv.c.z;
	float cy = p_uv->uv.c.y / p_uv->uv.c.z;
	float bx = p_uv->uv.b.x / p_uv->uv.b.z;
	float by = p_uv->uv.b.y / p_uv->uv.b.z;
	float ax = p_uv->uv.a.x / p_uv->uv.a.z;
	float ay = p_uv->uv.a.y / p_uv->uv.a.z;

	current = min;
	while (current.y <= max.y)
	{
		pixel_index = (int)(current.x) + ((int)(current.y) * p_win->size_x);

		while (current.x <= max.x)
		{
			alpha = calc_rasterizer(&ab, current.x, current.y);
			beta = calc_rasterizer(&ac, current.x, current.y);
			gamma = 1.0 - alpha - beta;

			if (alpha >= 0 && beta >= 0 && gamma >= 0)
			{
				z = 1 / ((triangle.a.z * gamma) + (triangle.b.z * beta) + (triangle.c.z * alpha));

				pixel.x = ((alpha * cx) + (beta * bx) + (gamma * ax)) * z;
                pixel.y = 1 - ((alpha * cy) + (beta * by) + (gamma * ay)) * z;

				pixel.x *= texture->surface->w;
				pixel.y *= texture->surface->h;

				if (z <= p_win->depth_buffer[pixel_index] || p_win->depth_buffer[pixel_index] == -1)
				{
					color = get_pixel_color(texture, (int)(pixel.x - EPSILON), (int)(pixel.y - EPSILON));
					draw_pixel(p_win, (int)(current.x), (int)(current.y), color);
					p_win->depth_buffer[pixel_index] = z;
				}
			}
			current.x++;
			pixel_index++;
		}
		current.x = min.x;
		current.y++;
	}
}

void	*thread_draw_texture_cpu(void *void_list)
{
	t_void_list 	*data;
	int				i;
	int				start;
	int				len;
	t_window		*win;
	t_triangle_list	*triangle_list;
	t_uv_list	*uv_list;
	t_triangle		*triangle;
	t_uv		*uv;

	data = (t_void_list *)(void_list);
	start = (int)(t_void_list_at(data, 0));
	len = (int)(t_void_list_at(data, 1));
	win = (t_window *)(t_void_list_at(data, 2));
	triangle_list = (t_triangle_list *)(t_void_list_at(data, 3));
	uv_list = (t_uv_list *)(t_void_list_at(data, 4));
	i = 0;
	while (i < len && (start + i) < triangle_list->size)
	{
		triangle = t_triangle_list_get(triangle_list, start + i);
		uv = t_uv_list_get(uv_list, start + i);
		draw_triangle_texture_cpu(win, triangle, uv);
		i++;
	}
	pthread_exit(NULL);
}

void	multithreading_draw_triangle_texture_cpu(t_window *p_win, t_triangle_list *p_triangle_list, t_uv_list *p_uv_list)
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
		clean_t_void_list(&(p_win->data[i]));
		t_void_list_add_back(&p_win->data[i], 5, (long)start, (long)len, p_win, p_triangle_list, p_uv_list);
		pthread_create(&(p_win->threads[i]), NULL, thread_draw_texture_cpu, &(p_win->data[i]));
		i++;
		start += len;
	}
	i = 0;
	while (i < nb_thread)
	{
		pthread_join(p_win->threads[i], NULL); // join et free des threads
		i++;
	}
}
