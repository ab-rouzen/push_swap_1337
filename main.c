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
	
	check_int(&argv[1]);
	stack_a = new_list(&argv[1]);
	sa(&stack_a);
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
	return (0);
}