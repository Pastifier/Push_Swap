/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:27:37 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/01 14:23:11y ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// TODO:
//	pass in the sorted array as info.
bool	pivot_around_two_thirds(t_stack *stack, t_stack *other)
{
	int		*arr;
	size_t	pivot_index;
	size_t	count_pb;
	bool	fetch;

	if (stack->capacity <= 3)
		return (true);
	arr = dup_stack_to_array_sort(stack);
	if (!arr)
		return (false);
	pivot_index = 2 * (stack->capacity) / 3;
	count_pb = 0;
	while (count_pb <= pivot_index - 1)
	{
		if (stack->top->value < arr[pivot_index])
			(pb(stack, other), ++count_pb);
		else if (stack->bottom->value < arr[pivot_index])
			(rra(stack, other), pb(stack, other), ++count_pb);
		else
			ra(stack, other);
	}
	free(arr);
	if (stack->capacity == 2)
		sort_two(stack, A);
	else if (stack->capacity == 3)
		sort_three(stack);
	fetch = pivot_around_two_thirds(stack, other);
	return (true * fetch);
}
