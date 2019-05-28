#include "unknow_project.h"

void		clip_triangle_to_plane(t_camera *p_camera, t_vector3 *p_points)
{
	t_vector3		tmp_point[4];
	t_vector3_list outside_points;
	t_vector3_list inside_points;
	t_vector3		forward;
	t_vector3		inv_forward;
	t_vector3		plane_center;
	float			dist[3];

	clean_t_vector3_list(&(p_camera->clipping_list));
	forward = create_t_vector3(0, 0, 1);
	inv_forward = inv_t_vector3(forward);
	plane_center = create_t_vector3(0, 0, p_camera->near);

	dist[0] = calc_distance_to_plane(forward, plane_center, p_points[0]);
	dist[1] = calc_distance_to_plane(forward, plane_center, p_points[1]);
	dist[2] = calc_distance_to_plane(forward, plane_center, p_points[2]);


	outside_points = create_t_vector3_list();
	inside_points = create_t_vector3_list();

	if (dist[0] >= 0)
		t_vector3_list_push_back(&inside_points, p_points[0]);
	else
		t_vector3_list_push_back(&outside_points, p_points[0]);

	if (dist[1] >= 0)
		t_vector3_list_push_back(&inside_points, p_points[1]);
	else
		t_vector3_list_push_back(&outside_points, p_points[1]);

	if (dist[2] >= 0)
		t_vector3_list_push_back(&inside_points, p_points[2]);
	else
		t_vector3_list_push_back(&outside_points, p_points[2]);

	if (inside_points.size == 0)
	{
		return ;
	}
	else if (inside_points.size == 1)
	{
		tmp_point[0] = t_vector3_list_at(&inside_points, 0);
		tmp_point[1] = intersect_plane_by_line(forward, plane_center, t_vector3_list_at(&outside_points, 0), t_vector3_list_at(&inside_points, 0));
		tmp_point[2] = intersect_plane_by_line(forward, plane_center, t_vector3_list_at(&outside_points, 1), t_vector3_list_at(&inside_points, 0));

		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[0]);
		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[1]);
		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[2]);
	}
	else if (inside_points.size == 2)
	{
		tmp_point[0] = t_vector3_list_at(&inside_points, 0);
		tmp_point[1] = t_vector3_list_at(&inside_points, 1);
		tmp_point[2] = intersect_plane_by_line(forward, plane_center, t_vector3_list_at(&inside_points, 0), t_vector3_list_at(&outside_points, 0));
		tmp_point[3] = intersect_plane_by_line(forward, plane_center, t_vector3_list_at(&inside_points, 1), t_vector3_list_at(&outside_points, 0));

		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[0]);
		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[1]);
		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[2]);

		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[1]);
		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[2]);
		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[3]);
	}
	else if (inside_points.size == 3)
	{
		tmp_point[0] = t_vector3_list_at(&inside_points, 0);
		tmp_point[1] = t_vector3_list_at(&inside_points, 1);
		tmp_point[2] = t_vector3_list_at(&inside_points, 2);

		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[0]);
		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[1]);
		t_vector3_list_push_back(&(p_camera->clipping_list), tmp_point[2]);
	}
}
