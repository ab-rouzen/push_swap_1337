.PHONY: all bonus re clean fclean $(NAME) $(NAME_LIBFT)

NAME = push_swap
NAME_B = so_long_bonus
INCL = ./push_swap.h
INCL_B = ./d_so_long_bonus/so_long_bonus.h
MAND_SRCS = ./push_swap.c ./ps_instructions.c ./ps_utils.c ./ps_list_utils.c

MAND_OBJS = $(MAND_SRCS:.c=.o)
LIBS = ./ft_printf/libftprintf.a
BONU_SRCS = 

BONU_OBJS = $(BONU_SRCS:.c=.o)
CC = gcc
FLAGS = 
PATH_LIBFT = ./libft/
NAME_LIBFT = libft.a

all : $(NAME)
	@echo Everything is up to go!
	#@make -C ./libft
	@make -C ./ft_printf

$(NAME) : $(MAND_OBJS) $(INCL) 
	@echo Checking files...
	$(CC) $(FLAGS) -o $(NAME) $(MAND_OBJS) $(LIBS)

bonus : $(NAME_B)
	@make -C ./libft
	@make -C ./ft_printf

$(NAME_B) : $(BONU_OBJS) $(INCL_B)
	@echo Checking files...
	$(CC) $(FLAGS) -o $(NAME_B) $(BONU_OBJS) $(LIBS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	@echo cleaning up...
	rm -f $(MAND_OBJS) $(BONU_OBJS)
	make clean -C ./ft_printf
	#make clean -C ./libft
fclean : clean
	rm -f $(NAME)

re : fclean all