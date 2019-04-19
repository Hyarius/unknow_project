#ifndef UNKNOW_PROJECT_GUI_H
# define UNKNOW_PROJECT_GUI_H

# include "unknow_project_basics.h"

// - COMPONENT ELEMENT

typedef struct	s_sprite
{
	t_vector2	pos; // - Position on screen
	t_vector2	size; // - Size on screen
	t_texture	texture; // - Image to print
}				t_sprite;

typedef struct	s_hitbox
{
	t_vector2	pos; // - position of the hitbox on screen
	t_vector2	size; // - size of the hitbox on screen
}				t_hitbox;

// - STRUCTURE ELEMENT

typedef struct	s_picture
{
	t_sprite	sprite; // - Sprite to draw on screen
}				t_picture;

typedef struct	s_button
{
	t_sprite	sprite; // - Sprite to draw on screen
	t_hitbox	hitbox; // - Hitbox of the button
	//TO_DO ---- FUNCTION
}				t_button;

typedef struct	s_entry
{
	t_string	str; // - Text linked to this entry
	t_sprite	sprite;	// - Sprite to draw on screen
	t_hitbox	hitbox; // - Hitbox of the entry
	char		active; // 0 = desactiver / 1 = activer
}				t_entry;

typedef struct	s_bar
{
	t_value		value; // - Value linked to this bar
	t_string	str; // - Text linked to this bar
	t_sprite	frame; // - Sprite of the frame to draw on screen
	t_sprite	bar; // - Sprite of the progression bar to draw on screen
	t_button	button; // - Button to interact with the bar
}				t_bar;

// - STRUCTURE LIST

typedef struct	s_picture_list // - A simply linked list of t_picture
{
	t_picture	picture;
	struct s_picture_list
				*next;
}				t_picture_list;

typedef struct	s_button_list // - A simply linked list of t_button
{
	t_button	button;
	struct s_button_list
				*next;
}				t_button_list;

typedef struct	s_entry_list // - A simply linked list of t_entry
{
	t_entry		entry;
	struct s_entry_list
				*next;
}				t_entry_list;

typedef struct	s_bar_list // - A simply linked list of t_bar
{
	t_bar		bar;
	struct s_bar_list
				*next;
}				t_bar_list;

// - INTERFACE

typedef struct	s_content // - Contain every elements of the GUI
{
	t_picture_list
				images;
	t_button_list
				buttons;
	t_entry_list
				entries;
	t_bar_list
				bars;
}				t_content;

typedef struct	s_gui // - Describ the gui on screen
{
	t_vector2	size; // - Number of subdivision of the screen inside the gui
	t_vector2	unit; // - Size of one subdivided square on screen
	t_content	content; // Store every elements on screen
}				t_gui;

#endif
