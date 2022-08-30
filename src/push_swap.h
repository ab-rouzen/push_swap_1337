/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:57:40 by arouzen           #+#    #+#             */
/*   Updated: 2022/08/29 21:17:49 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int					ft_printf(const char *str, ...);
int					ft_atoi(const char *str);
void				check_int(char ***nbr);
t_list				*new_list(char ***argv);
void				check_nbr(char *str);
void				check_dupl(t_list *stack_a);
void				check_fragment(char **str);
void				err_exit(int exit_code);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstblast(t_list *lst);
t_list				*ft_lstnew(int nbr);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_b, t_list **stack_a);
int					ra(t_list **stack_a);
int					rb(t_list **stack_b);
void				rrb(t_list **stack_b);
void				rra(t_list **stack_a);
void				rrr(t_list **stack_a, t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
char				**ft_split(char const *s, char c);
void				op_a(t_list **stack_a, t_list **stack_b, int w_len);
void				op_b(t_list **stack_b, t_list **stack_a, int w_len);
void				rewind_ra(t_list **stack_a, t_list **stack_b, int w_len);
void				rewind_rb(t_list **stack_b, t_list **stack_a, int w_len);
int					*to_ar(t_list *stack, int size);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				***parse_input(char **argv, int argc);
int					get_med(t_list *stack_a, int left, int s_back);
size_t				ft_strlen(const char *str);
int					is_sorted_b(t_list *stack_b, int size);
int					is_sorted_a(t_list *stack_a, int size);
int					get_med_back(t_list *stack_a, int left, int s_back);
int					*to_ar_back(t_list *stack, int size);
int					f_med(int *ar, int left, int right, int mid);
void				sort_head(t_list **stack_a, int w_len);
void				pa_if_w_len(t_list **stack_b, t_list **stack_a, int w_len);
int					get_max(t_list *stack);
int					check_stack(t_list *stack, int *ra, int pb);

#endif