#ifndef UNKNOW_PROJECT_GAME_ENGINE_H
# define UNKNOW_PROJECT_GAME_ENGINE_H

# include "unknow_project_list.h"

// - Contain every information about the world and it's representation
typedef struct	s_game_engine
{
	t_camera	cam;
	t_chunk_tab	chunks;
	t_entity_list
				entities;
	t_item_list
				items;
	t_object_list
				objects;
	t_player	player;
	t_enemy_list
				enemies;
}				t_game_engine;

#endif
