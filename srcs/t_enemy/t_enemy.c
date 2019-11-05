#include "unknow_project.h"

void        enemy_look(t_engine *engine)
{
  int       i;
  t_camera  *cam;
  t_mesh    target;

  i = 0;
  while (i < engine->physic_engine->mesh_list->size)
  {
    target = t_mesh_list_at(engine->physic_engine->mesh_list, i);
    if (ft_strcmp(target.name, "Player") == 0)
      break ;
    i++;
  }
  i = 0;
  while (i < engine->visual_engine->camera_list->size)
  {
    cam = t_camera_list_get(engine->visual_engine->camera_list, i);
    if (cam->body != NULL)
    {
      if (ft_strcmp(cam->body->name, "Enemy") == 0)
      {
        cam->pos = add_vector3_to_vector3(cam->body->pos, create_t_vector3(0.15, 0.45, -0.15));
        t_camera_look_at_point(cam, target.pos);
      }
    }
    i++;
  }
}

void        enemy_shoot(t_engine *engine)
{
    int     i;
    t_mesh  *target;

    i = 0;
    while (i < engine->physic_engine->mesh_list->size)
    {
        target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
        if (ft_strcmp(target->name, "Enemy") == 0)
        {
          if (target->tick >= 4 && cast_ray(engine, target->camera->pos,
              target->camera->forward, "Enemy")/*&& ft_strcmp(cast_ray(engine, target->camera->pos,
              target->camera->forward, "Enemy")->name, "Player") == 0*/)
          {
            printf("on rentre 2\n");
            engine->user_engine->player->hp -= 1;
            target->tick = 0;
          }
          else if (target->tick != 4)
              target->tick++;
        }
        i++;
    }
}
