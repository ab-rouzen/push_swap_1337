# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arouzen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 14:16:42 by arouzen           #+#    #+#              #
#    Updated: 2021/12/29 21:04:15 by arouzen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus re clean fclean $(NAME)

NAME = libftprintf.a
INCL = ft_printf.h
INCL_B = ft_printf_bonus.h
MAND_SRCS = ft_putnbr_base.c ft_putchar_fd.c ft_putstr_fd.c ft_printf.c
MAND_OBJS = $(MAND_SRCS:.c=.o)
BONU_SRCS = ft_putnbr_base.c ft_putchar_fd.c ft_putstr_fd.c ft_printf_bonus.c
BONU_OBJS = $(BONU_SRCS:.c=.o)
AR = ar
ARFLAGS = -rs
CC = gcc
FLAGS = -Wall -Wextra -Werror


all : $(NAME)
	@echo Everything is up to go!

$(NAME) : $(MAND_OBJS) $(INCL)
	@echo Checking files...
	$(AR) $(ARFLAGS) $(NAME) $(MAND_OBJS)

bonus : $(BONU_OBJS) $(INCL_B)
	@echo Checking files...
	$(AR) $(ARFLAGS) $(NAME) $(BONU_OBJS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	@echo cleaning up...
	rm -f $(MAND_OBJS) $(BONU_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
