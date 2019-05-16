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

t_color	fuze_t_color(t_color src1, t_color src2)
{
	t_color result;

	// printf("Color 1 : %0.3f / %0.3f / %0.3f / %0.3f\n", src1.r, src1.g, src1.b, src1.a);
	// printf("Color 2 : %0.3f / %0.3f / %0.3f / %0.3f\n", src2.r, src2.g, src2.b, src2.a);

	result.a = ((1.0 - src1.a) * src2.a) + src1.a;
	result.r = ((((1.0 - src1.a) * src2.a) * src2.r) + (src1.a * src1.r)) / result.a;
	result.g = ((((1.0 - src1.a) * src2.a) * src2.g) + (src1.a * src1.g)) / result.a;
	result.b = ((((1.0 - src1.a) * src2.a) * src2.b) + (src1.a * src1.b)) / result.a;

	//printf("result : %0.3f / %0.3f / %0.3f / %0.3f\n", result.r, result.g, result.b, result.a);

	//exit(15);

	return (result);
}
