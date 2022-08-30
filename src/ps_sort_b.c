/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:57:28 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/29 21:19:12 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rewind_rb(t_list **stack_b, t_list **stack_a, int w_len)
{
	int	i;
	int	med_back;
	int	a;

	if (!w_len)
		return ;
	i = 0;
	a = 0;
	med_back = get_med_back(*stack_b, 0, w_len);
	while (i < w_len && w_len != ft_lstsize(*stack_b))
	{
		rrb(stack_b);
		if ((*stack_b)->nbr >= med_back)
		{
			pa(stack_a, stack_b);
			a++;
		}
		i++;
	}
	op_a(stack_a, stack_b, a);
	op_b(stack_b, stack_a, w_len - a);
}

int	get_max(t_list *stack)
{
	int	max;

	max = stack->nbr;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

void	op_b(t_list **stack_b, t_list **stack_a, int w_len)
{
	t_list	*node;
	int		med;
	int		a;
	int		b;

	a = 0;
	b = 0;
	med = get_med(*stack_b, 0, w_len);
	node = *stack_b;
	//ft_printf("in op b, w_len is: %d\n", w_len);
	while (a + b < w_len && w_len > 2)
	{
		if (node->nbr >= med)
		{
			pa(stack_a, stack_b);
			a++;
		}
		else if (rb(stack_b))
			b++;
		node = *stack_b;
	}
	pa_if_w_len(stack_b, stack_a, w_len);
	if (a)
		op_a(stack_a, stack_b, a);
	rewind_rb(stack_b, stack_a, b);
}

void	pa_if_w_len(t_list **stack_b, t_list **stack_a, int w_len)
{
	int	i;

	if (w_len > 2 || !w_len)
		return ;
	i = 0;
	while (i < w_len)
	{
		pa(stack_a, stack_b);
		i++;
	}
	op_a(stack_a, stack_b, w_len);
}

int	is_sorted_b(t_list *stack_b, int size)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack_b)
		tmp = stack_b->nbr;
	while (i < size && stack_b)
	{
		if (stack_b->nbr > tmp)
			return (1);
		tmp = stack_b->nbr;
		stack_b = stack_b->next;
		i++;
	}
	return (0);
}
