#include "push_swap.h"

void	rewind_rb(t_list **stack_b, t_list **stack_a, int w_len, int chunck)
{
	int	i;
	int	ii;
	int	med_back;
	int	a;
	int	aa;
	int b;

	if(!chunck)
		return ;
	i = 0;
	a = 0;
	aa = 0;
	ii = 0;
	b = 0;
	ft_printf("In rew_b, chunck is %d && w_len is %d\n", chunck, w_len);
	med_back = get_med_back(*stack_b, w_len, chunck - w_len);
	while(i < w_len && (chunck != ft_lstsize(*stack_b) || chunck != w_len))
	{
		rrb(stack_b);
		if ((*stack_b)->nbr >= med_back)
		{
			pa(stack_a, stack_b);
			a++;
		}
		i++;
	}
	// if (chunck - w_len)
	// 	i = - i - a;
	ft_printf("2nd loop rew_b, a is %d \ni is %d\n", a,i);
	/*while (ii < chunck - w_len + i - a && chunck - w_len)
	{
		if ((*stack_b)->nbr >= med_back)
		{
			pa(stack_a, stack_b);
			aa++;
		}
		else
		{
			rb(stack_a);
			b++;
		}
		ii++;
	}*/
	if (chunck != w_len)
		op_b(stack_b, stack_a, i - a, a);
	else
		op_b(stack_b, stack_a, chunck, a);
	ft_printf("Exit rew_b, a is %d \ni is %d\naa is %d\n", a,i,aa);
	//op_a(stack_a, stack_b, a + aa);
	// if (ii)
	// 	rewind_rb(stack_b, stack_a, b + i - a, b + i - a);
	//op_b(stack_b, stack_a, chunck - a - aa);
}

void	op_b(t_list **stack_b, t_list **stack_a, int w_len, int prev)
{
	t_list	*node;
	int		med;
	int		a;
	int		b;
	t_list	*tmp;

	a = b = 0;
	med = get_med(*stack_b, w_len);
	node = *stack_b;
	ft_printf("In op_b, w_len is %d\n", w_len);
	if (is_sorted_b(*stack_b, w_len + prev))
	{
		while(a + b < w_len)
		{
			tmp = node->next;
			if (!a && !is_sorted_b(*stack_b, ft_lstsize(*stack_b)))
				break ;
			else if (node->nbr >= med)
			{
				pa(stack_a, stack_b);
				a++;
				//ft_printf("(opb) PA:a is %d\n", a);
			}
			else if (!check_rest_len_b(tmp, med, w_len - a - b))
			{
				//ft_printf("REST:a is %d & b is %d and w_len si %d\n", a,b,w_len);
				break ;
			}
			else if (rb(stack_b))
				b++;
			node = tmp;
		}
		//ft_printf("a is %d & b is %d and w_len si %d\n", a,b,w_len);
		if (a)
			op_a(stack_a, stack_b, a + prev, 0);
		rewind_rb(stack_b, stack_a, b, w_len - a);
	}
	else if (w_len)
	{
		a = 0;
		while (a < w_len)
		{
			pa(stack_a, stack_b);
			a++;
		}
		op_a(stack_a, stack_b, w_len, 0);
		rewind_rb(stack_b, stack_a, b, w_len - a);
	}
	
}

int	is_sorted_b(t_list *stack_b, int size)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack_b)
		tmp = stack_b->nbr;
	while (i < size && stack_b)
	{
		if(stack_b->nbr > tmp)
			return (1);
		tmp = stack_b->nbr;
		stack_b = stack_b->next;
		i++;
	}
	return (0);
}

int	check_rest_len_b(t_list *stack_b, int med, int w_len)
{
	int	i;

	i = 0;
	if (!stack_b)
		return (1);
	while (i < w_len && stack_b)
	{
		if (stack_b->nbr >= med)
			return (1);
		stack_b = stack_b->next;
		i++;
	}
	//ft_printf("been\n");
	return (0);
}