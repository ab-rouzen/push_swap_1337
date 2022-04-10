#include <stdlib.h>
#include "./ft_printf/ft_printf.h"
typedef struct 		s_list 
{
	int				nbr;
	struct s_list	*next;
}					t_list;

int	ft_atoi(const char *str);
void	check_int(char **nbr);
t_list	*new_list(char **argv);
void	check_nbr(char	*str);
void	check_dupl(char **nbr);
void	err_exit(int exit_code);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstnew(int nbr);
void	sa(t_list **stack_a);
t_list	**get_a_node(t_list **stack_a);


