#include "unknow_project.h"

t_color		color_white = {1.0, 1.0, 1.0, 1.0};
t_color		color_black = {0.0, 0.0, 0.0, 1.0};

void draw_t_mesh(t_window *p_win, t_camera *p_cam, t_mesh *mesh)
{
	t_color		tmp_color;
	float		darkness;
	t_line		line;
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

			clip_triangle_to_plane(p_cam, points);

			for (int j = 0; j < p_cam->clipping_list.size; j += 3)
			{
				points[0] = apply_t_camera(t_vector3_list_get(&(p_cam->clipping_list), j + 0), &(p_cam->projection)); // applique la position de la camera
				points[1] = apply_t_camera(t_vector3_list_get(&(p_cam->clipping_list), j + 1), &(p_cam->projection));
				points[2] = apply_t_camera(t_vector3_list_get(&(p_cam->clipping_list), j + 2), &(p_cam->projection));

				triangle = create_t_triangle(	create_t_vector2(points[0].x, points[0].y),
												create_t_vector2(points[1].x, points[1].y),
												create_t_vector2(points[2].x, points[2].y));

				draw_triangle_color_opengl(p_win, &triangle, &tmp_color); //draw le trait entre deux points

				line = create_t_line(			create_t_vector2(points[0].x, points[0].y),
												create_t_vector2(points[1].x, points[1].y));
				draw_line_color_opengl(p_win, &line, &color_black); //draw le trait entre deux points

				line = create_t_line(			create_t_vector2(points[0].x, points[0].y),
												create_t_vector2(points[2].x, points[2].y));
				draw_line_color_opengl(p_win, &line, &color_black);

				// line = create_t_line(			create_t_vector2(points[2].x, points[2].y),
				// 								create_t_vector2(points[1].x, points[1].y));
				// draw_line_color_opengl(p_win, &line, &color_black);
			}
		}
	}
}
