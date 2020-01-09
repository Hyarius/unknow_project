/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_geo_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:19:19 by gboutin           #+#    #+#             */
/*   Updated: 2020/01/09 14:20:03 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

float	signed_volume(t_vector4 a, t_vector4 b, t_vector4 c, t_vector4 d)
{
	t_vector4	sub_res1;
	t_vector4	sub_res2;
	t_vector4	sub_res3;

	sub_res1 = substract_vector4_to_vector4(b, a);
	sub_res2 = substract_vector4_to_vector4(c, a);
	sub_res3 = substract_vector4_to_vector4(d, a);
	return ((1.0 / 6.0) * dot_t_vector4(cross_t_vector4(sub_res1, sub_res2),
																	sub_res3));
}
