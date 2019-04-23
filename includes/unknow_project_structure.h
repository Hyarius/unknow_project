#ifndef UNKNOW_PROJECT_STRUCTURE_H
# define UNKNOW_PROJECT_STRUCTURE_H

# include "unknow_project_basic.h"

//Contain every information about the camera
typedef struct	s_camera
{
	t_matrice	MVP; // - The total matrix of the camera
	t_matrice	projection; // - The projection matrix of the camera
	t_matrice	view; // - The view matrix of the camera
	t_matrice	model; // - The model matrix of the camera
	t_vector3	direction; // - Describ where our camera look
	t_vector3	right; // - Describ the right direction relative to our camera
	t_vector3	up; // - Describ the up direction relative to our camera
	t_vector3	angle; // - Describ the angle of rotation of our camera
}				t_camera;

typedef struct	s_vertex // Store one vertex of a mesh
{
	t_vector3	vertex; // - A simple point in world reference
}				t_vertex;

typedef struct	s_uv // Store one UV of a mesh
{
	t_vector2	uv; // - A point inside the texture relative reference
}				t_uv;

typedef struct	s_mesh // Store vertices and UVs of one element
{
	t_vertex	vertices; // - Store every vertices of this element
	t_uv		uvs; // - Store every UVs of this element
	t_texture	texture; // - The texture to use to print this element
}				t_mesh;

typedef struct	s_chunk
{
	t_vector2	pos; // - Position of this chunk in the chunk reference
	t_vector2	size; // - size in world unit of one chunk
	t_mesh		meshes; // - Contain every immobile mesh inside the chunk
	int			active; // 0 - chunk desactivated / 1 - chunk activated
}				t_chunk;

// - Describ an 3D object
typedef struct	s_entity
{
	char		*name; // The name of the entity (Only for your information)
	t_vector3	coord; // Coord in world reference of this entity
	t_mesh		mesh; // The mesh of this entity, in entity reference
}				t_entity;

// - Will contain the stat of interacting entities : HP, velocity, jump etc
typedef struct	s_stat
{

}				t_stat;

// - Will contain every key binding / control information about the player
typedef struct	s_control
{

}				t_control;

// - Will contain every informations about a non-human character
typedef struct	s_AI_comp
{

}				t_AI_comp;

// - Will contain every informations about a item
typedef struct	s_item_comp
{

}				t_item_comp;

// - Will contain every informations about a object
typedef struct	s_obj_comp
{

}				t_obj_comp;

// - Contain informations about the player
typedef struct	s_player
{
	t_entity	entity;
	t_stat		stat; // - Contain the stat of the player
	t_control	control; // - Contain informations about key-binding
}				t_player;

// - Contain information about an item on floor (food, point, ammo, etc)
typedef struct	s_item
{
	t_entity	entity;
	t_item_comp	item_comp; // Contain information about the effect of the item
}				t_item;

// - Contain information about an interactive object (lever / door etc)
typedef struct	s_object
{
	t_entity	entity;
	t_obj_comp	obj_comp; // Contain information about object's interaction with the world
}				t_object;

// - Contain information about an enemy
typedef struct	s_enemy
{
	t_entity	entity;
	t_stat		stat; // - Contain the stat of the enemy
	t_AI_comp	AI_comp; // - Describ the comportement of the enemy
}				t_enemy;

#endif
