/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:38 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/07 18:08:29 by ebinjama         ###   ########.fr       */
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
	if (top_node)
	{
		top_node->above = to_push;
		to_push->below = top_node;
		stack->top = to_push;
	}
	if (!top_node)
		stack->top = to_push;
	if (!bot_node)
		stack->bottom = to_push;
	if (stack->best_of_both_worlds < to_push->value)
		stack->best_of_both_worlds = to_push->value;
	stack->capacity += 1;
}

t_elem	*stack_pop(t_stack *stack, t_stack *other)
{
	t_elem	*self;

	if (stack->capacity < 1 || !(stack->top))
		return (submit_error(),
			free_elements(stack), free_elements(other),
			exit(EXIT_FAILURE), NULL);
	self = stack->top;
	if (stack->capacity > 1)
	{
		stack->top = self->below;
		(stack->top)->above = NULL;
	}
	else
		stack->top = NULL;
	self->above = NULL;
	self->below = NULL;
	stack->capacity -= 1;
	return (self);
}

void	stack_rotate(t_stack *stack, t_stack *other)
{
	t_elem	*dummy;

	if (!stack || !(stack->capacity) || !(stack->top))
		return (submit_error(),
			free_elements(stack), free_elements(other),
			exit(EXIT_FAILURE));
	dummy = stack->top;
	stack->top = stack->top->below;
	dummy->above = stack->bottom;
	dummy->below = NULL;
	stack->bottom->below = dummy;
	stack->top->above = NULL;
	stack->bottom = dummy;
}

void	stack_rrotate(t_stack *stack, t_stack *other)
{
	t_elem	*dummy;

	if (!stack || !(stack->capacity) || !(stack->bottom))
		return (submit_error(),
			free_elements(stack), free_elements(other),
			exit(EXIT_FAILURE));
	dummy = stack->bottom;
	stack->bottom = stack->bottom->above;
	dummy->below = stack->top;
	dummy->above = NULL;
	stack->top->above = dummy;
	stack->bottom->below = NULL;
	stack->top = dummy;
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
