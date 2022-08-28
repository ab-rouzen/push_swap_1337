#include "push_swap.h"

void	rra(t_list **stack_a)
{
	//t_list *tmp;

	if (ft_lstsize(*stack_a) > 1)
	{
		//tmp = (*stack_a)->prev->prev;
		//ft_lstadd_front(stack_a, tmp->next);
		//tmp->next = (*stack_a);
		*stack_a = (*stack_a)->prev;
		ft_printf("rra\n");
	}
}

int	ra(t_list **stack_a)
{
	//t_list	*tmp;

	if (ft_lstsize(*stack_a) > 1)
	{
		//tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		//(*stack_a)->prev = tmp;
		//ft_lstadd_back(stack_a, tmp);
		ft_printf("ra\n");
	}
	return (1);
}

void	sa(t_list **stack_a)
{
	t_list	*tmp;
	//t_list	*nxt;

	if (ft_lstsize(*stack_a) > 2)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = (*stack_a)->next;
		(*stack_a)->prev = tmp->prev;
		tmp->prev->next = *stack_a;
		tmp->next->prev = tmp;
		tmp->prev = (*stack_a);
		(*stack_a)->next = tmp;
		//tmp->prev->next = *stack_a;
		ft_printf("sa\n");
	}
	else if (ft_lstsize(*stack_a) == 2)
	{
		*stack_a = (*stack_a)->next;
		ft_printf("sa\n");
	}


}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list *head;
	t_list *prev;

	if (*stack_b)
	{
		// tmp_b = (*stack_b);
		// if ((*stack_b)->next != *stack_b)
		// {
		// 	(*stack_b) = (*stack_b)->next;
		// 	(*stack_b)->prev = tmp_b->prev;
		// }
		if (*stack_b != (*stack_b)->next)
			head = (*stack_b)->next;
		else
			head = NULL;
		//prev = (*stack_b)->prev;
		//ft_lstadd_front(stack_a, *stack_b);
		// tmp_a = *stack_a;
		// *stack_a = tmp_b;
		// if (tmp_b)
		// {
		// 	(*stack_a)->next = tmp_a;
		// 	(*stack_a)->prev = tmp_a->prev;
		// }
		prev = (*stack_b)->prev;
		ft_lstadd_front(stack_a, *stack_b);
		*stack_b = head;
		if (*stack_b)
		{
			//(*stack_b)->next = tmp_b;
			(*stack_b)->prev = prev;
			(*stack_b)->prev->next = head;
		}		
		ft_printf("pa\n");

	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sb(stack_b);
	sa(stack_a);
	ft_printf("ss\n");
}