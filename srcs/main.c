/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:06 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/17 08:07:47 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	init_a;
	t_stack	*a;

	if (argc < 2)
		return (0);
	check_empty(--argc, ++argv);
	init_a = init_stack();
	a = validate_input(&init_a, argc, argv);
	if (!issorted(a))
	{
		if (a->capacity == 2)
			sort_two(a);
		else if (a->capacity == 3)
			sort_three(a);
	}
	return (free_elements(a), 0);
}
