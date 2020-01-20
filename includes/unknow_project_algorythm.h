#ifndef UNKNOW_PROJECT_ALGORYTHM_H
# define UNKNOW_PROJECT_ALGORYTHM_H

# include "unknow_project_mesh.h"

int         is_t_mesh_intersecting(t_mesh *mesh_compared, t_mesh *mesh_target);
t_mesh      *cast_ray(t_engine *engine, t_vec4 pos, t_vec4 direction, char *shooter);

#endif
