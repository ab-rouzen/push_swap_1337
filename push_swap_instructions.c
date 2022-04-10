#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	**node_a;
	t_list	**node_b;
	t_list	**node_c;
	t_list	*temp_a;
	t_list	*temp_c;

	node_a = get_a_node(stack_a);
	node_b = &(*node_a)->next;
	node_c = &(*node_b)->next;
	temp_a = *node_a;
	temp_c = *node_c;
	*node_a = *node_b;
	*node_c = temp_a;
	*node_b = temp_c;
}

t_list	**get_a_node(t_list **stack_a)
{
	t_list *pstack_a;

	pstack_a = *stack_a;
	while (pstack_a->next->next->next)
		pstack_a = pstack_a->next;
	return (&pstack_a->next);
}