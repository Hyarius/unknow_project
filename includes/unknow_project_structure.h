#ifndef UNKNOW_PROJECT_STRUCTURE_H
# define UNKNOW_PROJECT_STRUCTURE_H

# include "unknow_project_includes.h"
# include "unknow_project_basic.h"

typedef struct	s_surface
{
	GLuint  	w;           /* largeur */
    GLuint  	h;          /* hauteur */

    GLenum  	format;          /* RVB, RVBA, Luminance, Luminance Alpha */
    GLint   	internalFormat;  /* composantes d'un texel */

    GLubyte 	*pixels;         /* données de l'image */
}				t_surface;

typedef struct	s_image
{
	t_surface	*surface;
	GLuint		id;
}				t_image;

typedef struct	s_uv
{
	t_image		*image;
	t_triangle	*uv;
	float		alpha;
}				t_uv;

#endif
