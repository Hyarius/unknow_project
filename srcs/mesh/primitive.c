#include "unknow_project.h"

t_mesh		create_primitive_cube(t_vector3 pos, t_vector3 size)
{
	t_mesh result;

	result = create_t_mesh(pos);

	//Bottom part
	t_mesh_add_point(&result, create_t_vector3(0, 0, 0)); //A
	t_mesh_add_point(&result, create_t_vector3(size.x, 0, 0)); //B
	t_mesh_add_point(&result, create_t_vector3(size.x, 0, size.z)); //C
	t_mesh_add_point(&result, create_t_vector3(0, 0, size.z)); //D

	//Top part
	t_mesh_add_point(&result, create_t_vector3(0, size.y, 0)); //E
	t_mesh_add_point(&result, create_t_vector3(size.x, size.y, 0)); //F
	t_mesh_add_point(&result, create_t_vector3(size.x, size.y, size.z)); //G
	t_mesh_add_point(&result, create_t_vector3(0, size.y, size.z)); //H

	t_mesh_add_face(&result, create_t_face(2, 3, 1)); // FACE DOWN
	t_mesh_add_face(&result, create_t_face(0, 1, 3));

	t_mesh_add_face(&result, create_t_face(6, 5, 7)); // FACE TOP
	t_mesh_add_face(&result, create_t_face(4, 7, 5));

	t_mesh_add_face(&result, create_t_face(5, 1, 4)); // FACE FRONT
	t_mesh_add_face(&result, create_t_face(0, 4, 1));

	t_mesh_add_face(&result, create_t_face(6, 7, 2)); // FACE BACK
	t_mesh_add_face(&result, create_t_face(3, 2, 7));

	t_mesh_add_face(&result, create_t_face(6, 2, 5)); // FACE RIGHT
	t_mesh_add_face(&result, create_t_face(1, 5, 2));

	t_mesh_add_face(&result, create_t_face(7, 4, 3)); // FACE LEFT
	t_mesh_add_face(&result, create_t_face(0, 3, 4));

	t_mesh_compute_normals(&result);

	return (result);
}

t_mesh		create_primitive_plane(t_vector3 pos, t_vector3 size)
{
	t_mesh result;

	result = create_t_mesh(pos);

	t_mesh_add_point(&result, create_t_vector3(-size.x / 2.0, 0.0, -size.z / 2.0));
	t_mesh_add_point(&result, create_t_vector3(size.x / 2.0, 0.0, -size.z / 2.0));
	t_mesh_add_point(&result, create_t_vector3(size.x / 2.0, 0.0, size.z / 2.0));
	t_mesh_add_point(&result, create_t_vector3(-size.x / 2.0, 0.0, size.z / 2.0));

	t_mesh_add_face(&result, create_t_face(2, 1, 3));
	t_mesh_add_face(&result, create_t_face(0, 3, 1));

	t_mesh_add_face(&result, create_t_face(2, 3, 1));
	t_mesh_add_face(&result, create_t_face(0, 1, 3));

	t_mesh_compute_normals(&result);

	return (result);
}
