/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:29:59 by arouzen           #+#    #+#             */
/*   Updated: 2021/12/18 22:11:18 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FD 1
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_uputnbr_base(unsigned long int nb, char *base);
int		ft_printf(const char *str, ...);
void	ft_putnbr_base(long int nbr, char *base);

#endif
