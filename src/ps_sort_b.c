/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:57:28 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/29 09:58:14 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rewind_rb(t_list **stack_b, t_list **stack_a, int w_len, int chunck)
{
	int	i;
	int	med_back;
	int	a;

	if (!chunck)
		return ;
	i = 0;
	a = 0;
	med_back = get_med_back(*stack_b, 0, chunck);
	while (i < w_len && chunck != ft_lstsize(*stack_b))
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
	op_b(stack_b, stack_a, chunck - a);
}
/*
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
	if (w_len <= 15 && ft_lstsize(*stack_b) < 16)
	{
		hurry_chunck(stack_a, stack_b, w_len);
		return ;
	}


void	hurry_chunck(t_list **stack_a, t_list **stack_b, int w_len)
{
	int		max;
	int		i;
	t_list	*node;

	i = 0;
	while (i < w_len)
	{
		max = get_max(*stack_b);
		node = *stack_b;
		while (node)
		{
			if (node->nbr == max)
				break ;
			node = node->next;
			rb(stack_b);
		}
		pa(stack_a, stack_b);
		i++;
	}
}
*/

void	op_b(t_list **stack_b, t_list **stack_a, int w_len)
{
	t_list	*node;
	int		med;
	int		a;
	int		b;
	t_list	*tmp;

	a = b = 0;
	med = get_med(*stack_b, 0, w_len);
	node = *stack_b;
	// if (is_sorted_b(*stack_b, w_len) && w_len > 2)
	// {
		while (a + b < w_len)
		{
			tmp = node->next;
			// if (!a && !is_sorted_b(*stack_b, ft_lstsize(*stack_b)))
			// 	break ;
			/*else */if (node->nbr >= med)
			{
				pa(stack_a, stack_b);
				a++;
			}
			else if (rb(stack_b))
				b++;
			node = tmp;
		}
		if (a)
			op_a(stack_a, stack_b, a);
		rewind_rb(stack_b, stack_a, b, w_len - a);
	// }
	// else if (w_len)
	// {
	// 	a = 0;
	// 	while (a < w_len)
	// 	{
	// 		pa(stack_a, stack_b);
	// 		a++;
	// 	}
	// 	op_a(stack_a, stack_b, w_len);
	// 	rewind_rb(stack_b, stack_a, b, w_len - a);
	// }
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

int	check_rest_len_b(t_list *stack_b, int med, int w_len)
{
	int	i;

	i = 0;
	if (!stack_b)
		return (1);
	while (i < w_len && stack_b)
	{
		if (stack_b->nbr >= med)
			return (1);
		stack_b = stack_b->next;
		i++;
	}
	return (0);
}
