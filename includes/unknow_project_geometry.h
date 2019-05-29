#ifndef UNKNOW_PROJECT_GEOMETRY_H
# define UNKNOW_PROJECT_GEOMETRY_H

# include "unknow_project_vector.h"

typedef struct	s_triangle
{
	t_vector3	a;
	t_vector3	b;
	t_vector3	c;
}				t_triangle;

t_triangle	create_t_triangle(t_vector3 p_a, t_vector3 p_b, t_vector3 p_c);
t_triangle	*initialize_t_triangle(t_vector3 p_a, t_vector3 p_b, t_vector3 p_c);
void 		sort_t_triangle_points(t_triangle *p_triangle);

typedef struct	s_line
{
	t_vector3	a;
	t_vector3	b;
}				t_line;

t_line		create_t_line(t_vector3 p_a, t_vector3 p_b);
t_line		*initialize_t_line(t_vector3 p_a, t_vector3 p_b);

#endif
