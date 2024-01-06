/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:43 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/20 21:53:44 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h> // For size_t, malloc

/*----- LIST -----*/
typedef struct s_node {
	int				value;
	int				index;
	struct s_node	*above;
	struct s_node	*below;
}	t_node;

t_node	*create_node(int value);

/*----- STACK -----*/
typedef struct s_stack {
	size_t	capacity;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

t_stack	init_stack(void);
void	stack_swap(t_stack *stack, t_stack *other);
void	stack_push(t_stack *stack, t_node *to_push, t_stack *other);
void	stack_rotate(t_stack *stack, t_stack *other);
void	stack_rrotate(t_stack *stack, t_stack *other);
t_node	*stack_pop(t_stack *stack, t_stack *other);
#endif // !STACK_H
