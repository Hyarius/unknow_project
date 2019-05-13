#ifndef UNKNOW_PROJECT_LIST_H
# define UNKNOW_PROJECT_LIST_H

# include "unknow_project_basic.h"
# include "unknow_project_structure.h"

typedef struct	s_void_list
{
	void		**data;
	int			size;
	int			max_size;
}				t_void_list;

typedef struct	s_triangle_list
{
	t_triangle	*triangle;
	int			size;
	int			max_size;
}				t_triangle_list;

typedef struct	s_vector2_list
{
	union
	{
		t_vector2	*vector;
		float		*value;
	};
	int			size;
	int			max_size;
}				t_vector2_list;

typedef struct	s_vector3_list
{
	union
	{
		t_vector3
				*vector;
		float	*value;
	};
	int			size;
	int			max_size;
}				t_vector3_list;

typedef struct	s_vector2_int_list
{
	union
	{
		t_vector2_int
				*vector;
		int		*value;
	};
	int			size;
	int			max_size;
}				t_vector2_int_list;

typedef struct	s_vector3_int_list
{
	union
	{
		t_vector3_int
				*vector;
		int		*value;
	};
	int			size;
	int			max_size;
}				t_vector3_int_list;

typedef struct	s_color_list
{
	union
	{
		t_color	*color;
		float	*value;
	};
	int			size;
	int			max_size;
}				t_color_list;

#endif
