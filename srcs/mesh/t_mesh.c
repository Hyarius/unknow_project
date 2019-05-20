#include "unknow_project.h"

t_mesh		create_t_mesh()
{
	t_mesh result;

	result.vertices = initialize_t_vector3_list();
	result.faces = initialize_t_faces();
	result.colors = initialize_t_color_list();

	return (result);
}

t_mesh		*initialize_t_mesh()
{
	t_mesh *result;

	if (!(result = (t_mesh *)malloc(sizeof(t_mesh))))
		error_exit(-13, "Can't create a t_mesh array");

	*result = create_t_mesh();

	return(result);
}

void		free_t_mesh(t_mesh mesh)
{
	delete_t_vector3_list(mesh.vertices);
	delete_t_faces(mesh.faces);
	delete_t_color_list(mesh.colors);
}

void		delete_t_mesh(t_mesh *mesh)
{
	free_t_mesh(*mesh);
	mesh->vertices = NULL;
	mesh->faces = NULL;
	mesh->colors = NULL;
	free(mesh);
}

void		t_mesh_add_point(t_mesh *dest, t_vector3 new_point)
{
	t_vector3_list_push_back(dest->vertices, new_point);
}

void		t_mesh_set_face(t_mesh *dest, int a, int b, int c)
{
	int point_index[3];

	point_index[0] = a;
	point_index[1] = b;
	point_index[2] = c;
	t_faces_push_back(dest->faces, point_index);
}

void		t_mesh_set_color(t_mesh *dest, t_color p_color)
{
	t_color_list_push_back(dest->colors, p_color);
}
