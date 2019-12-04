#include "unknow_project.h"

void	ft_get_leaks(char *prog_name, char *msg)
{
	char *cmd;
	char *tmp;

	cmd = ft_strjoin("leaks ", prog_name);
	tmp = cmd;
	cmd = ft_strjoin(cmd, " | grep 'total leaked bytes'");
	ft_putstr(msg);
	ft_putchar('\n');
	system(cmd);
	free(tmp);
	free(cmd);
}