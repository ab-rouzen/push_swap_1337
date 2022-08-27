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
	char 	***args;

	if (argc == 1)
		return (0);
	args = parse_input(&argv[1], argc);
	stack_a = new_list(args);
	check_int(args);
	check_dupl(stack_a);
	stack_b = NULL;
	op_a(&stack_a, &stack_b, ft_lstsize(stack_a));
	stack_a = ft_lstlast(stack_a);
	/*while (stack_a)
	{
		ft_printf("%d\n", stack_a->nbr);
		stack_a = stack_a->prev;
	}
	ft_printf("%s\n", stack_a);*/
	return (0);
}