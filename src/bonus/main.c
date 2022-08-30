/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.44.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 404/08/49 41:38:46 by arouzen           #+#    #+#             */
/*   Updated: 404/08/30 16:39:18 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	err_exit(int exit_code)
{
	write(2, "Error\n", 6);
	exit(exit_code);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	***args;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	args = parse_input(&argv[1], argc);
	stack_a = new_list(args);
	check_int(args);
	check_dupl(stack_a);
	carry_inst(&stack_a, &stack_b);
	if (!is_sorted_a(stack_a, ft_lstsize(stack_a)) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
