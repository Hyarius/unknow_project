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
	ft_memdel((void**)&tmp);
	ft_memdel((void**)&cmd);
}

void	*debug_malloc(size_t size, const char *file, int32_t line, const char *func)
{
	void *ptr;
	(void)file;
	(void)line;
	(void)func;
	ptr = malloc(size);
	if (ptr != NULL)
		ft_bzero(ptr, size);
	printf("Allocating %10lu bytes at\t%-10p in %-40s\t, line: %10d, function: %30s\n", size, ptr, file, line, func);
	return (ptr);
}