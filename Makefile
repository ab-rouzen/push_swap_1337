.PHONY: all bonus re clean fclean $(NAME) $(NAME_B)

NAME = push_swap
NAME_B = checker
INCL = ./src/push_swap.h
INCL_B = ./src/bonus/checker.h
SRC_DIR = ./src/
BNS_DIR = ./src/bonus/
PRINTF_DIR = ./src/printf/
GNL_DIR = ./src/gnl/
SRC_DIR_B = ./src/bonus/
BUILD_DIR = ./build/
BUILD_DIR_B = ./build/bonus/
M_SRC_NAME = main.c \
			ps_instructions_a.c \
			ps_instructions_b.c \
			median_utils.c \
			ps_parse_utils_atoi.c \
			ps_parse_utils_split.c \
			ps_list_utils.c \
			ps_libft_utils.c \
			ps_sort_a.c ps_sort_b.c \
			ps_parse_utils.c median_utils_back.c \
			ps_list_utils_2.c
B_SRC_NAME = chkr_instructions_a.c \
			chkr_instructions_b.c \
			chkr_instructions_double.c\
			chkr_list_utils.c \
			chkr_list_utils_2.c \
			chkr_parse_utils.c \
			chkr_parse_utils_atoi.c \
			chkr_parse_utils_split.c \
			libft_utils.c \
			chkr_execution.c\
			main.c
M_OBJ_NAME = $(M_SRC_NAME:.c=.o)
B_OBJ_NAME = $(B_SRC_NAME:.c=.o)
B_OBJ = $(addprefix $(BUILD_DIR_B),$(B_OBJ_NAME))
M_OBJ = $(addprefix $(BUILD_DIR),$(M_OBJ_NAME))
LIB_PRINTF = ./src/printf/libftprintf.a
LIB_GNL = ./src/gnl/gnl.a
LIBS = $(LIB_GNL) $(LIB_PRINTF)
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

all :  LIB $(NAME)
	@echo $(NAME): Everything is up to go!

LIB :
	@make -C $(PRINTF_DIR)

LIB_B :
	@make -C $(GNL_DIR)
	@make -C $(PRINTF_DIR)

bonus : LIB_B $(NAME_B)

$(NAME) : $(M_OBJ) $(INCL)
	@echo $(NAME): Checking files...
	$(CC) $(FLAGS) -o $(NAME) $(M_OBJ) $(LIB_PRINTF)

$(NAME_B) : $(B_OBJ) $(INCL_B)
	@echo $(NAME_B): Checking files...
	$(CC) $(FLAGS) -o $(NAME_B) $(B_OBJ) $(LIBS)

$(BUILD_DIR)%.o : $(SRC_DIR)%.c $(INCL)
	mkdir -p $(BUILD_DIR)bonus
	$(CC) $(FLAGS) -o $@ -c $<
	
$(BUILD_DIR_B)%.o : $(BNS_DIR)%.c $(INCL_B)
	mkdir -p $(BUILD_DIR_B)
	@echo here
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	@echo cleaning up...
	rm -f $(M_OBJ)
	rm -rf $(BUILD_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(GNL_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(GNL_DIR)

re : fclean all