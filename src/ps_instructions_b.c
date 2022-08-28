#include "push_swap.h"

void	sb(t_list **stack_b)
{
	t_list *tmp;

	if (ft_lstsize(*stack_b) > 2)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = (*stack_b)->next;
		(*stack_b)->prev = tmp->prev;
		tmp->prev = (*stack_b);
		(*stack_b)->next = tmp;
		ft_printf("sb\n");
	}
	else if (ft_lstsize(*stack_b) == 2)
	{
		*stack_b = (*stack_b)->next;
		ft_printf("sb\n");
	}
}

int 	rb(t_list **stack_b)
{
	//t_list	*tmp;

	if (ft_lstsize(*stack_b) > 1)
	{
		//tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		//(*stack_b)->prev = tmp;
		//ft_lstadd_back(stack_b, tmp);
		ft_printf("rb\n");
	}
	return (1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rb(stack_b);
	ra(stack_a);
	ft_printf("rr\n");
}

void	rrb(t_list **stack_b)
{
	//t_list *tmp;

	if (ft_lstsize(*stack_b) > 1)
	{
		*stack_b = (*stack_b)->prev;
		ft_printf("rrb\n");
	}
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list *head;
	t_list *prev;

	if (*stack_a)
	{
		if (*stack_a != (*stack_a)->next)
			head = (*stack_a)->next;
		else
			head = NULL;
		// if ((*stack_a)->next != *stack_a)
		// {
		// 	(*stack_a) = (*stack_a)->next;
		// 	(*stack_a)->prev = tmp_a->prev;
		// }
		//prev = (*stack_b)->prev;
		prev = (*stack_a)->prev;
		ft_lstadd_front(stack_b, *stack_a);
		*stack_a = head;
		if (*stack_a)
		{
			//(*stack_b)->next = tmp_b;
			(*stack_a)->prev = prev;
			(*stack_a)->prev->next = head;
		}
		ft_printf("pb\n");
	}
}
