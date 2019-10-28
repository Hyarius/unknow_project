# include "unknow_project.h"

int		ft_floor(float source)
{
	int result;

	result = (int)(source);
	if (source - (float)(result) >= 0.5)
		result++;
	return (result);
}

int		is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

float 	ft_atof(char *s)
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
		a = a*10.0 + (c - '0');
	if (c == '.')
		while ((c = *s++) != '\0' && is_digit(c))
		{
			a = a*10.0 + (c - '0');
			e = e-1;
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
		e += i*sign;
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

float			get_short_float(float a, float b, float c)
{
	float			result;

	result = a;
	if (result > b)
		result = b;
	if (result > c)
		result = c;
	return (result);
}

float			get_big_float(float a, float b, float c)
{
	float			result;

	result = a;
	if (result < b)
		result = b;
	if (result < c)
		result = c;
	return (result);
}

float			float_min(float a, float b)
{
	if (a <= b)
		return (a);
	return (b);
}

float			float_max(float a, float b)
{
	if (a >= b)
		return (a);
	return (b);
}

// char		*ft_ftoa(float num)
// {
// 	short	i;
// 	int		tmp;
// 	short	size;
// 	char	*str;
//
// 	i = 0;
// 	size = 1;
// 	tmp = (int)round(num * 100);
// 	if (num == .0)
// 		return (ft_strdup("0.00"));
// 	(num < .0 && (tmp *= -1.) > 0) ? ++size : 1;
// 	(tmp < 100) ? ++size : 1;
// 	num = tmp;
// 	while (tmp != 0 && ++size)
// 		tmp /= 10;
// 	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
// 		return (NULL);
// 	str[size--] = 0;
// 	while ((int)num != 0 && ++i)
// 		(i != 3 && (str[size--] =
// 		((int)num % 10) + '0')) ? (num /= 10) : (str[size--] = '.');
// 	(i++ == 2) ? str[size--] = '.' : 1;
// 	(i++ == 3) ? str[size--] = '0' : 1;
// 	(size == 0) ? str[0] = '-' : 1;
// 	return (str);
// }

void	create_string(float nb, char *rest, int i)
{
	int		afterdots;
	int		dot;

	dot = 0;
	afterdots = 0;
	if (nb < 1)
	{
		rest[i++] = '.';
		dot = i;
		while (afterdots < 2)
		{
			nb *= 10;
			if (((int)(nb + 0.01)) != 10)
				rest[i++] = (int)(nb + 48 + 0.01);
			nb -= (int)nb;
			afterdots++;
		}
	}
	while (i - dot < 2)
		rest[i++] = '0';
	rest[i] = '\0';
}

char	*ft_ftoa(float n)
{
	char		*flt;
	char		*first;
	long int	nb;
	int			i;
	int			j;

	i = -1;
	j = -1;
	nb = (long int)n;
	first = ft_itoa(nb);
	flt = (char *)malloc(100);
	n -= (float)nb;
	if (n < 0)
	{
		n *= -1;
		if (nb == 0)
			flt[++j] = '-';
	}
	while (first[++i])
		flt[++j] = first[i];
	create_string(n, flt, i);
	free(first);
	return (flt);
}
