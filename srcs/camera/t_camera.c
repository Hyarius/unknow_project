#include "unknow_project.h"

t_camera	create_t_camera(t_window *p_win, t_vector3 p_pos, float p_fov, t_vector2 p_dist)
{
	t_camera result;

	result.pos = p_pos;
	result.fov = p_fov;
	result.near = p_dist.x;
	result.far = p_dist.y;

	result.model = create_t_matrix();
	result.view = t_camera_look_at(&result, create_t_vector3(0, 0, 1));
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

t_matrix		t_camera_look_at(t_camera *cam, t_vector3 target)
{
	t_matrix 	result;

	result = create_t_matrix();

	t_vector3 zaxis = normalize_t_vector3(create_t_vector3(target.x - cam->pos.x, target.y - cam->pos.y, target.z - cam->pos.z));
	t_vector3 xaxis = normalize_t_vector3(cross_t_vector3(zaxis, create_t_vector3(0, 1, 0)));
	t_vector3 yaxis = cross_t_vector3(xaxis, zaxis);

	zaxis.x = zaxis.x * -1;
	zaxis.y = zaxis.y * -1;
	zaxis.z = zaxis.z * -1;

	result.value[0][0] = xaxis.x;
	result.value[1][0] = xaxis.y;
	result.value[2][0] = xaxis.z;
	result.value[3][0] = - (dot_t_vector3(xaxis, cam->pos));

	result.value[0][1] = yaxis.x;
	result.value[1][1] = yaxis.y;
	result.value[2][1] = yaxis.z;
	result.value[3][1] = - (dot_t_vector3(yaxis, cam->pos));

	result.value[0][2] = zaxis.x;
	result.value[1][2] = zaxis.y;
	result.value[2][2] = zaxis.z;
	result.value[3][2] = - (dot_t_vector3(zaxis, cam->pos));

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
