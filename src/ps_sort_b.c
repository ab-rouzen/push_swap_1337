#include "push_swap.h"

void	rewind_rb(t_list **stack_b, t_list **stack_a, int w_len, int chunck)
{
	int	i;
	int	med_back;
	int	a;

	if(!chunck)
		return ;
	i = 0;
	a = 0;
	//ft_printf("In rew_b, chunck is %d\n", chunck);
	med_back = get_med_back(*stack_b, 0, chunck);
	while(i < w_len && chunck != ft_lstsize(*stack_b))
	{
		rrb(stack_b);
		if ((*stack_b)->nbr >= med_back)
		{
			pa(stack_a, stack_b);
			a++;
		}
		i++;
	}
	//ft_printf("Exit rew_b, a is %d\n", a);
	op_a(stack_a, stack_b, a);
	op_b(stack_b, stack_a, chunck - a);
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
	//ft_printf("In op_b, w_len is %d\n", w_len);
	if (is_sorted_b(*stack_b, w_len) && w_len > 2)
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
			//ft_printf("PA:a is %d\n", a);
		}
		// else if (!check_rest_len_b(tmp, med, w_len - a - b))
		// {
		// 	//ft_printf("REST:a is %d & b is %d and w_len si %d\n", a,b,w_len);
		// 	break ;
		// }
		else if (rb(stack_b))
			b++;
		node = tmp;
	}
	//ft_printf("a is %d & b is %d and w_len si %d\n", a,b,w_len);
	if (a)
		op_a(stack_a, stack_b, a);
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
	op_a(stack_a, stack_b, w_len);
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