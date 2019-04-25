#include "unknow_project.h"

t_vector2		convert_screen_to_opengl(t_window *p_win, t_vector2_int source)
{
	t_vector2 result;

	result.x = source.x / (p_win->size_x / 2.0) - 1.0f;
	result.y = -(source.y / (p_win->size_y / 2.0) - 1.0f);
	return (result);
}

void		convert_point_to_opengl(t_window *p_win, t_point *source)
{
	source->x = source->x / (p_win->size_x / 2.0) - 1.0f;
	source->y = -(source->y / (p_win->size_y / 2.0) - 1.0f);
}

void		convert_coord_to_opengl(t_window *p_win, t_vector2 *source)
{
	source->x = source->x / (p_win->size_x / 2.0) - 1.0f;
	source->y = -(source->y / (p_win->size_y / 2.0) - 1.0f);
}
