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

	mid = (ft_lstsize(stack_a) - s_back - 1) / 2 + 1;
	ar = to_ar(stack_a, s_back);
	right = ft_lstsize(stack_a) - 1 - s_back;
	med = f_med(ar, left, right, mid);
	ft_printf("med is %d\n", med);
	return(med);
}

int	*to_ar(t_list *stack, int size)
{
	int	*ar;
	int	i;
	int	s_stack;

	s_stack = ft_lstsize(stack);
	ar = malloc(sizeof(int) * s_stack - size);
	i = 0;
	while(stack && i <  s_stack - size)
	{
		ar[i++] = stack->nbr;
		stack = stack->next;
	}
	return(ar);
}

void	sort_med_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*tmp;
	int		left;

	node = *stack_a;
	left = (*stack_a)->nbr;
	if (is_sorted(*stack_a))
	{
	while (node)
	{
		if(node->nbr <= left)
		{
			tmp = node->next;
			pb(stack_b, stack_a);
			node = tmp;
		}
		else
		{
			tmp = node->next;
			ra(stack_a);
			node = tmp;
		}
	}
	if((*stack_a))
		sort_med_a(stack_a, stack_b);
	sort_med_b(stack_b, stack_a);
	}
}

int	s_size;
void	sort_med_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*node;
	t_list	*tmp;
	int		left;

	node = *stack_b;
	left = (*stack_b)->nbr;
	while (node)
	{
		if(node->nbr >= left)
		{
			tmp = node->next;
			pa(stack_a, stack_b);
			node = tmp;
		}
		else
		{
			tmp = node->next;
			rb(stack_b);
			node = tmp;
		}
	}
	if((*stack_b))
		sort_med_b(stack_b, stack_a);
	sort_med_a(stack_a, stack_b);
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

int	sort_1_3(t_list **stack_a, t_list **stack_b)
{
	t_list *node;
	int	min;
	int	i;
	int	pos;
	//int	min_3[3];

	//min={0};
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
		if ((pos == -1 && ft_lstsize(*stack_a) == 1))
			return 0;
		if (pos < ft_lstsize(*stack_a) - pos)
		{
			for(i = 0; i < pos; i++)
				ra(stack_a);
		}
		else
		{
			for(i = 0; i < ft_lstsize(*stack_a) - pos; i++)
				rra(stack_a);
		}
		pb(stack_b, stack_a);
	}
	return 0;
}

int	sort_1_2(t_list **stack_a, t_list **stack_b)
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
		if ((pos == -1 && ft_lstsize(*stack_a) == 1))
			return 0;
		if (pos < ft_lstsize(*stack_a) - pos)
		{
			for(i = 0; i < pos; i++)
				ra(stack_a);
		}
		else
		{
			for(i = 0; i < ft_lstsize(*stack_a) - pos; i++)
				rra(stack_a);
		}
		pb(stack_b, stack_a);
	}
	return 0;
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
		if (pos == -1 || ft_lstsize(*stack_a) == 1)
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
			if (nbr > (ft_lstlast(*stack_a))->nbr)
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

void	med_sort_a(t_list **stack_a, t_list **stack_b, int med, int s_back)
{
	t_list	*node;
	int	size;
	int	i;

	size = ft_lstsize(*stack_a) - s_back;
	node = *stack_a;
	i = 0;
	while (i < 2 && s_back)
	{
		ra(stack_a);
		i++;
	}
	i = 0;
	while(node && i < size && size > 2)
	{
		if(node->nbr > med)
		{
			node = node->next;
			pb(stack_b, stack_a);
		}
		else
		{
			node = node->next;
			ra(stack_a);
		}
		i++;
	}
	if (ft_lstsize(*stack_a) - s_back> 2)
	{
		med = get_med(*stack_a, 0, s_back);
		med_sort_a(stack_a, stack_b, med, s_back);
	}
	if (ft_lstsize(*stack_a) == 2)
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			ra(stack_a);
	if (size <= 1)
		ra(stack_a);
	if (size == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (s_size != ft_lstsize(*stack_a) && size != 1 && s_back != s_size - 1)
	{
		med = get_med(*stack_b, 0, s_back);
		med_sort_b(stack_b, stack_a, med, s_back + 2);
	}
}

void	med_sort_b(t_list **stack_b, t_list **stack_a, int med, int s_back)
{
	t_list	*node;
	int	size;
	int	i;

	size = ft_lstsize(*stack_b);
	node = *stack_b;
	i = 0;
	while(i < size && size != 2)
	{
		if(node->nbr > med)
		{
			node = node->next;
			pa(stack_a, stack_b);
		}
		else
		{
			node = node->next;
			rb(stack_b);
		}
		i++;
	}
	if (ft_lstsize(*stack_b) > 2)
	{
		med = get_med(*stack_b, 0, 0);
		med_sort_b(stack_b, stack_a, med, s_back);
	}
	if (ft_lstsize(*stack_b) == 2)
	{
		if ((*stack_b)->nbr < (*stack_b)->next->nbr)
			rb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	med = get_med(*stack_a, 0, s_back);
	med_sort_a(stack_a, stack_b, med, s_back + 2);
	}
} 

void	init_part(t_list **stack_a, t_list **stack_b, int	*tracker)
{
	int		med;
	t_list	*node;
	int		i;
	t_list	*lst_el;
	t_list	*tmp;

	lst_el = ft_lstlast(*stack_a);
	node = *stack_a;
	i = 0;
	med = get_med(*stack_a, 0, 0);
	while(node)
	{
		tmp = node->next;
		if (node->nbr > med)
		{
			pb(stack_b, stack_a);
			i++;
		}
		else
			ra(stack_a);
		if(node == lst_el)
			node = NULL;
		else
			node = tmp;
	}
	add_tracker(tracker, i);
	if (ft_lstsize(*stack_a) > 3)
		init_part(stack_a, stack_b, tracker);
}

void	add_tracker(int	*tracker, int i)
{
	int	j;

	j = 0;
	while(tracker[j])
		j++;
	tracker[j] = i;
	//tracker[j++] = 0;
}

int	get_borne(int	*tracker)
{
	int	i;

	i = 0;
	while(tracker[i])
		i++;
	return(--i);
}

void	op_a(t_list **stack_a, t_list **stack_b, int *tracker)
{
	int		med;
	t_list	*node;
	int		i;
	t_list	*tmp;

	node = *stack_a;
	i = 0;
	med = get_med(*stack_a, 0, ge);
	while(node)
	{
		if (node->nbr > med)
		{
			tmp  = node;
			pb(stack_b, stack_a);
			i++;
		}
		else
		{
			tmp = node;
			ra(stack_a);
		}
		node = node->next;
	}
	add_tracker(tracker, i);
	//op_b(stack_b, stack_a, tracker);
}

void	op_b(t_list **stack_b, t_list **stack_a, int *tracker)
{
	t_list	*node;
	int		size;
	int		med;
	int		a;
	int		b;
	t_list	*tmp;

	size = get_borne(tracker);
	a = b = 0;
	med = get_med(stack_b, 0, size);
	while(a + b < size)
	{
		tmp = node->next;
		if (node->nbr > med)
		{
			pa(stack_a, stack_b);
			a++;
		}
		else
		{
			ra(stack_b);
			b++;
		}
		node = tmp;
	}
	add_tracker(tracker, i);
}
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char 	***args;
	int		tracker[100] = {};
	int	med;

	args = parse_input(&argv[1], argc);
	stack_a = new_list(args);
	med = get_med(stack_a, 0, 0);
	s_size = ft_lstsize(stack_a);
	check_int(args);
	check_dupl(stack_a);
	stack_b = NULL;
	//ft_printf("size stack_a is : %d\n", ft_lstsize(stack_a));
	//pb(&stack_b, &stack_a);
	//pa(&stack_a, &stack_b);
	//ra(&stack_a);
	//sort_med_a(&stack_a, &stack_b);
	// while (stack_b)
	// 	pa(&stack_a, &stack_b);
	//med_sort_a(&stack_a, &stack_b, med, 0);
	// med = get_med(to_ar(stack_b),0,ft_lstsize(stack_b) - 1, (ft_lstsize(stack_b) - 1) / 2 + 1);
	// med_sort_b(&stack_b, &stack_a, med);
	init_part(&stack_a, &stack_b, tracker);
	//op_a(&stack_a, &stack_b, tracker);
	ft_printf("stack_a: argc %d\n", argc);
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
	
	ft_printf("stack_b:\n");
	while (stack_b)
	{
		ft_printf("%d\n", stack_b->nbr);
		stack_b = stack_b->next;
	}
	
	return (0);
}
