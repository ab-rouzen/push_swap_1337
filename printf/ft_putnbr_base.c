/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:31:48 by arouzen           #+#    #+#             */
/*   Updated: 2021/12/17 18:50:18 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_uputnbr_base(unsigned long int nbr, char *base)
{
	if (nbr > str_len(base) - 1)
		ft_putnbr_base(nbr / (str_len(base)), base);
	ft_putchar_fd(base[nbr % (str_len(base))], FD);
}

void	ft_putnbr_base(long int nbr, char *base)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar_fd('-', FD);
	}
	if (nbr > (long int) str_len(base) - 1)
		ft_putnbr_base(nbr / (str_len(base)), base);
	ft_putchar_fd(base[nbr % (str_len(base))], FD);
}
