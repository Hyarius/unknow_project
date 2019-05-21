#ifndef UNKNOW_PROJECT_MATH_H
# define UNKNOW_PROJECT_MATH_H

# include "unknow_project_camera.h"

typedef struct	s_rasterizer
{
	int 		a;
	int 		b;
	int 		c;
	int			max;
}				t_rasterizer;

int				apply_formula(t_rasterizer *rast, int x, int y);
int				get_short(int a, int b, int c);
int				get_big(int a, int b, int c);
void			set_rasterizer(t_rasterizer *rast, t_vector2 *s, t_vector2 *e, t_vector2 *ext);
float			calc_rasterizer(t_rasterizer *rast, int x, int y);

typedef struct	s_matrix
{
	float		value[4][4];
}				t_matrix;

t_matrix 		create_t_matrix();
t_matrix 		*initialize_t_matrix();
t_matrix 		create_translation_matrix(t_vector3 translation);
t_matrix 		create_scaling_matrix(t_vector3 scaling);
t_matrix 		create_rotation_x_matrix(float angle);
t_matrix 		create_rotation_y_matrix(float angle);
t_matrix 		create_rotation_z_matrix(float angle);
t_matrix 		create_rotation_matrix(float x, float y, float z);
t_matrix 		mult_matrix_by_matrix(t_matrix *m1, t_matrix *m2);
t_vector3 		mult_vector3_by_matrix(t_vector3 *vertex, t_matrix *m);
void			print_t_matrix(t_matrix *m);

int				generate_nbr(int min, int max);
t_vector2_int_list
				calc_line(t_vector2_int start, t_vector2_int end);

#endif
