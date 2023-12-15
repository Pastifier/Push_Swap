#include "stack.h"

t_node	*create_node(int value)
{
	t_node	*self;

	self = malloc(sizeof(t_node));
	if (!self)
		return (NULL);
	self->value = value;
	self->above = NULL;
	self->below = NULL;
	return (self);
}

t_stack	init_stack(t_node *list)
{
	return ((t_stack)
	{
		.capacity = 0,
		.top = list,
	});
}
