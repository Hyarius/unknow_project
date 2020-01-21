/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_engine.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:45:15 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/21 14:12:28 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_ENGINE_H
# define UNKNOW_PROJECT_ENGINE_H

# include "unknow_project_camera.h"
# include "unknow_project_engine_module.h"
# include "unknow_project_item.h"

typedef struct		s_engine
{
	int				playing;
	int				tick;
	t_visual_engine	*visual_engine;
	t_physic_engine	*physic_engine;
	t_user_engine	*user_engine;
	t_sound_engine	*sound_engine;
}					t_engine;

t_engine			new_engine(t_window *p_window);
t_engine			*initialize_t_engine(t_window *p_window);
void				delete_t_engine(t_engine dest);
void				free_t_engine(t_engine *dest);
void				t_engine_add_mesh(t_engine *engine, t_mesh p_mesh);
void				t_engine_add_item(t_engine *engine, t_item p_item);
t_mesh				*t_engine_get_mesh(t_engine *p_engine, int index);
void				t_engine_handle_camera(t_engine *p_engine, t_window *p_win);
void				t_engine_draw_mesh(t_engine *p_engine);
void				t_engine_apply_physic(t_engine *engine);
void				t_engine_place_camera(t_engine *engine, int index,
														t_vec4 p_new_pos);
void				t_engine_camera_look_at(t_engine *engine, int index,
														t_vec4 target);
void				t_engine_render_camera(t_engine *engine);
void				t_engine_prepare_camera(t_engine *engine);
void				t_engine_add_camera(t_engine *p_engine,
														t_camera new_camera);
int					can_move(t_mesh *mesh, t_engine *engine);
void				handle_t_camera_mouvement_by_key(t_camera *camera,
									t_keyboard *p_keyboard, t_engine *engine);
void				move_camera(t_camera *camera, t_vec4 mouvement,
													t_engine *engine, float j);
void				move_cam(t_camera *camera, t_keyboard *key,
															t_engine *engine);
void				t_user_engine_handle_camera(t_engine *engine,
											t_camera *cam, t_window *p_win);
void				t_physic_engine_apply_force(t_engine *engine);
void				player_action(t_camera *camera, t_keyboard *p_keyboard,
								t_engine *engine, t_texture **texture_weapons);
void				shoot_weapon(t_engine *engine, t_camera *camera,
								t_texture **texture_weapons);
void				player_take_dmg(t_engine *engine, int dmg);
void				enemy_shoot(t_engine *engine);
void				enemy_look(t_engine *engine);
void				enemy_move(t_engine *engine);
void				enemy_boss_look(t_engine *engine);
void				enemy_boss_shoot(t_engine *engine);
void				enemy_boss_spawn(t_engine *engine);
void				save_map(t_engine *engine, int wich);
void				save_player(t_engine *engine, int fd);
void				link_camera_to_mesh(t_engine *engine, int index,
																t_mesh *mesh);
t_mesh_editing		create_mesh_editing(int index, char *path);
t_mesh_editing		select_mesh(t_keyboard *p_keyboard, t_vec4 pos,
																char **path);
void				cast_mesh(t_engine *engine, t_mesh *mesh_editing);
void				load_map(t_camera *main_camera, t_engine *engine,
																char *path);
void				t_mesh_move_door(t_mesh	*mesh, t_engine *engine);
void				player_take_dmg(t_engine *engine, int dmg);
void				check_mesh_player(t_engine *engine, t_mesh mesh);
void				place_mesh(t_engine *engine, t_mesh_editing edit);
void				rotate_mesh(t_engine *engine);
void				left_move(t_engine *engine);
void				right_move(t_engine *engine);
void				up_move(t_engine *engine);
void				down_move(t_engine *engine);
void				equals_move(t_engine *engine);
void				minus_move(t_engine *engine);

#endif
