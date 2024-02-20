# COMPILER STUFF
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3

# LIBRARIES
DIR_LIBFT := libft

# MAIN PROGRAM
NAME := push_swap
SRC := init.c stack_operations.c stack_utils.c free.c validate.c ps_operations.c \
			ps_operations2.c ps_operations3.c validate_utils.c main.c \
			trivial_cases.c
SRCS := $(addprefix srcs/, $(SRC))
INCLUDE := push_swap.h
INCLUDES := $(addprefix includes/, $(INCLUDE))

# RULES
all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	@make -C $(DIR_LIBFT)
	$(CC) $(CFLAGS) -Iincludes $^ -L$(DIR_LIBFT) -Ilibft/includes -lft -o $@

clean:
	@make -C $(DIR_LIBFT) clean

fclean:
	@make -C $(DIR_LIBFT) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
