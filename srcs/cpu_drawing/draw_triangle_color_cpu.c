#include "unknow_project.h"

typedef struct	s_rasterizer
{
	int a;
	int b;
	int c;
	int	max;
}				t_rasterizer;

int apply_formula(t_rasterizer *rast, t_vector2 *p)
{
	return (rast->a * p->x + rast->b * p->y + rast->c);
}

void set_rasterizer(t_rasterizer *rast, t_vector2 *s, t_vector2 *e, t_vector2 *ext)
{
	rast->a = (s->y - e->y);
	rast->b = (e->x - s->x);
	rast->c = (s->x * e->y) - (s->y * e->x);
	rast->max = apply_formula(rast, ext);
}

void	calc_rasterizer(float *result, t_rasterizer *rast, t_vector2 *p)
{
	*result = ((float)(apply_formula(rast, p))) / ((float)(rast->max));
	//*result = apply_formula(rast, p);
	//*result = 1.0f / rast->max;
}

void use_rasterize(t_window *p_win, t_rasterizer *rast, t_color *p_color, int *value)
{
	t_vector2		p;
	float			alpha;
	float			beta;
	float			gamma;

	p.y = value[2];
	p.x = value[0];
	while (p.x < value[1])
	{
		/*calc_rasterizer(&alpha, &(rast[0]), &p);
		calc_rasterizer(&beta, &(rast[1]), &p);
		gamma = 1.0f - (alpha + beta);*/

		add_pixel_to_screen(p_win, p.x + p.y * p_win->size_x, p_color);
		p.x++;
	}
}

static void fill_down_flat_triangle(t_window *p_win, t_triangle *p_t, t_rasterizer *rast, t_color *p_color)
{
	t_vector2_int range;
	float slope[2];
	float current[2];
	int scan_line_y = p_t->a.y;
	int	value[3];

	slope[0] = (p_t->b.x - p_t->a.x) / (p_t->b.y - p_t->a.y);
	slope[1] = (p_t->c.x - p_t->a.x) / (p_t->c.y - p_t->a.y);
	current[0] = p_t->a.x;
	current[1] = p_t->a.x;
	while (scan_line_y <= p_t->b.y)
	{
		range.x = (int)(current[0]);
		range.y = (int)(current[1]);
		value[0] = range.x;
		value[1] = range.y;
		value[2] = scan_line_y;
		use_rasterize(p_win, rast, p_color, value);
		current[0] += slope[0];
		current[1] += slope[1];

		scan_line_y++;
	}
}

static void fill_top_flat_triangle(t_window *p_win, t_triangle *p_t, t_rasterizer *rast, t_color *p_color)
{
	t_vector2_int range;
	float slope[2];
	float current[2];
	int scan_line_y;
	int	value[3];

	slope[0] = (p_t->c.x - p_t->a.x) / (p_t->c.y - p_t->a.y);
	slope[1] = (p_t->c.x - p_t->b.x) / (p_t->c.y - p_t->b.y);
	current[0] = p_t->c.x;
	current[1] = p_t->c.x;
	scan_line_y = p_t->c.y;
	while (scan_line_y > p_t->a.y)
	{
		range.x = (int)(current[0]);
		range.y = (int)(current[1]);
		value[0] = range.x;
		value[1] = range.y;
		value[2] = scan_line_y;
		use_rasterize(p_win, rast, p_color, value);
		current[0] -= slope[0];
		current[1] -= slope[1];
		scan_line_y--;
	}
}

void draw_triangle_color_cpu(t_window *p_win, t_triangle *p_t, t_color *p_color)
{
	t_vector2 p_d;
	p_d = create_t_vector2(p_t->a.x + ((p_t->b.y - p_t->a.y) / (p_t->c.y -
				p_t->a.y) * (p_t->c.x - p_t->a.x)), p_t->b.y);
	t_triangle t1 = create_t_triangle(p_t->a, p_t->b, p_d);
	t_triangle t2 = create_t_triangle(p_t->b, p_d, p_t->c);
	t_triangle t3 = create_t_triangle(p_t->a, p_t->b, p_t->c);
	t_rasterizer rast[2];

	if (p_t->a.y > p_t->b.y || (p_t->a.y == p_t->b.y && p_t->a.x > p_t->b.x))
		t_vector2_swap(&(p_t->a), &(p_t->b));
	if (p_t->b.y > p_t->c.y || (p_t->b.y == p_t->c.y && p_t->b.x > p_t->c.x))
		t_vector2_swap(&(p_t->b), &(p_t->c));
	if (p_t->a.y > p_t->b.y || (p_t->a.y == p_t->b.y && p_t->a.x > p_t->b.x))
		t_vector2_swap(&(p_t->a), &(p_t->b));

	set_rasterizer(&(rast[0]), &(p_t->a), &(p_t->b), &(p_t->c));
	set_rasterizer(&(rast[1]), &(p_t->a), &(p_t->c), &(p_t->b));

	if (p_t->b.y == p_t->c.y)
	{
		fill_down_flat_triangle(p_win, &t3, rast, p_color);
	}
	else if (p_t->a.y == p_t->b.y || p_t->a.y == p_t->c.y)
	{
		fill_top_flat_triangle(p_win, &t3, rast, p_color);
	}
	else
	{
		fill_down_flat_triangle(p_win, &t1, rast, p_color);
		fill_top_flat_triangle(p_win, &t2, rast, p_color);
	}
}
