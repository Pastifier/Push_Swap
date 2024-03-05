/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:11 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/05 16:40:49 by ebinjama         ###   ########.fr       */
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
