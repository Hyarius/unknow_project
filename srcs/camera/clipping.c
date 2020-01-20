#include "unknow_project.h"

int			clip_triangle_to_plane(t_camera *p_camera, t_vec4 *p_points, t_vec4 *p_points_uv)
{
	// t_vec4 		cara.out_p[3];
	// t_vec4 		cara.in_p[3];
	// t_vec4 		cara.out_uv[3];
	// t_vec4 		cara.in_uv[3];
	// t_vec4		cara.forward;
	// t_vec4		cara.plane_center;
	// t_vec4		*cara.clp_lst;
	// t_vec4		*cara.clp_lst_uv;
	// int			cara.out_nb;
	// int			cara.in_nb;
	// float		cara.dist[3];
	t_clipping	cara;

	cara.clp_lst = p_camera->clipping_list;
	cara.clp_lst_uv = p_camera->clipping_list_uv;
	cara.forward = new_vec4(0, 0, 1);
	cara.plane_center = new_vec4(0, 0, p_camera->near);
	cara.dist[0] = dist_plane(cara.forward, cara.plane_center, p_points[0]);
	cara.dist[1] = dist_plane(cara.forward, cara.plane_center, p_points[1]);
	cara.dist[2] = dist_plane(cara.forward, cara.plane_center, p_points[2]);
	cara.out_nb = 0;
	cara.in_nb = 0;
	for (int i = 0; i < 3; i++)
	{
		if (cara.dist[i] >= 0)
		{
			cara.in_p[cara.in_nb] = p_points[i];
			if (p_points_uv != NULL)
				cara.in_uv[cara.in_nb] = p_points_uv[i];
			cara.in_nb++;
		}
		else
		{
			cara.out_p[cara.out_nb] = p_points[i];
			if (p_points_uv != NULL)
				cara.out_uv[cara.out_nb] = p_points_uv[i];
			cara.out_nb++;
		}
	}
	if (cara.in_nb == 1)
	{
		cara.clp_lst[0] = cara.in_p[0];
		cara.clp_lst[1] = inter_plane_line(cara.forward, cara.plane_center, cara.out_p[0], cara.in_p[0]);
		cara.clp_lst[2] = inter_plane_line(cara.forward, cara.plane_center, cara.out_p[1], cara.in_p[0]);

		if (p_points_uv != NULL)
		{
			cara.clp_lst_uv[0] = cara.in_uv[0];

			cara.clp_lst_uv[1] = inter_vec4_line(inter_ratio(cara.in_p[0].x, cara.out_p[0].x,
							cara.clp_lst[1].x), inter_ratio(cara.in_p[0].y, cara.out_p[0].y,
							cara.clp_lst[1].y), cara.in_uv[0], cara.out_uv[0]);
			cara.clp_lst_uv[2] = inter_vec4_line(inter_ratio(cara.in_p[0].x, cara.out_p[1].x,
							cara.clp_lst[2].x), inter_ratio(cara.in_p[0].y, cara.out_p[1].y,
							cara.clp_lst[2].y), cara.in_uv[0], cara.out_uv[1]);
		}
		return (3);
	}
	else if (cara.in_nb == 2)
	{
		cara.clp_lst[0] = cara.in_p[0];
		cara.clp_lst[1] = cara.in_p[1];
		cara.clp_lst[2] = inter_plane_line(cara.forward, cara.plane_center, cara.in_p[0], cara.out_p[0]);
		if (p_points_uv != NULL)
		{
			cara.clp_lst_uv[0] = cara.in_uv[0];
			cara.clp_lst_uv[1] = cara.in_uv[1];
			cara.clp_lst_uv[2] = inter_vec4_line(inter_ratio(cara.in_p[0].x, cara.out_p[0].x,
							cara.clp_lst[2].x),inter_ratio(cara.in_p[0].y, cara.out_p[0].y,
							cara.clp_lst[2].y), cara.in_uv[0], cara.out_uv[0]);
		}
		cara.clp_lst[3] = cara.in_p[1];
		cara.clp_lst[4] = inter_plane_line(cara.forward, cara.plane_center, cara.in_p[0], cara.out_p[0]);
		cara.clp_lst[5] = inter_plane_line(cara.forward, cara.plane_center, cara.in_p[1], cara.out_p[0]);
		if (p_points_uv != NULL)
		{
			cara.clp_lst_uv[3] = cara.in_uv[1];
			cara.clp_lst_uv[4] = inter_vec4_line(inter_ratio(cara.in_p[0].x, cara.out_p[0].x,
							cara.clp_lst[4].x), inter_ratio(cara.in_p[0].y, cara.out_p[0].y,
							cara.clp_lst[4].y), cara.in_uv[0], cara.out_uv[0]);
			cara.clp_lst_uv[5] = inter_vec4_line(inter_ratio(cara.in_p[1].x, cara.out_p[0].x,
							cara.clp_lst[5].x), inter_ratio(cara.in_p[1].y, cara.out_p[0].y,
							cara.clp_lst[5].y),cara.in_uv[1], cara.out_uv[0]);
		}

		return (6);
	}
	if (cara.in_nb == 3)
	{
		cara.clp_lst[0] = cara.in_p[0];
		cara.clp_lst[1] = cara.in_p[1];
		cara.clp_lst[2] = cara.in_p[2];

		if (p_points_uv != NULL)
		{
			cara.clp_lst_uv[0] = cara.in_uv[0];
			cara.clp_lst_uv[1] = cara.in_uv[1];
			cara.clp_lst_uv[2] = cara.in_uv[2];
		}
		return (3);
	}
	return (0);
}
