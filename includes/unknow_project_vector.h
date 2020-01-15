#ifndef UNKNOW_PROJECT_VECTOR_H
# define UNKNOW_PROJECT_VECTOR_H

typedef struct	s_vector4
{
    float		x;
    float		y;
    float		z;
    float		w;
}				t_vector4;

t_vector4 create_t_vector4(float p_x, float p_y, float p_z);
t_vector4	*initialize_t_vector4(float p_x, float p_y, float p_z);
t_vector4	add_vector4_to_vector4(t_vector4 a, t_vector4 b);
t_vector4	substract_vector4_to_vector4(t_vector4 a, t_vector4 b);
t_vector4	mult_vector4_by_vector4(t_vector4 a, t_vector4 b);
t_vector4	mult_vector4_by_float(t_vector4 a, float b);
t_vector4	divide_vector4_by_float(t_vector4 a, float b);
t_vector4	inv_t_vector4(t_vector4 src);
void		swap_t_vector4(t_vector4 *a, t_vector4 *b);
int			t_vector4_equal(t_vector4 a, t_vector4 b);
void		print_t_vector4(t_vector4 vector, char *str);;

typedef struct	s_vector3
{
    float		x;
    float		y;
    float		z;
}				t_vector3;

typedef struct	s_vector2
{
    float		x;
    float		y;
}				t_vector2;

t_vector2	create_t_vector2(float p_x, float p_y);
t_vector2	add_vector2_to_vector2(t_vector2 v1, t_vector2 v2);

typedef struct	s_vector2_int
{
    int			x;
    int			y;
}				t_vector2_int;

t_vector2_int
				create_t_vector2_int(int p_x, int p_y);

#endif
