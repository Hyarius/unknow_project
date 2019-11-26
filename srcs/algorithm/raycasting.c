# include "unknow_project.h"

t_mesh	*cast_ray_next(t_vector4 pos, t_vector4 direction, t_mesh *mesh)
{
	int 		k;
	t_line		line;
	t_vector4	intersection;

	k = -1;
	line = create_t_line(pos, add_vector4_to_vector4(pos, direction));
	while (++k < mesh->faces->size)
	{
		if ((mesh->no_hitbox == 0 || mesh->is_visible == 1) && intersect_triangle_by_segment(compose_t_triangle_from_t_mesh
				(mesh, t_face_list_get(mesh->faces, k)->index_vertices),
				t_face_list_get(mesh->faces, k)->normale, line,
				&intersection) == BOOL_TRUE)
			return (mesh);
	}
	return (NULL);
}

t_mesh	*cast_ray(t_engine *engine, t_vector4 pos, t_vector4 direction, char *shooter)
{
	int 		i;
	int 		j;
	t_mesh 		*mesh;

	i = -1;
	direction = divide_vector4_by_float(direction, 8);
	while (++i < 100)
	{
		j = -1;
		while (++j < t_engine_return_mesh_len(engine))
		{
			mesh = t_engine_get_mesh(engine, j);
			// t_mesh_set_color(mesh, create_t_color(0.0, 1.0, 0.0, 1.0));
			if (ft_strcmp(mesh->name, shooter) != 0)
			{
				mesh = cast_ray_next(pos, direction, mesh);
				if (mesh != NULL)
				// {
				// 	t_mesh_set_color(mesh, create_t_color(1.0, 0.0, 0.0, 1.0));
					return (mesh);
				// }
			}
		}
		pos = add_vector4_to_vector4(pos, direction);
	}
	return (NULL);
}
