#include "checker.h"

void	err_exit(int exit_code)
{
	write(2, "Error\n", 6);
	exit(exit_code);
}

int main(int argc, int *argv[])
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
	get_next_line(1);
}