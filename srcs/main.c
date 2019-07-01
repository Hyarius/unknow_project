#include "unknow_project.h"

int main(int argc, char **argv)
{

	if (argc != 1)
		error_exit(-1, "Bad argument");

	start_sdl(); //initialisation de la SDL

	t_window *win;
	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window
	int play = 0;
	SDL_Event event;

	t_vector3 point[3];
	point[0] = create_t_vector3(50.0, 50.0, 0.0);
	point[1] = create_t_vector3(250.0, 50.0, 0.0);
	point[2] = create_t_vector3(50.0, 250.0, 1.0);
	t_triangle triangle = create_t_triangle(convert_screen_to_opengl(win, point[0]), convert_screen_to_opengl(win, point[1]), convert_screen_to_opengl(win, point[2]));

	t_triangle uv_triangle = create_t_triangle(create_t_vector3(0, 0, 0), create_t_vector3(1, 0, 0), create_t_vector3(0, 1, 0));
	t_texture *texture = png_load("ressources/assets/texture/cube_number.png");
	t_uv uv = create_t_uv(uv_triangle, texture);

	prepare_screen(win, NULL, create_t_color(0.2, 0.2, 0.2, 1.0));

	draw_triangle_texture_cpu(win, &triangle, &uv);

	render_screen(win, NULL);

	while (play == 0)
	{
		if(SDL_PollEvent(&event) == 1)
		{
			if (event.type == SDL_QUIT)
				play = 1;
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
				play = 1;
		}
	}

	return (0);
}

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

// int main(int argc, char **argv)
// {
// 	if (argc != 1)
// 		error_exit(-1, "Bad argument");

// 	start_sdl(); //initialisation de la SDL

// 	t_window *win;
// 	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

// 	t_engine *engine = initialize_t_engine();

// 	t_engine_add_mesh(engine, create_primitive_plane(create_t_vector3(0, -1, 0), create_t_vector3(3, 0, 3), NULL, 0.0));
// 	t_mesh_set_visibility(t_engine_get_mesh(engine, 0), BOOL_TRUE);

// 	t_engine_place_camera(engine, create_t_vector3(3, 3, 3));
// 	t_engine_camera_look_at(engine, create_t_vector3(0, 0, 0));

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

// int main(int argc, char **argv)
// {
// 	if (argc != 1)
// 		error_exit(-1, "Bad argument");

// 	start_sdl(); //initialisation de la SDL

// 	t_window *win;
// 	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window

// 	t_texture *texture = png_load("ressources/assets/texture/cube_number.png");


// 	t_engine	*engine = initialize_t_engine();

// 	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(1.0, 1.0, 1.0), create_t_vector3(1.0, 1.0, 1.0), texture, 0.0));

// 	t_engine_place_camera(engine, create_t_vector3(0, 1, 0));

// 	t_camera_look_at_point(engine->cam, t_engine_get_mesh(engine, 0)->center);

// 	while (engine->playing == 1)
// 	{
// 		t_engine_handle_camera(engine);

// 		prepare_screen(win, engine->cam, create_t_color(0.2f, 0.2f, 0.2f, 1.0f)); // refresh de l'ecran avec les couleurs par default

// 		t_engine_draw_mesh(engine, win);

// 		render_screen(win, engine->cam); // affiche la fenetre

// 		t_engine_handle_event(engine);
// 	}
// 	return (0);
// }