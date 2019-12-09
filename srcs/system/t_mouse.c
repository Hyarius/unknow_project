#include "unknow_project.h"

t_mouse	create_t_mouse(void)
{
	t_mouse	result;

	result.old_pos = create_t_vector2_int(-1, -1);
	result.pos = create_t_vector2_int(-1, -1);
	result.rel_pos = create_t_vector2_int(0, 0);
	result.button[MOUSE_LEFT] = BOOL_FALSE;
	result.button[MOUSE_RIGHT] = BOOL_FALSE;
	result.button[MOUSE_MIDDLE] = BOOL_FALSE;
	result.clicked_left = BOOL_FALSE;
	result.clicked_right = BOOL_FALSE;
	return (result);
}

t_mouse	*initialize_t_mouse(void)
{
	t_mouse	*result;

	if (!(result = (t_mouse *)malloc(sizeof(t_mouse))))
		return (NULL);
	*result = create_t_mouse();
	return (result);
}

void	get_t_mouse_info(t_mouse *mouse)
{
	Uint32 mousestate;

	mouse->old_pos = mouse->pos;
	mousestate = SDL_GetMouseState(&(mouse->pos.x), &(mouse->pos.y));
	if (mouse->old_pos.x != -1)
		mouse->rel_pos = create_t_vector2_int((mouse->pos.x - WIN_X / 2),
											(mouse->pos.y - WIN_Y / 2));
	if (mousestate & SDL_BUTTON(SDL_BUTTON_LEFT))
		mouse->button[MOUSE_LEFT] = BOOL_TRUE;
	else
		mouse->button[MOUSE_LEFT] = BOOL_FALSE;
	if (mousestate & SDL_BUTTON(SDL_BUTTON_RIGHT))
		mouse->button[MOUSE_RIGHT] = BOOL_TRUE;
	else
		mouse->button[MOUSE_RIGHT] = BOOL_FALSE;
	if (mousestate & SDL_BUTTON(SDL_BUTTON_MIDDLE))
		mouse->button[MOUSE_MIDDLE] = BOOL_TRUE;
	else
		mouse->button[MOUSE_MIDDLE] = BOOL_FALSE;
}

int		get_mouse_state(t_mouse *mouse, int type)
{
	if (type < 0 || type > 3)
		return (-1);
	return (mouse->button[type]);
}
