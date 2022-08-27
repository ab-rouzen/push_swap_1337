/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:27:38 by arouzen           #+#    #+#             */
/*   Updated: 2021/12/29 21:04:00 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	p_uint(char c, va_list args, int *flags)
{
	unsigned int	m;

	if (c == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	if (c == 'x')
	{
		m = va_arg(args, unsigned int);
		if (flags[2] == 1 && m)
			ft_putstr_fd("0x", FD);
		ft_putnbr_base(m, "0123456789abcdef");
	}
	if (c == 'X')
	{
		m = va_arg(args, unsigned int);
		if (flags[2] == 1 && m)
			ft_putstr_fd("0X", FD);
		ft_putnbr_base(m, "0123456789ABCDEF");
	}
	if (c == 'p')
	{
		ft_putstr_fd("0x", FD);
		ft_uputnbr_base(va_arg(args, unsigned long int), "0123456789abcdef");
	}
}

void	p_int(char c, va_list args, int *flags)
{
	int	m;

	m = va_arg(args, int);
	if (c == 'i' || c == 'd')
	{
		if (m >= 0 && flags[1] == 1)
			ft_putchar_fd('+', FD);
		else if (m >= 0 && flags[0] == 1)
			ft_putchar_fd(' ', FD);
		ft_putnbr_base(m, "0123456789");
	}
	if (c == 'c')
		ft_putchar_fd(m, FD);
}

void	init(int *flags)
{
	int	i;

	i = 0;
	while (i < 3)
		flags[i++] = 0;
}

int	dflags(char *str, int *flags)
{
	int	i;

	i = 0;
	if (str[i] == ' ')
	{
		while (str[i + 1] == ' ')
			i++;
		flags[0] = 1;
	}
	else if (str[i] == '+')
	{
		while (str[i + 1] == '+')
			i++;
		flags[1] = 1;
	}
	else if (str[i] == '#')
	{
		while (str[i + 1] == '#')
			i++;
		flags[2] = 1;
	}
	return (++i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		flags[3];

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			ft_putchar_fd(str[i++], FD);
		if (!str[i++])
			break ;
		init(flags);
		if (str[i] == '+' || str[i] == ' ' || str[i] == '#')
			i += dflags((char *)&str[i], &flags[0]);
		if (str[i] == 'i' || str[i] == 'd' || str[i] == 'c')
			p_int(str[i], args, flags);
		if (str[i] == 's')
			ft_putstr_fd(va_arg(args, char *), FD);
		if (str[i] == 'u' || str[i] == 'x' || str[i] == 'p' || str[i] == 'X')
			p_uint(str[i], args, flags);
		if (str[i++] == '%')
			ft_putchar_fd('%', FD);
	}
	return (va_end(args), ft_putchar_fd('\0', 2));
}
