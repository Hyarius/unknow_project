#include "unknow_project.h"

t_color			get_pixel_color(t_texture *texture, float f_x, float f_y)
{
	int			x;
	int			y;
	int			i;
	unsigned char
				info[4];
	int			pixel_index;
	t_color		result;

	x = (int)(f_x * texture->surface->w);
	y = (int)(f_y * texture->surface->h);

	if (x < 0 || x >= texture->surface->w ||
		y < 0 || y >= texture->surface->h)
		return (create_t_color(1.0, 0.0, 0.0, 1.0));

	pixel_index = (x + y * texture->surface->w) * texture->surface->internalFormat;

	i = 0;
	while (i < 3)
	{
		info[i] = texture->surface->pixels[pixel_index + i];
		i++;
	}
	if (texture->surface->internalFormat == 4)
		info[3] = texture->surface->pixels[pixel_index + 3];
	else
		info[3] = 255;

	result = create_t_color_from_int((int)(info[0]), (int)(info[1]), (int)(info[2]), (int)(info[3]));

	return (result);
}
