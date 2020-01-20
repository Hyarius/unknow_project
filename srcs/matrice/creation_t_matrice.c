/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_t_matrice.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:59:25 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/20 11:21:46 by gboutin          ###   ########.fr       */
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

t_matrix	*initialize_t_matrix(void)
{
	t_matrix	*result;

	if (!(result = (t_matrix *)malloc(sizeof(t_matrix))))
		error_exit(-13, "Can't create a t_matrix array");
	*result = new_matrix();
	return (result);
}

t_matrix	newranslation_matrix(t_vec4 translation)
{
	t_matrix	result;

	result = new_matrix();
	result.value[3][0] = translation.x;
	result.value[3][1] = translation.y;
	result.value[3][2] = translation.z;
	return (result);
}

t_matrix	create_scaling_matrix(t_vec4 scaling)
{
	t_matrix	result;

	result = new_matrix();
	result.value[0][0] = scaling.x;
	result.value[1][1] = scaling.y;
	result.value[2][2] = scaling.z;
	return (result);
}

void		print_t_matrix(t_matrix *m) // a supprimer
{
	int	i;

	i = 0;
	printf("--------------------------------------------------------------\n");
	while (i < 4)
	{
		printf("|\t%-.2f|\t%-.2f|\t%-.2f|\t%-.2f|\n", m->value[0][i],\
				m->value[1][i], m->value[2][i], m->value[3][i]);
		i++;
	}
	printf("--------------------------------------------------------------\n");
}
