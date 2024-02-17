/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:26 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/17 08:09:09 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, t_stack *b)
{
	stack_rrotate(a, b);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b, t_stack *a)
{
	stack_rrotate(b, a);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	stack_rrotate(a, b);
	stack_rrotate(b, a);
	write(1, "rrr\n", 4);
}
