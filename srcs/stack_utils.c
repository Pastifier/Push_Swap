/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:17:00 by ebinjama          #+#    #+#             */
/*   Updated: 2024/03/07 18:33:38 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*cpy_stack_to_array_sort(t_stack *stack)
{
	size_t	i;
	t_elem	*iter;
	int		*self;

	if (!stack || !stack->top)
		return (NULL);
	self = malloc(sizeof(int) * (stack->capacity));
	if (!self)
		return (NULL);
	i = 0;
	iter = stack->top;
	while (iter)
	{
		self[i++] = iter->value;
		iter = iter->below;
	}
	merge_sort(self, 0, stack->capacity - 1);
	return (self);
}
