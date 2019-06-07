#include "unknow_project.h"

extern float dist_max;
extern float dist_min;

t_camera	create_t_camera(t_vector3 p_pos, float p_fov, t_vector2 p_dist)
{
	t_camera result;

	result.pos = p_pos; //position de la camera
	result.fov = p_fov; // champ de vision
	result.near = p_dist.x; //distance la plus proche pour voir un objet
	result.far = p_dist.y; // distance la plus eloigne pour voir un objet
	result.angle = create_t_vector3(0, 0, 0); // angle a laquel on voit l'objet
	result.speed = 0.1f; // vitesse de deplacement
	result.running = 3.4f; // action de courir
	result.slowing = 1.0f; // ralentissement pour le recul

	result.model = create_t_matrix(); // creation de la matrice d'identite permettant de faire les calculs matriciel par la suite
	t_camera_look_at(&result); //calcul de l'angle de la camera
	result.view = t_camera_compute_view(&result); //calcul de la matrice de vue
	result.projection = compute_projection_matrix(&result); //calcul de la matrice de projection
	result.sun_direction = normalize_t_vector3(create_t_vector3(0.0, -1, -0.4)); // direction de la lumiere
	result.triangle_color_list = create_t_triangle_list(); // list des triangles
	result.color_list = create_t_color_list(); //list des couleurs

	result.triangle_texture_list = create_t_triangle_list();
	result.uv_list = create_t_uv_list();
	result.darkness_list = create_t_color_list();

	return (result);
}

t_camera	*initialize_t_camera(t_vector3 p_pos, float p_fov, t_vector2 p_dist)
{
	t_camera *result;

	if (!(result = (t_camera *)malloc(sizeof(t_camera))))
		error_exit(-31, "Can't malloc a t_camera");

	*result = create_t_camera(p_pos, p_fov, p_dist);

	return (result);
}

void		t_camera_look_at(t_camera *cam) // calcul de l'angle de vue de la camera (forward, right, up)
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

t_matrix	t_camera_compute_view(t_camera *cam) //calcul de la matrice de vue
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

void		t_camera_change_fov(t_camera *cam, float delta)
{
	if (delta > 1 && cam->fov >= 60)
		cam->fov /= delta;
	if (delta < 1 && cam->fov < 90)
		cam->fov /= delta;
}

t_matrix	compute_projection_matrix(t_camera *p_cam) //calcul de la matrice de projection
{
	t_matrix	result;
	float		n;
	float		r;
	float		f;
	float		t;

	result = create_t_matrix_empty();
	n = p_cam->near;
	r = 1.0 / (tan(degree_to_radius(p_cam->fov / 2)));
	f = p_cam->far;
	t = 1.0 / (tan(degree_to_radius(p_cam->fov / 2))) / (4.0 / 3.0); // changer le (4/3) en (16/9) va changer le ratio de l'ecran, changeant l'apparence des cubes a l'ecran
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
	cam->projection = compute_projection_matrix(cam);
}

t_vector3	apply_t_camera(t_vector3 *src, t_matrix *mat) // applique la position de la camera
{
	t_vector3	result; // x -> coord a l'ecran en x de ce point / y -> coord a l'ecran en y de ce point / z -> distance reelle entre ce point et l'oeil de la camera
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
	result.z = sqrt(src->x * src->x + src->y * src->y + src->z * src->z);
	return (result);
}

void		t_camera_change_view(t_camera *cam, t_vector3 delta_angle)
{
	cam->angle = add_vector3_to_vector3(cam->angle, delta_angle);
	clamp_float_value(-89, &(cam->angle.z), 89);
	t_camera_look_at(cam);
}

void		handle_t_camera_mouvement_by_key(t_camera *cam, t_keyboard *p_keyboard) // calcul du mouvement de la camera a la clavier
{
	t_vector3	tmp;

	if (get_key_state(p_keyboard, SDL_SCANCODE_LSHIFT) == 0)
		tmp = create_t_vector3(cam->speed, 0.0, cam->speed);
	else
		tmp = create_t_vector3(cam->speed * cam->running, 0.0, cam->speed * cam->running);
	if (get_key_state(p_keyboard, SDL_SCANCODE_S) == 1)
	{
		tmp = create_t_vector3(cam->speed / cam->slowing, 0.0, cam->speed / cam->slowing);
		cam->pos = add_vector3_to_vector3(cam->pos, mult_vector3_by_vector3(normalize_t_vector3(mult_vector3_by_vector3(cam->forward, create_t_vector3(1.0, 0.0, 1.0))), tmp));
	}
	if (get_key_state(p_keyboard, SDL_SCANCODE_W) == 1)
		cam->pos = substract_vector3_to_vector3(cam->pos, mult_vector3_by_vector3(normalize_t_vector3(mult_vector3_by_vector3(cam->forward, create_t_vector3(1.0, 0.0, 1.0))), tmp));
	if (get_key_state(p_keyboard, SDL_SCANCODE_D) == 1)
		cam->pos = substract_vector3_to_vector3(cam->pos, mult_vector3_by_vector3(cam->right, tmp));
	if (get_key_state(p_keyboard, SDL_SCANCODE_A) == 1)
		cam->pos = add_vector3_to_vector3(cam->pos, mult_vector3_by_vector3(cam->right, tmp));
	if (get_key_state(p_keyboard, SDL_SCANCODE_SPACE) == 1)
		cam->pos = substract_vector3_to_vector3(cam->pos, create_t_vector3(0.0, -cam->speed, 0.0));
	if (get_key_state(p_keyboard, SDL_SCANCODE_LCTRL) == 1)
		cam->pos = add_vector3_to_vector3(cam->pos, create_t_vector3(0.0, -cam->speed, 0.0));
}

void		handle_t_camera_view_by_mouse(t_camera *cam, t_mouse *p_mouse) // calcul du mouvement de l'angle de la camera a la souris
{
	t_vector3	delta;

	delta = create_t_vector3(0, -(p_mouse->rel_pos.x / 10.0), p_mouse->rel_pos.y / 10.0);
	t_camera_change_view(cam, delta);
}

void 		t_camera_calc_depth(t_window *p_win, t_camera *p_cam)
{
	t_triangle	triangle;
	int			i;

	i = 0;
	while (i < p_cam->triangle_color_list.size)
	{
		triangle = t_triangle_list_at(&(p_cam->triangle_color_list), i);
		if (triangle.a.z > dist_max)
			dist_max = triangle.a.z;
		if (triangle.b.z > dist_max)
			dist_max = triangle.b.z;
		if (triangle.c.z > dist_max)
			dist_max = triangle.c.z;

		if (triangle.a.z < dist_min)
			dist_min = triangle.a.z;
		if (triangle.b.z < dist_min)
			dist_min = triangle.b.z;
		if (triangle.c.z < dist_min)
			dist_min = triangle.c.z;
		i++;
	}

	i = 0;
	while (i < p_cam->triangle_texture_list.size)
	{
		triangle = t_triangle_list_at(&(p_cam->triangle_texture_list), i);
		if (triangle.a.z > dist_max)
			dist_max = triangle.a.z;
		if (triangle.b.z > dist_max)
			dist_max = triangle.b.z;
		if (triangle.c.z > dist_max)
			dist_max = triangle.c.z;

		if (triangle.a.z < dist_min)
			dist_min = triangle.a.z;
		if (triangle.b.z < dist_min)
			dist_min = triangle.b.z;
		if (triangle.c.z < dist_min)
			dist_min = triangle.c.z;
		i++;
	}
}

void		draw_depth_from_camera_on_screen(t_window *p_win, t_camera *p_cam)
{
	t_triangle	triangle;
	t_line		line1;
	t_line		line2;
	int			i;

	dist_min = 9999.0f;
	dist_max = 0.0f;

	t_camera_calc_depth(p_win, p_cam);

	i = 0;
	while (i < p_cam->triangle_color_list.size)
	{
		triangle = t_triangle_list_at(&(p_cam->triangle_color_list), i);
		draw_triangle_depth_cpu(p_win, &triangle, t_color_list_get(&(p_cam->color_list), i));
		i++;
	}
}

void		draw_triangle_from_camera_on_screen(t_window *p_win, t_camera *p_cam)
{
	t_triangle	*triangle;
	t_uv		*uv;
	t_color		*color;
	t_color		*darkness;
	int			i;

	i = 0;
	while (i < p_cam->triangle_color_list.size)
	{
		triangle = t_triangle_list_get(&(p_cam->triangle_color_list), i);
		color = t_color_list_get(&(p_cam->color_list), i);
		draw_triangle_color_cpu(p_win, triangle, color);
		i++;
	}

	i = 0;
	while (i < p_cam->triangle_texture_list.size)
	{
		triangle = t_triangle_list_get(&(p_cam->triangle_texture_list), i);
		uv = t_uv_list_get(&(p_cam->uv_list), i);
		darkness = t_color_list_get(&(p_cam->darkness_list), i);
		draw_triangle_texture_cpu(p_win, triangle, uv, darkness);
		i++;
	}
}
