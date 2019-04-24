#include "unknow_project.h"

t_point		create_t_point(float p_x, float p_y, t_color p_color)
{
	t_point point;

	point.x = p_x;
	point.y = p_y;
	point.color = p_color;

	return (point);
}
