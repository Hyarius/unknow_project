#ifndef UNKNOW_PROJECT_BASIC_LIST_H
# define UNKNOW_PROJECT_BASIC_LIST_H

# include "unknow_project_structure.h"
# include "unknow_project_geometry.h"
# include "unknow_project_vector.h"

typedef struct	s_void_list
{
	void		**data;
	int			size;
	int			max_size;
}				t_void_list;

t_void_list new_void_list();
t_void_list *initialize_t_void_list();
void		t_void_list_add_back(t_void_list *dest, int nb, ...);
void		t_void_list_push_back(t_void_list *dest, void *to_add);
void		delete_t_void_list(t_void_list dest);
void		free_t_void_list(t_void_list *dest);
void		clean_t_void_list(t_void_list *dest);
void		*t_void_list_at(t_void_list *dest, int index);
void		**t_void_list_get(t_void_list *dest, int index);

typedef struct	s_triangle_list
{
	t_triangle	*triangle;
	int			size;
	int			max_size;
}				t_triangle_list;

t_triangle_list new_triangle_list();
t_triangle_list *initialize_t_triangle_list();
void			t_triangle_list_push_back(t_triangle_list *dest, t_triangle to_add);
void			t_triangle_list_add_back(t_triangle_list *dest, t_triangle *to_add);
void			delete_t_triangle_list(t_triangle_list dest);
void			free_t_triangle_list(t_triangle_list *dest);
void			clean_t_triangle_list(t_triangle_list *dest);
t_triangle		t_triangle_list_at(t_triangle_list *dest, int index);
t_triangle		*t_triangle_list_get(t_triangle_list *dest, int index);
void			t_triangle_list_resize(t_triangle_list *dest, int new_size);

typedef struct	s_vec4_list
{
	union
	{
		t_vec4	*vector;
		float	*value;
	};
	int			size;
	int			max_size;
}				t_vec4_list;

t_vec4_list		new_vec4_list();
t_vec4_list		*initialize_t_vec4_list();
void			t_vec4_list_push_back(t_vec4_list *dest, t_vec4 to_add);
void			t_vec4_list_add_back(t_vec4_list *dest, t_vec4 *to_add);
void			delete_t_vec4_list(t_vec4_list dest);
void			free_t_vec4_list(t_vec4_list *dest);
void			clean_t_vec4_list(t_vec4_list *dest);
t_vec4			t_vec4_list_at(t_vec4_list *dest, int index);
t_vec4			*t_vec4_list_get(t_vec4_list *dest, int index);
void 			t_vec4_list_set(t_vec4_list *dest, int index, t_vec4 *vector);
float			*t_vec4_list_obtain(t_vec4_list *dest, int index);
void			t_vec4_list_edit(t_vec4_list *dest, int index, t_vec4 p_color);
void			t_vec4_list_set(t_vec4_list *dest, int index, t_vec4 *p_color);
void			t_vec4_list_resize(t_vec4_list *dest, int new_size);

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

t_color_list	new_color_list();
t_color_list	*initialize_t_color_list();
void			t_color_list_push_back(t_color_list *dest, t_color to_add);
void			delete_t_color_list(t_color_list dest);
t_color			*t_color_list_get(t_color_list *dest, int index);

typedef struct	s_uv_list
{
	t_uv		*uvs;
	int			size;
	int			max_size;
}				t_uv_list;

t_uv_list		new_uv_list();
t_uv_list		*initialize_t_uv_list();
void			t_uv_list_push_back(t_uv_list *dest, t_uv to_add);
t_uv			*t_uv_list_get(t_uv_list *dest, int index);
void			clean_t_uv_list(t_uv_list *dest);

typedef struct	s_face_list
{
	t_face		*face;
	int			size;
	int			max_size;
}				t_face_list;

t_face_list		new_face_list(); //creer sans malloc
t_face_list		*initialize_t_face_list(); //creer avec malloc
void			t_face_list_push_back(t_face_list *dest, t_face to_add); // ajoute une t_face a la liste, a la fin, en la brut
t_face			t_face_list_at(t_face_list *dest, int index); //renvoi une copie de l'element situe a la position [index] de la liste
t_face			*t_face_list_get(t_face_list *dest, int index); //renvoi l'adresse de l'element situe a la position [index] de la liste

typedef struct			s_list_fd
{
	char				*rest;
	int					fd;
	struct s_list_fd	*next;
}						t_list_fd;

#endif
