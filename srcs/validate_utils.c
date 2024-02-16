/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:48 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/17 03:06:10 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	validate_result(t_eint *result);

char	*join_input_space(int inputc, char *inputv[])
{
	char	*original;
	char	*self;
	ssize_t	count;
	ssize_t	loa;

	loa = 0;
	count = inputc;
	while (inputc--)
		loa += ft_strlen(inputv[inputc]);
	self = malloc(sizeof(char) * (loa + count + 1));
	if (!self)
		return (submit_error(), exit(EXIT_FAILURE), NULL);
	original = self;
	loa = -1;
	while (++loa < count)
	{
		while (*inputv[loa])
		{
			*self++ = *inputv[loa]++;
		}
		*self++ = ' ';
	}
	*self = 0;
	return (original);
}

// TODO:
// - Use the hashset WHILE pushing to optimise dupe-checking
t_stack	*validate_input(t_stack *a, int inputc, char *inputv[])
{
	char	*hold;
	t_split	joined;
	t_eint	result;
	size_t	set_size;
	t_entry	*set;

	hold = join_input_space(inputc, inputv);
	joined = ft_split(hold, WHITE_SPACE);
	free(hold);
	if (!joined.array || !joined.wordcount)
		return (submit_error(), exit(EXIT_FAILURE), a);
	set_size = joined.wordcount * 2;
	set = ft_calloc(set_size, sizeof(t_entry));
	if (!set)
		return (submit_error(), free_2d(joined.array), exit(EXIT_FAILURE), a);
	while (joined.wordcount--)
	{
		result = ft_atoi(joined.array[joined.wordcount]);
		if (!validate_result(&result)
			|| !set_insert(set, result.value, set_size))
			return (free_2d(joined.array), free(set), free_elements(a),
				submit_error(), exit(EXIT_FAILURE), a);
		stack_push(a, create_element(result.value), NULL);
	}
	return (free_2d(joined.array), free(set), a);
}

bool	validate_result(t_eint *result)
{
	if (result->operations < 1)
		result->error = true;
	if (result->error)
		return (false);
	return (true);
}
