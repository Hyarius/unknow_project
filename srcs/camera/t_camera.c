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
	t_matrix result;
	t_matrix tmp1;
	t_matrix tmp2;
	t_vector3 inv_pos;
	t_matrix	rot_y;
	t_matrix	rot_z;

	rot_y = create_rotation_y_matrix(90);
	rot_z = create_rotation_z_matrix(90);
	inv_pos = create_t_vector3(-cam->pos.x, -cam->pos.y, -cam->pos.z);

	cam->forward = create_t_vector3(target.x - cam->pos.x,
								target.y - cam->pos.y,
								target.z - cam->pos.z);
	cam->right = mult_vector3_by_matrix(&(cam->forward), &rot_z);
	cam->up = mult_vector3_by_matrix(&(cam->forward), &rot_y);

	tmp1 = create_translation_matrix(inv_pos);

	tmp2 = create_t_matrix();
	tmp2.value[0][0] = cam->right.x;
	tmp2.value[0][1] = cam->right.y;
	tmp2.value[0][2] = cam->right.z;
	tmp2.value[1][0] = cam->up.x;
	tmp2.value[1][1] = cam->up.y;
	tmp2.value[1][2] = cam->up.z;
	tmp2.value[2][0] = cam->forward.x;
	tmp2.value[2][1] = cam->forward.y;
	tmp2.value[2][2] = cam->forward.z;

	result = mult_matrix_by_matrix(&tmp1, &tmp2);

	return (result);
}

t_matrix		compute_projection_matrix(t_window *p_win,t_camera *p_cam)
{
	t_matrix	result;
    float 		zRange;
    float 		tanHalfFOV;

    zRange = p_cam->near - p_cam->far;
    tanHalfFOV = tanf(degree_to_radius(p_cam->fov / 2.0));

    result.value[0][0] = 1.0f / (tanHalfFOV * ((float)(p_win->size_x) / (float)(p_win->size_y)));

    result.value[1][1] = 1.0f / tanHalfFOV;

    result.value[2][2] = (-p_cam->near - p_cam->far) / zRange;
    result.value[2][3] = 2.0f * p_cam->far * p_cam->near / zRange;

    result.value[3][2] = 1.0f;

	return (result);
}

t_matrix		compute_t_camera(t_camera *cam)
{
	t_matrix result;

	result = mult_matrix_by_matrix(&(cam->model), &(cam->view));
	result = mult_matrix_by_matrix(&(result), &(cam->projection));

	return (result);
}
