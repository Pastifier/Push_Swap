/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:59:04 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/03 14:45:50y ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_on_top(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->below->value;
	third = a->top->below->below->value;
	if (first > second && second < third && third > first)
		sa(a, b);
	else if (first < second && second > third && third < first)
		(pb(a, b), sa(a, b), pa(a, b), sa(a, b));
	else if (first < second && second > third && third > first)
		(pb(a, b), sa(a, b), pb(a, b), pa(a, b), pa(a, b));
	else if (first > second && second < third && third < first)
		(sa(a, b), pb(a, b), sa(a, b), pa(a, b));
	else if (first > second && second > third)
		(sa(a, b), pb(a, b), sa(a, b), pa(a, b), sa(a, b));	
}

void	push_half_chunk(t_stack *a, t_stack *b, t_arr map, size_t chunk_size)
{
	size_t	pa_count;

	pa_count = 0;
	while (b->top && pa_count < chunk_size / 2)
	{
		if (b->top->value >= map.arr[map.last_pivot])
			(pa(a, b), ++pa_count);
		else if (b->bottom->value >= map.arr[map.last_pivot])
			(rrb(a, b), pa(a, b), ++pa_count);
		else
			rb(a, b);
	}
	if (pa_count == 3)
		sort_three_on_top(a, b);
	while (--pa_count)
		rrb(a, b);
	while (b->top && pa_count < chunk_size / 2)
		(pa(a, b), ++pa_count);
	if (pa_count == 3)
		sort_three_on_top(a, b);
	print_stacks(a, b);
	exit(0);
}
