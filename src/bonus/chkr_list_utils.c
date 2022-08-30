/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkr_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:36:20 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/29 21:36:21 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*new_list(char ***args)
{
	int		i;
	int		j;
	t_list	*list;

	j = 0;
	i = 0;
	list = NULL;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			ft_lstadd_back(&list, ft_lstnew(ft_atoi(args[i][j++])));
		}
		i++;
	}
	return (list);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	if ((*alst))
		(*alst)->prev = new;
	new->prev = NULL;
	*alst = new;
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*prev;
	t_list	*step;

	step = *alst;
	prev = *alst;
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
	new->prev = prev;
}

t_list	*ft_lstnew(int nbr)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->nbr = nbr;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}