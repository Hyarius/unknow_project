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

t_color create_t_color_from_int(int p_r, int p_g, int p_b, int p_a)
{
	t_color color;

	color = create_t_color((float)(p_r) / 255.0f, (float)(p_g) / 255.0f,
							(float)(p_b) / 255.0f, (float)(p_a) / 255.0f);

	return (color);
}

t_color *initialize_t_color_from_int(int p_r, int p_g, int p_b, int p_a)
{
	t_color *color;

	if (!(color = (t_color *)malloc(sizeof(t_color))))
		return (NULL);

	*color = create_t_color_from_int(p_r, p_g, p_b, p_a);

	return (color);
}
