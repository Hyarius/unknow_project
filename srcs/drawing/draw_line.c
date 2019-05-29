#include "unknow_project.h"

void draw_line(t_window *p_win, t_line *p_line, t_color *color)
{
	t_line	line;
	t_vector3 coord[2];
	coord[0] = convert_screen_to_opengl(p_win, &(p_line->a));
	coord[1] = convert_screen_to_opengl(p_win, &(p_line->b));

	line = create_t_line(coord[0], coord[1]);
	draw_line_color_opengl(p_win, &line, color);
}
