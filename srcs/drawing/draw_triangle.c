#include "unknow_project.h"

void draw_triangle_color(t_window *p_win, t_triangle_list *p_t, t_color_list *p_color)
{
	t_triangle *tmp;
	t_triangle triangle;
	t_vector2 coord[3];
	int i;

	i = 0;
	while (i < p_t->size)
	{
		tmp = t_triangle_list_get(p_t, i); //permet de recupere le triangle numero i

		coord[0] = convert_screen_to_opengl(p_win, (int)(tmp->a.x), (int)(tmp->a.y)); // convertit la coordonnee a l'ecran pour opengl
		coord[1] = convert_screen_to_opengl(p_win, (int)(tmp->b.x), (int)(tmp->b.y));
		coord[2] = convert_screen_to_opengl(p_win, (int)(tmp->c.x), (int)(tmp->c.y));

		triangle = create_t_triangle(coord[0], coord[1], coord[2]);

		draw_triangle_color_opengl(p_win, &triangle, t_color_list_get(p_color, i)); //affichage du triangle

		i++;
	}
}

void draw_triangle_texture(t_window *p_win, t_triangle_list *p_t, t_uv_list *p_uv)
{
	t_triangle *tmp;
	t_triangle triangle;
	t_vector2 coord[3];
	int i;

	i = 0;
	while (i < p_t->size)
	{
		tmp = t_triangle_list_get(p_t, i); //permet de recupere le triangle numero i

		coord[0] = convert_screen_to_opengl(p_win, (int)(tmp->a.x), (int)(tmp->a.y)); // convertit la coordonnee a l'ecran pour opengl
		coord[1] = convert_screen_to_opengl(p_win, (int)(tmp->b.x), (int)(tmp->b.y));
		coord[2] = convert_screen_to_opengl(p_win, (int)(tmp->c.x), (int)(tmp->c.y));

		triangle = create_t_triangle(coord[0], coord[1], coord[2]);

		draw_triangle_texture_opengl(p_win, &triangle, t_uv_list_get(p_uv, i)); //affichage du triangle

		i++;
	}
}
