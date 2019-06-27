#include "unknow_project.h"

// int main(int argc, char **argv)
// {
// 	int nb_triangle = 7;
// 	t_triangle triangle[7];
// 	t_vector3 p[21];

// 	p[0] = create_t_vector3(0, 0, 0);//a
// 	p[1] = create_t_vector3(1, 0, 0);//a
// 	p[2] = create_t_vector3(0, 1, 0);//a

// 	p[3] = create_t_vector3(0, 0, 0);//a
// 	p[4] = create_t_vector3(1, 0, 0);//a
// 	p[5] = create_t_vector3(0, 0, 1);//a

// 	p[6] = create_t_vector3(0.5, 0.5, 0.5);//a
// 	p[7] = create_t_vector3(0, 0, -0.5);//a
// 	p[8] = create_t_vector3(1, 0, -0.5);//a

// 	p[9] = create_t_vector3(0, 0, 0);//a
// 	p[10] = create_t_vector3(0, 1, 0);//a
// 	p[11] = create_t_vector3(0, 0.5, -1);//a

// 	p[12] = create_t_vector3(0, 1, 0);//a
// 	p[13] = create_t_vector3(-1, 0, 0);//a
// 	p[14] = create_t_vector3(-1, 1, 0);//a

// 	p[15] = create_t_vector3(0, 0, 0.5);//a
// 	p[16] = create_t_vector3(1, 0, 0.5);//a
// 	p[17] = create_t_vector3(0, 1, 0.5);//a

// 	p[18] = create_t_vector3(-0.2, -0.5, 0.75);//a
// 	p[19] = create_t_vector3(0.8, -0.5, 0.75);//a
// 	p[20] = create_t_vector3(-0.2, 0.5, 0.75);//a

// 	for (int i = 0; i < nb_triangle; i++)
// 		triangle[i] = create_t_triangle(p[i * 3 + 0], p[i * 3 + 1], p[i * 3 + 2]);

// 	int result = is_triangle_contact(triangle[1], triangle[6]);

// 	printf("Result = %d\n", result);

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

	t_engine_place_camera(engine, create_t_vector3(0.5, 3, 3));
	t_engine_camera_look_at(engine, create_t_vector3(0.5, 0.5, 0.5));
	float size = 1;
	float velocity_max = 200;

	t_engine_add_mesh(engine, create_primitive_plane(create_t_vector3(0, 0, 0), create_t_vector3(size, size, size), NULL, 0.0));
	t_mesh *mesh = t_engine_get_mesh(engine, 0);
	t_mesh_set_color(mesh, create_t_color(0.2, 0.2, 1.0, 1.0));

	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(0.9, 1, 0), create_t_vector3(size / 2.0, size, size / 2.0), NULL, 10));
	mesh = t_engine_get_mesh(engine, 1);
	t_mesh_set_color(mesh, create_t_color(0.2, 0.2, 0.2, 1.0));

	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(1, 3, 1), create_t_vector3(size, size, size), NULL, 100));
	mesh = t_engine_get_mesh(engine, 2);
	t_mesh_set_color(mesh, create_t_color(0.2, 1.0, 0.2, 1.0));

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

// int		main(int argc, char **argv)
// {

// 	if (argc != 1)
// 		error_exit(-1, "Bad argument");

// 	start_sdl(); //initialisation de la SDL

// 	t_window *win;
// 	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

// 	t_engine *engine = initialize_t_engine();

// 	t_engine_add_mesh(engine, create_primitive_plane(create_t_vector3(7.5, -1, 7.5), create_t_vector3(10, 0, 10), NULL, 0.0));
// 	t_mesh_set_visibility(t_engine_get_mesh(engine, 0), BOOL_TRUE);

// 	float size = 1;

// 	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(0, 0, 0), create_t_vector3(size, size, size), NULL, 10.0));

// 	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(1, 5, 1), create_t_vector3(size, size, size), NULL, 2.0));

// 		while (engine->playing == 1)
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