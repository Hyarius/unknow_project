#include "unknow_project.h"

t_rect		create_t_rect(float p_x, float p_y, float p_w, float p_h)
{
	t_rect	rect;

	rect.x = p_x;
	rect.y = p_y;
	rect.w = p_w;
	rect.h = p_h;

	return (rect);
}
