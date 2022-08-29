.PHONY: all bonus re clean fclean $(NAME) $(NAME_LIBFT)

NAME = push_swap
NAME_B = checker
INCL = ./src/push_swap.h
INCL_B = ./bonus/checker.h
SRC_DIR = ./src/
PRINTF_DIR = ./src/printf
SRC_DIR_B = ./src_B/
BUILD_DIR = ./build/
M_SRC_NAME = main.c ps_instructions_a.c ps_instructions_b.c \
			median_utils.c ps_parse_utils_atoi.c ps_parse_utils_split.c\
			ps_list_utils.c ps_libft_utils.c ps_sort_a.c ps_sort_b.c \
			ps_parse_utils.c median_utils_back.c ps_list_utils_2.c
M_OBJ_NAME = $(M_SRC_NAME:.c=.o)
M_OBJ = $(addprefix $(BUILD_DIR),$(M_OBJ_NAME))
LIBS = ./src/printf/libftprintf.a
BONU_SRC = 
BONU_OBJ = $(BONU_SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

all : LIB $(NAME)
	@echo Everything is up to go!

LIB :
	@make -C $(PRINTF_DIR)
$(NAME) : $(M_OBJ) $(INCL) 
	@echo Checking files...
	$(CC) $(FLAGS) -o $(NAME) $(M_OBJ) $(LIBS)

bonus : $(NAME_B)
	@make -C $(PRINTF_DIR)

$(NAME_B) : $(BONU_OBJS) $(INCL_B)
	@echo Checking files...
	$(CC) $(FLAGS) -o $(NAME_B) $(BONU_OBJS) $(LIBS)

$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	@echo cleaning up...
	rm $(M_OBJ)
	rm -r $(BUILD_DIR)
	make clean -C ./printf
fclean : clean
	rm $(NAME)

re : fclean all