/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:10:33 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/17 16:10:33 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_stack		*init_stack(void);
void		push_top(t_stack *stack, int value);
void		push_back(t_stack *stack, int value);
int			pop_top(t_stack *stack);
void		free_stack(t_stack *stack);

#endif
