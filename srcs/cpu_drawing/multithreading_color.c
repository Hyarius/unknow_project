#include "unknow_project.h"

int nb_thread = NB_THREAD;

void *thread_triangle_color(void *p_data)
{
	t_void_list *data;

	data = (t_void_list *)(p_data);

	int index = (int)(t_void_list_at(data, 0));
	int t_start = (int)(t_void_list_at(data, 1));
	int t_len = (int)(t_void_list_at(data, 2));
	t_window *p_win = (t_window *)(t_void_list_at(data, 3));
	t_triangle_list *p_t = (t_triangle_list *)(t_void_list_at(data, 4));
	t_color_list *p_color = (t_color_list *)(t_void_list_at(data, 5));

	int tmp;
	t_triangle *tmp_triangle;
	t_color *tmp_color;
	int i = 0;
	while (i < t_len)
	{
		tmp = t_start + i;
		tmp_triangle = t_triangle_list_get(p_t, tmp);
		tmp_color = t_color_list_get(p_color, tmp);

		calc_triangle_color_cpu(p_win, index,
					tmp_triangle,
					tmp_color);
		i++;
	}
	pthread_exit(NULL);
}

/*
0 - index;
1 - start;
2 - len;
3 - p_window
4 - list triangle
5 - list color
*/

void draw_triangle_color_cpu(t_window *p_win, t_triangle_list *p_t, t_color_list *p_color)
{
	int thread_length;
	long i;
	long t_start;
	long t_len;

	thread_length = p_t->size / nb_thread;
	i = 0;
	while (i < nb_thread)
	{
		t_start = i * thread_length;
		if (i == nb_thread - 1)
			t_len = p_t->size - t_start;
		else
			t_len = thread_length;

		t_void_list_add_back(&(p_win->data[i]), 6, (void *)i, (void *)(t_start), (void *)(t_len), p_win, p_t, p_color);

		pthread_create(&(p_win->threads[i]), NULL, thread_triangle_color, &(p_win->data[i]));

		i++;
	}
	i = 0;
	while (i < nb_thread)
	{
		pthread_join(p_win->threads[i], NULL);
		i++;
	}
}
