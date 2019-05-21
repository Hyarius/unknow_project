#include "unknow_project.h"

void draw_t_mesh(t_window *p_win, t_matrix *mvp, t_mesh *mesh)
{
	t_color		color = create_t_color_from_int(255, 255, 255, 255);
	t_line test;
	t_vector3	p1;
	t_vector3	p2;
	t_vector3	p3;

	for (int i = 0; i < mesh->faces->size; i++)
	{
		p1 = t_vector3_list_at(mesh->vertices, t_faces_at(mesh->faces, i)[0]);
		p2 = t_vector3_list_at(mesh->vertices, t_faces_at(mesh->faces, i)[1]);
		p3 = t_vector3_list_at(mesh->vertices, t_faces_at(mesh->faces, i)[2]);

		p1 = apply_t_camera(&p1, mvp);
		p2 = apply_t_camera(&p2, mvp);
		p3 = apply_t_camera(&p3, mvp);

		test = create_t_line(create_t_vector2(p1.x, p1.y), create_t_vector2(p2.x, p2.y));
		draw_line_color_opengl(p_win, &test, &color);

		test = create_t_line(create_t_vector2(p1.x, p1.y), create_t_vector2(p3.x, p3.y));
		draw_line_color_opengl(p_win, &test, &color);

		test = create_t_line(create_t_vector2(p3.x, p3.y), create_t_vector2(p2.x, p2.y));
		draw_line_color_opengl(p_win, &test, &color);
	}
}
