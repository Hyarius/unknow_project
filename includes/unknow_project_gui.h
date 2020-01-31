/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_gui.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:10:18 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/31 14:42:27 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_GUI_H
# define UNKNOW_PROJECT_GUI_H

# include "unknow_project_geometry.h"

typedef struct	s_button
{
	t_vec2_int	pos;
	t_vec2_int	size;
	char		clicked;
}				t_button;

t_button		new_button(void);
t_button		*initialize_t_button(void);

int				t_mouse_state(t_mouse *mouse);
int				t_key_state(t_keyboard *key);

typedef struct	s_letter
{
	t_texture	*let;
	SDL_Surface	*font;
}				t_letter;

typedef struct	s_gui
{
	t_letter	**letter;
	t_texture	**menu;
	int			idx;
	int			key_press;
	int			key_change;
	int			sens;
	int			info_print;
	t_texture	*text_weap[16];
	t_texture	*text_am[6];
	t_texture	*skybox;
}				t_gui;

t_gui			new_gui(void);
t_gui			*initialize_t_gui(void);
void			drawing_front_hp(t_camera *main_camera, t_player *player);
void			drawing_front_mun(t_camera *main_camera, t_texture **texture,
															t_player *player);
void			drawing_front_weapons(t_camera *main_camera,
										t_texture **texture, t_player *player);
void			create_minimap(t_engine *engine);
void			draw_minimap(t_engine *engine);
void			load_letter(t_gui *gui, char *str, int idx);
void			set_t_gui_texte(t_gui *gui);
void			print_info_bar(t_camera *main_camera, t_player *player,
																t_gui *gui);
void			load_menu(t_gui *gui);
void			t_engine_handle_event(t_camera *main_camera, t_gui *gui,
															t_engine *engine);
void			t_user_engine_handle_menu(t_camera *main_camera, t_gui *gui,
															t_engine *engine);
void			t_user_engine_handle_menu_next(t_engine *engine);

void			main_menu(t_engine *engine);
void			synopsis_menu(t_engine *engine);
void			play_menu(t_camera *main_camera, t_engine *engine, int *play);
void			settings_menu(t_camera *main_camera, t_gui *gui,
															t_engine *engine);
void			controls_menu(t_camera *main_camera, t_gui *gui,
												t_engine *engine);
void			pause_menu(t_engine *engine);
void			settings_pause_menu(t_engine *engine);
void			credits_menu(t_engine *engine);
void			set_player_editing(t_engine *engine);
void			set_weapon_editing(t_engine *engine);
void			save_pause(t_engine *engine);
void			print_set_player(t_camera *main_camera, t_gui *gui,
															t_engine *engine);
void			print_set_weapon(t_camera *main_camera, t_gui *gui,
															t_engine *engine);
void			map_editor(t_camera *main_camera, t_gui *gui, t_engine *engine,
												t_mesh_editing mesh_editing);
void			load_path_texture(t_visual_engine *visual_engine);
void			load_texture_cube_wall(t_visual_engine *engine);
void			load_texture_door(t_visual_engine *engine);
void			load_texture_key_elevator(t_visual_engine *engine);
void			load_texture_slope_pack(t_visual_engine *engine);
void			load_texture_ammo_ladder(t_visual_engine *engine);
void			load_texture_platform_plane(t_visual_engine *engine);
void			load_texture_end(t_visual_engine *engine);
void			print_set_ar(t_camera *cam, t_gui *gui, t_player *plr);
void			print_set_rifle(t_camera *cam, t_gui *gui, t_player *plr);
void			print_set_shotgun(t_camera *cam, t_gui *gui, t_player *plr);
void			print_set_walldest(t_camera *cam, t_gui *gui, t_player *plr);
void			close_map(t_engine *engine);
void			print_info_editing(t_camera *main_camera, t_keyboard *key,
																	t_gui *gui);
void			create_minimap(t_engine *engine);
int				select_texture(t_keyboard *key, t_visual_engine *engine);
void			game_over(t_engine *engine);

#endif
