#include "push_swap.h"

void	err_exit(int exit_code)
{
	ft_printf("Error!\n");
	exit(exit_code);
}

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