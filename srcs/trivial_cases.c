/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trivial_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:48:03 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/17 08:24:36 by ebinjama         ###   ########.fr       */
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

void	sort_two(t_stack *stack)
{
	if (stack->top->value > stack->top->below->value)
		sa(stack, NULL);
}

void	sort_three(t_stack *stack)
{
	if (stack->top->value > stack->bottom->value)
		ra(stack, NULL);
	if (stack->top->value > stack->top->below->value)
		sa(stack, NULL);
	if (stack->top->value > stack->bottom->value)
		rra(stack, NULL);
}
