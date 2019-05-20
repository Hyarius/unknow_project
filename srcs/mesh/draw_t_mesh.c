#include "unknow_project.h"

void		draw_t_mesh(t_window *p_win, t_vector3 camera, t_mesh *mesh)
{
	int			*index;
	t_vector3 coords[3];
	t_triangle_list t;

	t = create_t_triangle_list();

	for (int i = 0; i < mesh->faces->size; i++)
	{
		index = t_faces_at(mesh->faces, i);
		coords[0] = t_vector3_list_at(mesh->vertices, index[0]);
		coords[1] = t_vector3_list_at(mesh->vertices, index[1]);
		coords[2] = t_vector3_list_at(mesh->vertices, index[2]);


		/*printf("Face %d :", i + 1);
		print_t_vector3(coords[0], "\nA : ");
		print_t_vector3(coords[1], "\nB : ");
		print_t_vector3(coords[2], "\nC : ");
		printf("\n");*/
		draw_triangle_color_cpu(p_win, &t, mesh->colors);
	}
}
