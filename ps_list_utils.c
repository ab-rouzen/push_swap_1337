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
		{
			ft_lstadd_back(&list, ft_lstnew(ft_atoi(args[i][j++])));
		}
		i++;
	}
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*crawler;

	crawler = lst;
	while (crawler)
	{
		lst = crawler;
		crawler = crawler->next;
	}
	return (lst);
}

t_list	*ft_lstblast(t_list *lst)
{
	t_list	*crawler;


	crawler = lst;
	if (!crawler)
		return(crawler);
	while (crawler->next)
	{
		lst = crawler;
		crawler = crawler->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
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
	}
	if (!prev)
		*alst = new;
	else
		prev->next = new;
	new->next = NULL;
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

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	get_pos(t_list *lst, t_list *node)
{
	int	i;

	i = 1;
	while (lst)
	{
		if (lst == node)
			return (i);
		i++;
		lst = lst->next;
	}
	return (0);
}

