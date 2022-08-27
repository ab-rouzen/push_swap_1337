#include "push_swap.h"

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
	//ft_printf("In op_a, w_len is %d\n", w_len);
	if (is_sorted_a(*stack_a, w_len) && w_len > 2)
	{
		//ft_printf("is a w_len is %d\n", w_len);
		while(a + b < w_len )
		{
			tmp = node->next;
			//ft_printf("a is %d & b is %d and w_len si %d\n", a,b,w_len);
			// if (!b && !is_sorted_a(*stack_a, ft_lstsize(*stack_a)))
			// 	break ;
			if (node->nbr < med)
			{
				pb(stack_b, stack_a);
				b++;
			}
			// else if (!check_rest_len_a(node, med, w_len - a - b))
			// {
			// 	//ft_printf("a is %d & b is %d and w_len si %d\n", a,b,w_len);
			//  	break ;
			// }
			else if (ra(stack_a))
				a++;
			node = tmp;
		}
		//ft_printf("now here %d\n", w_len - b);
		if (is_sorted_a(*stack_a, ft_lstsize(*stack_a)))
			rewind_ra(stack_a, stack_b, a, w_len - b);
	}
	node = *stack_a;
	if (w_len == 2)
		if(node->nbr > node->next->nbr)
			sa(stack_a);
	op_b(stack_b, stack_a, b);
}

void	rewind_ra(t_list **stack_a, t_list **stack_b, int w_len, int chunck)
{
	int	i;
	int	med_back;
	int	b;

	if (!chunck)
		return ;
	i = 0;
	b = 0;
	//ft_printf("In rew_a, chunck is %d\n", chunck);
	med_back = get_med_back(*stack_a, 0, w_len);
	while(i < w_len & chunck != ft_lstsize(*stack_a))
	{
		rra(stack_a);
		if ((*stack_a)->nbr <= med_back & chunck != 2)
		{
			pb (stack_b, stack_a);
			b++;
		}
		i++;
	}
	if (chunck - b == 2)
	{
		if((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(stack_a);
	}
	//ft_printf("chunk is %d & b is %d\n", chunck, b);
	 op_a(stack_a, stack_b, chunck - b);
	op_b(stack_b, stack_a, b);
}

int	is_sorted_a(t_list *stack_a, int size)
{
	int	tmp;
	int	i;

	i = 0;
	if(stack_a)
		tmp = stack_a->nbr;
	while (i < size && stack_a)
	{
		if(stack_a->nbr <= tmp)
			return (1); 
		tmp = stack_a->nbr;
		stack_a = stack_a->next;
		i++;
	}
	//ft_printf("is sorted\n");
	return (0);
}

int	check_rest_len_a(t_list *stack_a, int med, int w_len)
{
	int	i;

	i = 0;
	if (!stack_a)
		return (1);
	while (i < w_len && stack_a)
	{
		if (stack_a->nbr < med)
			return (1);
		stack_a = stack_a->next;
		i++;
	}
	//ft_printf("been\n");
	return (0);
}