# COMPILER STUFF
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3

# MAIN PROGRAM
NAME := push_swap
SRCS := init.c stack_operations.c main.c
INCLUDES := stack.h

# RULES
all: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(SRCS)
