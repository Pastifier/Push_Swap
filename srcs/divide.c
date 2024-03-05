/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:27:58 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/05 19:14:20 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_till_done(t_stack *a, t_stack *b, t_arr map);
static void	rrotate_till_done(t_stack *a, t_stack *b, t_arr map);

void	pivot_around_two_thirds(t_stack *a, t_stack *b, t_arr map, bool flag)
{
	if (map.chunk_size <= 3)
		return ;
	
	if (flag == ROTATE)
		rotate_till_done(a, b, edit_map(map));
	else
		rrotate_till_done(a, b, edit_map(map));
	if (map.chunk_size / 3 == 2)
		sort_two(a, b);
	else if (map.chunk_size / 3 == 3)
		sort_three(a);
	pivot_around_two_thirds(a, b, edit_map(map), flag);
}

static void	rotate_till_done(t_stack *a, t_stack *b, t_arr map)
{
	size_t	pb_count;

	pb_count = 0;
	while (pb_count < 2 * map.chunk_size)
	{
		if (a->top->value < map.arr[map.chunk_pivot])
			(pb(a, b), ++pb_count);
		else
			ra(a, b);
	}
}

static void	rrotate_till_done(t_stack *a, t_stack *b, t_arr map)
{
	size_t	pb_count;

	pb_count = 0;
	while (pb_count < 2 * map.chunk_size)
	{
		if (a->top->value < map.arr[map.chunk_pivot])
			(pb(a, b), ++pb_count);
		else
			rra(a, b);
	}
}
