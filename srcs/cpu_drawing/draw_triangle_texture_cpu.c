#include "unknow_project.h"

static void fill_down_flat_triangle(t_window *p_win, t_triangle *p_t)
{
	t_vector2_int range;
	float slope[2];
	float current[2];
	int scan_line_y = p_t->a.y;

	slope[0] = (p_t->b.x - p_t->a.x) / (p_t->b.y - p_t->a.y);
	slope[1] = (p_t->c.x - p_t->a.x) / (p_t->c.y - p_t->a.y);
	current[0] = p_t->a.x;
	current[1] = p_t->a.x;
	while (scan_line_y <= p_t->b.y)
	{
		range.x = (int)(current[0]);
		range.y = (int)(current[1]);
		current[0] += slope[0];
		current[1] += slope[1];

		scan_line_y++;
	}
}

static void fill_top_flat_triangle(t_window *p_win, t_triangle *p_t)
{
	t_vector2_int range;
	float slope[2];
	float current[2];
	int scan_line_y;

	slope[0] = (p_t->c.x - p_t->a.x) / (p_t->c.y - p_t->a.y);
	slope[1] = (p_t->c.x - p_t->b.x) / (p_t->c.y - p_t->b.y);
	current[0] = p_t->c.x;
	current[1] = p_t->c.x;
	scan_line_y = p_t->c.y;
	while (scan_line_y > p_t->a.y)
	{
		range.x = (int)(current[0]);
		range.y = (int)(current[1]);
		current[0] -= slope[0];
		current[1] -= slope[1];
		scan_line_y--;
	}
}

void draw_triangle_texture_cpu(t_window *p_win, t_triangle *p_t, t_triangle *p_triangle_uv, t_texture *p_texture, float alpha)
{
	t_vector2 p_d;
	p_d = create_t_vector2(p_t->a.x + ((p_t->b.y - p_t->a.y) / (p_t->c.y -
				p_t->a.y) * (p_t->c.x - p_t->a.x)), p_t->b.y);
	t_triangle t1 = create_t_triangle(p_t->a, p_t->b, p_d);
	t_triangle t2 = create_t_triangle(p_t->b, p_d, p_t->c);

	if (p_t->a.y > p_t->b.y || (p_t->a.y == p_t->b.y && p_t->a.x > p_t->b.x))
		t_vector2_swap(&(p_t->a), &(p_t->b));
	if (p_t->b.y > p_t->c.y || (p_t->b.y == p_t->c.y && p_t->b.x > p_t->c.x))
		t_vector2_swap(&(p_t->b), &(p_t->c));
	if (p_t->a.y > p_t->b.y || (p_t->a.y == p_t->b.y && p_t->a.x > p_t->b.x))
		t_vector2_swap(&(p_t->a), &(p_t->b));

	if (p_t->b.y == p_t->c.y)
	{
		fill_top_flat_triangle(p_win, &t1);
	}
	if (p_t->a.y == p_t->b.y || p_t->a.y == p_t->c.y)
	{
		fill_top_flat_triangle(p_win, &t1);
	}
	else
	{
		fill_down_flat_triangle(p_win, &t1);
		fill_top_flat_triangle(p_win, &t2);
	}
}
