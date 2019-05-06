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

void *thread_rasterize_function(void *arg)
{
	/*t_void_list *data = arg;
	t_window *p_win = t_void_list_at(data, 0);
	int index = (int)(t_void_list_at(data, 3));
	int y_start;
	int find;

	float y_delta = *((float *)(t_void_list_at(data, 2)));
	float alpha;
	float beta;
	float gamma;

	t_vector2_int p;

	y_start = (int)(t_void_list_at(data, 1)) + index * y_delta;
	p.y = (int)(t_void_list_at(data, 1)) + index * y_delta;
	while (p.y < y_start + y_delta)
	{
		find = 0;
		p.x = (int)(t_void_list_at(data, 4));
		while (p.x < (int)(t_void_list_at(data, 5)))
		{
			calc_rasterizer(&alpha, t_void_list_at(data, 6), &p);
			calc_rasterizer(&beta, t_void_list_at(data, 7), &p);
			gamma = 1.0f - (alpha + beta);

			if (alpha >= 0.0f && alpha <= 1.0f && beta >= 0.0f && beta <= 1.0f
				&& gamma >= 0.0f && gamma <= 1.0f)
			{
				find = 1;
				add_pixel_to_screen(p_win, index, p.x + p.y * p_win->size_x, t_void_list_at(data, 8));
			}
			else if (find == 1)
				break;
			p.x++;
		}
		p.y++;
	}*/
	//printf("thread : %d\n", pthread_self());
	pthread_exit(NULL);
}

/*
void draw_triangle_color_cpu(t_window *p_win, t_triangle *p_t, t_color *p_color)
{
	int			x_min;
	int			x_max;

	int			y_min;
	int			y_max;

	t_rasterizer	ab;
	t_rasterizer	ac;

	int find;

	float alpha;
	float beta;
	float gamma;

	t_vector2_int p;


	x_min = get_short(p_t->a.x, p_t->b.x, p_t->c.x);
	y_min = get_short(p_t->a.y, p_t->b.y, p_t->c.y);

	x_max = get_big(p_t->a.x, p_t->b.x, p_t->c.x);
	y_max = get_big(p_t->a.y, p_t->b.y, p_t->c.y);

	set_rasterizer(&ab, &(p_t->a), &(p_t->b), &(p_t->c));
	set_rasterizer(&ac, &(p_t->a), &(p_t->c), &(p_t->b));

	p.y = y_min;
	while (p.y < y_max)
	{
		find = 0;
		p.x = x_min;
		while (p.x < x_max)
		{
			calc_rasterizer(&alpha, &ab, p.x, p.y);
			calc_rasterizer(&beta, &ac, p.x, p.y);
			gamma = 1.0f - (alpha + beta);

			if (alpha >= 0.0f && alpha <= 1.0f && beta >= 0.0f && beta <= 1.0f
				&& gamma >= 0.0f && gamma <= 1.0f)
			{
				find = 1;
				add_pixel_to_screen(p_win, p.x + p.y * p_win->size_x, p_color);
			}
			else if (find == 1)
				break;
			p.x++;
		}
		p.y++;
	}
}
*/

void draw_triangle_color_cpu(t_window *p_win, t_triangle *p_t, t_color *p_color)
{
	float			alpha;
	float			beta;
	float			gamma;
	float			base_alpha;
	float			base_beta;
	float			base_gamma;
	float			alpha_x;
	float			beta_x;
	float			gamma_x;
	float			alpha_y;
	float			beta_y;
	float			gamma_y;

	t_vector2		delta_alpha;
	t_vector2		delta_beta;
	t_vector2		delta_gamma;

	t_rasterizer	ab;
	t_rasterizer	ac;
	t_rasterizer	bc;

	int			x_min;
	int			x_max;

	int			y_min;
	int			y_max;

	int			x;
	int			y;

	int find;

	set_rasterizer(&ab, &(p_t->a), &(p_t->b), &(p_t->c));
	set_rasterizer(&ac, &(p_t->a), &(p_t->c), &(p_t->b));
	set_rasterizer(&bc, &(p_t->b), &(p_t->c), &(p_t->a));

	base_alpha = calc_rasterizer(&ab, 0, 0);
	base_beta = calc_rasterizer(&ac, 0, 0);
	base_gamma = calc_rasterizer(&bc, 0, 0);

	alpha_x = calc_rasterizer(&ab, 1, 0);
	beta_x = calc_rasterizer(&ac, 1, 0);
	gamma_x = calc_rasterizer(&bc, 1, 0);

	alpha_y = calc_rasterizer(&ab, 0, 1);
	beta_y = calc_rasterizer(&ac, 0, 1);
	gamma_y = calc_rasterizer(&bc, 0, 1);

	delta_alpha.x = alpha_x - base_alpha;
	delta_alpha.y = alpha_y - base_alpha;
	delta_beta.x = beta_x - base_beta;
	delta_beta.y = beta_y - base_beta;
	delta_gamma.x = gamma_x - base_gamma;
	delta_gamma.y = gamma_y - base_gamma;

	x_min = get_short(p_t->a.x, p_t->b.x, p_t->c.x);
	y_min = get_short(p_t->a.y, p_t->b.y, p_t->c.y);

	x_max = get_big(p_t->a.x, p_t->b.x, p_t->c.x);
	y_max = get_big(p_t->a.y, p_t->b.y, p_t->c.y);

	x = x_min;
	base_alpha = base_alpha + (x * delta_alpha.x);
	base_beta = base_beta + (x * delta_beta.x);
	base_gamma = base_gamma + (x * delta_gamma.x);

	y = y_min;
	//printf("%d, %d, %d, %d\n", x_min, x_max, y_min, y_max);
	while (y < y_max)
	{
		find = 0;
		x = x_min;
		alpha = base_alpha + (y * delta_alpha.y);
		beta = base_beta + (y * delta_beta.y);
		gamma = base_gamma + (y * delta_gamma.y);
		while (x < x_max)
		{
			if (alpha > 0.0f && beta > 0.0f && gamma > 0.0f)
			{
				find = 1;
				add_pixel_to_screen(p_win, x + y * p_win->size_x, p_color);
			}
			else if (find == 1)
				break;

			alpha += delta_alpha.x;
			beta += delta_beta.x;
			gamma += delta_gamma.x;
			x++;
		}
		y++;
	}
}
