#include "unknow_project.h"

t_camera	create_t_camera(t_window *p_win, t_vector3 p_pos, float p_fov, t_vector2 p_dist)
{
	t_camera result;

	result.pos = p_pos;
	result.fov = p_fov;
	result.near = p_dist.x;
	result.far = p_dist.y;
	result.angle = create_t_vector3(0, 0, 0);

	result.model = create_t_matrix();
	t_camera_look_at(&result);
	result.view = t_camera_compute_view(&result);
	result.projection = compute_projection_matrix(p_win, &result);

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
	t_vector3 yaxis = cross_t_vector3(xaxis, zaxis);

	cam->forward = zaxis;
	cam->right = xaxis;
	cam->up = yaxis;
}

t_matrix		t_camera_compute_view(t_camera *cam)
{
	t_matrix	result;
	t_vector3	inv_forward;

	/*printf("-------------------------------------\n");
	print_t_vector3(cam->forward, "cam->forward: ");endl();
	print_t_vector3(cam->right, "cam->right: ");endl();
	print_t_vector3(cam->up, "cam->up: ");endl();*/

	result = create_t_matrix();

	inv_forward = mult_vector3_to_vector3(cam->forward, create_t_vector3(-1, -1, -1));

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

t_matrix		compute_projection_matrix(t_window *p_win, t_camera *p_cam)
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

t_matrix		compute_t_camera(t_camera *cam)
{
	t_matrix result;

	cam->view = t_camera_compute_view(cam);
	result = mult_matrix_by_matrix(&(cam->projection), &(cam->view)); // Attention, danger
	result = mult_matrix_by_matrix(&(result), &(cam->model)); // tout a fait

	return (result);
}

t_vector3		apply_t_camera(t_vector3 *src, t_matrix *mat)
{
	t_vector3	result;
	float		delta;

	result.x = src->x * mat->value[0][0] + src->y * mat->value[1][0] + src->z * mat->value[2][0] + mat->value[3][0];
	result.y = src->x * mat->value[0][1] + src->y * mat->value[1][1] + src->z * mat->value[2][1] + mat->value[3][1];
	result.z = src->x * mat->value[0][2] + src->y * mat->value[1][2] + src->z * mat->value[2][2] + mat->value[3][2];
	delta = src->x * mat->value[0][3] + src->y * mat->value[1][3] + src->z * mat->value[2][3] + mat->value[3][3];

	if (delta != 0)
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

void			handle_t_camera_mouvement_by_key(t_camera *cam, int key)
{
	if (key == SDLK_DOWN)
		cam->pos = substract_vector3_to_vector3(cam->pos, cam->forward);
	if (key == SDLK_UP)
		cam->pos = add_vector3_to_vector3(cam->pos, cam->forward);
	if (key == SDLK_RIGHT)
		cam->pos = add_vector3_to_vector3(cam->pos, cam->right);
	if (key == SDLK_LEFT)
		cam->pos = substract_vector3_to_vector3(cam->pos, cam->right);
	if (key == SDLK_SPACE)
		cam->pos = add_vector3_to_vector3(cam->pos, cam->up);
	if (key == SDLK_LSHIFT)
		cam->pos = substract_vector3_to_vector3(cam->pos, cam->up);
}

void			handle_t_camera_view_by_key(t_camera *cam, int key)
{
	if (key == SDLK_d)
		t_camera_change_view(cam, create_t_vector3(0, -5, 0));
	if (key == SDLK_a)
		t_camera_change_view(cam, create_t_vector3(0, 5, 0));
	if (key == SDLK_w)
		t_camera_change_view(cam, create_t_vector3(0, 0, 5));
	if (key == SDLK_s)
		t_camera_change_view(cam, create_t_vector3(0, 0, -5));
}

void			handle_t_camera_view_by_mouse(t_camera *cam, t_mouse *p_mouse)
{
	t_vector3	delta;

	delta = create_t_vector3(0, p_mouse->rel_pos.x / 10.0, p_mouse->rel_pos.y / 10.0);
	t_camera_change_view(cam, delta);
}