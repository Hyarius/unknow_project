#include "unknow_project.h"

int			clip_triangle_to_plane(t_camera *p_camera, t_vector3 *p_points)
{
	t_vector3 		outside_points[3];
	t_vector3 		inside_points[3];
	t_vector3		forward;
	t_vector3		plane_center;
	int				outside_nb;
	int				inside_nb;
	float			dist[3];

	forward = create_t_vector3(0, 0, 1);
	plane_center = create_t_vector3(0, 0, p_camera->near);

	dist[0] = calc_distance_to_plane(forward, plane_center, p_points[0]); //calcul de la distance du triangle par rapport au plan
	dist[1] = calc_distance_to_plane(forward, plane_center, p_points[1]);
	dist[2] = calc_distance_to_plane(forward, plane_center, p_points[2]);

	outside_nb = 0;
	inside_nb = 0;
	for (int i = 0; i < 3; i++)
	{
		if (dist[i] >= 0)
		{
			inside_points[inside_nb] = p_points[i];
			inside_nb++;
		}
		else
		{
			outside_points[outside_nb] = p_points[i];
			outside_nb++;
		}
	}
	if (inside_nb == 1) // si 1 point a l'interieur, creation de 2 nouveaux point pour refaire le triangle
	{
		p_camera->clipping_list[0] = inside_points[0];
		p_camera->clipping_list[1] = intersect_plane_by_line(forward, plane_center, outside_points[0], inside_points[0]);
		p_camera->clipping_list[2] = intersect_plane_by_line(forward, plane_center, outside_points[1], inside_points[0]);
		return (3);
	}
	else if (inside_nb == 2) // si 2 points a l'interieur, creation de 2 nouveaux point pour creer 2 triangles
	{
		p_camera->clipping_list[0] = inside_points[0];
		p_camera->clipping_list[1] = inside_points[1];
		p_camera->clipping_list[2] = intersect_plane_by_line(forward, plane_center, inside_points[0], outside_points[0]);
		p_camera->clipping_list[3] = inside_points[1];
		p_camera->clipping_list[4] = intersect_plane_by_line(forward, plane_center, inside_points[0], outside_points[0]);
		p_camera->clipping_list[5] = intersect_plane_by_line(forward, plane_center, inside_points[1], outside_points[0]);

		return (6);
	}
	else if (inside_nb == 3) // si 3 point a l'interieur, rien a faire
	{
		p_camera->clipping_list[0] = inside_points[0];
		p_camera->clipping_list[1] = inside_points[1];
		p_camera->clipping_list[2] = inside_points[2];

		return (3);
	}
	return (0);
}
