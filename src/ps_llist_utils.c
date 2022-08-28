#include "push_swap.h"

t_list	*new_list(char ***args)
{
	int	i;
	int	j;
	t_list *list;

	j = 0;
	i = 0;
	list = NULL;
	while (args[i])
	{
		j = 0;
		while(args[i][j])
			ft_lstadd_back(&list, ft_lstnew(ft_atoi(args[i][j++])));
		//ft_printf("%d\n", list->nbr);
		i++;
	}
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;
	t_list	*prv;

	node = lst;
	prv = lst;
	while (node)
	{
		prv = node;
		node = node->next;
		if (node == lst)
			break ;
	}
	return (prv);
}

t_list	*ft_lstblast(t_list *lst)
{
	t_list	*node;


	node = lst;
	if (!node)
		return(node);
	while (node->next)
	{
		lst = node;
		node = node->next;
	}
	return (lst);
}
/*
void	ft_remove_list(t_list **alst, t_list *el)
{
	t_list	*node;
	t_list	*prev;

	node = *alst;
	prev = *alst;
	while (node && node != el)
	{
		prev = node;
		node = node->next;
		if (node == *alst)
			break ;
	}
	if (prev == *alst == el)
		*alst = NULL;
	else if (node == el)
	{
		prev = 
	}
}
*/

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (*alst)
	{
		new->next = *alst;
		new->prev = (*alst)->prev;
		(*alst)->prev = new;
		*alst = new;
		(*alst)->prev->next = new;
	}
	// if ((*alst))
	// {
	// 	new->prev = (*alst)->prev;
	// 	(*alst)->prev = new;
	// }
	else
	{
		*alst = new;
		(*alst)->next = new;
		(*alst)->prev = new;
	}
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *prev;
	t_list	*step;

	prev = step = *alst;
	while (step)
	{
		prev = step;
		step = step->next;
		if (step == (*alst))
			break ;
	}
	if (!step)
		*alst = new;
	else
		prev->next = new;
	new->next = (*alst);
	if (!prev)
		new->prev = new;
	else
	{
		new->prev = prev;
		(*alst)->prev = new;
	}
}

t_list	*ft_lstnew(int nbr)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->nbr = nbr;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

int	ft_lstsize(t_list *lst)
{
	int	i;
	t_list	*node;

	i = 0;
	node = lst;
	while (node)
	{
		node = node->next;
		i++;
		if (node == lst)
			break ;
	}
	return (i);
}

