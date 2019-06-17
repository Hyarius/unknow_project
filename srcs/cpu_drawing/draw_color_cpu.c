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
				float z = 1.0f / ((triangle.a.z * gamma) + (triangle.b.z * beta) + (triangle.c.z * alpha));

				if (z < p_win->depth_buffer[pixel_index])
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
}

/*

nb thread = 8

size totale = 16

thread 1 ->
start 0
len 2

thread 2 _>
start 2
len 2

*/

void	*thread_draw_color_cpu(void *void_list)
{
	t_void_list 	*data;
	int				i;
	int				start;
	int				len;
	t_window		*win;
	t_triangle_list	*triangle_list;
	t_color_list	*color_list;
	t_triangle		*triangle;
	t_color			*color;

	data = (t_void_list *)(void_list);
	start = (int)(t_void_list_at(data, 0));
	len = (int)(t_void_list_at(data, 1));
	win = (t_window *)(t_void_list_at(data, 2));
	triangle_list = (t_triangle_list *)(t_void_list_at(data, 3));
	color_list = (t_color_list *)(t_void_list_at(data, 4));
	i = 0;
	while (i < len && (start + i) < triangle_list->size)
	{
		triangle = t_triangle_list_get(triangle_list, start + i);
		color = t_color_list_get(color_list, start + i);
		draw_triangle_color_cpu(win, triangle, color);
		i++;
	}
	pthread_exit(NULL);
}

void	multithreading_draw_triangle_color_cpu(t_window *p_win, t_triangle_list *p_triangle_list, t_color_list *p_color_list)
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
	while (i < nb_thread)
	{
		len = p_triangle_list->size / nb_thread;
		if (i < modulo)
			len++;
		clean_t_void_list(&(p_win->data[i]));
		t_void_list_add_back(&p_win->data[i], 5, (long)start, (long)len, p_win, p_triangle_list, p_color_list);
		pthread_create(&(p_win->threads[i]), NULL, thread_draw_color_cpu, &(p_win->data[i]));
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