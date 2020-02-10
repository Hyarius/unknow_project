/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_structure.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:40:11 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/07 15:09:26 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_STRUCTURE_H
# define UNKNOW_PROJECT_STRUCTURE_H

# include "unknow_project_geometry.h"

typedef struct	s_color
{
	float		r;
	float		g;
	float		b;
	float		a;
}				t_color;

t_color			new_color(float p_r, float p_g, float p_b, float p_a);
t_color			*initialize_t_color(float p_r, float p_g, float p_b, float p_a);
t_color			new_color_from_int(int p_r, int p_g, int p_b, int p_a);
t_color			fuze_t_color(t_color src1, t_color src2);

typedef struct	s_fuck_norme
{
	t_triangle	triangle;
	t_vec4		min;
	t_vec4		max;
	t_triangle	st;
	t_color		rgb;
	float		s;
	float		t;
	int			pixel_index;
	int			x;
	int			y;
	t_vec4		w;
	t_vec4		pixel_sample;
	float		z;
	float		area;
}				t_fuck_norme;

typedef struct	s_surface
{
	GLuint		w;
	GLuint		h;

	GLenum		format;
	GLint		intern_format;

	GLubyte		*pixels;
}				t_surface;

typedef struct	s_texture
{
	t_surface	*surface;
	GLuint		id;
	char		*path;
	char		letter;
}				t_texture;

t_color			get_pixel_color(t_texture *texture, int x, int y);

typedef struct	s_uv
{
	t_texture	*texture;
	t_triangle	uv;
}				t_uv;

t_uv			new_uv(t_triangle p_triangle, t_texture *p_image);
t_uv			*initialize_t_uv(t_triangle p_triangle, t_texture *p_image);

typedef struct	s_face
{
	t_color		color;
	int			index_vertices[3];
	int			index_uvs[3];
	t_vec4		normale;
}				t_face;

t_face			new_face();
t_face			*initialize_t_face();
void			set_t_face_vertices(t_face *face, int a, int b, int c);
void			set_t_face_uvs(t_face *face, int a, int b, int c);
void			set_t_face_color(t_face *face, t_color color);
void			free_t_texture(t_texture **dest);

#endif
