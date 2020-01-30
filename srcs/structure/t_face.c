/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_face.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <jubeal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:46:16 by jubeal            #+#    #+#             */
/*   Updated: 2020/01/30 11:19:19 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_face	new_face(void)
{
	t_face	result;
	int		i;

	result.normale = new_vec4(0, 0, 0);
	i = -1;
	while (++i < 3)
	{
		result.color = new_color(1.0, 1.0, 1.0, 1.0);
		result.index_vertices[i] = -1;
		result.index_uvs[i] = -1;
	}
	return (result);
}

t_face	*initialize_t_face(void)
{
	t_face	*result;

	if (!(result = (t_face *)malloc(sizeof(t_face))))
		error_exit(-13, "Can't create a t_face");
	*result = new_face();
	return (result);
}

void	set_t_face_vertices(t_face *face, int a, int b, int c)
{
	face->index_vertices[0] = a;
	face->index_vertices[1] = b;
	face->index_vertices[2] = c;
}

void	set_t_face_uvs(t_face *face, int a, int b, int c)
{
	face->index_uvs[0] = a;
	face->index_uvs[1] = b;
	face->index_uvs[2] = c;
}

void	set_t_face_color(t_face *face, t_color color)
{
	face->color = color;
}
