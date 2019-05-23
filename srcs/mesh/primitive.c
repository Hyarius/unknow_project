#include "unknow_project.h"

t_mesh		create_primitive_cube(t_vector3 coord, t_vector3 size)
{
	t_mesh result;

	result = create_t_mesh();

	t_mesh_add_point(&result, create_t_vector3(coord.x, coord.y, coord.z));
	t_mesh_add_point(&result, create_t_vector3(coord.x + size.x, coord.y, coord.z));
	t_mesh_add_point(&result, create_t_vector3(coord.x, coord.y + size.y, coord.z));
	t_mesh_add_point(&result, create_t_vector3(coord.x + size.x, coord.y + size.y, coord.z));

	t_mesh_add_point(&result, create_t_vector3(coord.x, coord.y, coord.z + size.z));
	t_mesh_add_point(&result, create_t_vector3(coord.x + size.x, coord.y, coord.z + size.z));
	t_mesh_add_point(&result, create_t_vector3(coord.x, coord.y + size.y, coord.z + size.z));
	t_mesh_add_point(&result, create_t_vector3(coord.x + size.x, coord.y + size.y, coord.z + size.z));

	t_mesh_add_face(&result, create_t_face(7, 3, 5));
	t_mesh_add_face(&result, create_t_face(5, 3, 1));
	t_mesh_add_face(&result, create_t_face(0, 4, 2));
	t_mesh_add_face(&result, create_t_face(2, 4, 6));
	t_mesh_add_face(&result, create_t_face(4, 0, 5));
	t_mesh_add_face(&result, create_t_face(5, 0, 1));
	t_mesh_add_face(&result, create_t_face(6, 2, 7));
	t_mesh_add_face(&result, create_t_face(7, 2, 3));
	t_mesh_add_face(&result, create_t_face(6, 4, 7));
	t_mesh_add_face(&result, create_t_face(7, 4, 5));
	t_mesh_add_face(&result, create_t_face(2, 0, 3));
	t_mesh_add_face(&result, create_t_face(3, 0, 1));

	return (result);
}
