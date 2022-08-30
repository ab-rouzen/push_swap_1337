/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:57:24 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/30 19:53:34 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_a(t_list **stack_a, t_list **stack_b, int w_len)
{
	int		med;
	t_list	*node;
	int		a;
	int		b;

	node = *stack_a;
	a = 0;
	b = 0;
	med = get_med(*stack_a, 0, w_len);
	while (a + b < w_len && w_len > 2 && check_stack(*stack_a, &a, b))
	{
		if (node->nbr < med)
		{
			pb(stack_b, stack_a);
			b++;
		}
		else if (ra(stack_a))
			a++;
		node = *stack_a;
	}
	sort_head(stack_a, w_len);
	rewind_ra(stack_a, stack_b, a);
	op_b(stack_b, stack_a, b);
}

int	check_stack(t_list *stack, int *ra, int pb)
{
	int	size;

	size = ft_lstsize(stack);
	if ((!is_sorted_a(stack, size) && !pb) || (size == 3 && !pb))
	{
		*ra = 0;
		return (0);
	}
	return (1);
}

void	sort_head(t_list **stack_a, int w_len)
{
	t_list	*node;

	node = *stack_a;
	if (ft_lstsize(node) == 3)
	{
		if (node->nbr == get_max(*stack_a))
		{
			ra(stack_a);
			if ((*stack_a)->nbr > (*stack_a)->next->nbr)
				sa(stack_a);
		}
		else if (node->next->nbr == get_max(*stack_a))
		{
			rra(stack_a);
			if ((*stack_a)->nbr > (*stack_a)->next->nbr)
				sa(stack_a);
		}
		else if (node->nbr > node->next->nbr)
			sa(stack_a);
	}
	else if (w_len == 2)
		if (node->nbr > node->next->nbr)
			sa(stack_a);
}

void	rewind_ra(t_list **stack_a, t_list **stack_b, int w_len)
{
	int	i;
	int	med_back;
	int	b;

	if (!w_len)
		return ;
	i = 0;
	b = 0;
	med_back = get_med_back(*stack_a, 0, w_len);
	while (i < w_len && w_len != ft_lstsize(*stack_a))
	{
		rra(stack_a);
		if ((*stack_a)->nbr <= med_back & w_len != 2)
		{
			pb(stack_b, stack_a);
			b++;
		}
		i++;
	}
	op_a(stack_a, stack_b, w_len - b);
	op_b(stack_b, stack_a, b);
}

int	is_sorted_a(t_list *stack_a, int size)
{
	int	i;

	i = 0;
	while (i < size && stack_a && stack_a->next)
	{
		if (stack_a->nbr > stack_a->next->nbr)
			return (1);
		stack_a = stack_a->next;
		i++;
	}
	return (0);
}
