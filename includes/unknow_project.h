#ifndef UNKNOW_PROJECT_H
# define UNKNOW_PROJECT_H

# include "unknow_project_includes.h"
# include "unknow_project_define.h"

# include "unknow_project_basic.h"
# include "unknow_project_mesh.h"
# include "unknow_project_math.h"
# include "unknow_project_drawing.h"
# include "unknow_project_camera.h"
# include "unknow_project_system.h"

//			PNG reader
t_image 	*png_load(char *path);

//			Shader - handler
GLuint		load_shaders(const char * p_vertex_file_path,
						const char * p_fragment_file_path);

//			convert
t_vector2	convert_screen_to_opengl(t_window *p_win, int p_x, int p_y);
void		convert_vector2_to_opengl(t_window *p_win, t_vector2 *source);
t_vector2_int
				convert_vector2_to_vector2_int(t_vector2 *base);
t_vector3_int
				convert_vector3_to_vector3_int(t_vector3 *base);
float			degree_to_radius(float angle);
float			radius_to_degree(float radian);

void		prepare_screen(t_window *win, t_camera *p_cam, t_color color);
void		render_screen(t_window *win, t_camera *p_cam);

#endif
