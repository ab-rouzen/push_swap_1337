/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:56:52 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/28 18:06:08 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) > 1)
	{
		temp = ft_lstblast(*stack_a);
		ft_lstadd_front(stack_a, temp->next);
		temp->next = NULL;
		ft_printf("rra\n");
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
		ft_printf("ra\n");
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
		ft_printf("sa\n");
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
		ft_printf("pa\n");
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sb(stack_b);
	sa(stack_a);
	ft_printf("ss\n");
}
