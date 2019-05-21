#ifndef UNKNOW_PROJECT_CAMERA_H
# define UNKNOW_PROJECT_CAMERA_H

#include "unknow_project_vector.h"
#include "unknow_project_window.h"
#include "unknow_project_math.h"

typedef struct	s_camera
{
	t_matrix	model;
	t_matrix	view;
	t_matrix	projection;

	t_vector3	pos;

	t_vector3	forward;
	t_vector3	right;
	t_vector3	up;

	float		fov;
	float		near;
	float		far;
}				t_camera;

t_camera	create_t_camera(t_window *p_win, t_vector3 p_pos, float p_fov, t_vector2 p_dist);
t_camera	*initialize_t_camera(t_window *p_win, t_vector3 p_pos, float p_fov, t_vector2 p_dist);
t_matrix	compute_projection_matrix(t_window *p_win, t_camera *p_cam);
t_matrix	compute_t_camera(t_camera *cam);
t_matrix	t_camera_look_at(t_camera *cam, t_vector3 target);
t_vector3	apply_t_camera(t_vector3 *src, t_matrix *mvp);
#endif
