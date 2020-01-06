#include "unknow_project.h"

static void	t_mesh_init_point_primitive_cave(t_mesh *result, t_vector4 size)
{
	size.x -= EPSILON;
	size.y -= EPSILON;
	size.z -= EPSILON;
	t_mesh_add_point(result, create_t_vector4(0.0, 0.0, 0.0));
	t_mesh_add_point(result, create_t_vector4(size.x, 0.0, 0.0));
	t_mesh_add_point(result, create_t_vector4(0.0, 0.0, size.z));
	t_mesh_add_point(result, create_t_vector4(size.x, 0.0, size.z));
	t_mesh_add_point(result, create_t_vector4(0.0, size.y, 0.0));
	t_mesh_add_point(result, create_t_vector4(size.x, size.y, 0.0));
	t_mesh_add_point(result, create_t_vector4(0.0, size.y, size.z));
	t_mesh_add_point(result, create_t_vector4(size.x, size.y, size.z)); //exterieur
    t_mesh_add_point(result, create_t_vector4(size.x / 8.0, 0.0, size.z / 8.0));          //interieur
	t_mesh_add_point(result, create_t_vector4(size.x - size.x / 8.0, 0.0, size.z / 8.0));
	t_mesh_add_point(result, create_t_vector4(size.x / 8.0, 0.0, size.z - size.z / 8.0));
	t_mesh_add_point(result, create_t_vector4(size.x - size.x / 8.0, 0.0, size.z - size.z / 8.0));
	t_mesh_add_point(result, create_t_vector4(size.x / 8.0, size.y, size.z / 8.0));
	t_mesh_add_point(result, create_t_vector4(size.x - size.x / 8.0, size.y, size.z / 8.0));
	t_mesh_add_point(result, create_t_vector4(size.x / 8.0, size.y, size.z - size.z / 8.0));
	t_mesh_add_point(result, create_t_vector4(size.x - size.x / 8.0, size.y, size.z - size.z / 8.0));
}

static void	t_mesh_init_uv_point_primitive_cave(t_mesh *result)
{
	t_mesh_add_uv(result, create_t_vector4(0.0f, 0.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(1.0f / 3.0f, 0.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(2.0f / 3.0f, 0.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(0.0f, 1.0f / 3.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(1.0f / 3.0f, 1.0f / 3.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(2.0f / 3.0f, 1.0f / 3.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(1.0f, 1.0f / 3.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(0.0f, 2.0f / 3.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(1.0f / 3.0f, 2.0f / 3.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(2.0f / 3.0f, 2.0f / 3.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(1.0f, 2.0f / 3.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(1.0f / 3.0f, 1.0f, 0.0f));
	t_mesh_add_uv(result, create_t_vector4(2.0f / 3.0f, 1.0f, 0.0f));
}

static void	t_mesh_init_face_primitive_cave_next(t_mesh *result, t_face tmp_face1, t_face tmp_face2)
{
	set_t_face_vertices(&tmp_face1, 3, 7, 15);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 3, 15, 11);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
    set_t_face_vertices(&tmp_face1, 2, 14, 6);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 2, 10, 14);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
    set_t_face_vertices(&tmp_face1, 1, 5, 7);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 1, 7, 3);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
    set_t_face_vertices(&tmp_face1, 0, 5, 1);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 0, 4, 5);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
    set_t_face_vertices(&tmp_face1, 0, 6, 4);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 0, 2, 6);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);

    set_t_face_vertices(&tmp_face1, 9, 11, 15);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 9, 15, 13);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
    set_t_face_vertices(&tmp_face1, 8, 9, 13);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 8, 13, 12);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
    set_t_face_vertices(&tmp_face1, 10, 8, 12);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 10, 12, 14);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
}

static void	t_mesh_init_face_primitive_cave(t_mesh *result, t_face tmp_face1, t_face tmp_face2)
{
	set_t_face_vertices(&tmp_face1, 0, 1, 9);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 0, 9, 8);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
    set_t_face_vertices(&tmp_face1, 1, 3, 9);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 9, 3, 11);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
    set_t_face_vertices(&tmp_face1, 2, 0, 10);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 10, 0, 8);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);

    set_t_face_vertices(&tmp_face1, 5, 4, 12);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 5, 12, 13);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
    set_t_face_vertices(&tmp_face1, 7, 5, 13);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 7, 13, 15);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
    set_t_face_vertices(&tmp_face1, 4, 6, 14);
	set_t_face_uvs(&tmp_face1, 0, 1, 3);
	set_t_face_vertices(&tmp_face2, 4, 14, 12);
	set_t_face_uvs(&tmp_face2, 4, 3, 1);
	t_mesh_add_face(result, tmp_face1);
	t_mesh_add_face(result, tmp_face2);
}

t_mesh		create_primitive_cave(t_vector4 pos, t_vector4 size, char *texture_path, float gravity)
{
	t_mesh	result;
	t_face	tmp_face1;
	t_face	tmp_face2;

	result = create_t_mesh(pos);
	result.primitive = 1;
	result.size = create_t_vector4(size.x, size.y, size.z);
	t_mesh_activate_gravity(&result, gravity);
	t_mesh_init_point_primitive_cave(&result, size);
	t_mesh_init_uv_point_primitive_cave(&result);
	tmp_face1 = create_t_face();
	tmp_face2 = create_t_face();
	t_mesh_init_face_primitive_cave(&result, tmp_face1, tmp_face2);
	t_mesh_init_face_primitive_cave_next(&result, tmp_face1, tmp_face2);
	t_mesh_compute_normals(&result);
	t_mesh_compute_bubble_box(&result);
	if (texture_path != NULL)
		result.texture = png_load(texture_path);
	return (result);
}
