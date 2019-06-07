#ifndef UNKNOW_PROJECT_MESH_H
# define UNKNOW_PROJECT_MESH_H

# include "unknow_project_list.h"
# include "unknow_project_camera.h"
# include "unknow_project_window.h"

typedef struct	s_mesh
{
	t_vector3	pos;
	t_texture	*texture;
	t_vector3_list
				*vertices;
	t_vector3_list
				*uvs;
	t_vector3_list
				*normales;
	t_face_list	*faces;
}				t_mesh;

t_mesh		create_t_mesh(t_vector3 pos);
t_mesh		load_t_mesh(t_vector3 pos, char *path);
t_mesh		*initialize_t_mesh(t_vector3 pos);
void		free_t_mesh();
void		delete_t_mesh();
void		t_mesh_add_point(t_mesh *dest, t_vector3 new_point);
void		t_mesh_add_uv(t_mesh *dest, t_vector3 new_uv);
void		t_mesh_add_face(t_mesh *dest, t_face new_face);
void 		t_mesh_set_texture(t_mesh *dest, t_texture *p_texture);
void		t_mesh_compute_normals(t_mesh *mesh);

t_mesh		create_primitive_cube(t_vector3 coord, t_vector3 size, t_texture *texture);
t_mesh		create_primitive_plane(t_vector3 pos, t_vector3 size, t_texture *texture);
void 		draw_t_mesh(t_window *p_win, t_camera *p_cam, t_mesh *mesh);
void		rotate_t_mesh(t_mesh *mesh, t_vector3 angle, t_vector3 center);

#endif
