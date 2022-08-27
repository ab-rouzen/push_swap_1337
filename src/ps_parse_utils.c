#include "push_swap.h"

char ***parse_input(char **argv, int	argc)
{
	char	***list;
	int		i;

	i = 0;
	list = malloc(sizeof(char***) * argc);
	while(argv[i])
	{
		list[i] = ft_split(argv[i], ' ');
		if(!(*list[i]))
			err_exit(-1);
		i++;
	}
	list[i] = NULL;
	return (list);
}

void	check_int(char ***nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		check_fragment(nbr[i]);
		i++;
	}
}

void	check_dupl(t_list *stack_a)
{
	t_list	*step_x;
	t_list	*step_y;

	step_x = step_y = stack_a;
	while (step_x)
	{
		while(step_y)
		{
			if (step_x->nbr == step_y->nbr && step_x != step_y)
				err_exit(8);
			step_y = step_y->next;
		}
		step_x = step_x->next;
		step_y = stack_a;
	}
}

void	check_fragment(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		check_nbr(str[i]);
		i++;
	}
}

void	check_nbr(char *str)
{
	if ((*str == '-' || *str == '+') && ft_strlen(str) != 1)
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			err_exit(0);
		str++;
	}
}
