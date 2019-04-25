#include "unknow_project.h"

t_png_info get_pixels_data(char *path)
{
	t_png_info	png_info;
	FILE		*fp;

	fp = fopen(path, "rd");
	png_info.png_ptr = png_create_read_struct (PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	png_info.info_ptr = png_create_info_struct (png_info.png_ptr);
	png_init_io (png_info.png_ptr, fp);
	png_read_png (png_info.png_ptr, png_info.info_ptr, 0, 0);
	png_get_IHDR (png_info.png_ptr, png_info.info_ptr, & png_info.width, & png_info.height, & png_info.bit_depth,
		  & png_info.color_type, & png_info.interlace_method, & png_info.compression_method,
		  & png_info.filter_method);
	png_info.rows = png_get_rows (png_info.png_ptr, png_info.info_ptr);
    printf ("Width is %d, height is %d\n", png_info.width, png_info.height);
    png_info.rowbytes = png_get_rowbytes (png_info.png_ptr, png_info.info_ptr);
    printf ("One row bytes = %d\n", png_info.rowbytes);
	fclose(fp);
	return (png_info);
}

unsigned char *png_load(char *path)
{
	t_png_info	png_info;

	png_info = get_pixels_data(path);
	return (NULL);
}
