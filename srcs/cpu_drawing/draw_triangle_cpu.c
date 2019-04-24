#include "unknow_project.h"

void fill_down_flat_triangle(t_window *p_win, t_point *v1, t_point *v2, t_point *v3)
{
	 float invslope1 = (v2->x - v1->x) / (v2->y - v1->y);
	 float invslope2 = (v3->x - v1->x) / (v3->y - v1->y);
	 t_vector2 current_1;
	 t_vector2 current_2;

	 current_1 = create_t_vector2(v1->x, v1->y);
	 current_2 = create_t_vector2(v1->x, v1->y);
	 while (current_1.y <= v2->y)
	 {
 		// TO-DO DRAW LINE

		 t_vector2_add(&current_1, invslope1, 1);
		 t_vector2_add(&current_2, invslope2, 1);
	 }
}

void fill_top_flat_triangle(t_window *p_win, t_point *v1, t_point *v2, t_point *v3)
{
	float invslope1 = (v2->x - v1->x) / (v2->y - v1->y);
	float invslope2 = (v3->x - v1->x) / (v3->y - v1->y);
	t_vector2 current_1;
	t_vector2 current_2;

	current_1 = create_t_vector2(v3->x, v3->y);
	current_2 = create_t_vector2(v3->x, v3->y);
	while (current_1.y > v1->y)
	{
		// TO-DO DRAW LINE

		t_vector2_add(&current_1, -invslope1, -1);
		t_vector2_add(&current_2, -invslope2, -1);
	}
}

void draw_triangle_cpu(t_window *p_win, t_point p_a, t_point p_b, t_point p_c)
{
	t_point p_d;

	if (p_a.y > p_b.y)
		t_point_swap(&p_a, &p_b);
	if (p_b.y > p_c.y)
		t_point_swap(&p_b, &p_c);
	if (p_a.y > p_b.y)
		t_point_swap(&p_a, &p_b);

	if (p_b.y == p_c.y)
	{
		fill_down_flat_triangle(p_win, &p_a, &p_b, &p_c);
	}
	if (p_a.y == p_b.y || p_a.y == p_c.y)
	{
		fill_top_flat_triangle(p_win, &p_a, &p_b, &p_c);
	}
	else
	{
		p_d = create_t_point(p_a.x + ((p_b.y - p_a.y) / (p_c.y - p_a.y) * (p_c.x - p_a.x)), p_b.y, p_a.color);
		fill_down_flat_triangle(p_win, &p_a, &p_b, &p_d);
		fill_top_flat_triangle(p_win, &p_b, &p_d, &p_c);
	}
}
