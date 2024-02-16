/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:52:54 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/17 03:05:51 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*create_element(int value)
{
	t_elem	*self;

	self = malloc(sizeof(t_elem));
	if (!self)
		return (NULL);
	self->value = value;
	self->above = NULL;
	self->below = NULL;
	return (self);
}

t_stack	init_stack(void)
{
	return ((t_stack)
		{
			.capacity = 0,
			.top = NULL,
			.bottom = NULL
		});
}
