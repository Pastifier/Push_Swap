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
#include "push_swap.h"
#include "validate.h"
#include <stdlib.h>

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
