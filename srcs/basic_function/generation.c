#include "unknow_project.h"

int		generate_nbr(int min, int max)
{
	int	value;

	value = rand();
	return(rand() % max + min);
}
