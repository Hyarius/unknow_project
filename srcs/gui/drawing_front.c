#include "unknow_project.h"

void    drawing_front_hp(t_camera *main_camera)
{
    draw_rectangle_color_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(-0.2, -1), create_t_vector2(0.4, 0.2)), initialize_t_color(0.7, 0.7, 0.7, 1.0));
}
