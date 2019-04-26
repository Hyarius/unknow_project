#include "unknow_project.h"

void add_pixel_to_screen(t_window *p_win, int p_coord, t_color *color)
{
	t_vector3_list_add_back(&(p_win->vertex_buffer_data), &(p_win->coord_data[p_coord]));
	t_color_list_add_back(&(p_win->color_buffer_data), color);
}

void clean_buffers(t_window *p_win)
{
	clean_t_color_list(&(p_win->color_buffer_data));
	clean_t_vector3_list(&(p_win->vertex_buffer_data));
}
