/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:52:54 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/19 05:52:28 by ebinjama         ###   ########.fr       */
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

void    print_stacks(t_stack *stack, t_stack *other)
{
    t_elem  *itera;
    t_elem  *iterb;

    itera = stack->top;
    iterb = other->top;
    ft_putendl_fd("---a---    ---b---", STDOUT_FILENO);
    while (itera || iterb)
    {
        ft_putstr_fd("   ", STDOUT_FILENO);
        if (itera)
        {
            ft_putnbr_fd(itera->value, STDOUT_FILENO);
            if (!itera->below)
                itera = NULL;
            else
                itera = itera->below;
        }
        else
            ft_putstr_fd(" ", STDOUT_FILENO);

        ft_putstr_fd("          ", STDOUT_FILENO);

        if (iterb)
        {
            ft_putnbr_fd(iterb->value, STDOUT_FILENO);
            if (!iterb->below)
                iterb = NULL;
            else
                iterb = iterb->below;
        }
        else
            ft_putstr_fd(" ", STDOUT_FILENO);

        ft_putendl_fd("", STDOUT_FILENO);
    }
    ft_putendl_fd("--xax--    --xbx--", STDOUT_FILENO);
}
