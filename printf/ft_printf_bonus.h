/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:26:40 by arouzen           #+#    #+#             */
/*   Updated: 2021/12/29 21:03:50 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define FD 1
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_uputnbr_base(unsigned long int nb, char *base);
int		ft_printf(const char *str, ...);
void	ft_putnbr_base(long int nbr, char *base);

#endif
