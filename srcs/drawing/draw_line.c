#include "unknow_project.h"

void draw_line(t_window *p_win, t_line *p_line, t_color *color)
{
	t_line	line;
	t_vector2 coord[2];
	coord[0] = convert_screen_to_opengl(p_win, (int)(p_line->a.x), (int)(p_line->a.y));
	coord[1] = convert_screen_to_opengl(p_win, (int)(p_line->b.x), (int)(p_line->b.y));

	line = create_t_line(coord[0], coord[1]);
	draw_line_color_opengl(p_win, &line, color);
}
