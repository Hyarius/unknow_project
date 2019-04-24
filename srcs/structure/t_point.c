#include "unknow_project.h"

t_point		create_t_point(float p_x, float p_y, t_color p_color)
{
	t_point point;

	point.x = p_x;
	point.y = p_y;
	point.color = p_color;

	return (point);
}

void t_point_swap(t_point *a, t_point *b)
{
	t_point tmp;

	tmp.x = a->x;
	tmp.y = a->y;
	tmp.color = a->color;
	*a = *b;
	*b = tmp;
}
