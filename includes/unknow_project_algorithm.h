/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_algorithm.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:21:37 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/20 16:59:35 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_ALGORITHM_H
# define UNKNOW_PROJECT_ALGORITHM_H

# include "unknow_project_mesh.h"

int		is_t_mesh_intersecting(t_mesh *mesh_compared, t_mesh *mesh_target);
t_mesh	*cast_ray(t_engine *engine, t_vec4 pos, t_vec4 dir, char *shooter);

#endif
