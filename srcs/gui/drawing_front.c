#include "unknow_project.h"

void    drawing_front_hp(t_camera *main_camera, t_gui *p_gui)
{
    t_view_port_clear_buffers(main_camera->view_port);
    draw_rectangle_color_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(-0.22, -1), create_t_vector2(0.44, 0.22)), initialize_t_color(0.0, 1.0, 0.0, 1.0));
    draw_rectangle_color_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(-0.2, -1), create_t_vector2(0.4 * p_gui->perso.hp, 0.2)), initialize_t_color(1.0, 0.3, 0.3, 1.0));
    draw_buffer_opengl(main_camera->view_port->window, main_camera->view_port->window->color_data);
}

void    drawing_front_mun(t_camera *main_camera, t_gui *p_gui, t_texture *texture)
{
    t_view_port_clear_buffers(main_camera->view_port);
    draw_rectangle_color_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(0.76, -1), create_t_vector2(0.24, 0.2)), initialize_t_color(0.8, 0.8, 0.8, 1.0));
    draw_buffer_opengl(main_camera->view_port->window, main_camera->view_port->window->color_data);
    t_view_port_clear_buffers(main_camera->view_port);
    draw_rectangle_texture_cpu(main_camera->view_port, create_t_rectangle(create_t_vector2(0.8, -1), create_t_vector2(0.2, 0.2)), texture);
    draw_buffer_opengl(main_camera->view_port->window, main_camera->view_port->window->color_data);
}
