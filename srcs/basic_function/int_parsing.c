#include "unknow_project.h"

int		ft_atoi(const char *str)
{
	int			i;
	long long	number;
	int			neg;

	i = 0;
	number = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * neg);
}
