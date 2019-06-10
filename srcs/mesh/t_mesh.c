#include "unknow_project.h"

t_mesh			create_t_mesh(t_vector3 pos)
{
	t_mesh result;

	result.pos = pos;
	result.texture = NULL;
	result.vertices = initialize_t_vector3_list();
	result.uvs = initialize_t_vector3_list();
	result.faces = initialize_t_face_list();
	result.normales = initialize_t_vector3_list();

	return (result);
}

t_mesh			*initialize_t_mesh(t_vector3 pos)
{
	t_mesh *result;

	if (!(result = (t_mesh *)malloc(sizeof(t_mesh))))
		error_exit(-13, "Can't create a t_mesh array");

	*result = create_t_mesh(pos);

	return(result);
}

void			free_t_mesh(t_mesh mesh)
{
	delete_t_vector3_list(mesh.vertices);
	delete_t_vector3_list(mesh.uvs);
	delete_t_face_list(mesh.faces);
}

void			delete_t_mesh(t_mesh *mesh)
{
	free_t_mesh(*mesh);
	free(mesh);
}

void		t_mesh_add_uv(t_mesh *dest, t_vector3 new_uv)
{
	t_vector3_list_push_back(dest->uvs, new_uv);
}

void			t_mesh_add_point(t_mesh *dest, t_vector3 new_point)
{
	t_vector3_list_push_back(dest->vertices, new_point);
}

void			t_mesh_add_face(t_mesh *dest, t_face new_face)
{
	t_face_list_push_back(dest->faces, new_face);
}

void 			t_mesh_set_texture(t_mesh *dest, t_texture *p_texture)
{
	dest->texture = p_texture;
}

void			t_mesh_compute_normals(t_mesh *mesh)
{
	t_face		*face;
	t_vector3	a;
	t_vector3	b;
	t_vector3	c;
	int			i;

	clean_t_vector3_list(mesh->normales);
	i = 0;
	while (i < mesh->faces->size)
	{
		face = t_face_list_get(mesh->faces, i);

		a = t_vector3_list_at(mesh->vertices, face->index_vertices[0]);
		b = substract_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face->index_vertices[1]), a);
		c = substract_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face->index_vertices[2]), a);

		face->normale = normalize_t_vector3(cross_t_vector3(b, c));

		t_vector3_list_push_back(mesh->normales, create_t_vector3(0, 0, 0));
		t_vector3_list_push_back(mesh->normales, face->normale);

		i++;
	}

}

void			rotate_t_mesh(t_mesh *mesh, t_vector3 angle, t_vector3 center)
{
	t_matrix	translate;
	t_matrix	rotation;
	t_matrix	inv_translate;
	t_vector3	*target;

	translate = create_translation_matrix(center);
	inv_translate = create_translation_matrix(inv_t_vector3(center));
	rotation = create_rotation_matrix(angle.x, angle.y, angle.z);
	for (int i = 0; i < mesh->vertices->size; i++)
	{
		target = t_vector3_list_get(mesh->vertices, i);
		*target = mult_vector3_by_matrix(target, &translate);
		*target = mult_vector3_by_matrix(target, &rotation);
		*target = mult_vector3_by_matrix(target, &inv_translate);
	}
	t_mesh_compute_normals(mesh);
}
