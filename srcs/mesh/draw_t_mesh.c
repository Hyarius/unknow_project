#include "unknow_project.h"

void draw_t_mesh(t_window *p_win, t_camera *p_cam, t_mesh *mesh)
{
	t_color		tmp_color;
	t_color		color_white = create_t_color_from_int(255, 255, 255, 255);
	t_color		color_black = create_t_color_from_int(0, 0, 0, 255);
	float		darkness;
	t_line		line;
	t_triangle	triangle;
	t_vector3	p1;
	t_vector3	p2;
	t_vector3	p3;

	for (int i = 0; i < mesh->faces->size; i++)
	{
		t_face face = t_face_list_at(mesh->faces, i); // recuperation la face du volume a draw

		p1 = add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face.index[0]), mesh->pos);
		p2 = add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face.index[1]), mesh->pos);
		p3 = add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face.index[2]), mesh->pos);

		float result = dot_t_vector3(face.normale, normalize_t_vector3(substract_vector3_to_vector3(p1, p_cam->pos)));

		if (result < 0)
		{
			darkness = - dot_t_vector3(face.normale, p_cam->sun_direction);

			darkness += 1;
			darkness = darkness / (2 / (1 - 0.1));

			if (darkness < 0.1)
				darkness = 0.1;

			tmp_color.r = color_white.r * darkness;
			tmp_color.g = color_white.g * darkness;
			tmp_color.b = color_white.b * darkness;
			tmp_color.a = color_white.a;
			p1 = apply_t_camera(&p1, &(p_cam->mvp)); // applique la position de la camera
			p2 = apply_t_camera(&p2, &(p_cam->mvp));
			p3 = apply_t_camera(&p3, &(p_cam->mvp));

			triangle = create_t_triangle(create_t_vector2(p1.x, p1.y), create_t_vector2(p2.x, p2.y), create_t_vector2(p3.x, p3.y));
			draw_triangle_color_opengl(p_win, &triangle, &tmp_color); //draw le trait entre deux points

			line = create_t_line(create_t_vector2(p1.x, p1.y), create_t_vector2(p2.x, p2.y));
			draw_line_color_opengl(p_win, &line, &color_black); //draw le trait entre deux points

			line = create_t_line(create_t_vector2(p1.x, p1.y), create_t_vector2(p3.x, p3.y));
			draw_line_color_opengl(p_win, &line, &color_black);

			line = create_t_line(create_t_vector2(p3.x, p3.y), create_t_vector2(p2.x, p2.y));
			draw_line_color_opengl(p_win, &line, &color_black);
		}
	}
	// for (int i = 0; i < mesh->normales->size; i += 2)
	// {
	// 	t_face face = t_face_list_at(mesh->faces, i / 2); // recuperation la face du volume a draw
	//
	// 	p3 = add_vector3_to_vector3(t_vector3_list_at(mesh->vertices, face.index[0]), mesh->pos);
	// 	p1 = add_vector3_to_vector3(t_vector3_list_at(mesh->normales, i), p3);
	// 	p2 = add_vector3_to_vector3(t_vector3_list_at(mesh->normales, i + 1), p3);
	//
	// 	p1 = apply_t_camera(&p1, &(p_cam->mvp));
	// 	p2 = apply_t_camera(&p2, &(p_cam->mvp));
	//
	// 	test = create_t_line(create_t_vector2(p1.x, p1.y), create_t_vector2(p2.x, p2.y));
	// 	draw_line_color_opengl(p_win, &test, &color_black); //draw le trait entre deux points
	// }
}
