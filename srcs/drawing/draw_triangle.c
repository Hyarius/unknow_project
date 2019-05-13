#include "unknow_project.h"

void draw_triangle_color(t_window *p_win, t_triangle_list *p_t, t_color_list *p_color)
{
	t_triangle *tmp;
	t_triangle triangle;
	t_vector2 coord[3];
	int index;
	int i;

	i = 0;
	while (i < p_t->size)
	{
		tmp = t_triangle_list_get(p_t, i);

		coord[0] = convert_screen_to_opengl(p_win, (int)(tmp->a.x), (int)(tmp->a.y));
		coord[1] = convert_screen_to_opengl(p_win, (int)(tmp->b.x), (int)(tmp->b.y));
		coord[2] = convert_screen_to_opengl(p_win, (int)(tmp->c.x), (int)(tmp->c.y));

		triangle = create_t_triangle(coord[0], coord[1], coord[2]);

		draw_triangle_color_opengl(p_win, &triangle, t_color_list_get(p_color, i));

		i++;
	}
}

void draw_triangle_texture(t_window *p_win, t_triangle *p_t_screen, t_triangle *p_t_uv, t_texture *p_texture, float p_alpha)
{
	t_triangle triangle;
	t_vector2 coord[3];

	coord[0] = convert_screen_to_opengl(p_win, (int)(p_t_screen->a.x), (int)(p_t_screen->a.y));
	coord[1] = convert_screen_to_opengl(p_win, (int)(p_t_screen->b.x), (int)(p_t_screen->b.y));
	coord[2] = convert_screen_to_opengl(p_win, (int)(p_t_screen->c.x), (int)(p_t_screen->c.y));

	triangle = create_t_triangle(coord[0], coord[1], coord[2]);

	draw_triangle_texture_opengl(p_win, &triangle, p_t_uv, p_texture, p_alpha);
}
