#include "push_swap.h"

void	sb(t_list **stack_b)
{
	t_list *temp;

	if (ft_lstsize(*stack_b) >= 2)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		(*stack_b)->next = temp;
		ft_printf("sb\n");
	}
}

void	rb(t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) > 1)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstadd_back(stack_b, temp);
		ft_printf("rb\n");
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rb(stack_b);
	ra(stack_a);
}

void	rra(t_list **stack_a)
{
	t_list *temp;

	if (ft_lstsize(*stack_a) > 1)
	{
		temp = ft_lstblast(*stack_a);
		ft_lstadd_front(stack_a, temp->next);
		temp->next = NULL;
		ft_printf("rra\n");
	}
}

void	rrb(t_list **stack_b)
{
	t_list *temp;

	if (ft_lstsize(*stack_b) > 1)
	{
		temp = ft_lstblast(*stack_b);
		ft_lstadd_front(stack_b, temp->next);
		temp->next = NULL;
		ft_printf("rrb\n");
	}
}

void	ra(t_list **stack_a)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) > 1)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_back(stack_a, temp);
		ft_printf("ra\n");
	}
}

void	sa(t_list **stack_a)
{
	t_list *temp;

	if (ft_lstsize(*stack_a) >= 2)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		(*stack_a)->next = temp;
		ft_printf("sa\n");
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;

	if (*stack_b)
	{
		temp = (*stack_b)->next;
		ft_lstadd_front(stack_a, *stack_b);
		*stack_b = temp;
		ft_printf("pa\n");
	}
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list *temp;

	if (*stack_a)
	{
		temp = (*stack_a)->next;
		ft_lstadd_front(stack_b, *stack_a);
		*stack_a = temp;
		ft_printf("pb\n");
	}
}

t_list	**get_a_node(t_list **stack_a)
{
	t_list *pstack_a;

	pstack_a = *stack_a;
	while (pstack_a->next->next->next)
		pstack_a = pstack_a->next;
	return (&pstack_a->next);
}
