#include "unknow_project.h"

void draw_triangle_color_cpu(t_window *p_win, t_triangle_list *p_t, t_color_list *p_color)
{
	for (int i = 0; i < p_t->size; i++)
		calc_triangle_color_cpu(p_win, i, t_triangle_list_get(p_t, i), t_color_list_get(p_color, i));
	clean_z_buffer(p_win);
}

// void *thread_triangle_color(void *p_data)
// {
// 	t_void_list *data;
//
// 	data = (t_void_list *)(p_data);
//
// 	int t_start = (int)(t_void_list_at(data, 0));
// 	int t_len = (int)(t_void_list_at(data, 1));
// 	t_window *p_win = (t_window *)(t_void_list_at(data, 2));
// 	t_triangle_list *p_t = (t_triangle_list *)(t_void_list_at(data, 3));
// 	t_color_list *p_color = (t_color_list *)(t_void_list_at(data, 4));
//
// 	int tmp;
// 	t_triangle *tmp_triangle;
// 	t_color *tmp_color;
// 	int i = 0;
// 	while (i < t_len)
// 	{
// 		tmp = t_start + i;
// 		tmp_triangle = t_triangle_list_get(p_t, tmp); //recupere l'adresse du triangle numero tmp
// 		tmp_color = t_color_list_get(p_color, tmp); // recupere la couleur du tmp
//
// 		calc_triangle_color_cpu(p_win, tmp, tmp_triangle, tmp_color);	//calcul du triangle
// 		i++;
// 	}
// 	pthread_exit(NULL);
// }
//
// void draw_triangle_color_cpu(t_window *p_win, t_triangle_list *p_t, t_color_list *p_color)
// {
// 	int thread_length;
// 	long i;
// 	long t_start; //premier triangle a tracer
// 	long t_len; //nombre de triangle a tracer
//
// 	thread_length = p_t->size / NB_THREAD; //nombre de triangle / nombre de thread
// 	i = 0;
// 	while (i < NB_THREAD)
// 	{
// 		t_start = i * thread_length; //premier triangle du thread
// 		if (i == NB_THREAD - 1) //permet de gerer si le nombre de triangle n'est pas egale dans chaque thread
// 			t_len = p_t->size - t_start;
// 		else
// 			t_len = thread_length;
//
// 		clean_t_void_list(&(p_win->data[i]));
// 		t_void_list_add_back(&(p_win->data[i]), 5, (void *)(t_start), (void *)(t_len), p_win, p_t, p_color); // permet de rajouter un element contenant d'autres elements a la liste
//
// 		pthread_create(&(p_win->threads[i]), NULL, thread_triangle_color, &(p_win->data[i])); // creation du thread, et appel a la fonction thread_triangle_color
//
// 		i++;
// 	}
// 	i = 0;
// 	while (i < NB_THREAD)
// 	{
// 		pthread_join(p_win->threads[i], NULL); // join et free des threads
// 		i++;
// 	}
// 	clean_z_buffer(p_win);
// }
