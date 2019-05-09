#include "unknow_project.h"

typedef struct	s_rasterizer
{
	int a;
	int b;
	int c;
	int	max;
}				t_rasterizer;

int apply_formula(t_rasterizer *rast, int x, int y)
{
	return (rast->a * x + rast->b * y + rast->c);
}

void set_rasterizer(t_rasterizer *rast, t_vector2 *s, t_vector2 *e, t_vector2 *ext)
{
	rast->a = (s->y - e->y);
	rast->b = (e->x - s->x);
	rast->c = (s->x * e->y) - (s->y * e->x);
	rast->max = apply_formula(rast, ext->x, ext->y);
}

float	calc_rasterizer(t_rasterizer *rast, int x, int y)
{
	return (((float)(apply_formula(rast, x, y))) / ((float)(rast->max)));
}

int	get_short(int a, int b, int c)
{
	int result;

	result = a;
	if (result > b)
		result = b;
	if (result > c)
		result = c;
	return (result);
}

int	get_big(int a, int b, int c)
{
	int result;

	result = a;
	if (result < b)
		result = b;
	if (result < c)
		result = c;
	return (result);
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

void apply_pixel(t_window *p_win, int *value, float *base, t_color *p_color)
{
	if (base[3] > 0.0f && base[4] > 0.0f && base[5] > 0.0f)
	{
		value[6] = 1;
		add_pixel_to_screen(p_win, value[5] + value[4] * p_win->size_x, p_color);
	}
	else if (value[6] == 1)
		value[6] = -1;
}

void draw_triangle_color_cpu(t_window *p_win, t_triangle *p_t, t_color *p_color)
{
	int				value[7];
	float			base[6];
	t_vector2		delta[3];

	set_variable(p_t, value, base, delta);
	value[4] = value[2];
	while (value[4] < value[3])
	{
		value[6] = 0;
		value[5] = value[0];
		base[3] = base[0] + (value[4] * delta[0].y);
		base[4] = base[1] + (value[4] * delta[1].y);
		base[5] = base[2] + (value[4] * delta[2].y);
		while (value[5] < value[1] && value[6] != -1)
		{
			apply_pixel(p_win, value, base, p_color);
			base[3] += delta[0].x;
			base[4] += delta[1].x;
			base[5] += delta[2].x;
			value[5]++;
		}
		value[4]++;
	}
}
