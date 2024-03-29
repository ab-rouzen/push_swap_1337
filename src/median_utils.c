/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:56:48 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/30 19:02:13 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	part_ar(int *ar, int left, int right, int idx)
{
	int	i;
	int	tmp;
	int	pos;

	pos = left;
	i = left;
	tmp = ar[right];
	ar[right] = ar[idx];
	ar[idx] = tmp;
	while (i < right)
	{
		if (ar[i] <= ar[right])
		{
			tmp = ar[pos];
			ar[pos] = ar[i];
			ar[i] = tmp;
			pos++;
		}
		i++;
	}
	tmp = ar[pos];
	ar[pos] = ar[right];
	ar[right] = tmp;
	return (pos);
}

int	f_med(int *ar, int left, int right, int mid)
{
	int	kth;

	kth = part_ar(ar, left, right, left);
	if (kth + 1 < mid)
		return (f_med(ar, kth + 1, right, mid));
	else if (kth + 1 > mid)
		return (f_med(ar, left, kth - 1, mid));
	return (ar[kth]);
}

int	get_med(t_list *stack_a, int left, int s_back)
{
	int	right;
	int	mid;
	int	*ar;
	int	med;

	mid = s_back / 2 + 1;
	ar = to_ar(stack_a, s_back);
	right = s_back - 1;
	med = f_med(ar, left, right, mid);
	free (ar);
	return (med);
}

int	*to_ar(t_list *stack, int size)
{
	int	*ar;
	int	i;
	int	s_stack;

	s_stack = ft_lstsize(stack);
	ar = malloc(sizeof(int) * size);
	i = 0;
	while (stack && i < size)
	{
		ar[i++] = stack->nbr;
		stack = stack->next;
	}
	return (ar);
}
