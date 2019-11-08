#include "unknow_project.h"

t_vector3	get_normal(t_vector3 pos, t_vector3 direction, t_mesh *mesh)
{
	int 		k;
	t_line		line;
	t_vector3	intersection;

	k = -1;
	direction = mult_vector3_by_float(direction, 10.0);
	line = create_t_line(pos, add_vector3_to_vector3(pos, direction));
	while (++k < mesh->faces->size)
	{
		if (intersect_triangle_by_segment(compose_t_triangle_from_t_mesh
				(mesh, t_face_list_get(mesh->faces, k)->index_vertices),
				t_face_list_get(mesh->faces, k)->normale, line,
				&intersection) == BOOL_TRUE)
			return (t_face_list_get(mesh->faces, k)->normale);
	}
	return (create_t_vector3(0.0, 0.0, 0.0));
}

t_mesh		place_mesh(t_vector3 ray, t_vector3 pos)
{
	t_mesh mesh;

	if (ray.x > 0)
	{
		ray.x = round_float(ray.x, 2);
		ray.x = ray.x * 10.0 + pos.x;
	}
	else
	{
		ray.x = round_float(ray.x, 2);
		ray.x = ray.x * 10.0 + pos.x;
	}
	if (ray.y > 0)
	{
		ray.y = round_float(ray.y, 2);
		ray.y = ray.y * 10.0 + pos.y;
	}
	else
	{
		ray.y = round_float(ray.y, 2);
		ray.y = ray.y * 10.0 + pos.y;
	}
	if (ray.z > 0)
	{
		ray.z = round_float(ray.z, 2);
		ray.z = ray.z * 10.0 + pos.z;
	}
	else
	{
		ray.z = round_float(ray.z, 2);
		ray.z = ray.z * 10.0 + pos.z;
	}
	mesh = create_primitive_cube(ray, create_t_vector3(1.0, 1.0, 1.0), NULL, 0.0);
	return(mesh);
}

void		map_editor(t_camera *main_camera, t_gui *gui, t_engine *engine)
{
	t_mesh		*target;
	t_mesh		mesh;
	t_vector3	normal;
	static t_color    *color_armor = NULL;

	if (color_armor == NULL)
		color_armor = initialize_t_color(0.3, 0.3, 1.0, 1.0);

	t_view_port_clear_buffers(main_camera->view_port);
	draw_rectangle_color_cpu_front(main_camera->view_port, create_t_rectangle(create_t_vector2(0.0, 0.0), create_t_vector2(0.005, 0.01)), color_armor);
	draw_buffer_opengl(main_camera->view_port->window, main_camera->view_port->window->color_data);
	if (t_mouse_state(engine->user_engine->mouse) == 2)
	{
		target = cast_ray(engine, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, "Player");
		if (target == NULL)
		{
			mesh = place_mesh(t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, t_camera_list_get(engine->visual_engine->camera_list, 0)->pos);
			t_mesh_set_color(&mesh, create_t_color(1.0, 1.0, 1.0, 1.0));
			t_mesh_set_name(&mesh, "cube");
			t_engine_add_mesh(engine, mesh);
		}
		else
		{
			normal = get_normal(t_camera_list_get(engine->visual_engine->camera_list, 0)->pos, t_camera_list_get(engine->visual_engine->camera_list, 0)->forward, target);
			if (t_vector3_equal(round_t_vector3(normal, 2), round_t_vector3(target->forward, 2)) == BOOL_TRUE)
				mesh = create_primitive_cube(create_t_vector3(target->pos.x - 1.0, target->pos.y, target->pos.z), create_t_vector3(1.0, 1.0, 1.0), NULL, 0.0);
			else if (t_vector3_equal(round_t_vector3(normal, 2), round_t_vector3(inv_t_vector3(target->forward), 2)) == BOOL_TRUE)
				mesh = create_primitive_cube(create_t_vector3(target->pos.x + 1.0, target->pos.y, target->pos.z), create_t_vector3(1.0, 1.0, 1.0), NULL, 0.0);
			else if (t_vector3_equal(round_t_vector3(normal, 2), round_t_vector3(target->up, 2)) == BOOL_TRUE)
				mesh = create_primitive_cube(create_t_vector3(target->pos.x, target->pos.y - 1.0, target->pos.z), create_t_vector3(1.0, 1.0, 1.0), NULL, 0.0);
			else if (t_vector3_equal(round_t_vector3(normal, 2), round_t_vector3(inv_t_vector3(target->up), 2)) == BOOL_TRUE)
				mesh = create_primitive_cube(create_t_vector3(target->pos.x, target->pos.y + 1.0, target->pos.z), create_t_vector3(1.0, 1.0, 1.0), NULL, 0.0);
			else if (t_vector3_equal(round_t_vector3(normal, 2), round_t_vector3(target->right, 2)) == BOOL_TRUE)
				mesh = create_primitive_cube(create_t_vector3(target->pos.x, target->pos.y, target->pos.z + 1.0), create_t_vector3(1.0, 1.0, 1.0), NULL, 0.0);
			else if (t_vector3_equal(round_t_vector3(normal, 2), round_t_vector3(inv_t_vector3(target->right), 2)) == BOOL_TRUE)
				mesh = create_primitive_cube(create_t_vector3(target->pos.x, target->pos.y, target->pos.z - 1.0), create_t_vector3(1.0, 1.0, 1.0), NULL, 0.0);
			t_mesh_set_color(&mesh, create_t_color(1.0, 1.0, 1.0, 1.0));
			t_mesh_set_name(&mesh, "cube");
			t_engine_add_mesh(engine, mesh);
		}
	}
}
