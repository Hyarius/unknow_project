/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_algorythm.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:21:37 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/20 15:22:47 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_ALGORYTHM_H
# define UNKNOW_PROJECT_ALGORYTHM_H

# include "unknow_project_mesh.h"

int		is_t_mesh_intersecting(t_mesh *mesh_compared, t_mesh *mesh_target);
t_mesh	*cast_ray(t_engine *engine, t_vec4 pos, t_vec4 dir, char *shooter);

#endif
