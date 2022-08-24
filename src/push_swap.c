#include "push_swap.h"

 /*
Pseudo code for algorithm:

#for stack_a

1 -> find median of the current working part of the stack (the entire stack at the beginning)
2 -> split stack a into two parts, input variable will determine length to traverse,ra when > median and pb when <
3 -> call function to rra all ra'ed elements.
		-> function later calls sort_a
		-> recursively repeat untill working part becomes <= 2 elements
4 -> Sort the 2 elements
5 -> If pb occurs, call sort_b to retrieve the last chunk, sort_b will know how much to send back
	with the sort_a sending it how many elements it pushed to b.


#for stack_b

1 -> find median of the last chunk sent using input param, working chunk/part
2 -> split chunk into two, pa when >= median, rb otherwise.
3 -> if pa occurs, call sort_a with param how many pb made.
4 -> Call sort_a to handle the last pushed elements
4 -> call function rewind_rb to rrb all rb'ed elements.
		-> function then calls sort_b
 
 */

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char 	***args;

	args = parse_input(&argv[1], argc);
	stack_a = new_list(args);
	check_int(args);
	check_dupl(stack_a);
	stack_b = NULL;
	op_a(&stack_a, &stack_b, ft_lstsize(stack_a));
	/*
	ft_printf("stack_a: argc %d\n", argc);
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}*/
	return (0);
}
