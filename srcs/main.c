#include "unknow_project.h"

// int main(int argc, char **argv)
// {

// 	if (argc != 1)
// 		error_exit(-1, "Bad argument");

// 	start_sdl(); //initialisation de la SDL

// 	t_window *win;
// 	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

// 	t_engine *engine = initialize_t_engine();

// 	t_engine_place_camera(engine, create_t_vector3(0.5, 3, 3));
// 	t_engine_camera_look_at(engine, create_t_vector3(0.5, 0.5, 0.5));
// 	float size = 1;
// 	float velocity_max = 200;

// 	t_engine_add_mesh(engine, create_primitive_plane(create_t_vector3(0, 0, 0), create_t_vector3(size, size, size), NULL, 0.0));
// 	t_mesh *mesh = t_engine_get_mesh(engine, 0);
// 	t_mesh_set_color(mesh, create_t_color(0.2, 0.2, 1.0, 1.0));

// 	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(0.9, 3, 0), create_t_vector3(size / 2.0, size, size / 2.0), NULL, 10));
// 	mesh = t_engine_get_mesh(engine, 1);
// 	t_mesh_set_color(mesh, create_t_color(0.2, 0.2, 0.2, 1.0));

// 	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(1, 3, 1), create_t_vector3(size, size, size), NULL, 100));
// 	mesh = t_engine_get_mesh(engine, 2);
// 	t_mesh_set_color(mesh, create_t_color(0.2, 1.0, 0.2, 1.0));

// 	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-1.5, 3, -1.5), create_t_vector3(size / 2.0, 0.1, size / 2.0), NULL, 10));
// 	mesh = t_engine_get_mesh(engine, 3);
// 	t_mesh_set_color(mesh, create_t_color(0.2, 0.2, 1.0, 1.0));

// 	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(-0.8, 2, -0.8), create_t_vector3(size / 2.0, 0.1, size / 2.0), NULL, 10));
// 	mesh = t_engine_get_mesh(engine, 4);
// 	t_mesh_set_color(mesh, create_t_color(0.2, 0.2, 1.0, 1.0));

// 	while (engine->playing == 1)
// 	{
// 		t_engine_apply_physic(engine);

// 		t_engine_handle_camera(engine);

// 		prepare_screen(win, engine->cam, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

// 		t_engine_draw_mesh(engine, win);

// 		render_screen(win, engine->cam); // affiche la fenetre

// 		t_engine_handle_event(engine);
// 	}
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
	t_mesh_set_visibility(t_engine_get_mesh(engine, 0), BOOL_TRUE);

	int size_x = 10; //nombre de mesh (cube)
	int size_y = 10; //nombre de mesh (cube)
	int height = 3;
	float size = 0.8;
	int range = 50;
	int count = 1;
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			int h = height * 2;

			t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(j, h, i), create_t_vector3(size, size, size), NULL, 100.0));
			t_mesh *mesh = t_engine_get_mesh(engine, count);
			t_mesh_set_color(mesh, list_color[2]);
			count++;
		}
	}
	for (i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			int h = height * 4;

			t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(j + 0.2, h, i + 0.2 ), create_t_vector3(size, size, size), NULL, 100.0));
			t_mesh *mesh = t_engine_get_mesh(engine, count);
			t_mesh_set_color(mesh, list_color[4]);
			count++;
		}
	}
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