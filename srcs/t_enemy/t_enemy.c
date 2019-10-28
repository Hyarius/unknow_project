#include "unknow_project.h"

void        enemy_shoot(t_engine *engine)
{
    int     i;
    t_mesh  *target;

    i = 0;
    while (i < engine->physic_engine->mesh_list->size)
    {
        target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
        if (ft_strcmp(target->name, "Enemy"))
        {
                if (target->tick >= 4 && ft_strcmp(cast_ray(engine, target->pos,
                    target->forward)->name, "Player") == 0)
                {
                    engine->user_engine->player->hp -= 20;
                    target->tick = 0;
                }
                else if (target->tick != 4)
                    target->tick++;
        }
        i++;
    }
}
