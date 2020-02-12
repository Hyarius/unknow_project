/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_geometry.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:11:02 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/11 11:00:23 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_GEOMETRY_H
# define UNKNOW_PROJECT_GEOMETRY_H

# include "unknow_project_vector.h"

typedef struct	s_triangle
{
	t_vec4		a;
	t_vec4		b;
	t_vec4		c;
}				t_triangle;

t_triangle		new_triangle(t_vec4 p_a, t_vec4 p_b, t_vec4 p_c);
t_triangle		*initialize_t_triangle(t_vec4 p_a, t_vec4 p_b, t_vec4 p_c);
void			sort_t_triangles(t_triangle *a, t_triangle *b);
void			sort_t_triangle_points(t_triangle *p_triangle);
t_triangle		t_triangle_add_vec4(t_triangle triangle, t_vec4 to_add);
t_triangle		mult_triangle_by_vec4(t_triangle triangle, t_vec4 to_add);
void			t_triangle_get_min_max_value(t_triangle *triangle,
											t_vec4 *min, t_vec4 *max);
int				t_triangle_equal(t_triangle a, t_triangle b);
int				t_triangle_is_bigger(t_triangle a, t_triangle b);
int				t_triangle_similarity(t_triangle a, t_triangle b);
int				t_triangle_similarity_segment(t_triangle p_a,
											t_vec4 p_b, t_vec4 p_c);
int				is_triangle_contact(t_triangle a, t_triangle b);
int				is_triangle_contact(t_triangle a, t_triangle b);
int				triangles_intersection(t_triangle tri1, t_triangle tri2);
float			maximum_dist_triangles(t_triangle tri1, t_triangle tri2);
t_vec4			triangle_center(t_triangle tri);

typedef struct	s_line
{
	t_vec4		a;
	t_vec4		b;
}				t_line;

t_line			new_line(t_vec4 p_a, t_vec4 p_b);
t_line			*initialize_t_line(t_vec4 p_a, t_vec4 p_b);
void			print_t_line(t_line line, char *str);
float			size_line(t_line line);

typedef struct	s_rectangle
{
	t_vec2		pos;
	t_vec2		size;
}				t_rectangle;

t_rectangle		new_rectangle(t_vec2 p_pos, t_vec2 p_size);
t_rectangle		*initialize_t_rectangle(t_vec2 p_pos, t_vec2 p_size);

#endif
