/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:27:58 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/04 13:10:10 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivot_around_two_thirds(t_stack *stack, t_stack *other, t_arr *map)
{
	size_t	count_pb;
	size_t	chunk_size;

	if (stack->capacity <= 3)
		return ;
	count_pb = map->last_pivot;
	map->last_pivot += 2 * (stack->capacity) / 3;
	chunk_size = 0;
	while (count_pb < map->last_pivot)
	{
		if (stack->top->value < map->arr[map->last_pivot])
			(pb(stack, other), ++count_pb, ++chunk_size);
		else if (stack->bottom->value < map->arr[map->last_pivot])
			(rra(stack, other), pb(stack, other), ++count_pb, ++chunk_size);
		else
			ra(stack, other);
	}
	pivot_around_two_thirds(stack, other, map);
	if (stack->capacity == 2)
		sort_two(stack, A);
	else if (stack->capacity == 3)
		sort_three(stack);
	push_half_chunk(stack, other, map, chunk_size);
}

void	pivot_around_two_thirds_on_top(t_sptr a, t_sptr b, t_arr *m,
	size_t chunk_size_the_sequel)
{
	size_t	count_pb;
	size_t	chunk_size;

	if (chunk_size <= 3)
		return ;
	count_pb = m->last_pivot;
	m->last_pivot += 2 * (a->capacity) / 3;
	chunk_size = 0;
	while (count_pb < m->last_pivot)
	{
		if (a->top->value < m->arr[m->last_pivot])
			(pb(a, b), ++count_pb, ++chunk_size);
		else if (a->bottom->value < m->arr[m->last_pivot])
			(rra(a, b), pb(a, b), ++count_pb, ++chunk_size);
		else
			ra(a, b);
	}
	pivot_around_two_thirds_on_top(a, b, m, chunk_size_the_sequel);
	if (chunk_size == 2)
		sort_two(a, A);
	else if (chunk_size == 3)
		sort_three_on_top(a, b);
	push_half_chunk(a, b, m, chunk_size);
	while (--chunk_size / 2)
		rra(a, b);
}
