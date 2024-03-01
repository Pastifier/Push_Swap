/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:59:04 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/01 15:13:35 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_on_top(t_stack *a, t_stack *b)
{
	int	*first;
	int	*second;
	int	*third;

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
	else if (first > second && second > first)
		(sa(a, b), pb(a, b), sa(a, b), pa(a, b), sa(a, b));	
}
