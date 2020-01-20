/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_t_matrice.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:59:25 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/20 13:50:41 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

t_matrix	new_matrix(void)
{
	t_matrix	result;
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (j != i)
				result.value[i][j] = 0.0f;
			else
				result.value[i][j] = 1.0f;
		}
	}
	return (result);
}

t_matrix	new_matrix_empty(void)
{
	t_matrix	result;
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			result.value[i][j] = 0.0f;
	}
	return (result);
}

t_matrix	new_translation_matrix(t_vec4 translation)
{
	t_matrix	result;

	result = new_matrix();
	result.value[3][0] = translation.x;
	result.value[3][1] = translation.y;
	result.value[3][2] = translation.z;
	return (result);
}
