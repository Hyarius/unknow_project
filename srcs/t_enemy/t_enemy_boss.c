#include "unknow_project.h"

void		enemy_boss_look(t_engine *engine)
{
	int			i;
	t_camera	*cam;
	t_mesh		*target;
	float		tmp;

	i = -1;
	while (++i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(target->name, "Player") == 0)
			break ;
	}
	i = -1;
	while (++i < engine->visual_engine->camera_list->size)
	{
		cam = t_camera_list_get(engine->visual_engine->camera_list, i);
		if (cam->body != NULL)
		{
			if (ft_strcmp(cam->body->name, "Enemy_boss") == 0)
			{
				cam->pos = add_vector4_to_vector4(cam->body->pos, create_t_vector4(0.15, 0.45, -0.15));
				t_camera_look_at_point(cam, target->center);
				tmp = (cam->yaw - cam->body->angle.x);
				if (tmp > cam->body->angle.x + 1.0f || tmp < cam->body->angle.x - 1.0f)
				{
					t_mesh_rotate_around_point(cam->body, create_t_vector4(0.0, tmp, 0.0), cam->body->center);
					cam->body->angle.x = cam->yaw;
				}
			}
		}
	}
}

void		enemy_boss_shoot(t_engine *engine)
{
	int			i;
	int			diff;
	t_mesh		*target;
	t_mesh		*mesh;

	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(target->name, "Enemy_boss") == 0)
		{
			printf("shoot = %d\n", engine->tick % target->tick);
			if (target->tick == -5)
				target->tick = engine->tick;
			if (engine->tick % target->tick == 6)
			{
				mesh = cast_ray(engine, target->camera->pos, target->camera->forward, "Enemy_boss");
				if (mesh != NULL)
				{
					if (ft_strcmp(mesh->name, "Player") == 0)
					{
						if (engine->user_engine->player->armor != 0)
						{
							if (engine->user_engine->player->armor >= 30)
								engine->user_engine->player->armor -= 30;
							else
							{
								diff = 30 - engine->user_engine->player->armor;
								engine->user_engine->player->armor = 0;
								engine->user_engine->player->hp -= diff;
							}
						}
						else
							engine->user_engine->player->hp -= 30;
					}
					else if (mesh->hp != -1)
					{
						t_mesh_set_visibility(mesh, BOOL_FALSE);
						mesh->no_hitbox = 1;
					}
				}
				target->tick = engine->tick;
			}
		}
		i++;
	}
}
