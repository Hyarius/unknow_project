#include "unknow_project.h"

t_camera	create_t_camera(t_window *p_win, t_vector3 p_pos, float p_fov, t_vector2 p_dist)
{
	t_camera result;

	result.pos = p_pos; //position de la camera
	result.fov = p_fov; // champ de vision
	result.near = p_dist.x; //distance la plus proche pour voir un objet
	result.far = p_dist.y; // distance la plus eloigne pour voir un objet
	result.angle = create_t_vector3(0, 0, 0); //angle a laquel on voit l'objet
	result.speed = 0.1f;

	result.model = create_t_matrix(); // creation de la matrice d'identite permettant de faire les calculs matriciel par la suite
	t_camera_look_at(&result); //calcul de l'angle de la camera
	result.view = t_camera_compute_view(&result); //calcul de la matrice de vue
	result.projection = compute_projection_matrix(p_win, &result); //calcul de la matrice de projection

	result.sun_direction = normalize_t_vector3(create_t_vector3(0, -1, -0.4));

	result.triangle_list = create_t_triangle_list();

	result.color_list = create_t_color_list();

	return (result);
}

t_camera	*initialize_t_camera(t_window *p_win, t_vector3 p_pos, float p_fov, t_vector2 p_dist)
{
	t_camera *result;

	if (!(result = (t_camera *)malloc(sizeof(t_camera))))
		error_exit(-31, "Can't malloc a t_camera");

	*result = create_t_camera(p_win, p_pos, p_fov, p_dist);

	return (result);
}

void			t_camera_look_at(t_camera *cam)
{
	t_vector3 zaxis = normalize_t_vector3(create_t_vector3(cos(degree_to_radius(cam->angle.z)) * sin(degree_to_radius(cam->angle.y)),
						sin(degree_to_radius(cam->angle.z)),
						cos(degree_to_radius(cam->angle.z)) * cos(degree_to_radius(cam->angle.y))));
	t_vector3 xaxis = normalize_t_vector3(create_t_vector3(sin(degree_to_radius(cam->angle.y) - 3.14f / 2.0f),
						0,
						cos(degree_to_radius(cam->angle.y) - 3.14f / 2.0f)));
	t_vector3 yaxis = normalize_t_vector3(cross_t_vector3(xaxis, zaxis));

	cam->forward = zaxis;
	cam->right = xaxis;
	cam->up = inv_t_vector3(yaxis);
}

t_matrix		t_camera_compute_view(t_camera *cam) //calcul de la matrice de vue
{
	t_matrix	result;
	t_vector3	inv_forward;

	result = create_t_matrix();

	inv_forward = mult_vector3_by_vector3(cam->forward, create_t_vector3(-1, -1, -1));

	result.value[0][0] = cam->right.x;
	result.value[1][0] = cam->right.y;
	result.value[2][0] = cam->right.z;
	result.value[3][0] = - (dot_t_vector3(cam->right, cam->pos));

	result.value[0][1] = cam->up.x;
	result.value[1][1] = cam->up.y;
	result.value[2][1] = cam->up.z;
	result.value[3][1] = - (dot_t_vector3(cam->up, cam->pos));

	result.value[0][2] = inv_forward.x;
	result.value[1][2] = inv_forward.y;
	result.value[2][2] = inv_forward.z;
	result.value[3][2] = - (dot_t_vector3(inv_forward, cam->pos));

	return (result);
}

t_matrix		compute_projection_matrix(t_window *p_win, t_camera *p_cam) //calcul de la matrice de projection
{
	t_matrix	result;

	result = create_t_matrix_empty();

	float n = p_cam->near;
	float r = 1.0 / (tan(degree_to_radius(p_cam->fov / 2)));
	float f = p_cam->far;
	float t = 1.0 / (tan(degree_to_radius(p_cam->fov / 2))) / (4.0 / 3.0);


	result.value[0][0] = t;

	result.value[1][1] = r;

	result.value[2][2] = -(f) / (f - n);
	result.value[2][3] = -1;

	result.value[3][2] = -(2 * f * n) / (f - n);

	return (result);
}

void		compute_t_camera(t_camera *cam)
{
	cam->view = t_camera_compute_view(cam);
}

t_vector3		apply_t_camera(t_vector3 *src, t_matrix *mat) // applique la position de la camera
{
	t_vector3	result;
	float		delta;

	result.x = src->x * mat->value[0][0] + src->y * mat->value[1][0] + src->z * mat->value[2][0] + mat->value[3][0];
	result.y = src->x * mat->value[0][1] + src->y * mat->value[1][1] + src->z * mat->value[2][1] + mat->value[3][1];
	result.z = src->x * mat->value[0][2] + src->y * mat->value[1][2] + src->z * mat->value[2][2] + mat->value[3][2];
	delta = src->x * mat->value[0][3] + src->y * mat->value[1][3] + src->z * mat->value[2][3] + mat->value[3][3];

	if (delta < 0)
	{
		result.x /= delta;
		result.y /= delta;
		result.z /= delta;
	}

	return (result);
}

void			t_camera_change_view(t_camera *cam, t_vector3 delta_angle)
{
	cam->angle = add_vector3_to_vector3(cam->angle, delta_angle);
	t_camera_look_at(cam);
}

void			handle_t_camera_mouvement_by_key(t_camera *cam, t_keyboard *p_keyboard) // calcul du mouvement de la camera a la clavier
{
	if (get_key_state(p_keyboard, SDL_SCANCODE_S) == 1)
		cam->pos = add_vector3_to_vector3(cam->pos, mult_vector3_by_vector3(cam->forward, create_t_vector3(cam->speed, 0.0, cam->speed)));
	if (get_key_state(p_keyboard, SDL_SCANCODE_W) == 1)
		cam->pos = substract_vector3_to_vector3(cam->pos, mult_vector3_by_vector3(cam->forward, create_t_vector3(cam->speed, 0.0, cam->speed)));
	if (get_key_state(p_keyboard, SDL_SCANCODE_D) == 1)
		cam->pos = substract_vector3_to_vector3(cam->pos, mult_vector3_by_vector3(cam->right, create_t_vector3(cam->speed, 0.0, cam->speed)));
	if (get_key_state(p_keyboard, SDL_SCANCODE_A) == 1)
		cam->pos = add_vector3_to_vector3(cam->pos, mult_vector3_by_vector3(cam->right, create_t_vector3(cam->speed, 0.0, cam->speed)));
	if (get_key_state(p_keyboard, SDL_SCANCODE_SPACE) == 1)
		cam->pos = substract_vector3_to_vector3(cam->pos, create_t_vector3(0.0, -cam->speed, 0.0));
	if (get_key_state(p_keyboard, SDL_SCANCODE_LCTRL) == 1)
		cam->pos = add_vector3_to_vector3(cam->pos, create_t_vector3(0.0, -cam->speed, 0.0));
}

void			handle_t_camera_view_by_mouse(t_camera *cam, t_mouse *p_mouse) // calcul du mouvement de l'angle de la camera a la souris
{
	t_vector3	delta;

	delta = create_t_vector3(0, -(p_mouse->rel_pos.x / 10.0), p_mouse->rel_pos.y / 10.0);
	t_camera_change_view(cam, delta);
}

void			draw_triangle_from_camera_on_screen(t_window *p_win, t_camera *p_cam)
{
	t_triangle	*triangle;
	t_color		color_black = {0.0, 0.0, 0.0, 1.0};
	t_line line;
	int i;

	i = 0;
	while (i < p_cam->triangle_list.size)
	{
		triangle = t_triangle_list_get(&(p_cam->triangle_list), i);
		//draw_triangle_color_opengl(p_win, triangle, t_color_list_get(&(p_cam->color_list), i));
		draw_triangle_color_cpu(p_win, triangle, t_color_list_get(&(p_cam->color_list), i));

		//
		// line.a.x = triangle->a.x;
		// line.a.y = triangle->a.y;
		// line.b.x = triangle->b.x;
		// line.b.y = triangle->b.y;
		// draw_line_color_opengl(p_win, &(line), &color_black); //draw le trait entre deux points
		//
		// line.a.x = triangle->a.x;
		// line.a.y = triangle->a.y;
		// line.b.x = triangle->c.x;
		// line.b.y = triangle->c.y;
		//
		// draw_line_color_opengl(p_win, &(line), &color_black); //draw le trait entre deux points
		//

		i++;
	}
}
