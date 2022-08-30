/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_utils_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:01:16 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/29 18:12:56 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_med_back(t_list *stack_a, int left, int s_back)
{
	int	right;
	int	mid;
	int	*ar;
	int	med;

	mid = s_back / 2 + 1;
	ar = to_ar_back(stack_a, s_back);
	right = s_back - 1;
	med = f_med(ar, left, right, mid);
	return (med);
	free (ar);
}

int	*to_ar_back(t_list *stack, int size)
{
	int	*ar;
	int	i;

	stack = ft_lstlast(stack);
	ar = malloc(sizeof(int) * size);
	i = 0;
	while (stack && i < size)
	{
		ar[i++] = stack->nbr;
		stack = stack->prev;
	}
	return (ar);
}
