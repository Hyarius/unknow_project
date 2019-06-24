#include "unknow_project.h"

// int main(int argc, char **argv)
// {
// 	t_triangle a;
// 	t_triangle b;
// 	t_vector3 p[6];
//
// 	p[0] = create_t_vector3(0, 0, 0);
// 	p[1] = create_t_vector3(1, 0, 0);
// 	p[2] = create_t_vector3(0, 1, 0);
// 	p[3] = create_t_vector3(0, 0, 0);
// 	p[4] = create_t_vector3(1, 0, 0);
// 	p[5] = create_t_vector3(0, 0, 1);
//
// 	a = create_t_triangle(p[0], p[1], p[2]);
// 	b = create_t_triangle(p[3], p[4], p[5]);
//
// 	int result = is_triangle_contact(a, b);
//
// 	printf("Result = %d\n false = %d / true = %d\n", result, BOOL_FALSE, BOOL_TRUE);
// 	return (0);
// }

int main(int argc, char **argv)
{

	if (argc != 1)
		error_exit(-1, "Bad argument");

	start_sdl(); //initialisation de la SDL

	t_window *win;
	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

	t_engine *engine = initialize_t_engine();

	t_color		list_color[8];

	list_color[0] = create_t_color(0.2, 0.2, 0.2, 1.0);
	list_color[1] = create_t_color(0.2, 0.9, 0.9, 1.0);
	list_color[2] = create_t_color(0.9, 0.2, 0.9, 1.0);
	list_color[3] = create_t_color(0.9, 0.9, 0.2, 1.0);
	list_color[4] = create_t_color(0.2, 0.2, 0.9, 1.0);
	list_color[5] = create_t_color(0.2, 0.9, 0.2, 1.0);
	list_color[6] = create_t_color(0.9, 0.2, 0.2, 1.0);
	list_color[7] = create_t_color(0.9, 0.9, 0.9, 1.0);

	t_engine_add_mesh(engine, create_primitive_plane(create_t_vector3(7.5, -1, 7.5), create_t_vector3(10, 0, 10), NULL, 0.0));
	t_mesh_set_visibility(t_engine_get_mesh(engine, 0), BOOL_FALSE);

	int size_x = 1; //nombre de mesh (cube)
	int size_y = 1; //nombre de mesh (cube)
	int height = 1;
	float size = 1;
	int range = 50;
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			int h = 1;

			t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(j, h, i), create_t_vector3(size, size, size), NULL, 30.0));
			t_mesh *mesh = t_engine_get_mesh(engine, j + i * size_x + 1);
			t_mesh_set_color(mesh, list_color[2]);
		}
	}
	for (i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			int h = 2;

			t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(j+ 0.02, h + 0.02, i ), create_t_vector3(size, size, size), NULL, 3.0));
			t_mesh *mesh = t_engine_get_mesh(engine, j + i * size_x + 1);
			t_mesh_set_color(mesh, list_color[4]);
		}
	}
	t_mesh *mesh = t_engine_get_mesh(engine, 1);
	t_mesh_set_color(mesh, list_color[3]);
	mesh = t_engine_get_mesh(engine, 2);
	t_mesh_set_color(mesh, list_color[5]);
	t_engine_place_camera(engine, create_t_vector3(-size_x, height / 2, size_y));
	t_engine_camera_look_at(engine, t_mesh_list_get(engine->physic_engine->mesh_list, (size_x / 2) + (size_x * (size_y / 2)))->pos);

	while (engine->playing == 1)
	{
		t_engine_apply_physic(engine);

		t_engine_handle_camera(engine);

		prepare_screen(win, engine->cam, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

		t_engine_draw_mesh(engine, win);

		render_screen(win, engine->cam); // affiche la fenetre

		t_engine_handle_event(engine);
	}
	return (0);
}
