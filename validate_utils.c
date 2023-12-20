/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:48 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/20 21:53:49 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "validate.h"

static bool	is_permitted(int c);
static bool	validate_element(t_stack *a, t_stack *b, size_t index, char **ia);
static bool	validate_result(t_stack *a, t_stack *b, char *hold, t_eint *result);

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

t_stack	*validate_input(t_stack *a, t_stack *b, int inputc, char *inputv[])
{
	char	*hold;
	char	*dummy;
	t_split	joined;
	t_eint	result;

	hold = join_input_space(inputc, inputv);
	dummy = --hold;
	while (*++dummy)
		if (!ft_isdigit(*dummy) && !is_permitted(*dummy))
			return (free(++hold), submit_error(), exit(EXIT_FAILURE), NULL);
	joined = ft_split(++hold, ' ');
	if (!joined.array)
		return (free(hold), exit(EXIT_FAILURE), a);
	while (joined.wordcount--)
	{
		if (!validate_element(a, b, joined.wordcount, joined.array))
			return (submit_error(), free(hold), a);
		result = ft_atoi(joined.array[joined.wordcount]);
		if (!validate_result(a, b, hold, &result))
			return (free_2d(joined.array),
				submit_error(), exit(EXIT_FAILURE), a);
		stack_push(a, create_node(result.value), b);
	}
	return (free_2d(joined.array), free(hold), a);
}

bool	is_permitted(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f'
		|| c == '-' || c == '+');
}

bool	validate_result(t_stack *a, t_stack *b, char *hold, t_eint *result)
{
	if (result->error)
		return (free_elements(a), free_elements(b), free(hold), false);
	return (true);
}

bool	validate_element(t_stack *a, t_stack *b, size_t index, char **ia)
{
	char	curr;
	char	next;
	int		i;
	bool	sign_flag;

	sign_flag = false;
	i = -1;
	while (ia[index][++i])
	{
		curr = ia[index][i];
		next = ia[index][i + 1];
		if ((sign_flag && (is_permitted(curr)))
			|| (ft_isdigit(curr) && (next == '-' || next == '+')))
			return (free_elements(a), free_elements(b),
				free_2d(ia), false);
		sign_flag = (curr == '-' || curr == '+');
		if (sign_flag && next == 0)
			return (free_elements(a), free_elements(b),
				free_2d(ia), false);
	}
	return (true);
}
