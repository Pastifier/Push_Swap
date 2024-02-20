/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:17:00 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/19 09:08:57 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_set_greatest(t_stack *stack)
{
	t_elem	*iter;
	int		temp;

	if (!stack->top)
		return ;
	iter = stack->top;
	temp = iter->value;
	while (iter)
	{
		if (iter->value > temp)
			temp = iter->value;
		iter = iter->below;
	}
	stack->greatest = temp;
}

void	stack_set_least(t_stack *stack)
{
	t_elem	*iter;
	int		temp;

	if (!stack->top)
		return ;
	iter = stack->top;
	temp = iter->value;
	while (iter)
	{
		if (iter->value < temp)
			temp = iter->value;
		iter = iter->below;
	}
	stack->least = temp;
}

void	stack_cmp(t_stack *stack, t_elem *to_push)
{
	if (stack->top)
	{
		if (to_push->value > stack->greatest)
			stack->greatest = to_push->value;
		else if (to_push->value < stack->least)
			stack->least = to_push->value;
	}
	else
	{
		stack->greatest = to_push->value;
		stack->least = to_push->value;
	}
}
