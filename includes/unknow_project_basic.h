#ifndef UNKNOW_PROJECT_BASIC_H
# define UNKNOW_PROJECT_BASIC_H

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

typedef struct	s_vector3_int
{
    int			x;
    int			y;
    int			z;
}				t_vector3_int;

typedef struct	s_vector2_int
{
    int			x;
    int			y;
}				t_vector2_int;

typedef struct	s_matrice
{
	float		value[4][4];
}				t_matrice;

// Store a rectangle
typedef struct	s_rect
{

	float		x; //Coord of the top/left corner in x axis
	float		y; //Coord of the top/left corner in y axis
	float		w; //Weigth of the rect
	float		h; //Heigth of the rect
}				t_rect;

 // A simply linked list of char
typedef struct	s_string
{
	char		c;
	struct s_string
				*next;
}				t_string;

typedef struct	s_color
{
	float		r;
	float		g;
	float		b;
	float		a;
}				t_color;

typedef struct	s_line
{
	t_vector2	a;
	t_vector2	b;
}				t_line;

typedef struct	s_triangle
{
	t_vector2	a;
	t_vector2	b;
	t_vector2	c;
}				t_triangle;

// Store a value, and it max, used by function/struct to store and calculate ratio/percent
typedef struct	s_value
{
	int			actual; // - Actual value of the bar
	int			max; // - Maximum value of the bar
}				t_value;

typedef struct	s_rasterizer
{
	int 		a;
	int 		b;
	int 		c;
	int			max;
}				t_rasterizer;

char			*ft_strnew(int size);
int				ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *src1, char *src2);
void			ft_stradd(char **src1, char *src2);
void 			ft_putchar(char c);
void 			ft_putstr(char *str);
void 			ft_putnbr(int n);
char			*ft_strcut(char **src, char delim);
int				ft_strchr(char *src, char d);

int				get_next_line(const int fd, char **line);

void 			error_exit(int error, char *message);

int				generate_nbr(int min, int max);

void			ft_bzero(void *src, size_t nb_bytes);

#endif
