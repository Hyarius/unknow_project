/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_project_algorithm.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:21:37 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/21 13:37:48 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOW_PROJECT_ALGORITHM_H
# define UNKNOW_PROJECT_ALGORITHM_H

# include "unknow_project_mesh.h"

int		mesh_intersect(t_mesh *mesh_compared, t_mesh *mesh_target);
t_mesh	*cast_ray(t_engine *engine, t_vec4 pos, t_vec4 dir, char *shooter);

#endif
