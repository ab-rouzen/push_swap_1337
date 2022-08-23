#include "checker.h"

char ***parse_input(char **argv, int	argc)
{
	char	***list;
	int		i;

	i = 0;
	list = malloc(sizeof(char***) * argc);
	while(argv[i])
	{
		list[i] = ft_split(argv[i], ' ');
		i++;
	}
	list[i] = NULL;
	return (list);
}

void	check_int(char ***nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		check_fragment(nbr[i]);
		i++;
	}
}

void	check_dupl(t_list *stack_a)
{
	t_list	*step_x;
	t_list	*step_y;

	step_x = step_y = stack_a;
	while (step_x)
	{
		while(step_y)
		{
			if (step_x->nbr == step_y->nbr && step_x != step_y)
				err_exit(8);
			step_y = step_y->next;
		}
		step_x = step_x->next;
		step_y = stack_a;
	}
}

void	check_fragment(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		check_nbr(str[i]);
		i++;
	}
}

void	check_nbr(char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9'))
			err_exit(0);
		str++;
	}
}

int	scrap(char *str)
{
	int	i;
	int	minus;

	minus = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	return (i * minus);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	holder;
	int		sign;

	holder = 0;
	i = scrap((char *)str);
	sign = 1;
	if (i < 0)
	{
		sign = -1;
		i *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
		holder = holder * 10 + (str[i++] - 48);
	if (sign == -1)
		return (-holder);
	return (holder);
}

static int	tabcount(const char *str, char c)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		j = i;
		while (str[i] != c && str[i])
			i++;
		if (j != i)
			count++;
	}
	return (count);
}

static char	**freeme(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free (tab);
	return (NULL);
}

static char	**allo_mem(char **blk, char *str, char c)
{
	char	*loc;
	int		i;
	int		m;

	i = 0;
	m = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		loc = &str[i];
		while (str[i] != c && str[i])
			i++;
		if ((&str[i] - loc) != 0)
		{
			blk[m] = malloc(sizeof(char) * (&str[i] - loc + 1));
			if (!blk[m])
				return (freeme(blk, m));
			m++;
		}
	}
	blk[m] = NULL;
	return (blk);
}

static void	feelme(char *str, char c, char **tab)
{
	int		i;
	int		m;
	char	*loc;

	i = 0;
	m = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		loc = &str[i];
		while (str[i] != c && str[i])
			i++;
		if (&str[i] - loc != 0)
			ft_strlcpy(tab[m], loc, &str[i] - loc + 1);
		m++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*ns;

	ns = (char *)s;
	if (!ns)
		return (NULL);
	tab = malloc(sizeof(char **) * tabcount(ns, c) + 1);
	if (!tab)
		return (NULL);
	allo_mem(tab, ns, c);
	if (!tab)
		return (NULL);
	feelme(ns, c, tab);
	return (tab);
}