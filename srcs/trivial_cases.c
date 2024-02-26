/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:48:03 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/26 09:40:59 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	issorted(t_stack *stack)
{
	t_elem	*iter;

	if (stack->capacity < 1 || !stack->top)
		return (false);
	iter = stack->top->below;
	while (iter)
	{
		if (iter->value < iter->above->value)
			return (false);
		iter = iter->below;
	}
	return (true);
}

void	sort_two(t_stack *stack, bool is_a)
{
	if (is_a && stack->top->value > stack->top->below->value)
		sa(stack, NULL);
	else if (stack->top->value > stack->top->below->value)
		sb(NULL, stack);
}

void	sort_two_both(t_stack *a, t_stack *b)
{
	if (a->top->value > a->top->below->value
		&& b->top->value > b->top->below->value)
		ss(a, b);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->value;
	b = stack->top->below->value;
	c = stack->bottom->value;
	if (a > b && b > c)
		(ra(stack, NULL), sa(stack, NULL));
	else if (a < b && b > c && a < c)
		(rra(stack, NULL), sa(stack, NULL));
	else if (a > b && b < c && a < c)
		sa(stack, NULL);
	else if (a < b && b > c && a > c)
		rra(stack, NULL);
	else if (a > b && b < c && a > c)
		ra(stack, NULL);
}

void	sort_five(t_stack *a, t_stack *b)
{
	stack_set_least(a);
	while (a->capacity > 3)
	{
		if (a->top->value == a->least)
			(pb(a, b), stack_set_least(a));
		else if (a->bottom->value == a->least)
			rra(a, b);
		else if (a->bottom->above->value == a->least)
			rra(a, b);
		else
			ra(a, b);
	}
	sort_three(a);
	while (b->top)
		pa(a, b);
}
