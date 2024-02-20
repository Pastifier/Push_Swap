/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:23 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/19 03:03:05 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_stack *b)
{
	stack_rotate(a, b);
	write(1, "ra\n", 3);
}

void	rb(t_stack *a, t_stack *b)
{
	stack_rotate(b, a);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	stack_rotate(a, b);
	stack_rotate(b, a);
	write(1, "rr\n", 3);
}
