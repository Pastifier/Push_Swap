/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:19 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/17 03:05:58 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_stack *b)
{
	stack_swap(a, b);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b, t_stack *a)
{
	stack_swap(b, a);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	stack_swap(a, b);
	stack_swap(b, a);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	stack_push(a, stack_pop(b, a), b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	stack_push(b, stack_pop(a, b), a);
	write(1, "pb\n", 3);
}
