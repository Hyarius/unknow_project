#include "unknow_project.h"

t_vector2 axe_x;
t_vector2 axe_y;
t_vector2 axe_z;

t_vector2 put_vertex_on_screen(t_window *p_win, t_vector3 vertex)
{
	t_vector2 result = create_t_vector2(vertex.x * axe_x.x + vertex.y * axe_y.x + vertex.z * axe_z.x + 700,
										vertex.x * axe_x.y + vertex.y * axe_y.y + vertex.z * axe_z.y + 500);

	return (result);
}

int main(int argc, char **argv)
{
	if (argc != 1)
		error_exit(-1, "Bad argument");

	start_sdl();

	t_window *win;
	win = initialize_t_window(argv[0], 1840, 1220);

	axe_x = create_t_vector2(100, 0);
	axe_y = create_t_vector2(-50, -50);
	axe_z = create_t_vector2(0, -100);

	SDL_Event event;
	int play = 1;
	int state = 1;

	t_triangle_list	*t;
	t_color_list	*c;

	t = initialize_t_triangle_list();
	c = initialize_t_color_list();

	t_mesh mesh;

	mesh = create_t_mesh();

	t_mesh_add_point(&mesh, create_t_vector3(0, 0, 0));
	t_mesh_add_point(&mesh, create_t_vector3(3, 0, 0));
	t_mesh_add_point(&mesh, create_t_vector3(0, 3, 0));
	t_mesh_add_point(&mesh, create_t_vector3(3, 3, 0));

	t_mesh_add_point(&mesh, create_t_vector3(0, 0, 3));
	t_mesh_add_point(&mesh, create_t_vector3(3, 0, 3));
	t_mesh_add_point(&mesh, create_t_vector3(0, 3, 3));
	t_mesh_add_point(&mesh, create_t_vector3(3, 3, 3));

	t_mesh_set_color(&mesh, create_t_color_from_int(255, 0, 0, 255));
	t_mesh_set_color(&mesh, create_t_color_from_int(0, 255, 0, 255));
	t_mesh_set_color(&mesh, create_t_color_from_int(0, 0, 255, 255));
	t_mesh_set_color(&mesh, create_t_color_from_int(125, 125, 125, 255));
	t_mesh_set_color(&mesh, create_t_color_from_int(0, 0, 0, 255));
	t_mesh_set_color(&mesh, create_t_color_from_int(255, 255, 255, 255));

	t_mesh_set_face(&mesh, 7, 3, 5);
	t_mesh_set_face(&mesh, 5, 3, 1);
	t_mesh_set_face(&mesh, 0, 4, 2);
	t_mesh_set_face(&mesh, 2, 4, 6);
	t_mesh_set_face(&mesh, 4, 0, 5);
	t_mesh_set_face(&mesh, 5, 0, 1);
	t_mesh_set_face(&mesh, 6, 2, 7);
	t_mesh_set_face(&mesh, 7, 2, 3);
	t_mesh_set_face(&mesh, 6, 4, 7);
	t_mesh_set_face(&mesh, 7, 4, 5);
	t_mesh_set_face(&mesh, 2, 0, 3);
	t_mesh_set_face(&mesh, 3, 0, 1);

	prepare_screen(win, create_t_color(0.2f, 0.2f, 0.2f, 1.0f), state);

	draw_t_mesh(win, create_t_vector3(0, 0, 0), &mesh);

	render_screen(win, state);

	while (play == 1)
	{
		if (SDL_PollEvent(&event) == 1)
		{
			if (event.type == SDL_QUIT)
				play = 0;
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
				play = 0;
		}
	}
	return (0);
}
