#include "push_swap.h"

void	err_exit(int exit_code)
{
	ft_printf("Error!\n");
	exit(exit_code);
}

int	part_ar(int *ar,int left, int right, int idx)
{
	int	i;
	int	tmp;
	int	pos;

	pos = left;
	i = left;
	tmp = ar[right];
	ar[right] = ar[idx];
	ar[idx] = tmp;
	while (i < right)
	{
		if (ar[i] <= ar[right])
		{
			tmp = ar[pos];
			ar[pos] = ar[i];
			ar[i] = tmp;
			pos++;
		}
		i++;
	}
	tmp = ar[pos];
	ar[pos] = ar[right];
	ar[right] = tmp;
	return(pos);
}

int	f_med(int *ar, int left, int right, int mid)
{
	int	kth;

	kth = part_ar(ar, left, right, left);
	if (kth + 1 < mid)
		return(f_med(ar, kth + 1, right, mid));
	else if (kth + 1 > mid)
		return (f_med(ar, left, kth - 1, mid));
	return(ar[kth]);
}

int	get_med(t_list *stack_a, int left,int s_back)
{
	int	right;
	int	mid;
	int	*ar;
	int	med;

	mid = s_back / 2 + 1;
	ar = to_ar(stack_a, s_back);
	right = s_back - 1;
	med = f_med(ar, left, right, mid);
	//ft_printf("med is %d\n", med);
	return(med);
}

int	*to_ar(t_list *stack, int size)
{
	int	*ar;
	int	i;
	int	s_stack;

	s_stack = ft_lstsize(stack);
	ar = malloc(sizeof(int) * size);
	i = 0;
	while(stack && i <  size)
	{
		ar[i++] = stack->nbr;
		stack = stack->next;
	}
	return(ar);
}

int	is_sorted(t_list *stack_a)
{
	int	nb;

	if (!stack_a)
		return(1);
	nb = stack_a->nbr;	
	while (stack_a)
	{
		if(nb > stack_a->nbr)
			return(1);
		nb = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return(0);
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

void	op_a(t_list **stack_a, t_list **stack_b, int w_len)
{
	int		med;
	t_list	*node;
	int		a;
	int		b;
	t_list	*tmp;

	node = *stack_a;
	a = b = 0;
	med = get_med(*stack_a, 0, w_len);
	if (w_len > 2)
	{
		while(a + b < w_len)
		{
			tmp = node->next;
			if (node->nbr <= med)
			{
				pb(stack_b, stack_a);
				b++;
			}
			else
			{
				ra(stack_a);
				a++;
			}
			node = tmp;
		}
		if(a > 0)
			rewind_ra(stack_a, stack_b, a);
	}
	node = *stack_a;
	if (w_len == 2)
		if(node->nbr > node->next->nbr)
			sa(stack_a);
	if(b > 0)
		op_b(stack_b, stack_a, b);
}

void	rewind_ra(t_list **stack_a, t_list **stack_b, int w_len)
{
	int	i;

	i = 0;
	while(i < w_len)
	{
		rra(stack_a);
		i++;
	}
	op_a(stack_a, stack_b, w_len);
}

void	rewind_rb(t_list **stack_b, t_list **stack_a, int w_len)
{
	int	i;

	i = 0;
	while(i < w_len)
	{
		rrb(stack_b);
		i++;
	}
	op_b(stack_b, stack_a, w_len);
}

void	op_b(t_list **stack_b, t_list **stack_a, int w_len)
{
	t_list	*node;
	int		med;
	int		a;
	int		b;
	t_list	*tmp;

	a = b = 0;
	med = get_med(*stack_b, 0, w_len);
	node = *stack_b;
	while(a + b < w_len)
	{
		tmp = node->next;
		if (node->nbr >= med)
		{
			pa(stack_a, stack_b);
			a++;
		}
		else
		{
			rb(stack_b);
			b++;
		}
		node = tmp;
	}
	if(a > 0)
		op_a(stack_a, stack_b, a);
	if (b > 0)
		rewind_rb(stack_b, stack_a, b);

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
