#include "push_swap.h"

void	rewind_rb(t_list **stack_b, t_list **stack_a, int w_len)
{
	int	i;

	if(!w_len)
		return ;
	i = 0;
	while(i < w_len && w_len != ft_lstsize(*stack_b))
	{
		rrb(stack_b);
		i++;
	}
	op_b(stack_b, stack_a, w_len);
}

// int	cmp_b(t_list *node, int	med)
// {

// }

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
		else if (rb(stack_b))
			b++;
		node = tmp;
	}
	if (a)
		op_a(stack_a, stack_b, a);
	rewind_rb(stack_b, stack_a, b);
}

int	is_sorted_b(t_list *stack_b)
{
	int	tmp;

	while (stack_b)
	{
		tmp = stack_b->nbr;
		if(stack_b->nbr > tmp)
			return (1);
		stack_b = stack_b->next;
	}
	return (0);
}
