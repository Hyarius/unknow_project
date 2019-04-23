#include "unknow_project.h"

int				get_next_line(const int fd, char **line)
{
	static char *saved = NULL;
	char		*buffer;
	int			result = 1;

	if (fd > 10000 || fd < 0)
		return (-1);

	while (ft_strchr(saved, '\n') == 0 && result > 0)
	{
		buffer = ft_strnew(BUFF_SIZE);
		result = read(fd, buffer, BUFF_SIZE);
		ft_stradd(&saved, buffer);
		free(buffer);
		if (result == -1)
			return (-1);
	}
	*line = ft_strcut(&saved, '\n');
	if (result + ft_strlen(*line) == 0)
		return (0);
	else
		return (1);
}
