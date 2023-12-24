/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:54 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/20 21:53:55 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO:
// create input validation.
#include "libft/libft.h"
#include "push_swap.h"
#include "validate.h"
#include "hash_table.h"
#include <stdlib.h>

static size_t	my_abs(int value);

void	submit_error(void)
{
	return ((void)write(2, "Error\n", 6));
}

void	check_empty(int inputc, char *inputv[])
{
	int	i;

	i = -1;
	while (inputc--)
		while (inputv[inputc][++i])
			if (!ft_strchr(WHITE_SPACE, inputv[inputc][i]))
				return ;
	return (submit_error(), exit(EXIT_FAILURE));
}

bool	set_insert(t_entry *set, int value, size_t set_size)
{
	size_t	hash;

	if (!set || !set_size)
		return (true);
	hash = my_abs(value % set_size);
	if (set[hash].value == value)
		return (true);
	if (set[hash].occupied)
		while (set[++hash].occupied)
			if (hash >= set_size)
				hash = 0;
	set[hash].occupied = true;
	set[hash].value = value;
	return (false);
}

void	check_dupes(t_stack *a)
{
	t_entry	*set;
	t_node	*dummy;

	if (!a || !a->top)
		return (submit_error(), exit(EXIT_FAILURE));
	set = ft_calloc(a->capacity * 2, sizeof(t_entry));
	dummy = a->top;
	while (dummy)
	{
		if (set_insert(set, dummy->value, a->capacity * 2))
			return (free(set), free_elements(a),
				submit_error(), exit(EXIT_FAILURE));
		dummy = dummy->below;
	}
	free(set);
}

size_t	my_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}
