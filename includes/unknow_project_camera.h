#ifndef UNKNOW_PROJECT_CAMERA_H
# define UNKNOW_PROJECT_CAMERA_H

#include "unknow_project_window.h"
#include "unknow_project_math.h"
#include "unknow_project_system.h"
#include "unknow_project_geometry.h"
#include "unknow_project_mesh.h"

typedef struct	s_camera
{
	t_mesh		*body;
	t_view_port *view_port;

	t_matrix	model;
	t_matrix	view;
	t_matrix	projection;

	float		dist_max;

	t_matrix	mvp;
	t_vec4	clipping_list[6];
	t_vec4	clipping_list_uv[6];
	t_triangle_list
				triangle_color_list;
	t_color_list
				color_list;

	t_triangle_list
				triangle_texture_list;
	t_uv_list	uv_list;
	t_color_list
				darkness_list;

	t_vec4	pos;
	float		pitch; // l'angle pour l'axis y
	float		yaw; // l'angle pour l'axis x
	float		speed;
	float		running;
	float		slowing;

	t_vec4	forward;
	t_vec4	right;
	t_vec4	up;

	t_vec4	sun_direction;

	float		fov;
	float		near;
	float		far;

	int			crounch;
	int			f_press;
	int			r_press;

}				t_camera;

t_camera	new_camera(t_window *window, t_vec4 p_pos, float p_fov, t_vec2 p_dist);
t_camera	*initialize_t_camera(t_window *window, t_vec4 p_pos, float p_fov, t_vec2 p_dist);
void		t_camera_set_view_port(t_camera *camera, t_vec2_int new_pos, t_vec2_int new_size);
void		t_camera_change_window(t_camera *camera, t_window *new_window);
void		t_camera_change_view_port(t_camera *camera, t_view_port *new_view_port);
void		delete_t_cam(t_camera dest);
void		free_t_cam(t_camera *dest);
void		translate_camera(t_camera *camera, t_vec4 mouvement);
t_matrix	compute_projection_matrix(t_camera *p_cam);
void		compute_t_camera(t_camera *cam);
void		t_camera_change_fov(t_camera *cam, float delta);
t_vec4		apply_t_camera(t_vec4 *src, t_matrix *mvp);
t_matrix	t_camera_compute_view(t_camera *cam);
void		t_camera_look_at_point(t_camera *cam, t_vec4 target);
void		t_camera_look_at(t_camera *cam);
void		t_camera_change_view(t_camera *cam, float delta_yaw, float delta_pitch);
void		handle_t_camera_view_by_mouse(t_camera *cam, t_mouse *p_mouse);
int			clip_triangle_to_plane(t_camera *p_camera, t_vec4 *p_points, t_vec4 *p_points_uv);
void		draw_triangle_from_camera_on_screen(t_camera *p_cam);
void 		t_camera_calc_depth(t_camera *p_cam);
void		clean_t_camera(t_camera *camera);
void		t_mesh_move_elevator(t_mesh *mesh, t_mesh *body);

typedef struct	s_clipping
{
	t_vec4 		out_p[3];
	t_vec4 		in_p[3];
	t_vec4 		out_uv[3];
	t_vec4 		in_uv[3];
	t_vec4		forward;
	t_vec4		plane_center;
	t_vec4		*clp_lst;
	t_vec4		*clp_lst_uv;
	int			out_nb;
	int			in_nb;
	float		dist[3];
}				t_clipping;

#endif
