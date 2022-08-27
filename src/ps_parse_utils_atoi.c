#include "push_swap.h"

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
	{
		if (-holder < MIN_INT)
			err_exit(4);
		return (-holder);
	}
	if (holder > MAX_INT)
		err_exit(4);
	return (holder);
}
