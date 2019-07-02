#include "unknow_project.h"

// int main(int argc, char **argv)
// {
// 	if (argc != 1)
// 		error_exit(-1, "Bad argument");

// 	start_sdl(); //initialisation de la SDL

// 	t_window *win;
// 	win = initialize_t_window(argv[0], 1840, 1220);	//creation et initialisation de la window
// 	int play = 0;
// 	SDL_Event event;

// 	t_vector3 point[4];
// 	point[0] = create_t_vector3(300.0, 100.0, 10.0);
// 	point[1] = create_t_vector3(100.0, 200.0, 10.0);
// 	point[2] = create_t_vector3(300.0, 300.0, 10.0);
// 	t_triangle triangle = create_t_triangle(convert_screen_to_opengl(win, point[0]), convert_screen_to_opengl(win, point[1]), convert_screen_to_opengl(win, point[2]));

// 	t_triangle uv_triangle = create_t_triangle(create_t_vector3(0, 0, 0), create_t_vector3(1, 0, 0), create_t_vector3(0, 1, 0));
// 	t_texture *texture = png_load("ressources/assets/texture/cube_number.png");
// 	t_uv uv = create_t_uv(uv_triangle, texture);

// 	while (play == 0)
// 	{
// 		prepare_screen(win, NULL, create_t_color(0.2, 0.2, 0.2, 1.0));

// 		draw_triangle_depth_cpu(win, &triangle, (triangle.a.z >= triangle.c.z ? triangle.a.z : triangle.c.z));

// 		render_screen(win, NULL);

// 		if(SDL_PollEvent(&event) == 1)
// 		{
// 			if (event.type == SDL_QUIT)
// 				play = 1;
// 			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
// 				play = 1;
// 			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r)
// 			{
// 				triangle.a.z -= 0.1;

// 				triangle.c.z += 0.1;

// 				if (triangle.c.z <= 0)
// 					triangle.c.z = 0.0001;

// 				printf("Distance a decrease -> %f\n", triangle.c.z);
// 			}
// 			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_t)
// 			{
// 				triangle.a.z += 0.1;

// 				triangle.c.z -= 0.1;

// 				if (triangle.c.z <= 0)
// 					triangle.c.z = 0.0001;

// 				printf("Distance a increase -> %f\n", triangle.c.z);
// 			}
// 		}
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

	t_texture *texture = png_load("ressources/assets/texture/cube_number.png");


	t_engine	*engine = initialize_t_engine();

	t_engine_add_mesh(engine, create_primitive_plane(create_t_vector3(1.0, 0, 1.0), create_t_vector3(4.0, 0.0, 4.0), NULL, 0.0));

	t_engine_add_mesh(engine, create_primitive_cube(create_t_vector3(2.0, 2.0, 0.5), create_t_vector3(1.0, 1.0, 1.0), NULL, 100.0));

	t_mesh *mesh = t_engine_get_mesh(engine, 1);

	t_mesh_set_color(mesh, create_t_color(0.5, 0.6, 0.8 ,1.0));

	t_mesh_add_force(mesh, create_t_vector3(-0.01, 0.0, 0.0));

	t_engine_place_camera(engine, create_t_vector3(1, 1, 1));

	t_camera_look_at_point(engine->cam, create_t_vector3(0, 0, 0));

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