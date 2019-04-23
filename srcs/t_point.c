#include "unknow_project.h"

t_point		create_t_point(float p_x, float p_y, t_color p_color)
{
	t_point point;

	point.x = p_x;
	point.y = p_y;
	point.color = p_color;

	return (point);
}

void		set_t_point_vector2(t_point *p_src, t_vector2 p_coord)
{
	p_src->x = p_coord.x;
	p_src->y = p_coord.y;
}

void		set_t_point_int(t_point *p_src, int p_x, int p_y)
{
	p_src->x = p_x;
	p_src->y = p_y;
}

void		set_t_point_float(t_point *p_src, float p_x, float p_y)
{
	p_src->x = p_x;
	p_src->y = p_y;
}
