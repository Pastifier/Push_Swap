/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:31 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/20 21:53:32 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stack.h"
# include "validate.h"
# include "operations.h"

# ifndef WHITE_SPACE
#  define WHITE_SPACE " \n\t\r\v\f"
# endif // !WHITE_SPACE

/*----- FREE -----*/
void	free_elements(t_stack *stack);
void	free_2d(char **arr);

#endif // !PUSH_SWAP_H
