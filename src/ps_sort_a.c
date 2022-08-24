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
			else if (ra(stack_a))
				a++;
			node = tmp;
		}
		rewind_ra(stack_a, stack_b, a);
	}
	node = *stack_a;
	if (w_len == 2)
		if(node->nbr > node->next->nbr)
			sa(stack_a);
	op_b(stack_b, stack_a, b);
}

void	rewind_ra(t_list **stack_a, t_list **stack_b, int w_len)
{
	int	i;

	if (!w_len)
		return ;
	i = 0;
	while(i < w_len & w_len != ft_lstsize(*stack_a))
	{
		rra(stack_a);
		i++;
	}
	op_a(stack_a, stack_b, w_len);
}

int	is_sorted_a(t_list *stack_a)
{
	int	tmp;

	while (stack_a)
	{
		tmp = stack_a->nbr;
		if(stack_a->nbr < tmp)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
