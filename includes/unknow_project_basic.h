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

typedef struct	s_matrice
{
	float		value[4][4];
}				t_matrice;

// Store a rectangle
typedef struct	s_rect
{

	float		x; //Coord of the down/left corner in x axis
	float		y; //Coord of the down/left corner in y axis
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

// Store a value, and it max, used by function/struct to store and calculate ratio/percent
typedef struct	s_value
{
	int			actual; // - Actual value of the bar
	int			max; // - Maximum value of the bar
}				t_value;

//Store information about an image, loaded on the CPU
typedef struct	s_surface
{
	void 		*pixels;
	t_vector2	size;
	long long	format;
	int			bits_per_pixel;
	int			bytes_per_pixel;
	long long	r;
	long long	g;
	long long	b;
	long long	a;
}				t_surface;

//Store an surface, and send it to the GPU, saving it inside ID
typedef struct	s_texture
{
	t_surface	surface; //The image content : pixels and format information
	GLuint		ID; // Equivalent of a pointer, but inside the GPU
	t_vector2	size; //How many sprite in x and y in the texture
	t_rect		rect; //Describ on sprite of the texture
}				t_texture;

#endif
