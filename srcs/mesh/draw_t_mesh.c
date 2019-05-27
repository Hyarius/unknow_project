#include "unknow_project.h"

t_color		color[9] = {
	{1.0, 1.0, 1.0, 1.0},
	{1.0, 0.0, 0.0, 1.0},
	{0.0, 0.0, 1.0, 1.0},
	{0.0, 1.0, 0.0, 1.0},
	{1.0, 1.0, 0.0, 1.0},
	{0.0, 1.0, 1.0, 1.0},
	{1.0, 0.1, 0.1, 1.0},
	{0.1, 1.0, 0.1, 1.0},
	{0.1, 0.1, 1.0, 1.0},
};

void draw_t_mesh(t_window *p_win, t_camera *p_cam, t_mesh *mesh)
{
	t_color		tmp_color;
	float		darkness;
	t_line		line;
	t_triangle	triangle;
	t_vector3	points[3];

	printf("\n\n\n\n\n");

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

			if (darkness < 0.1)
				darkness = 0.1;

			tmp_color.r = color[i / 2].r * darkness;
			tmp_color.g = color[i / 2].g * darkness;
			tmp_color.b = color[i / 2].b * darkness;
			tmp_color.a = color[i / 2].a;

			points[0] = apply_t_camera(&points[0], &(p_cam->mvp)); // applique la position de la camera
			points[1] = apply_t_camera(&points[1], &(p_cam->mvp));
			points[2] = apply_t_camera(&points[2], &(p_cam->mvp));

			clip_triangle_to_plane(p_cam, points); // Doit etre apres la multiplication view, mais AVANT la projection. A add dans apply_t_camera puis look at
				//https://github.com/OneLoneCoder/videos/blob/master/OneLoneCoder_olcEngine3D_Part3.cpp
				//line 576 - 596
			for (int j = 0; j < p_cam->clipping_list.size; j += 3)
			{
				triangle = create_t_triangle(	create_t_vector2(t_vector3_list_at(&(p_cam->clipping_list), 0).x, t_vector3_list_at(&(p_cam->clipping_list), 0).y),
												create_t_vector2(t_vector3_list_at(&(p_cam->clipping_list), 1).x, t_vector3_list_at(&(p_cam->clipping_list), 1).y),
												create_t_vector2(t_vector3_list_at(&(p_cam->clipping_list), 2).x, t_vector3_list_at(&(p_cam->clipping_list), 2).y));
				draw_triangle_color_opengl(p_win, &triangle, &tmp_color); //draw le trait entre deux points

				line = create_t_line(			create_t_vector2(t_vector3_list_at(&(p_cam->clipping_list), 0).x, t_vector3_list_at(&(p_cam->clipping_list), 0).y),
												create_t_vector2(t_vector3_list_at(&(p_cam->clipping_list), 1).x, t_vector3_list_at(&(p_cam->clipping_list), 1).y));
				draw_line_color_opengl(p_win, &line, &color[6]); //draw le trait entre deux points

				line = create_t_line(			create_t_vector2(t_vector3_list_at(&(p_cam->clipping_list), 0).x, t_vector3_list_at(&(p_cam->clipping_list), 0).y),
												create_t_vector2(t_vector3_list_at(&(p_cam->clipping_list), 2).x, t_vector3_list_at(&(p_cam->clipping_list), 2).y));
				draw_line_color_opengl(p_win, &line, &color[7]);

				line = create_t_line(			create_t_vector2(t_vector3_list_at(&(p_cam->clipping_list), 2).x, t_vector3_list_at(&(p_cam->clipping_list), 2).y),
												create_t_vector2(t_vector3_list_at(&(p_cam->clipping_list), 1).x, t_vector3_list_at(&(p_cam->clipping_list), 1).y));
				draw_line_color_opengl(p_win, &line, &color[8]);
			}
		}
	}
	// for (int i = 0; i < mesh->normales->size; i += 2)
	// {
	// 	t_face face = t_face_list_at(mesh->faces, i / 2); // recuperation la face du volume a draw
	//
	// 	points[2] = add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face.index[0]), mesh->pos);
	// 	points[0] = add_vector3_to_vector3(t_vector3_list_at(mesh->normales, i), points[2]);
	// 	points[1] = add_vector3_to_vector3(t_vector3_list_at(mesh->normales, i + 1), points[2]);
	//
	// 	points[0] = apply_t_camera(&points[0], &(p_cam->mvp));
	// 	points[1] = apply_t_camera(&points[1], &(p_cam->mvp));
	//
	// 	test = create_t_line(create_t_vector2(points[0].x, points[0].y), create_t_vector2(points[1].x, points[1].y));
	// 	draw_line_color_opengl(p_win, &test, &color_black); //draw le trait entre deux points
	// }
}
