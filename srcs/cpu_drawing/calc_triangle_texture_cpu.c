#include "unknow_project.h"

//trouve le pixel du triangle texture dans le triangle ecran
void find_pixel(t_window *p_win, int *value, float *base, t_uv *uvs)
{
	int pixel_x;
	int pixel_y;
	int coord;

	pixel_x = ((base[3] * uvs->uv->c.x) + (base[4] * uvs->uv->b.x) + (base[5] * uvs->uv->a.x)) * uvs->image->surface->w; //conversion des 3 x triangle ecran dans triangle texture
	pixel_y = ((((base[3] * uvs->uv->c.y) + (base[4] * uvs->uv->b.y) + (base[5] * uvs->uv->a.y)) * uvs->image->surface->h) * -1) + uvs->image->surface->h;//conversion des 3 y triangle ecran dans triangle texture + inversion du Y car on est sur le repere texture basique

	if (pixel_x < 0 || pixel_x >= uvs->image->surface->w || pixel_y < 0 || pixel_y >= uvs->image->surface->h)
		return;

	int rgba[4]; //store les 4 variables de la couleur
	int	i = 0;
	rgba[3] = 255; //mets l'alpha a 255 par defaut

	while (i < uvs->image->surface->internalFormat) //InternalFormat decris le nombre d'infos necessaires par pixel (3 ou 4)
	{
		rgba[i] = uvs->image->surface->pixels[(pixel_x + (pixel_y * uvs->image->surface->w)) * uvs->image->surface->internalFormat + i]; //store chaque nuance de R/G/B/A dans la variable rgba
		i++;
	}

	t_color color;

	color = create_t_color_from_int(rgba[0], rgba[1], rgba[2], rgba[3]); //convertis les 4 int en t_color

	coord = value[5] + value[4] * p_win->size_x;
	if (p_win->z_buffer[coord] < value[7])
	{
		p_win->z_buffer[coord] = value[7];
		add_pixel_to_screen(p_win, coord, &color);	//affiche le pixel a l'ecran
	}
}

void calc_triangle_texture_cpu(t_window *p_win, int index, t_triangle *p_t, t_uv *uvs)
{
	int				value[8];
	float			base[6];
	t_vector2		delta[3];

	set_variable(p_t, value, base, delta);	//Initialise les variables y, x, index thread, etc etc
	value[7] = index;						//Thread actuel
	value[4] = value[2];					//y = y min

	while (value[4] < value[3] && value[4] >= 0 && value[4] < p_win->size_y)         	//tant que y < y_max
	{
		value[6] = 0;						//find pas encore dans le triangle
		value[5] = value[0];				//x = x_min
		base[3] = base[0] + (value[4] * delta[0].y); //Initialisation de alpha | beta | gamma
		base[4] = base[1] + (value[4] * delta[1].y);
		base[5] = base[2] + (value[4] * delta[2].y);
		while (value[5] < value[1] && value[6] != -1 && value[5] >= 0 && value[5] < p_win->size_x)//tant que x < x_max ET find pas encore sorti du triangle
		{
			if (base[3] > 0.0f && base[4] > 0.0f && base[5] > 0.0f) //si on est dans le triangle
			{
				value[6] = 1;										//on indique qu'on est dans le triangle
				find_pixel(p_win, value, base, uvs); //value[4] -> y  /  value[5] -> x  /  value[7] -> index thread  /  base[3] = alpha  /  base[4] = beta  /  base[5] = gamma
			}
			else if (value[6] == 1) //indique qu'on est sorti
				value[6] = -1;

			base[3] += delta[0].x; //deplace les alpha | beta | gamma grace aux deltas definis precedemment
			base[4] += delta[1].x;
			base[5] += delta[2].x;
			value[5]++; //decale le x
		}
		value[4]++; //decale le y
	}
}
