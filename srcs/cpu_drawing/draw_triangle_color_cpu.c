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

void	calc_rasterizer(float *result, t_rasterizer *rast, int x, int y)
{
	*result = ((float)(apply_formula(rast, x, y))) / ((float)(rast->max));
	//*result = apply_formula(rast, p);
	//*result = 1.0f / rast->max;
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
				add_pixel_to_screen(p_win, 0, p.x + p.y * p_win->size_x, p_color);
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
	int			x_min;
	int			x_max;

	int			y_min;
	int			y_max;

	int			x;
	int			y;

	x_min = get_short(p_t->a.x, p_t->b.x, p_t->c.x);
	y_min = get_short(p_t->a.y, p_t->b.y, p_t->c.y);

	x_max = get_big(p_t->a.x, p_t->b.x, p_t->c.x);
	y_max = get_big(p_t->a.y, p_t->b.y, p_t->c.y);

	y = y_min;
	while (y < y_max)
	{
		x = x_min;
		while (x < x_max)
		{
			x++;
		}
		y++;
	}
}
