typedef struct 		s_list 
{
	int				nbr;
	struct s_list	*next;
    struct s_list   *prev;
}					t_list;

char	*get_next_line(int fd);
