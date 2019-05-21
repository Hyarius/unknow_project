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

	t_mesh_add_face(&result, 7, 3, 5);
	t_mesh_add_face(&result, 5, 3, 1);
	t_mesh_add_face(&result, 0, 4, 2);
	t_mesh_add_face(&result, 2, 4, 6);
	t_mesh_add_face(&result, 4, 0, 5);
	t_mesh_add_face(&result, 5, 0, 1);
	t_mesh_add_face(&result, 6, 2, 7);
	t_mesh_add_face(&result, 7, 2, 3);
	t_mesh_add_face(&result, 6, 4, 7);
	t_mesh_add_face(&result, 7, 4, 5);
	t_mesh_add_face(&result, 2, 0, 3);
	t_mesh_add_face(&result, 3, 0, 1);

	return (result);
}
