#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include "./ft_libft/libft.h"
typedef struct 		s_list 
{
	int				nbr;
	struct s_list	*next;
}					t_list;

int		ft_printf(const char *str, ...);
int		ft_atoi(const char *str);
void	check_int(char ***nbr);
t_list	*new_list(char ***argv);
void	check_nbr(char	*str);
void	check_dupl(t_list *stack_a);
void	check_fragment(char	**str);
void	err_exit(int exit_code);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
int     ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstblast(t_list *lst);
t_list	*ft_lstnew(int nbr);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rrb(t_list **stack_b);
void	rra(t_list **stack_a);
void    rrr(t_list **stack_a, t_list **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);
t_list	**get_a_node(t_list **stack_a);
int		sort(t_list **stack_a, t_list **stack_b);
char	**ft_split(char const *s, char c);
int		get_pos(t_list *lst, t_list *node);

void	add_tracker(int	**tracker, int a, int b, int s);
void	op_a(t_list **stack_a, t_list **stack_b, int w_len);
void	op_b(t_list **stack_b, t_list **stack_a, int w_len);
void	rewind_ra(t_list **stack_a, t_list **stack_b, int w_len);
void	rewind_rb(t_list **stack_b, t_list **stack_a, int w_len);


void	init_part(t_list **stack_a, t_list **stack_b, int	*tracker);

void	sort_med_a(t_list **stack_a, t_list **stack_b);
void	sort_med_b(t_list **stack_b, t_list **stack_a);
int		is_sorted(t_list *stack_a);
void	med_sort_b(t_list **stack_b, t_list **stack_a, int med, int s_back);
int		*to_ar(t_list *stack, int size);


#endif