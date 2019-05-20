#ifndef UNKNOW_PROJECT_MATH_H
# define UNKNOW_PROJECT_MATH_H

typedef struct	s_rasterizer
{
	int 		a;
	int 		b;
	int 		c;
	int			max;
}				t_rasterizer;

int			apply_formula(t_rasterizer *rast, int x, int y);
int			get_short(int a, int b, int c);
int			get_big(int a, int b, int c);
void		set_rasterizer(t_rasterizer *rast, t_vector2 *s, t_vector2 *e, t_vector2 *ext);
float		calc_rasterizer(t_rasterizer *rast, int x, int y);

typedef struct	s_matrice
{
	float		value[4][4];
}				t_matrice;


int				generate_nbr(int min, int max);
t_vector2_int_list
			calc_line(t_vector2_int start, t_vector2_int end);

#endif
