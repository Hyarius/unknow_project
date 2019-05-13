#include "unknow_project.h"

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

void apply_pixel(t_window *p_win, int *value, float *base, t_color *p_color)
{
	if (base[3] > 0.0f && base[4] > 0.0f && base[5] > 0.0f)
	{
		value[6] = 1;
		add_pixel_to_screen(p_win, value[7], value[5] + value[4] * p_win->size_x, p_color);
	}
	else if (value[6] == 1)
		value[6] = -1;
}

void calc_triangle_color_cpu(t_window *p_win, int index, t_triangle *p_t, t_color *p_color)
{
	int				value[8];
	float			base[6];
	t_vector2		delta[3];
	int				b = 0;

	set_variable(p_t, value, base, delta);
	value[7] = index;
	value[4] = value[2];

	while (value[4] < value[3])
	{
		value[6] = 0;
		value[5] = value[0];
		base[3] = base[0] + (value[4] * delta[0].y);
		base[4] = base[1] + (value[4] * delta[1].y);
		base[5] = base[2] + (value[4] * delta[2].y);
		b++;
		while (value[5] < value[1] && value[6] != -1)
		{
			if (b == 1)
				p_win->vertex_buffer_data[0]->size++;
			b = 0;
			apply_pixel(p_win, value, base, p_color);
			base[3] += delta[0].x;
			base[4] += delta[1].x;
			base[5] += delta[2].x;
			value[5]++;
		}
		value[4]++;
	}
}
