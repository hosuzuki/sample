#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	int i = 0;

	if (!begin_list)
		return (0);
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

#ifdef TEST
# include <stdio.h>

void ft_free(t_list *list)
{
	t_list *tmp;
	while (list != NULL)
	{
		tmp = list->next;
		free (list);
		list = tmp;
	}
}

int ft_list_add_back(t_list *list)
{
		t_list *tmp;
		t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		ft_free(list);
		return (-1);
	}
	new->next = NULL;
	new->data = NULL;
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

	int main(void)
{
	int i;
	int j = 0;
	t_list *lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->next = NULL;
	lst->data = NULL;
	while (j < 10)
	{
		if (-1 == ft_list_add_back(lst))
		{
			ft_free(lst);
			return (-1);
		}
		j++;
	}
	i = ft_list_size(lst);
	printf("i: %d\n", i);
	return (0);
}

#endif
