#ifndef UNKNOW_PROJECT_GEOMETRY_H
# define UNKNOW_PROJECT_GEOMETRY_H

# include "unknow_project_vector.h"

typedef struct	s_triangle
{
	t_vector2	a;
	t_vector2	b;
	t_vector2	c;
}				t_triangle;

t_triangle	create_t_triangle(t_vector2 p_a, t_vector2 p_b, t_vector2 p_c);
t_triangle	*initialize_t_triangle(t_vector2 p_a, t_vector2 p_b, t_vector2 p_c);

typedef struct	s_line
{
	t_vector2	a;
	t_vector2	b;
}				t_line;

#endif
