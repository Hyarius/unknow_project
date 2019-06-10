#include "unknow_project.h"

t_mesh		read_obj_file(char *path, t_vector3 pos)
{
	t_mesh	result;
	char	*line;
	char	**line_split;
	char	**tab;
	int		index[4];
	int		index_uv[4];
	t_face	tmp_face;

	result = create_t_mesh(pos);

	tmp_face = create_t_face();

	int fd = open(path, O_RDONLY);
	 if (fd < 0)
	 	error_exit(-8000, "impossible fd");
	while (get_next_line(fd, &line))
	{
		line_split = ft_strsplit(line, ' ');
		int len = ft_tablen(line_split);
		if (ft_strcmp(line_split[0], "v") == 0)
		{
			t_mesh_add_point(&result, create_t_vector3(atof(line_split[1]), atof(line_split[2]), atof(line_split[3])));
		}
		else if (ft_strcmp(line_split[0], "vt") == 0)
		{
			t_mesh_add_uv(&result, create_t_vector3(atof(line_split[1]), atof(line_split[2]), 0.0));
		}
		else if (ft_strcmp(line_split[0], "f") == 0)
		{
			// 2 - 1 - 3 - 4
			for (int i = 0; i < 4; i++)
			{
				tab = ft_strsplit(line_split[i + 1], '/');
				index[i] = ft_atoi(tab[0]) - 1;
				if (ft_tablen(tab) == 2)
					index_uv[i] = ft_atoi(tab[1]) - 1;
			}

			set_t_face_vertices(&tmp_face, index[0], index[1], index[2]);
			set_t_face_uvs(&tmp_face, index_uv[0], index_uv[1], index_uv[2]);
			t_mesh_add_face(&result, tmp_face);

			set_t_face_vertices(&tmp_face, index[0], index[2], index[3]);
			set_t_face_uvs(&tmp_face, index_uv[0], index_uv[2], index_uv[3]);
			t_mesh_add_face(&result, tmp_face);
		}
	}
	t_mesh_compute_normals(&result);

	t_mesh_set_texture(&result, NULL);

	return(result);
}
