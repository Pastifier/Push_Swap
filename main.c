/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:06 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/20 21:53:07 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "validate.h"

int	main(int argc, char *argv[])
{
	t_stack	init_a;
	t_stack	*a;

	if (argc < 2)
		return (0);
	check_empty(--argc, ++argv);
	init_a = init_stack();
	a = validate_input(&init_a, argc, argv);
	return (free_elements(a), 0);
}
