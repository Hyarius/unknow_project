#include "unknow_project.h"

t_vector2		convert_screen_to_opengl(t_window *p_win, int p_x, int p_y)
{
	t_vector2 result;

	result.x = p_x / (p_win->size_x / 2.0) - 1.0f;
	result.y = -(p_y / (p_win->size_y / 2.0) - 1.0f);

	return (result);
}

void		convert_vector2_to_opengl(t_window *p_win, t_vector2 *source)
{
	source->x = source->x / (p_win->size_x / 2.0) - 1.0f;
	source->y = -(source->y / (p_win->size_y / 2.0) - 1.0f);
}

t_vector3			*get_opengl_coord(t_window *p_win, int i, int j)
{
	int coord = i + j * p_win->size_x;

	return (&(p_win->coord_data[coord]));
}

t_vector2_int	convert_vector2_to_vector2_int(t_vector2 *base)
{
	return (create_t_vector2_int((int)(base->x), (int)(base->y)));
}

t_vector3_int	convert_vector3_to_vector3_int(t_vector3 *base)
{
	return (create_t_vector3_int((int)(base->x), (int)(base->y), (int)(base->z)));
}
