#ifndef UNKNOW_PROJECT_PNG_READER_H
# define UNKNOW_PROJECT_PNG_READER_H

#include "unknow_project_basic.h"
#include "unknow_project_includes.h"

typedef struct	s_surface
{
	GLuint  w;           /* largeur */
    GLuint  h;          /* hauteur */

    GLenum  format;          /* RVB, RVBA, Luminance, Luminance Alpha */
    GLint   internalFormat;  /* composantes d'un texel */

    GLubyte *pixels;         /* données de l'image */
}				t_surface;

typedef struct	s_texture
{
	t_surface	*surface;
	GLuint		id;
}				t_texture;

#endif
