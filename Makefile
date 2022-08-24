.PHONY: all bonus re clean fclean $(NAME) $(NAME_LIBFT)

NAME = push_swap
NAME_B = checker
INCL = ./push_swap.h
INCL_B = ./bonus/checker.h
BIN_DIR = ./bin/
BIN_DIR_B = ./bin_B/
MAND_SRCS = ./main.c ./ps_instructions_a.c ./ps_instructions_b.c \
			./median_utils.c ./ps_parse_utils_atoi.c ./ps_parse_utils_split.c\
			./ps_llist_utils.c ./ps_libft_utils.c ./ps_sort_a.c ./ps_sort_b.c \
			./ps_parse_utils.c

MAND_OBJS = $(MAND_SRCS:.c=.o)
LIBS = ./printf/libftprintf.a
BONU_SRCS = 
BONU_OBJS = $(BIN_DIR)$(BONU_SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

all : BINS $(NAME)
	@echo Everything is up to go!

BINS :
	#make -C ./libft
	@make -C ./printf
$(NAME) : $(MAND_OBJS) $(INCL) 
	@echo Checking files...
	$(CC) $(FLAGS) -o $(NAME) $(MAND_OBJS) $(LIBS)
	#make clean

bonus : $(NAME_B)
	@make -C ./libft
	@make -C ./ft_printf

$(NAME_B) : $(BONU_OBJS) $(INCL_B)
	@echo Checking files...
	$(CC) $(FLAGS) -o $(NAME_B) $(BONU_OBJS) $(LIBS)

%.o : %.c
	$(CC) $(FLAGS) -o $(BIN_DIR)$@ -c $<

clean :
	@echo cleaning up...
	rm -rf $(BIN_DIR) $(BIN_DIR_B)
	make clean -C ./printf
fclean : clean
	rm -f $(NAME)

re : fclean all