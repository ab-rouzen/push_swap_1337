/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:56:29 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/29 20:13:46 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*	Pseudo code for algorithm:                                                */
/*                                                                            */
/*	#for stack_a                                                              */
/*                                                                            */
/*	1                                                                         */
/*	-> find median of the current working part of the stack (the entire       */
/*	stack at the beginning)                                                   */
/*	2 -> split stack a into two parts,                                        */
/*	input variable will determine length to traverse,ra when > median         */
/*	and pb when <                                                             */
/*	3 -> call function to rra all ra'ed elements.                             */
/*		-> function later calls sort_a                                        */
/*		-> recursively repeat untill working part becomes <= 2 elements       */
/*	4 -> Sort the 2 elements                                                  */
/*	5 -> If pb occurs, call sort_b to retrieve the last chunk,                */
/*	sort_b will know how much to send back                                    */
/*	with the sort_a sending it how many elements it pushed to b.              */
/*                                                                            */
/*                                                                            */
/*	#for stack_b                                                              */
/*                                                                            */
/*	1 -> find median of the last chunk sent using input param,                */
/*		working chunk/part                                                    */
/*	2 -> split chunk into two, pa when >= median, rb otherwise.               */
/*	3 -> if pa occurs, call sort_a with param how many pb made.               */
/*	4 -> Call sort_a to handle the last pushed elements                       */
/*	4 -> call function rewind_rb to rrb all rb'ed elements.                   */
/*		-> function then calls sort_b                                         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_exit(int exit_code)
{
	write(2, "Error\n", 6);
	exit(exit_code);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	***args;
	int		size;

	if (argc == 1)
		return (0);
	args = parse_input(&argv[1], argc);
	stack_a = new_list(args);
	check_int(args);
	check_dupl(stack_a);
	size = ft_lstsize(stack_a);
	stack_b = NULL;
	//is_sorted_a(stack_a, size)
	//	return (0);
	op_a(&stack_a, &stack_b, size);
	//stack_a = ft_lstlast(stack_a);
	/*while (stack_a)
	{
		ft_printf("%d\n", stack_a->nbr);
		stack_a = stack_a->prev;
	}
	ft_printf("%s\n", stack_a);*/
	return (0);
}
