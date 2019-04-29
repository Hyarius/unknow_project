#include "unknow_project.h"

t_surface *read_png_file(const char *filename)
{
	FILE		*fp;
	png_structp	png_ptr;
	png_infop	info_ptr;
	t_surface	*surface;

	int bit_depth, color_type;

	if (!(surface = (t_surface *)malloc(sizeof(t_surface))))
		error_exit(-29, "Can't malloc a t_surface");

	fp = fopen (filename, "rb");

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	info_ptr = png_create_info_struct (png_ptr);

	png_init_io (png_ptr, fp);

	png_read_info (png_ptr, info_ptr);

	bit_depth = png_get_bit_depth (png_ptr, info_ptr);
	color_type = png_get_color_type (png_ptr, info_ptr);

	if (color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb (png_ptr);

	if (png_get_valid (png_ptr, info_ptr, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha (png_ptr);

	if (bit_depth == 16)
		png_set_strip_16 (png_ptr);
	else if (bit_depth < 8)
		png_set_packing (png_ptr);

	png_read_update_info (png_ptr, info_ptr);

	png_get_IHDR (png_ptr, info_ptr,
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
	{
		error_exit(0, "XXX");
	}

	surface->pixels = (GLubyte *)malloc (sizeof (GLubyte) * surface->w * surface->h * surface->internalFormat);

	png_bytep *row_pointers;

	row_pointers = (png_bytep *)malloc (sizeof (png_bytep) * surface->h);

	int i = 0;
	while (i < surface->h)
	{
		row_pointers[i] = (png_bytep)(surface->pixels + ((surface->h - (i + 1)) * surface->w * surface->internalFormat));
		i++;
	}

	png_read_image (png_ptr, row_pointers);

	free (row_pointers);

	png_read_end (png_ptr, NULL);
	png_destroy_read_struct (&png_ptr, &info_ptr, NULL);

	fclose (fp);

	return (surface);
}

t_texture *png_load(char *path)
{
	t_texture *texture;
	SDL_Surface *surface;
	int internal_format;
	int format;

	if (!(texture = (t_texture *)malloc(sizeof(t_texture))))
		error_exit(-29, "Can't malloc a t_texture");

	texture->surface = read_png_file(path);

	surface = IMG_Load(path);

	if (surface == NULL)
		error_exit(-32, "Can't load a sdl_surface");
	if (surface->format->BytesPerPixel == 3)
	{
		internal_format = GL_RGB;
		if (surface->format->Rmask == 0xff)
			format = GL_RGB;
		else
			format = GL_BGR;
	}
	else if (surface->format->BytesPerPixel == 4)
	{
		internal_format = GL_RGBA;
		if (surface->format->Rmask == 0xff)
			format = GL_RGBA;
		else
			format = GL_BGRA;
	}
	glGenTextures(1, &(texture->id));
	glBindTexture(GL_TEXTURE_2D, (texture->id));

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, internal_format, surface->w,
				surface->h, 0, format,
				GL_UNSIGNED_BYTE, surface->pixels);

	glBindTexture(GL_TEXTURE_2D, 0);

	SDL_FreeSurface(surface);

	return (texture);
}
