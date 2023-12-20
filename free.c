/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:52:45 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/20 21:52:46 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	free_elements(t_stack *stack);
void	free_2d(char **arr);

void	free_elements(t_stack *stack)
{
	t_node	*top_node;
	t_node	*next;

	if (!stack)
		return ;
	if (!stack->top)
		return ;
	top_node = stack->top;
	while (top_node)
	{
		next = top_node->below;
		free(top_node);
		if (!next)
			break ;
		top_node = next;
	}
}

void	free_2d(char **arr)
{
	char	**original;

	if (!arr)
		return ;
	original = arr;
	while (*arr)
		free(*arr++);
	free(original);
}
