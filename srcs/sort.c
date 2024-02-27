/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:49:15 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/27 10:56:13 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack *a, t_stack *b)
{
	//if (!pivot_around_two_thirds(a, b))
	//	return (submit_error(),
	//		free_elements(a), free_elements(b), exit(2));
	pivot_around_two_thirds(a, b);
	if (a->capacity == 2)
		sort_two(a, A);
	else if (a->capacity == 3)
		sort_three(a);
	else
		sort_five(a, b);
}