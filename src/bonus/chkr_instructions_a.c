#include "checker.h"

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