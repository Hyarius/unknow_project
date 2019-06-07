#include "unknow_project.h"

void	draw_t_mesh(t_window *p_win, t_camera *p_cam, t_mesh *mesh)
{
	t_uv 		tmp_uv;
	t_color		tmp_color;
	float		darkness;
	t_triangle	triangle;
	t_vector3	points[3];
	t_vector3	points_uv[3];

	for (int i = 0; i < mesh->faces->size; i++)
	{
		t_face face = t_face_list_at(mesh->faces, i); // recuperation la face du volume a draw

		points[0] = add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face.index_vertices[0]), mesh->pos);
		points[1] = add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face.index_vertices[1]), mesh->pos);
		points[2] = add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face.index_vertices[2]), mesh->pos);

		points_uv[0] = t_vector3_list_at(mesh->uvs, face.index_uvs[0]);
		points_uv[1] = t_vector3_list_at(mesh->uvs, face.index_uvs[1]);
		points_uv[2] = t_vector3_list_at(mesh->uvs, face.index_uvs[2]);

		float result = dot_t_vector3(face.normale, normalize_t_vector3(substract_vector3_to_vector3(points[0], p_cam->pos)));

		if (result < 0)
		{
			darkness = - dot_t_vector3(face.normale, p_cam->sun_direction);

			darkness += 1;
			darkness = darkness / (2 / (1 - 0.1));

			if (darkness < 0.3)
				darkness = 0.3;

			tmp_color.r = darkness;
			tmp_color.g = darkness;
			tmp_color.b = darkness;
			tmp_color.a = 1.0f;

			points[0] = mult_vector3_by_matrix(&points[0], &(p_cam->view));
			points[1] = mult_vector3_by_matrix(&points[1], &(p_cam->view));
			points[2] = mult_vector3_by_matrix(&points[2], &(p_cam->view));

			int nb_clipped = clip_triangle_to_plane(p_cam, points, points_uv);

			for (int j = 0; j < nb_clipped; j += 3)
			{
				triangle.a = apply_t_camera(&(p_cam->clipping_list[j + 0]), &(p_cam->projection)); // applique la position de la camera
				triangle.b = apply_t_camera(&(p_cam->clipping_list[j + 1]), &(p_cam->projection));
				triangle.c = apply_t_camera(&(p_cam->clipping_list[j + 2]), &(p_cam->projection));

				if (mesh->texture == NULL)
				{
					t_color_list_push_back(&(p_cam->color_list), tmp_color);
					t_triangle_list_push_back(&(p_cam->triangle_color_list), triangle);
				}
				else
				{
					t_triangle_list_push_back(&(p_cam->triangle_texture_list), triangle);
					triangle.a = p_cam->clipping_list_uv[j + 0];
					triangle.b = p_cam->clipping_list_uv[j + 1];
					triangle.c = p_cam->clipping_list_uv[j + 2];
					tmp_uv = create_t_uv(triangle, mesh->texture);
					t_uv_list_push_back(&(p_cam->uv_list), tmp_uv);
					t_color_list_push_back(&(p_cam->darkness_list), tmp_color);
				}
			}
		}
	}
}
