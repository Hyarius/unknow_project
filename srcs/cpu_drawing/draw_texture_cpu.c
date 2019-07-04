#include "unknow_project.h"

void	draw_triangle_texture_cpu(t_view_port *p_view_port, t_triangle *p_triangle, t_uv *p_uv)
{

}

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
