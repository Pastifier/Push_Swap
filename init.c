/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:52:54 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/20 21:52:55 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*create_node(int value)
{
	t_node	*self;

	self = malloc(sizeof(t_node));
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
