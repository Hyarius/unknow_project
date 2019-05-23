#ifndef UNKNOW_PROJECT_STRUCTURE_H
# define UNKNOW_PROJECT_STRUCTURE_H

# include "unknow_project_geometry.h"

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

typedef struct	s_color
{
	float		r;
	float		g;
	float		b;
	float		a;
}				t_color;

t_color		create_t_color(float p_r, float p_g, float p_b, float p_a);
t_color		*initialize_t_color(float p_r, float p_g, float p_b, float p_a);
t_color 	create_t_color_from_int(int p_r, int p_g, int p_b, int p_a);
t_color 	*initialize_t_color_from_int(int p_r, int p_g, int p_b, int p_a);
t_color		fuze_t_color(t_color src1, t_color src2);

typedef struct	s_uv
{
	t_image		*image;
	t_triangle	*uv;
	float		alpha;
}				t_uv;

t_uv		create_t_uv(t_triangle *p_triangle, t_image *p_image, float p_alpha);
t_uv		*initialize_t_uv(t_triangle *p_triangle, t_image *p_image, float p_alpha);

typedef struct	s_face
{
	int			index[3];
	t_vector3	normale;
}				t_face;

t_face create_t_face(int a, int b, int c);
t_face *initialize_t_face(int a, int b, int c);

#endif
