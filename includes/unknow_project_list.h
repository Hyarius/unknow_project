#ifndef UNKNOW_PROJECT_LIST_H
# define UNKNOW_PROJECT_LIST_H

# include "unknow_project_basic.h"
# include "unknow_project_structure.h"

typedef struct	s_vertex_list
{
	t_vertex	vertex;
	struct s_vertex
				*next;
}				t_vertex_list;

typedef struct	s_uv_list
{
	t_uv	vertex;
	struct s_uv_list
				*next;
}				t_uv_list;

typedef struct	s_mesh_list
{
	t_mesh		mesh;
	struct s_mesh_list
				*next;
}				t_mesh_list;

typedef struct	s_chunk_tab
{
	t_chunk		chunk;
	struct s_chunk_tab
				*top;
	struct s_chunk_tab
				*down;
	struct s_chunk_tab
				*right;
	struct s_chunk_tab
				*left;
}				t_chunk_tab;

typedef struct	s_object_list
{
	t_object	object;
	struct s_object_list
				*next;
}				t_object_list;

typedef struct	s_item_list
{
	t_item		item;
	struct s_item_list
				*next;
}				t_item_list;

typedef struct	s_entity_list
{
	t_entity	entity;
	struct s_entity_list
				*next;
}				t_entity_list;

typedef struct	s_enemy_list
{
	t_enemy		enemy;
	struct s_enemy_list
				*next;
}				t_enemy_list;

#endif
