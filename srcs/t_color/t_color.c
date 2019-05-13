#include "unknow_project.h"

t_color create_t_color(float p_r, float p_g, float p_b, float p_a)
{
	t_color color;

	color.r = p_r;
	color.g = p_g;
	color.b = p_b;
	color.a = p_a;

	return (color);
}

t_color *initialize_t_color(float p_r, float p_g, float p_b, float p_a)
{
	t_color *color;

	if (!(color = (t_color *)malloc(sizeof(t_color))))
		return (NULL);

	*color = create_t_color(p_r, p_g, p_b, p_a);

	return (color);
}
