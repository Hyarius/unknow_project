#include "unknow_project.h"

void apply_pixel(t_window *p_win, int *value, float *base, t_color *p_color)
{
	int coord;

	if (base[3] > 0.0f && base[4] > 0.0f && base[5] > 0.0f)
	{
		value[6] = 1;			//Find est dans le triangle
		coord = value[5] + value[4] * p_win->size_x;
		if (p_win->z_buffer[coord] <= value[7])
		{
		 	p_win->z_buffer[coord] = value[7];
			add_pixel_to_screen(p_win, coord, p_color);	//affiche le pixel a l'ecran
		}
	}
	else if (value[6] == 1)	//verification de sortie du triangle
		value[6] = -1;		//Find est resorti du triangle
}

void calc_triangle_color_cpu(t_window *p_win, int index, t_triangle *p_t, t_color *p_color)
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
			apply_pixel(p_win, value, base, p_color);  //on applique le pixel dans le buffer
			base[3] += delta[0].x; //deplace les alpha | beta | gamma grace aux deltas definis precedemment
			base[4] += delta[1].x;
			base[5] += delta[2].x;
			value[5]++; //decale le x
		}
		value[4]++; //decale le y
	}
}
