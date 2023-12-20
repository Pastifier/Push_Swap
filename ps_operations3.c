/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:26 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/20 21:53:27 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, t_stack *b)
{
	stack_rrotate(a, b);
	write(1, "ra\n", 3);
}

void	rrb(t_stack *b, t_stack *a)
{
	stack_rrotate(b, a);
	write(1, "rb\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	stack_rrotate(a, b);
	stack_rrotate(b, a);
	write(1, "rrr\n", 3);
}
