/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkr_instructions_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:32:41 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/30 19:47:27 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_list **stack_a)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) > 1)
	{
		temp = ft_lstblast(*stack_a);
		ft_lstadd_front(stack_a, temp->next);
		temp->next = NULL;
	}
}

int	ra(t_list **stack_a)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) > 1)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		ft_lstadd_back(stack_a, temp);
	}
	return (1);
}

void	sa(t_list **stack_a)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) > 1)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		temp->prev = (*stack_a);
		(*stack_a)->next = temp;
		(*stack_a)->prev = NULL;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b)
	{
		temp = (*stack_b)->next;
		ft_lstadd_front(stack_a, *stack_b);
		*stack_b = temp;
		if (*stack_b)
			(*stack_b)->prev = NULL;
	}
}
