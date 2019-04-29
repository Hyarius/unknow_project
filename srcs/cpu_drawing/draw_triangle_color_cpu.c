#include "unknow_project.h"

void draw_line_color(t_window *p_win, t_vector2_int range, int p_y, t_color *p_color)
{
	int delta;
	int i;

	i = range.x + p_y * p_win->size_x;
	delta = (range.x > range.y ? -1 : 1);
	while (range.x != range.y)
	{
		if (range.x >= 0 && range.x < p_win->size_x &&
			p_y >= 0 && p_y < p_win->size_y)
		{
			add_pixel_to_screen(p_win, i, p_color);
		}
		range.x += delta;
		i += delta;
	}
}

void fill_down_flat_triangle(t_window *p_win, t_vector2 *v1, t_vector2 *v2, t_vector2 *v3, t_color *p_color)
{
	t_vector2_int range;
	float slope[2];
	float current[2];
	int scan_line_y = v1->y;

	slope[0] = (v2->x - v1->x) / (v2->y - v1->y);
	slope[1] = (v3->x - v1->x) / (v3->y - v1->y);
	current[0] = v1->x;
	current[1] = v1->x;
	while (scan_line_y <= v2->y)
	{
		range.x = (int)(current[0]);
		range.y = (int)(current[1]);
		draw_line_color(p_win, range, scan_line_y, p_color);
		current[0] += slope[0];
		current[1] += slope[1];

		scan_line_y++;
	}
}

void fill_top_flat_triangle(t_window *p_win, t_vector2 *v1, t_vector2 *v2, t_vector2 *v3, t_color *p_color)
{
	t_vector2_int range;
	float slope[2];
	float current[2];
	int scan_line_y;

	slope[0] = (v3->x - v1->x) / (v3->y - v1->y);
	slope[1] = (v3->x - v2->x) / (v3->y - v2->y);
	current[0] = v3->x;
	current[1] = v3->x;
	scan_line_y = v3->y;
	while (scan_line_y > v1->y)
	{
		range.x = (int)(current[0]);
		range.y = (int)(current[1]);
		draw_line_color(p_win, range, scan_line_y, p_color);
		current[0] -= slope[0];
		current[1] -= slope[1];
		scan_line_y--;
	}

}

void draw_triangle_color_cpu(t_window *p_win, t_triangle *p_t, t_color *p_color)
{
	t_vector2 p_d;

	if (p_t->a.y > p_t->b.y || (p_t->a.y == p_t->b.y && p_t->a.x > p_t->b.x))
		t_vector2_swap(&(p_t->a), &(p_t->b));
	if (p_t->b.y > p_t->c.y || (p_t->b.y == p_t->c.y && p_t->b.x > p_t->c.x))
		t_vector2_swap(&(p_t->b), &(p_t->c));
	if (p_t->a.y > p_t->b.y || (p_t->a.y == p_t->b.y && p_t->a.x > p_t->b.x))
		t_vector2_swap(&(p_t->a), &(p_t->b));

	if (p_t->b.y == p_t->c.y)
	{
		fill_down_flat_triangle(p_win, &(p_t->a), &(p_t->b), &(p_t->c), p_color);
	}
	if (p_t->a.y == p_t->b.y || p_t->a.y == p_t->c.y)
	{
		fill_top_flat_triangle(p_win, &(p_t->a), &(p_t->b), &(p_t->c), p_color);
	}
	else
	{
		p_d = create_t_vector2(p_t->a.x + ((p_t->b.y - p_t->a.y) / (p_t->c.y -
				p_t->a.y) * (p_t->c.x - p_t->a.x)), p_t->b.y);
		fill_down_flat_triangle(p_win, &(p_t->a), &(p_t->b), &p_d, p_color);
		fill_top_flat_triangle(p_win, &(p_t->b), &p_d, &(p_t->c), p_color);
	}
}
