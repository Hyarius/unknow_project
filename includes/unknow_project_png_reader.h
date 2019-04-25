#ifndef UNKNOW_PROJECT_PNG_READER_H
# define UNKNOW_PROJECT_PNG_READER_H

#include "unknow_project_basic.h"
#include "unknow_project_includes.h"

typedef struct	s_png_info
{
	png_structp	png_ptr;
    png_infop	info_ptr;
	png_uint_32	width;
    png_uint_32	height;
    int			bit_depth;
    int			color_type;
    int			interlace_method;
    int			compression_method;
    int			filter_method;
	png_bytepp 	rows;
    int			rowbytes;
}				t_png_info;

#endif
