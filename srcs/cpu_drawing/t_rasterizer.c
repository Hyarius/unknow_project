#include "unknow_project.h"

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
