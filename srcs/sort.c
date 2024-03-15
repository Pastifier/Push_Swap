/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:11:51 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/08 22:46:53 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		assign_sorted_indeces(t_stack *a, int *sorted_arr);
static size_t	count_bit_places(int nbr);
static void		push_zeroes_to_b_and_back_to_a(t_stack *a, t_stack *b,
					size_t shift_count);

void	radix_sort(t_stack *a, t_stack *b, int *sorted_arr)
{
	size_t	bit_places_count;
	size_t	shift_count;

	if (a->capacity <= 5)
		return (sort_five(a, b));
	assign_sorted_indeces(a, sorted_arr);
	bit_places_count = count_bit_places(a->capacity - 1);
	shift_count = 0;
	while (shift_count < bit_places_count)
		(push_zeroes_to_b_and_back_to_a(a, b, shift_count), ++shift_count);
}

static void	assign_sorted_indeces(t_stack *a, int *sorted_arr)
{
	size_t	j;
	t_elem	*iter;

	iter = a->top;
	while (iter)
	{
		j = -1;
		while (++j < a->capacity)
		{
			if (iter->value == sorted_arr[j])
			{
				iter->sorted_index = j;
				break ;
			}
		}
		iter = iter->below;
	}
}

static size_t	count_bit_places(int nbr)
{
	size_t	self;

	if (nbr == 0)
		return (1);
	self = 0;
	while (nbr != 0)
	{
		nbr /= 2;
		++self;
	}
	return (self);
}

static void	push_zeroes_to_b_and_back_to_a(t_stack *a, t_stack *b,
	size_t shift_count)
{
	size_t	size;

	size = a->capacity;
	while (size--)
	{
		if (a->capacity >= 2 && (a->top->sorted_index >> shift_count) & 1)
			ra(a, b);
		else if (((a->top->sorted_index >> shift_count) & 1) == 0)
			pb(a, b);
	}
	while (b->capacity)
		pa(a, b);
}
