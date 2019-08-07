#include "unknow_project.h"

int                 t_button_state(t_mouse *mouse)
{
    if (get_mouse_state(mouse, MOUSE_LEFT) == BOOL_TRUE)
    {
        mouse->clicked = BOOL_TRUE;
        return (1);
    }
    else if (get_mouse_state(mouse, MOUSE_LEFT) == BOOL_FALSE && mouse->clicked == BOOL_TRUE)
    {
        mouse->clicked = BOOL_FALSE;
        return (2);
    }
    else
    {
        return (0);
    }
}
