#include "unknow_project.h"

t_vector2		convert_screen_to_opengl(t_window p_win, t_vector2 source)
{
	return (create_t_vector2(
		source.x / (p_win.size_x / 2.0) - 1.0f,
		-(source.y / (p_win.size_y / 2.0) - 1.0f)
	));
}
