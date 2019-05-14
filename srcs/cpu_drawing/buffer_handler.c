#include "unknow_project.h"

void add_pixel_to_screen(t_window *p_win, int index, int p_coord, t_color *color)
{
	t_vector3_list_add_back((p_win->vertex_buffer_data[index]), &(p_win->coord_data[p_coord]));
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

void set_variable(t_triangle *p_t, int *value, float *base, t_vector2 *delta)
{
	t_rasterizer	ab;
	t_rasterizer	ac;
	t_rasterizer	bc;

	value[0] = get_short(p_t->a.x, p_t->b.x, p_t->c.x); //x_min
	value[1] = get_big(p_t->a.x, p_t->b.x, p_t->c.x); //x_max
	value[2] = get_short(p_t->a.y, p_t->b.y, p_t->c.y); //y_min
	value[3] = get_big(p_t->a.y, p_t->b.y, p_t->c.y); //y_max
	set_rasterizer(&ab, &(p_t->a), &(p_t->b), &(p_t->c));
	set_rasterizer(&ac, &(p_t->a), &(p_t->c), &(p_t->b));
	set_rasterizer(&bc, &(p_t->b), &(p_t->c), &(p_t->a));
	base[0] = calc_rasterizer(&ab, 0, 0); //alpha
	base[1] = calc_rasterizer(&ac, 0, 0); // beta
	base[2] = calc_rasterizer(&bc, 0, 0); // gamma
	delta[0].x = calc_rasterizer(&ab, 1, 0) - base[0]; //alpha
	delta[0].y = calc_rasterizer(&ab, 0, 1) - base[0]; //alpha
	delta[1].x = calc_rasterizer(&ac, 1, 0) - base[1]; // beta
	delta[1].y = calc_rasterizer(&ac, 0, 1) - base[1]; // beta
	delta[2].x = calc_rasterizer(&bc, 1, 0) - base[2]; // gamma
	delta[2].y = calc_rasterizer(&bc, 0, 1) - base[2]; // gamma
	base[0] = base[0] + (value[0] * delta[0].x);
	base[1] = base[1] + (value[0] * delta[1].x);
	base[2] = base[2] + (value[0] * delta[2].x);
}
