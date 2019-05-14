#include "unknow_project.h"

//dessine une texture via le CPU
void draw_triangle_texture_cpu(t_window *p_win, t_triangle *p_t_screen, t_triangle *p_t_uv, t_image *p_texture, float alpha)
{
	t_uv uv = create_t_uv(p_t_uv, p_texture);

	calc_triangle_texture_cpu(p_win, 0, p_t_screen, &uv);
}
