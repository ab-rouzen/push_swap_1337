/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:08:57 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/28 18:10:18 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (crawler);
	while (crawler->next)
	{
		lst = crawler;
		crawler = crawler->next;
	}
	return (lst);
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
