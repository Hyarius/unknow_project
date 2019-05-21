#ifndef UNKNOW_PROJECT_MESH_H
# define UNKNOW_PROJECT_MESH_H

# include "unknow_project_list.h"
# include "unknow_project_camera.h"
# include "unknow_project_window.h"

typedef struct	s_faces
{
	int			*coords;
	int			size;
	int			max_size;
}				t_faces;

t_faces create_t_faces();
t_faces *initialize_t_faces();
void	t_faces_push_back(t_faces *dest, int *to_add);
void	free_t_faces(t_faces dest);
void	delete_t_faces(t_faces *dest);
void	clean_t_faces(t_faces *dest);
int		*t_faces_at(t_faces *dest, int index);
void	t_faces_resize(t_faces *dest, int new_size);

typedef struct	s_mesh
{
	t_vector3_list
				*vertices;

	t_faces		*faces;

}				t_mesh;

t_mesh		create_t_mesh();
t_mesh		*initialize_t_mesh();
void		free_t_mesh();
void		delete_t_mesh();
void		t_mesh_add_point(t_mesh *dest, t_vector3 new_point);
void		t_mesh_add_face(t_mesh *dest, int a, int b, int c);

t_mesh		create_primitive_cube(t_vector3 coord, t_vector3 size);
void 		draw_t_mesh(t_window *p_win, t_matrix *mvp, t_mesh *mesh);
#endif
