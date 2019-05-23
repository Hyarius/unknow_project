#ifndef UNKNOW_PROJECT_SYSTEM_H
# define UNKNOW_PROJECT_SYSTEM_H

# include "unknow_project_define.h"
# include "unknow_project_vector.h"

typedef struct	s_mouse
{
	t_vector2_int
				old_pos;
	t_vector2_int
				pos;
	t_vector2_int
				rel_pos;
	int			button[MOUSE_BUTTON];
}				t_mouse;

t_mouse		create_t_mouse();
t_mouse		*initialize_t_mouse();
void		get_t_mouse_info(t_mouse *mouse);
void		print_t_mouse(t_mouse *mouse);

#endif