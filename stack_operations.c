#include "stack.h"

void	stack_push(t_stack *stack, t_node *to_push)
{
	t_node	*list;
	t_node	*head;

	list = stack->top;
	head = list;
	head->above = to_push;
	to_push->below = head;
	to_push->above = NULL;
	stack->capacity += 1;
	stack->top = to_push;
}

t_node	*stack_pop(t_stack *stack)
{
	t_node	*self;

	if (stack->capacity < 1)
		return (NULL);
	self = stack->top;
	stack->top = self->below;
	(stack->top)->above = NULL;
	self->below = NULL;
	stack->capacity -= 1;
	return (self);
}
