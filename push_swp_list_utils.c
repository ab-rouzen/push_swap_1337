#include "push_swap.h"

t_list	*new_list(char **argv)
{
	int	i;
	t_list *list;

	i = 0;
	list = NULL;
	while (argv[i])
		ft_lstadd_front(&list, ft_lstnew(ft_atoi(argv[i++])));
	return (list);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

t_list	*ft_lstnew(int nbr)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	(*new_node).nbr = nbr;
	(*new_node).next = NULL;
	return (new_node);
}