#ifndef UNKNOW_PROJECT_MATH_H
# define UNKNOW_PROJECT_MATH_H

# include "unknow_project_vector.h"
# include "unknow_project_basic_list.h"

typedef struct	s_matrix
{
	float		value[4][4];
}				t_matrix;

t_matrix 		create_t_matrix();
t_matrix 		*initialize_t_matrix();
t_matrix 		create_t_matrix_empty();
t_matrix 		create_translation_matrix(t_vector3 translation);
t_matrix 		create_scaling_matrix(t_vector3 scaling);
t_matrix 		create_rotation_x_matrix(float angle);
t_matrix 		create_rotation_y_matrix(float angle);
t_matrix 		create_rotation_z_matrix(float angle);
t_matrix 		create_rotation_matrix(float x, float y, float z);
t_matrix 		mult_matrix_by_matrix(t_matrix *m1, t_matrix *m2);
t_vector3 		mult_vector3_by_matrix(t_vector3 *vertex, t_matrix *m);
void			print_t_matrix(t_matrix *m);

typedef struct	s_rasterizer
{
	float 		a;
	float 		b;
	float 		c;
	float		max;
} 				t_rasterizer;

t_rasterizer 	create_t_rasterizer(t_vector3 s, t_vector3 e, t_vector3 ext);
t_rasterizer	*initialize_t_rasterizer(t_vector3 s, t_vector3 e, t_vector3 ext);
float 			apply_formula(t_rasterizer *rast, float x, float y);
float			calc_rasterizer(t_rasterizer *rast, float x, float y);

int				generate_nbr(int min, int max);
t_vector2_int_list
				calc_line(t_vector2_int start, t_vector2_int end);
t_vector3		cross_t_vector3(t_vector3 a, t_vector3 b);
t_vector3 		normalize_t_vector3(t_vector3 v);
float			dot_t_vector3(t_vector3 a, t_vector3 b);
float			edge_t_vector3(t_vector3 a, t_vector3 b, t_vector3 c);
t_vector3		intersect_plane_by_line(t_vector3 p_normal, t_vector3 p_center, t_vector3 start, t_vector3 end);
float			calc_distance_to_plane(t_vector3 p_normal, t_vector3 p_center, t_vector3 p_point);
void			clamp_float_value(float min, float *value, float max);
float			calc_dist_vector3_to_vector3(t_vector3 a, t_vector3 b);
void			clamp_int_value(int min, int *value, int max);
t_vector3		interpolate_vector3_over_line(float ratio_x, float ratio_y, t_vector3 ua, t_vector3 ub);
float			interpolate_ratio(float a, float b, float c);
int				get_short(int a, int b, int c);
int				get_big(int a, int b, int c);
float			get_short_float(float a, float b, float c);
float			get_big_float(float a, float b, float c);



#endif
