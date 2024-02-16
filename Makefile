# COMPILER STUFF
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3

# LIBRARIES
DIR_LIBFT := ./libft

# MAIN PROGRAM
NAME := push_swap
SRC := init.c stack_operations.c free.c validate.c ps_operations.c \
				ps_operations2.c ps_operations3.c validate_utils.c main.c
srcs := $(addprefix srcs/, $(SRC))
INCLUDE := stack.h validate.h push_swap.h operations.h hash_table.h
INCLUDES := $(addprefix includes/, $(INCLUDE))

# RULES
all: $(SRCS) $(INCLUDES)
	@make -C $(DIR_LIBFT) re
	$(CC) $(CFLAGS) -I. -o $(NAME) $(SRCS) -L$(DIR_LIBFT) -lft

clean:
	@make -C $(DIR_LIBFT) clean

fclean:
	@make -C $(DIR_LIBFT) fclean
	rm -rf $(NAME)

re: fclean all
