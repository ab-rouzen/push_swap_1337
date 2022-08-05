#include "push_swap.h"

void	check_int(char ***nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
		check_nbr(nbr[i++]);
	//check_dupl(nbr);
}

void	check_dupl(char ***nbr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (nbr[k])
	{
		while (nbr[k][i])
		{
			while(nbr[k][j])
			{
				if (ft_atoi(nbr[k][i]) == ft_atoi(nbr[k][j]) && i != j)
					err_exit(0);
				j++;
			}
			i++;
			j = 0;
		}
		k++;
	} 
}

void	check_nbr(char	*str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != ' ')
			err_exit(0);
		str++
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