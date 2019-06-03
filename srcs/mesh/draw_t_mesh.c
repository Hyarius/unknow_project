#include "unknow_project.h"

void	draw_t_mesh(t_window *p_win, t_camera *p_cam, t_mesh *mesh)
{
	t_color		tmp_color;
	t_color		color_white = {1.0, 1.0, 1.0, 1.0};
	float		darkness;
	t_triangle	triangle;
	t_vector3	points[3];

	for (int i = 0; i < mesh->faces->size; i++)
	{
		t_face face = t_face_list_at(mesh->faces, i); // recuperation la face du volume a draw

		points[0] = add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face.index[0]), mesh->pos);
		points[1] = add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face.index[1]), mesh->pos);
		points[2] = add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face.index[2]), mesh->pos);

		float result = dot_t_vector3(face.normale, normalize_t_vector3(substract_vector3_to_vector3(points[0], p_cam->pos)));

		if (result < 0)
		{
			darkness = - dot_t_vector3(face.normale, p_cam->sun_direction);

			darkness += 1;
			darkness = darkness / (2 / (1 - 0.1));

			if (darkness < 0.3)
				darkness = 0.3;

			tmp_color.r = color_white.r * darkness;
			tmp_color.g = color_white.g * darkness;
			tmp_color.b = color_white.b * darkness;
			tmp_color.a = color_white.a;

			points[0] = mult_vector3_by_matrix(&points[0], &(p_cam->view));
			points[1] = mult_vector3_by_matrix(&points[1], &(p_cam->view));
			points[2] = mult_vector3_by_matrix(&points[2], &(p_cam->view));

			int nb_clipped = clip_triangle_to_plane(p_cam, points);

			for (int j = 0; j < nb_clipped; j += 3)
			{
				triangle.a = apply_t_camera(&(p_cam->clipping_list[j + 0]), &(p_cam->projection)); // applique la position de la camera
				triangle.b = apply_t_camera(&(p_cam->clipping_list[j + 1]), &(p_cam->projection));
				triangle.c = apply_t_camera(&(p_cam->clipping_list[j + 2]), &(p_cam->projection));

				t_color_list_push_back(&(p_cam->color_list), tmp_color);
				t_triangle_list_push_back(&(p_cam->triangle_list), triangle);
			}
		}
	}
}
//
// Pythagore 2D : Result^2 = A^2 + B^2 ---> Result = racine(A^2 + B^2)
// Pythagore 3D : Result^2 = A^2 + B^2 + C^2 ---> Result = racine(A^2 + B^2 + C^2)
//
// 1) 1.500
// 2) 1.802
// 3) 1.802
// 4) 2.060
// 5) 1.802
// 6) 1.802
