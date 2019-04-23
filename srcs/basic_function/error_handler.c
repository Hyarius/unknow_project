#include "unknow_project.h"

void error_exit(int error, char *message)
{
	printf("Error %d : %s\n", error, message);
	exit(error);
}
