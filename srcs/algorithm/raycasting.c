# include "unknow_project.h"

t_mesh	*cast_ray(t_engine *engine, t_vector3 pos, t_vector3 direction)
{
	int 		i;
	int 		j;
	int 		k;
	float		subdivision = 3;
	t_vector3	dest_pos;
	t_line		line;
	t_triangle	triangle;
	t_vector3	intersection;
	t_mesh 		*mesh;
	t_face		*face;

	i = 0;
	direction = normalize_t_vector3(direction);
	direction = divide_vector3_by_float(direction, subdivision);
	//print_t_vector3(direction, "direction");
	while (i < FAR * subdivision)
	{
		j = 0;
		dest_pos = add_vector3_to_vector3(pos, direction);
		print_t_vector3(dest_pos, "dest_pos");

		while (j < t_engine_return_mesh_len(engine))
		{
			k = 0;
			mesh = t_engine_get_mesh(engine, j);
			line = create_t_line(pos, dest_pos);
			while (k < mesh->faces->size)
			{
				face = t_face_list_get(mesh->faces, k);
				triangle = compose_t_triangle_from_t_mesh(mesh, face->index_vertices);

				//printf("Drawing line from %d,%d,%d to %d,%d,%d\n", pos.x, pos.y, pos.z, dest_pos.x, dest_pos.y, dest_pos.z);
				if (intersect_triangle_by_segment(triangle, face->normale, line, &intersection) == BOOL_TRUE)
					return (mesh);
				k++;
			}
			j++;
		}
		pos = dest_pos;
		i++;
	}
	return (NULL);
}