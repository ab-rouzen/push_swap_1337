#include "push_swap.h"

void	err_exit(int exit_code)
{
	ft_printf("Error!\n");
	exit(exit_code);
}

int	sort_1(t_list **stack_a, t_list **stack_b)
{
	t_list *node;
	int	min;
	int	i;
	int	pos;

	while (1)
	{
		node = *stack_a;
		min = node->nbr;
		pos = -1;
		i = 0;
		while (node)
		{
			if (min > node->nbr)
			{
				min = node->nbr;
				pos = i;
			}
			node = node->next;
			i++;
		}
		if (pos == -1 && ft_lstsize(*stack_a) == 1)
			return 0;
		for(i = 0; i < pos; i++)
			ra(stack_a);
		pb(stack_b, stack_a);
	}
	return 0;
}

void	sort_2(t_list **stack_a, t_list **stack_b)
{
	t_list	*step_a;
	int		nbr;
	int		i;

	step_a = *stack_a;
	nbr = step_a->nbr;
	while(step_a)
	{
		if (nbr > step_a->nbr )
		{
			if (nbr > (ft_lstlast(*stack_a))-
			>nbr)
			{
				ra(stack_a);
			}
			else
				sa(stack_a);
			step_a = step_a->next;
			//nbr = step_a->nbr;
		}
		else if (nbr > (ft_lstlast(*stack_a))->nbr)
		{
			i = 0;
			while (i < get_pos(*stack_a, step_a) - 1)
			{
				pb(stack_b, stack_a);
				i++;
			}
			rra(stack_a);
			//sa(stack_a);
			for(i = 0; i < 3; i++)
				pb(stack_b, stack_a);
			step_a = *stack_a;
			nbr = (*stack_a)->nbr;
		}
		else
			step_a = step_a->next;
	}
}

char ***parse_input(char **argv, int	argc)
{
	char	***list;
	int		i;

	i = 0;
	list = malloc(sizeof(char***) * argc);
	while(argv[i])
	{
		list[i] = ft_split(argv[i], ' ');
		i++;
	}
	list[i] = NULL;
	return (list);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char 	***args;

	args = parse_input(&argv[1], argc);
	check_int(args);
	stack_a = new_list(args);
	check_dupl(stack_a);
	stack_b = NULL;
	//ft_printf("size stack_a is : %d\n", ft_lstsize(stack_a));
	//pb(&stack_b, &stack_a);
	//pa(&stack_a, &stack_b);
	//ra(&stack_a);
	sort_2(&stack_a, &stack_b);
	// while (stack_b)
	// 	pa(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
	/*
	ft_printf("stack_b:\n");
	while (stack_b)
	{
		ft_printf("%d\n", stack_b->nbr);
		stack_b = stack_b->next;
	}
	*/
	return (0);
}
