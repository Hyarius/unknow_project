#include "unknow_project.h"

void			enemy_boss_look(t_engine *engine)
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

void			enemy_boss_shoot(t_engine *engine)
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

t_vector4	spawn_mine(t_vector4 pos)
{
	t_vector4	ret;

	ret.x = generate_float(pos.x - 4.5, pos.x + 4.5);
	if (ret.x > -1.5f && ret.x < 1.5f)
	{
		if (ret.x < 0)
			ret.x -= 1.5f;
		else
			ret.x += 1.5f;
	}
	ret.y = 0.0001;
	ret.z = generate_float(pos.z - 4.5, pos.z + 4.5);
	if (ret.z > -1.5f && ret.z < 1.5f)
	{
		if (ret.z < 0)
			ret.z -= 1.5f;
		else
			ret.z += 1.5f;
	}
	ret.w = 1.0;
	return (ret);
}

void			enemy_boss_spawn(t_engine *engine)
{
	int					i;
	int					k;
	t_mesh			*target;
	t_mesh			mesh;
	static int	j = 0;

	i = 0;
	k = engine->visual_engine->camera_list->size - 3;
	while (i < engine->physic_engine->mesh_list->size)
	{
		target = t_mesh_list_get(engine->physic_engine->mesh_list, i);
		if (ft_strcmp(target->name, "Enemy_boss") == 0)
		{
			if (j == 0)
				j = engine->tick;
			if (engine->tick - j == 3)
			{
				mesh = create_primitive_cube(spawn_mine(target->pos), create_t_vector4(0.3, 0.5, 0.3), NULL, 0.0);
				t_mesh_set_color(&mesh, create_t_color(1.0, 1.0, 1.0, 1.0));
				t_mesh_set_name(&mesh, "Enemy_mine");
				mesh.hp = 10;
				// cast_mesh_bis(engine, &mesh);
				t_engine_add_mesh(engine, mesh);
				// link_enemy_to_camera(engine, k);
				// link_t_camera_to_t_mesh(engine, 2 + k, t_engine_get_mesh(engine, engine->physic_engine->mesh_list->size - 1));
				j = engine->tick;
			}
		}
		i++;
	}
}
