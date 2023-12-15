#ifndef STACK_H
# define STACK_H

# include <stdlib.h> // For size_t
# include <stdio.h>  // For testing with printf
/*----- LIST -----*/
typedef struct s_node {
	int		value;
	struct s_node	*above;
	struct s_node	*below;
}	t_node;

t_node	*create_node(int value);

/*----- STACK -----*/
typedef struct s_stack {
	size_t	capacity;
	t_node	*top;
}	t_stack;

t_stack	init_stack(t_node *list);
void	stack_push(t_stack *stack, t_node *to_push);
t_node	*stack_pop(t_stack *stack);
#endif // !STACK_H
