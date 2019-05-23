#ifndef UNKNOW_PROJECT_MESH_H
# define UNKNOW_PROJECT_MESH_H

# include "unknow_project_list.h"
# include "unknow_project_camera.h"
# include "unknow_project_window.h"

typedef struct	s_mesh
{
	t_vector3_list
				*vertices;
	t_face_list	*faces;
}				t_mesh;

t_mesh		create_t_mesh();
t_mesh		*initialize_t_mesh();
void		free_t_mesh();
void		delete_t_mesh();
void		t_mesh_add_point(t_mesh *dest, t_vector3 new_point);
void		t_mesh_add_face(t_mesh *dest, t_face new_face);
void		t_mesh_compute_normales(t_mesh *mesh);

t_mesh		create_primitive_cube(t_vector3 coord, t_vector3 size);
void 		draw_t_mesh(t_window *p_win, t_matrix *mvp, t_mesh *mesh);
#endif
