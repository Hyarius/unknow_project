/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_list.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:57:08 by spuisais          #+#    #+#             */
/*   Updated: 2020/01/20 15:57:55 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_LIST_H
# define UNKNOW_PROJECT_LIST_H

# include "unknow_project_mesh.h"
# include "unknow_project_camera.h"

typedef struct	s_mesh_list
{
	t_mesh		*mesh;
	int			size;
	int			max_size;
}				t_mesh_list;

t_mesh_list		new_mesh_list();
t_mesh_list		*initialize_t_mesh_list();
void			t_mesh_list_push_back(t_mesh_list *dest, t_mesh to_add);
void			delete_t_mesh_list(t_mesh_list dest);
void			free_t_mesh_list(t_mesh_list *dest);
t_mesh			t_mesh_list_at(t_mesh_list *dest, int index);
t_mesh			*t_mesh_list_get(t_mesh_list *dest, int index);

typedef struct	s_camera_list
{
	t_camera	*camera;
	int			size;
	int			max_size;
}				t_camera_list;

t_camera_list	new_camera_list();
t_camera_list	*initialize_t_camera_list();
void			t_camera_list_push_back(t_camera_list *dest, t_camera to_add);
void			t_camera_list_add_back(t_camera_list *dest, t_camera *to_add);
void			delete_t_camera_list(t_camera_list dest);
void			free_t_camera_list(t_camera_list *dest);
void			clean_t_camera_list(t_camera_list *dest);
t_camera		t_camera_list_at(t_camera_list *dest, int index);
t_camera		*t_camera_list_get(t_camera_list *dest, int index);

#endif
