/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:38 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/17 02:45:50 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Assuming to_push has been popped, or is
// an individual node.
void	stack_push(t_stack *stack, t_elem *to_push, t_stack *other)
{
	t_elem	*top_node;
	t_elem	*bot_node;

	if (!stack || !to_push)
		return (submit_error(), free_elements(stack),
			free_elements(other), free(to_push), exit(EXIT_FAILURE));
	top_node = stack->top;
	bot_node = stack->bottom;
	to_push->above = NULL;
	to_push->below = NULL;
	if (!top_node && !bot_node)
	{
		stack->top = to_push;
		stack->bottom = to_push;
	}
	else
	{
		top_node->above = to_push;
		to_push->below = top_node;
		stack->top = to_push;
	}
	stack->capacity += 1;
	to_push->index = stack->capacity - 1;
}

t_elem	*stack_pop(t_stack *stack, t_stack *other)
{
	t_elem	*self;

	if (stack->capacity < 1 || !(stack->top))
		return (submit_error(),
			free_elements(stack), free_elements(other),
			exit(EXIT_FAILURE), NULL);
	self = stack->top;
	stack->top = self->below;
	(stack->top)->above = NULL;
	self->above = NULL;
	self->below = NULL;
	self->index = 0;
	stack->capacity -= 1;
	return (self);
}

void	stack_rotate(t_stack *stack, t_stack *other)
{
	t_elem	*iter;
	int		top_value;
	int		temp;

	if (!stack || !(stack->capacity) || !(stack->top))
		return (submit_error(),
			free_elements(stack), free_elements(other),
			exit(EXIT_FAILURE));
	iter = stack->top;
	top_value = iter->value;
	while (iter->below)
	{
		temp = iter->value;
		iter->value = (iter->below)->value;
		(iter->below)->value = temp;
		iter = iter->below;
	}
	iter->value = top_value;
}

void	stack_rrotate(t_stack *stack, t_stack *other)
{
	t_elem	*iter;
	int		bot_value;
	int		temp;

	if (!stack || !(stack->capacity) || !(stack->bottom))
		return (submit_error(),
			free_elements(stack), free_elements(other),
			exit(EXIT_FAILURE));
	iter = stack->bottom;
	bot_value = iter->value;
	while (iter->above)
	{
		temp = iter->value;
		iter->value = (iter->above)->value;
		(iter->above)->value = temp;
		iter = iter->above;
	}
	iter->value = bot_value;
}

void	stack_swap(t_stack *stack, t_stack *other)
{
	t_elem	*top_below;
	t_elem	*top_node;
	int		temp;

	if (!stack || !stack->top)
		return (submit_error(),
			free_elements(stack), free_elements(other),
			exit(EXIT_FAILURE));
	if (!(stack->top->below))
		return ;
	top_node = stack->top;
	top_below = stack->top->below;
	temp = top_node->value;
	top_node->value = top_below->value;
	top_below->value = temp;
}
