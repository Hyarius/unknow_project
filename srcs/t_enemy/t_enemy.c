#include "unknow_project.h"

void		enemy_look(t_engine *engine)
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
			if (ft_strcmp(cam->body->name, "Enemy") == 0)
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

void		enemy_shoot(t_engine *engine)
{
	int			i;
	int			diff;
	static int	j = -5;
	t_mesh		*target;
	t_mesh		*mesh;

	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(target->name, "Enemy") == 0)
		{
			mesh = cast_ray(engine, target->camera->pos, target->camera->forward, "Enemy");
			if (mesh != NULL && engine->tick - j == 2 && ft_strcmp(mesh->name, "Player") == 0)
			{
				Mix_PlayChannel(-1, engine->sound_engine->sounds[23], 0); //trouver spatialisation du son
				if (engine->user_engine->player->armor != 0)
				{
					Mix_PlayChannel(4, engine->sound_engine->sounds[24], 0);
					if (engine->user_engine->player->armor >= 5)
						engine->user_engine->player->armor -= 5;
					else
					{
						diff = 5 - engine->user_engine->player->armor;
						engine->user_engine->player->armor = 0;
						engine->user_engine->player->hp -= diff;
					}
				}
				else
				{
					if (rand() % 2 == 0)
						Mix_PlayChannel(4, engine->sound_engine->sounds[16], 0);
					else
						Mix_PlayChannel(4, engine->sound_engine->sounds[17], 0);
					engine->user_engine->player->hp -= 5;
				}	
				j = -5;
			}
			else if (mesh != NULL && engine->tick - j > 3 && ft_strcmp(mesh->name, "Player") == 0)
				j = engine->tick;
			else if (mesh == NULL || ft_strcmp(mesh->name, "Player") != 0)
				j = -5;
		}
		i++;
	}
}

void		enemy_move(t_engine *engine)
{
	int			i;
	t_mesh		*mesh;
	t_mesh		*target;

	i = 0;
	while (i < engine->physic_engine->mesh_list->size)
	{
		mesh = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(mesh->name, "Enemy") == 0)
		{
			target = cast_ray(engine, mesh->camera->pos, mesh->camera->forward, "Enemy");
			if (target != NULL && ft_strcmp(target->name, "Player") == 0)
			{
				mesh->force = divide_vector4_by_float(mesh->camera->forward, 25);
				mesh->force.y = 0;
				if (can_move(mesh, engine) == BOOL_TRUE)
					t_mesh_move(mesh, mesh->force);
			}
			else
				mesh->force = create_t_vector4(0.0, 0.0, 0.0);
		}
		i++;
	}
}
