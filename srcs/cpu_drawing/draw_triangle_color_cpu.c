#include "unknow_project.h"

typedef struct	s_rasterizer
{
	int a;
	int b;
	int c;
	int	max;
}				t_rasterizer;

int apply_formula(t_rasterizer *rast, t_vector2_int *p)
{
	return (rast->a * p->x + rast->b * p->y + rast->c);
}

void set_rasterizer(t_rasterizer *rast, t_vector2_int s, t_vector2_int e, t_vector2_int ext)
{
	rast->a = (s.y - e.y);
	rast->b = (e.x - s.x);
	rast->c = (s.x * e.y) - (s.y * e.x);
	rast->max = apply_formula(rast, &ext);
}

void	calc_rasterizer(float *result, t_rasterizer *rast, t_vector2_int *p)
{
	*result = ((float)(apply_formula(rast, p))) / ((float)(rast->max));
	//*result = apply_formula(rast, p);
	//*result = 1.0f / rast->max;
}

void	set_limits(t_triangle *p_t, int *limit)
{
	limit[0] = p_t->a.x;
	if (p_t->b.x < limit[0])
		limit[0] = p_t->b.x;
	if (p_t->c.x < limit[0])
		limit[0] = p_t->c.x;

	limit[1] = p_t->a.x;
	if (p_t->b.x > limit[1])
		limit[1] = p_t->b.x;
	if (p_t->c.x > limit[1])
		limit[1] = p_t->c.x;

	limit[2] = p_t->a.y;
	if (p_t->b.y < limit[2])
		limit[2] = p_t->b.y;
	if (p_t->c.y < limit[2])
		limit[2] = p_t->c.y;

	limit[3] = p_t->a.y;
	if (p_t->b.y > limit[3])
		limit[3] = p_t->b.y;
	if (p_t->c.y > limit[3])
		limit[3] = p_t->c.y;
}



void draw_triangle_color_cpu(t_window *p_win, t_triangle *p_t, t_color *p_color)
{
	int				limit[4]; // 0 = x min / 1 = x max / 2 = y min / 3 = y max
	t_vector2_int 	a;
	t_vector2_int 	b;
	t_vector2_int 	c;
	t_vector2_int 	p;
	float			alpha;
	float			beta;
	float			gamma;
	int				x;
	int				y;
	t_rasterizer	ab;
	t_rasterizer	ac;

	set_limits(p_t, limit);
	a = convert_vector2_to_vector2_int(&(p_t->a));
	b = convert_vector2_to_vector2_int(&(p_t->b));
	c = convert_vector2_to_vector2_int(&(p_t->c));

	set_rasterizer(&ab, a, b, c);
	set_rasterizer(&ac, a, c, b);

	x = limit[0];
	while (x < limit[1])
	{
		y = limit[2];
		while (y < limit[3])
		{
			p.x = x;
			p.y = y;
			calc_rasterizer(&alpha, &ac, &p);
			calc_rasterizer(&beta, &ab, &p);
			gamma = 1.0f - (alpha + beta);

			if (alpha >= 0.0f && alpha <= 1.0f && beta >= 0.0f && beta <= 1.0f
				&& gamma >= 0.0f && gamma <= 1.0f)
			{
				add_pixel_to_screen(p_win, x + y * p_win->size_x, p_color);
			}
			y++;
		}
		x++;
	}
}
