#include "unknow_project.h"

t_camera	create_t_camera(t_window *p_win, t_vector3 p_pos, float p_fov, t_vector2 p_dist)
{
	t_camera result;

	result.pos = p_pos;
	result.fov = p_fov;
	result.near = p_dist.x;
	result.far = p_dist.y;

	result.model = create_t_matrix();
	result.view = t_camera_look_at(&result, create_t_vector3(0, 1, 0));
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
	t_matrix 	tmp1;
	t_matrix 	tmp2;
	t_vector3	inv_pos;
	t_matrix	rot_z;

	rot_z = create_rotation_z_matrix(90);
	inv_pos = create_t_vector3(-cam->pos.x, -cam->pos.y, -cam->pos.z);

	cam->forward = create_t_vector3(target.x - cam->pos.x,
								target.y - cam->pos.y,
								target.z - cam->pos.z);
	cam->right = mult_vector3_by_matrix(&(cam->forward), &rot_z);
	cam->up = cross_vector3(&(cam->forward), &(cam->right));

	tmp1 = create_translation_matrix(inv_pos);

	tmp2 = create_t_matrix();
	tmp2.value[0][0] = cam->right.x;
	tmp2.value[0][1] = cam->right.y;
	tmp2.value[0][2] = cam->right.z;
	tmp2.value[1][0] = cam->forward.x;
	tmp2.value[1][1] = cam->forward.y;
	tmp2.value[1][2] = cam->forward.z;
	tmp2.value[2][0] = cam->up.x;
	tmp2.value[2][1] = cam->up.y;
	tmp2.value[2][2] = cam->up.z;

	result = mult_matrix_by_matrix(&tmp1, &tmp2);

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

	result = mult_matrix_by_matrix(&(cam->model), &(cam->view));
	result = mult_matrix_by_matrix(&(result), &(cam->projection));

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
