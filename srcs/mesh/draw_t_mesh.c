#include "unknow_project.h"

void draw_t_mesh(t_window *p_win, t_matrix *mvp, t_mesh *mesh)
{
	t_vector3	p1;
	t_vector3	p2;
	t_vector3	p3;

	p1 = t_vector3_list_at(mesh->vertices, t_faces_at(mesh->faces, 0)[0]);
	p2 = t_vector3_list_at(mesh->vertices, t_faces_at(mesh->faces, 0)[1]);
	p3 = t_vector3_list_at(mesh->vertices, t_faces_at(mesh->faces, 0)[2]);

	printf("-----------\n");

	print_t_vector3(p1, "P1 = ");
	endl();
	print_t_vector3(p2, "P2 = ");
	endl();
	print_t_vector3(p3, "P3 = ");
	endl();

	p1 = apply_t_camera(&p1, mvp);
	p2 = apply_t_camera(&p2, mvp);
	p3 = apply_t_camera(&p3, mvp);

	print_t_vector3(p1, "P1 = ");
	endl();
	print_t_vector3(p2, "P2 = ");
	endl();
	print_t_vector3(p3, "P3 = ");
	endl();
}
