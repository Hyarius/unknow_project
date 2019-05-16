#include "unknow_project.h"

t_uv	create_t_uv(t_triangle *p_triangle, t_image *p_image, float p_alpha)
{
	t_uv result;

	result.image = p_image;
	result.uv = p_triangle;
	result.alpha = p_alpha;

	return (result);
}

t_uv	*initialize_t_uv(t_triangle *p_triangle, t_image *p_image, float p_alpha)
{
	t_uv *result;

	if (!(result = (t_uv *)malloc(sizeof(t_uv))))
		return (NULL);

	*result = create_t_uv(p_triangle, p_image, p_alpha);

	return (result);
}
