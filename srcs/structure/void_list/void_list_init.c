#include "unknow_project.h"

t_void_list	create_t_void_list(void)
{
	t_void_list	list;

	if (!(list.data = (void **)malloc(sizeof(void *) * PUSH_SIZE)))
		error_exit(-15, "Can't malloc a void * array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_void_list	*initialize_t_void_list(void)
{
	t_void_list	*list;

	if (!(list = (t_void_list *)malloc(sizeof(t_void_list))))
		error_exit(-16, "Can't create a t_void_list array");
	*list = create_t_void_list();
	return (list);
}

void		delete_t_void_list(t_void_list dest)
{
	ft_memdel((void**)&(dest.data));
	// free(dest.data);
	// dest.data = NULL;
	dest.size = 0;
}

void		free_t_void_list(t_void_list *dest)
{
	delete_t_void_list(*dest);
	ft_memdel((void**)&(dest));
	// free(dest);
}

void		clean_t_void_list(t_void_list *dest)
{
	dest->size = 0;
}
