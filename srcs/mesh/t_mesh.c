#include "unknow_project.h"

t_mesh		create_t_mesh()
{
	t_mesh result;

	result.vertices = initialize_t_vector3_list();
	result.faces = initialize_t_face_list();

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
	delete_t_face_list(mesh.faces);
}

void		delete_t_mesh(t_mesh *mesh)
{
	free_t_mesh(*mesh);
	free(mesh);
}

void		t_mesh_add_point(t_mesh *dest, t_vector3 new_point)
{
	t_vector3_list_push_back(dest->vertices, new_point);
}

void		t_mesh_add_face(t_mesh *dest, t_face new_face)
{
	t_face_list_push_back(dest->faces, new_face);
}

void		t_mesh_compute_normales(t_mesh *mesh)
{
	int i = 0;
	while (i < mesh->faces->size)
	{

		i++;
	}
}