#include "unknow_project.h"

t_gui create_t_gui(t_rectangle rec)
{
	t_gui result;

    result.rec = rec;
	return (result);
}

t_gui *initialize_t_gui(t_rectangle rec)
{
	t_gui *result;

	if (!(result = (t_gui *)malloc(sizeof(t_gui))))
		error_exit(-13, "Can't create a t_gui");

	*result = create_t_gui(rec);

	return (result);
}
