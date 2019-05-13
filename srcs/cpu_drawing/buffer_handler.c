#include "unknow_project.h"

void add_pixel_to_screen(t_window *p_win, int index, int p_coord, t_color *color)
{
	//p_win->vertex_buffer_data[index]->size++;
	//p_win->vertex_buffer_data[index]->size--;
	t_vector3_list_add_back((p_win->vertex_buffer_data[index]), &(p_win->coord_data[p_coord]));
	//p_win->vertex_buffer_data[index]->size++;
	t_color_list_add_back((p_win->color_buffer_data[index]), color);
}

void clean_buffers(t_window *p_win)
{
	int i = 0;

	while (i < NB_THREAD)
	{
		clean_t_color_list((p_win->color_buffer_data[i]));
		clean_t_vector3_list((p_win->vertex_buffer_data[i]));
		i++;
	}
}
