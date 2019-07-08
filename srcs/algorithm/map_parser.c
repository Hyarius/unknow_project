#include "unknow_project.h"

t_mesh_list		read_map_file(char *path)
{
	t_mesh_list	*result;
	char		*line;
	char		**line_split;
	int			fd;
	t_texture	*texture;
	t_vector3	vector[3];
	char		*obj_path[256];
	int			i = 0;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	 	error_exit(-7000, "impossible fd");
	result = initialize_t_mesh_list();
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) != 0)
		{
			line_split = ft_strsplit(line, ' ');
			printf("%s\n", line_split[0]);
			if (ft_strcmp(line_split[0], "plane:") == 0)
			{
				vector[0] = create_t_vector3(ft_atof(line_split[1]),
											ft_atof(line_split[2]),
											ft_atof(line_split[3]));
				vector[1] = create_t_vector3(ft_atof(line_split[4]),
											ft_atof(line_split[5]),
											ft_atof(line_split[6]));
				if (ft_strcmp(line_split[7], "NULL") != 0){
					texture = png_load(line_split[7]);
				}
				else
					texture = NULL;
				t_mesh_list_push_back(result,
									create_primitive_plane(vector[0], vector[1], texture, ft_atof(line_split[8])));
				vector[2] = create_t_vector3(ft_atof(line_split[9]),
											ft_atof(line_split[10]),
											ft_atof(line_split[11]));
				t_mesh_rotate(t_mesh_list_get(result, result->size - 1), vector[2]);
			}
			else if (ft_strcmp(line_split[0], "cube:") == 0)
			{
				vector[0] = create_t_vector3(ft_atof(line_split[1]),
											ft_atof(line_split[2]),
											ft_atof(line_split[3]));
				vector[1] = create_t_vector3(ft_atof(line_split[4]),
											ft_atof(line_split[5]),
											ft_atof(line_split[6]));
				if (ft_strcmp(line_split[7], "NULL") != 0)
					texture = png_load(line_split[7]);
				else
					texture = NULL;
				t_mesh_list_push_back(result,
									create_primitive_cube(vector[0], vector[1], texture, ft_atof(line_split[8])));
				vector[2] = create_t_vector3(ft_atof(line_split[9]),
											ft_atof(line_split[10]),
											ft_atof(line_split[11]));
				t_mesh_rotate(t_mesh_list_get(result, result->size - 1), vector[2]);
			}
			else if (ft_strcmp(line_split[0], "#") == 0)
			{
				vector[0] = create_t_vector3(ft_atof(line_split[2]),
											ft_atof(line_split[3]),
											ft_atof(line_split[4]));
				vector[1] = create_t_vector3(ft_atof(line_split[5]),
											ft_atof(line_split[6]),
											ft_atof(line_split[7]));
				// if (!ft_strcmp(line_split[7], "NULL"))
				// 	texture = png_load(line_split[7]);
				// else
				// 	texture = NULL;

				t_mesh_list_push_back(result, read_obj_file(line_split[1], vector[0], vector[1], ft_atof(line_split[9])));

				vector[2] = create_t_vector3(ft_atof(line_split[10]),
											ft_atof(line_split[11]),
											ft_atof(line_split[12]));
				t_mesh_rotate(t_mesh_list_get(result, result->size - 1), vector[2]);
				i++;
			}
			// printf("fd = %d\n", fd);
			printf("%s\n", line_split[0]);
		}
			printf("%s\n", line_split[0]);
	}

	// t_mesh_compute_bubble_box(&result);
	return(*result);
}