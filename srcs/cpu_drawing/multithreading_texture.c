#include "unknow_project.h"

void draw_triangle_texture_cpu(t_window *p_win, t_triangle_list *p_triangle, t_uv_list *p_uvs)
{
	for (int i = 0; i < p_triangle->size; i++)
		calc_triangle_texture_cpu(p_win, 0, &(p_triangle->triangle[i]), &(p_uvs->uvs[i]));
}

/*void *thread_triangle_texture(void *p_data)
{
	t_void_list *data;

	data = (t_void_list *)(p_data);

	int index = (int)(t_void_list_at(data, 0)); // permet de recuperer l'element x du data
	int t_start = (int)(t_void_list_at(data, 1));
	int t_len = (int)(t_void_list_at(data, 2));
	t_window *p_win = (t_window *)(t_void_list_at(data, 3));
	t_triangle_list *p_t = (t_triangle_list *)(t_void_list_at(data, 4));
	t_uv_list *p_uvs = (t_uv_list *)(t_void_list_at(data, 5));

	int tmp;
	t_triangle *tmp_triangle;
	t_uv *tmp_uv;
	int i = 0;
	while (i < t_len)
	{
		tmp = t_start + i;
		tmp_triangle = t_triangle_list_get(p_t, tmp); //recupere l'adresse du triangle numero tmp
		tmp_uv = t_uv_list_get(p_uvs, tmp); // recupere la couleur du tmp

		calc_triangle_texture_cpu(p_win, tmp, tmp_triangle,	tmp_uv);	//calcul du triangle
		i++;
	}
	pthread_exit(NULL);
}

void draw_triangle_texture_cpu(t_window *p_win, t_triangle_list *p_triangle, t_uv_list *p_uvs)
{
	int thread_length;
	long i;
	long t_start; //premier triangle a tracer
	long t_len; //nombre de triangle a tracer

	thread_length = p_triangle->size / NB_THREAD; //nombre de triangle / nombre de thread
	i = 0;
	while (i < NB_THREAD)
	{
		t_start = i * thread_length; //premier triangle du thread
		if (i == NB_THREAD - 1) //permet de gerer si le nombre de triangle n'est pas egale dans chaque thread
			t_len = p_triangle->size - t_start;
		else
			t_len = thread_length;

		clean_t_void_list(&(p_win->data[i]));
		t_void_list_add_back(&(p_win->data[i]), 6, (void *)i, (void *)(t_start), (void *)(t_len), p_win, p_triangle, p_uvs); // permet de rajouter un element contenant d'autres elements a la liste

		pthread_create(&(p_win->threads[i]), NULL, thread_triangle_texture, &(p_win->data[i])); // creation du thread, et appel a la fonction thread_triangle_color

		i++;
	}
	i = 0;
	while (i < NB_THREAD)
	{
		pthread_join(p_win->threads[i], NULL); // join et free des threads
		i++;
	}
}*/
