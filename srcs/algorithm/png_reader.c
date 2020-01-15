/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:32:25 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/15 14:47:48 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_surface		*read_png_file(const char *filename)
{
	FILE		*fp; // 1
	png_structp	png_ptr; // 1
	png_infop	info_ptr; // 1
	t_surface	*surface; // 1
	int			bit_depth; // 1
	int			color_type; // 1
	int			i; // 2
	png_bytep	*row_pointers; // 2

	if (!(surface = (t_surface *)malloc(sizeof(t_surface))))
		error_exit(-29, "Can't malloc a t_surface");
	if ((fp = fopen(filename, "rb")) == NULL)
		error_exit(-500, ft_strjoin(filename, " doesn't exist"));
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	info_ptr = png_create_info_struct(png_ptr);
	png_init_io(png_ptr, fp);
	png_read_info(png_ptr, info_ptr);
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);
	color_type = png_get_color_type(png_ptr, info_ptr);
	png_read_update_info(png_ptr, info_ptr);
	png_get_IHDR(png_ptr, info_ptr,
				(png_uint_32*)(&surface->w),
				(png_uint_32*)(&surface->h),
				&bit_depth, &color_type,
				NULL, NULL, NULL);
	if (color_type == PNG_COLOR_TYPE_RGB)
	{
		surface->format = GL_RGB;
		surface->internalFormat = 3;
	}
	else if (color_type == PNG_COLOR_TYPE_RGB_ALPHA)
	{
		surface->format = GL_RGBA;
		surface->internalFormat = 4;
	}
	else
		error_exit(0, "XXX");
	surface->pixels = (GLubyte *)malloc(sizeof(GLubyte) * surface->w
						* surface->h * surface->internalFormat);
	row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * surface->h);
	i = -1;
	while (++i < surface->h)
		row_pointers[i] = (png_bytep)(surface->pixels + ((surface->h - (i + 1))
						* surface->w * surface->internalFormat));
	png_read_image(png_ptr, row_pointers);
	free(row_pointers);
	png_read_end(png_ptr, NULL);
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(fp);
	return (surface);
}

t_texture		*png_load(char *path)
{
	t_texture	*texture;

	if (!(texture = (t_texture *)malloc(sizeof(t_texture))))
		error_exit(-29, "Can't malloc a t_texture");
	texture->path = path;
	texture->surface = read_png_file(path);
	return (texture);
}
