/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:38:46 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/29 23:25:34 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <string.h>
void	err_exit(int exit_code)
{
	write(2, "Error\n", 6);
	exit(exit_code);
}

char	**get_inst(void)
{
	char	**inst;
	int		i;

	inst = malloc(sizeof(char**) * 1000);

	//inst = {};
	i = 0;
	while (i < 1000)
	{
		inst[i] = get_next_line(0);
		if (inst[i] == NULL)
			return (inst);
		i++;		
	}
	return (NULL);
}

void	free_mem(char **mem, int size)
{
	int	i;

	i = 0;
	//(char *) mem;
	while (mem[i])
		free(mem[i++]);
}

void	check_inst(char **inst)
{
	int		i;
	int		j;
	char	**valid_inst;
	int		ok;

	valid_inst = ft_split("sa sb pa pb ra rb rra rrb rrr ss", ' ');
	i = 0;
	while (inst[i])
	{
		j = 0;
		ok = 1;
		while (valid_inst[j])
		{
			if (!ft_strncmp(inst[i], valid_inst[j], ft_strlen(inst[i]) - 1))
			{
				ok = 0;
			}
			j++;
		}
		if (ok)
			err_exit(1);
		i++;
	}
	free_mem(valid_inst, 10);
}

int	is_sorted_a(t_list *stack_a, int size)
{
	int	i;

	i = 0;
	//ft_printf("size is %d and i is %d\n", size, i);
	// if (ft_lstsize(stack_a) == size && size == 3)
	// 	return (0);
	// if (ft_lstsize(stack_a) <= 2)
	// 	return (1);
	while (i < size && stack_a && stack_a->next)
	{
		if (stack_a->nbr > stack_a->next->nbr)
			return (1);
		stack_a = stack_a->next;
		i++;
	}
	// ft_printf("size is %d and i is %d\n", size, i);
	// if (i < size - 1)
	//  	return (1);
	return (0);
}

void	carry_inst(t_list **stack_a, t_list **stack_b, char **inst)
{
	int	i;

	i = 0;
	while (inst[i])
	{
		if (!ft_strncmp(inst[i], "sa", 2))
			sa(stack_a);
		else if (!ft_strncmp(inst[i], "sb", 2))
			sb(stack_b);
		else if (!ft_strncmp(inst[i], "ra", 2))
			ra(stack_a);
		else if (!ft_strncmp(inst[i], "rb", 2))
			rb(stack_b);
		else if (!ft_strncmp(inst[i], "rra", 2))
			rra(stack_a);
		else if (!ft_strncmp(inst[i], "rrb", 2))
			rrb(stack_b);
		else if (!ft_strncmp(inst[i], "pa", 2))
			pa(stack_a, stack_b);
		else if (!ft_strncmp(inst[i], "pb", 2))
			pb(stack_b, stack_a);
		else if (!ft_strncmp(inst[i], "ss", 2))
			ss(stack_a, stack_b);
		else if (!ft_strncmp(inst[i], "rrr", 2))
			rrr(stack_a, stack_b);
		i++;
	}
}

int main(int argc, char *argv[])
{
    t_list	*stack_a;
	t_list	*stack_b;
	char 	***args;
	char	**inst;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	inst = get_inst();
	check_inst(inst);
	args = parse_input(&argv[1], argc);
	stack_a = new_list(args);
	check_int(args);
	check_dupl(stack_a);
	carry_inst(&stack_a, &stack_b, inst);
	// while (stack_a)
	// {
	// 	ft_printf("%d\n", stack_a->nbr);
	// 	stack_a = stack_a->prev;
	// }
	if (!is_sorted_a(stack_a, ft_lstsize(stack_a)) && !stack_b && stack_a)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}