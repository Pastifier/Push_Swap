/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:27:37 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/27 11:28:54 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	pivot_around_two_thirds(t_stack *stack, t_stack *other)
{
	int		*arr;
	size_t	pivot_index;
	size_t	desired_cap;
	size_t	count_pb;
	bool	fetch;

	if (stack->capacity <= 5)
		return (true);
	arr = dup_stack_to_array_sort(stack);
	if (!arr)
		return (false);
	pivot_index = 2 * (stack->capacity - 1) / 3;
	desired_cap = 2 * stack->capacity / 3;
	count_pb = 0;
	while (count_pb <= desired_cap)
	{
		if (stack->top->value < arr[pivot_index])
			(pb(stack, other), ++count_pb);
		else if (stack->bottom->value < arr[pivot_index])
			(rra(stack, other), pb(stack, other), ++count_pb);
		else
			ra(stack, other);
	}
	free(arr);
	fetch = pivot_around_two_thirds(stack, other);
	return (true * fetch);
}

void	push_back_two_thirds(t_stack *stack, t_stack *other)
{
	size_t	initial_capacity;

	initial_capacity = other->capacity - (stack->capacity + 2 * stack->capacity);
	while (other->capacity > initial_capacity)
	{
		if (other->top->value < stack->top->value)
			(pa(stack, other), ra(stack, other));
		if (other->top->value > stack->top->value)
			(ra(stack, other), pa(stack, other), rra(stack, other));
	}
}