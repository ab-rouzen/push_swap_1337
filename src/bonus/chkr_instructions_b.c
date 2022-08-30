/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkr_instructions_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:38:51 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/30 19:47:06 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb(t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) > 1)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		temp->prev = (*stack_b);
		(*stack_b)->next = temp;
		(*stack_b)->prev = NULL;
	}
}

int	rb(t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) > 1)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		ft_lstadd_back(stack_b, temp);
	}
	return (1);
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) > 1)
	{
		temp = ft_lstblast(*stack_b);
		ft_lstadd_front(stack_b, temp->next);
		temp->next = NULL;
	}
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	if (*stack_a)
	{
		temp = (*stack_a)->next;
		ft_lstadd_front(stack_b, *stack_a);
		*stack_a = temp;
		if (*stack_a)
			(*stack_a)->prev = NULL;
	}
}
