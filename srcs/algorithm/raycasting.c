# include "unknow_project.h"

t_mesh	*cast_ray(t_engine *engine, t_vector3 pos, t_vector3 direction)
{
	int 		i;
	int 		j;
	int 		k;
	// float		subdivision = 3;
	// t_vector3	dest_pos;
	t_line		line;
	// t_triangle	triangle;
	t_vector3	intersection;
	t_mesh 		*mesh;
	// t_face		*face;

	i = 0;
	direction = normalize_t_vector3(direction);
	direction = divide_vector3_by_float(direction, 3);
	while (i < FAR * 3)
	{
		j = 0;
		// dest_pos = add_vector3_to_vector3(pos, direction);
		while (j < t_engine_return_mesh_len(engine))
		{
			k = 0;
			mesh = t_engine_get_mesh(engine, j);
			line = create_t_line(pos, add_vector3_to_vector3(pos, direction));
			t_mesh_set_color(mesh, create_t_color(1, 0, 0, 1));
			// t_mesh_set_visibility(mesh, 1);
			while (k < mesh->faces->size)
			{
				// face = t_face_list_get(mesh->faces, k);
				// triangle = compose_t_triangle_from_t_mesh(mesh, face->index_vertices);
				if (intersect_triangle_by_segment(compose_t_triangle_from_t_mesh
						(mesh, t_face_list_get(mesh->faces, k)->index_vertices),
						t_face_list_get(mesh->faces, k)->normale, line,
						&intersection) == BOOL_TRUE)
					return (mesh);
				k++;
			}
			j++;
		}
		pos = add_vector3_to_vector3(pos, direction);
		i++;
	}
	return (NULL);
}
