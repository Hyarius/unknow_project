#include "unknow_project.h"

t_vector2_list create_t_vector2_list(t_vector2 src)
{
	t_vector2_list list;

	list.next = NULL;
	list.vector = src;

	return (list);
}

t_vector2_list *initialize_t_vector2_list(t_vector2 src)
{
	t_vector2_list *list;

	if (!(list = (t_vector2_list *)malloc(sizeof(t_vector2_list))))
		return (NULL);

	*list = create_t_vector2_list(src);

	return (list);
}

int	t_vector2_list_len(t_vector2_list *src)
{
	t_vector2_list *tmp;
	int len;

	len = 0;
	tmp = src;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	t_vector2_list_push_back(t_vector2_list *dest, t_vector2 to_add)
{
	t_vector2_list *tmp;

	tmp = dest;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = initialize_t_vector2_list(to_add);
}

void	t_vector2_list_add(t_vector2_list *front, t_vector2_list *back)
{
	while (front->next != NULL)
		front = front->next;

	front->next = back;
}

void	free_t_vector2_list(t_vector2_list dest)
{
	(void)dest;
	//Clear content and don't free dest
}

void	delete_t_vector2_list(t_vector2_list *dest)
{
	(void)dest;
	//Clear content and free dest
}
