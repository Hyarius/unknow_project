# include "unknow_project.h"

void            t_user_engine_handle_pause(t_camera *main_camera, t_gui *gui, t_user_engine *user_engine, int *play)
{
    if (*play == -1)
        main_pause(main_camera, gui, user_engine, play);
}

// void            main_pause(t_camera *main_camera, t_gui *gui, t_user_engine *user_engine, int *play)
// {
    
// 	t_mouse *mouse = user_engine->mouse;
// 	t_keyboard *keyboard = user_engine->keyboard;
//     t_vector2_int pos;

// 	get_t_mouse_info(mouse);
//     pos = create_t_vector2_int(mouse->pos.x * 100 / WIN_X, mouse->pos.y * 100 / WIN_Y);
//     printf("x = %d | y = %d\n", pos.x, pos.y);
//     if (pos.x > 43 && pos.x < 56)
//     {
//         if (pos.y > 56 && pos.y < 61)
//             if (t_mouse_state(mouse) == 2)
// 		        *play = 1;
//         if (pos.y > 63 && pos.y < 68)
//         	if (t_mouse_state(mouse) == 2)
// 		        *play = 3;
//         if (pos.y > 70 && pos.y < 75)
//         	if (t_mouse_state(mouse) == 2)
// 		        *play = 5;
//         if (pos.y > 76 && pos.y < 82)
//         	if (t_mouse_state(mouse) == 2)
// 		        *play = 0;
//     }
//     else
//         user_engine->mouse->clicked = BOOL_FALSE;
// }
