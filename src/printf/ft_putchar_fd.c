/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:31:18 by arouzen           #+#    #+#             */
/*   Updated: 2021/12/29 20:17:25 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	static int	i = 0;
	int			hol;

	if (fd == 1)
	{
		write(fd, &c, 1);
		i++;
		return (0);
	}
	return (hol = i, i = 0, hol);
}