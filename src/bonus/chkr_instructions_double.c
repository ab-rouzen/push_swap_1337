/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkr_instructions_double.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:47:07 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/30 19:51:53 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rr(t_list **stack_a, t_list **stack_b)
{
	rb(stack_b);
	ra(stack_a);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
