/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <adjouber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:09:04 by adjouber          #+#    #+#             */
/*   Updated: 2019/10/31 17:09:05 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unknow_project.h"

int		is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

float	ft_atof(char *s)
{
	float	a;
	int		neg;
	int		e;
	int		c;
	int		sign;
	int		i;

	a = 0.0;
	neg = 1;
	e = 0;
	if (s[0] == '-')
	{
		neg = -1;
		s++;
	}
	while ((c = *s++) != '\0' && is_digit(c))
		a = a * 10.0 + (c - '0');
	if (c == '.')
		while ((c = *s++) != '\0' && is_digit(c))
		{
			a = a * 10.0 + (c - '0');
			e = e - 1;
		}
	if (c == 'e' || c == 'E')
	{
		sign = 1;
		i = 0;
		c = *s++;
		if (c == '+')
			c = *s++;
		else if (c == '-')
		{
			c = *s++;
			sign = -1;
		}
		while (is_digit(c))
		{
			i = i * 10 + (c - '0');
			c = *s++;
		}
		e += i * sign;
	}
	while (e > 0)
	{
		a *= 10.0;
		e--;
	}
	while (e < 0)
	{
		a *= 0.1;
		e++;
	}
	return (a * neg);
}
