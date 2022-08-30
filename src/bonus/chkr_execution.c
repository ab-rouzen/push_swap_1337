/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkr_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:02:44 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/30 20:33:27 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	carry_inst(t_list **stack_a, t_list **stack_b)
{
	char	*inst;

	while (1)
	{
		inst = get_next_line(0);
		if (!inst)
			return ;
		check_inst(inst);
		execute_inst(stack_a, stack_b, inst);
		free (inst);
	}
}

void	check_inst(char *inst)
{
	int			j;
	static char	*valid_inst[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	j = 0;
	while (valid_inst[j])
	{
		if (!ft_strncmp(inst, valid_inst[j], 5))
			return ;
		j++;
	}
	if (inst)
		err_exit(-1);
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

void	execute_inst(t_list **stack_a, t_list **stack_b, char *inst)
{
	if (!ft_strncmp(inst, "sa\n", 4))
		sa(stack_a);
	else if (!ft_strncmp(inst, "sb\n", 4))
		sb(stack_b);
	else if (!ft_strncmp(inst, "ra\n", 4))
		ra(stack_a);
	else if (!ft_strncmp(inst, "rb\n", 4))
		rb(stack_b);
	else if (!ft_strncmp(inst, "rra\n", 4))
		rra(stack_a);
	else if (!ft_strncmp(inst, "rrb\n", 4))
		rrb(stack_b);
	else if (!ft_strncmp(inst, "pa\n", 4))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(inst, "pb\n", 4))
		pb(stack_b, stack_a);
	else if (!ft_strncmp(inst, "ss\n", 4))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(inst, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else if (!ft_strncmp(inst, "rr\n", 4))
		rr(stack_a, stack_b);
}
