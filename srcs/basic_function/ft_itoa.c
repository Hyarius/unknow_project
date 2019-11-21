#include "unknow_project.h"

static int	ft_size(long nb)
{
	int		size;

	size = 0;
	if (nb <= 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*array;
	int		size;
	long	nb;

	nb = n;
	size = ft_size(nb);
	if (!(array = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	array[size--] = '\0';
	if (nb == 0)
		array[0] = '0';
	if (nb < 0)
	{
		array[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		array[size] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
	return (array);
}
