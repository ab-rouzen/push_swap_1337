/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:57:24 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/29 10:19:54 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_a(t_list **stack_a, t_list **stack_b, int w_len)
{
	int		med;
	t_list	*node;
	int		a;
	int		b;
	t_list	*tmp;

	node = *stack_a;
	a = b = 0;
	med = get_med(*stack_a, 0, w_len);
	if (is_sorted_a(*stack_a, w_len) && w_len > 2)
	{
		while (a + b < w_len)
		{
			tmp = node->next;
			if (node->nbr < med)
			{
				pb(stack_b, stack_a);
				b++;
			}
			else if (ra(stack_a))
				a++;
			node = tmp;
		}
		if (is_sorted_a(*stack_a, ft_lstsize(*stack_a)))
			rewind_ra(stack_a, stack_b, a, w_len - b);
	}
	node = *stack_a;
	if (w_len == 2)
		if (node->nbr > node->next->nbr)
			sa(stack_a);
	op_b(stack_b, stack_a, b);
}

void	rewind_ra(t_list **stack_a, t_list **stack_b, int w_len, int chunck)
{
	int	i;
	int	med_back;
	int	b;

	if (!chunck)
		return ;
	i = 0;
	b = 0;
	med_back = get_med_back(*stack_a, 0, w_len);
	while (i < w_len & chunck != ft_lstsize(*stack_a))
	{
		rra(stack_a);
		if ((*stack_a)->nbr <= med_back & chunck != 2)
		{
			pb(stack_b, stack_a);
			b++;
		}
		i++;
	}
	op_a(stack_a, stack_b, chunck - b);
	op_b(stack_b, stack_a, b);
}

int	is_sorted_a(t_list *stack_a, int size)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack_a)
		tmp = stack_a->nbr;
	while (i < size && stack_a)
	{
		if (stack_a->nbr <= tmp)
			return (1);
		tmp = stack_a->nbr;
		stack_a = stack_a->next;
		i++;
	}
	return (0);
}

int	check_rest_len_a(t_list *stack_a, int med, int w_len)
{
	int	i;

	i = 0;
	if (!stack_a)
		return (1);
	while (i < w_len && stack_a)
	{
		if (stack_a->nbr < med)
			return (1);
		stack_a = stack_a->next;
		i++;
	}
	return (0);
}
