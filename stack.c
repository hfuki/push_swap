/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:10:28 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/17 16:10:28 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack	*init_stack(void)
{
	t_stack	*stack;
	t_node	*nil;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	nil = malloc(sizeof(t_node));
	if (!nil)
	{
		free(stack);
		return (NULL);
	}
	nil->next = nil;
	nil->prev = nil;
	stack->top = nil;
	stack->size = 0;
	return (stack);
}

void	push_top(t_stack *stack, int value)
{
	t_node	*new;

	if (!stack)
		return ;
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = stack->top->next;
	new->prev = stack->top;
	stack->top->next->prev = new;
	stack->top->next = new;
	stack->size++;
}

void	push_back(t_stack *stack, int value)
{
	t_node	*new;

	if (!stack)
		return ;
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = stack->top;
	new->prev = stack->top->prev;
	stack->top->prev->next = new;
	stack->top->prev = new;
	stack->size++;
}

int	pop_top(t_stack *stack)
{
	int		value;
	t_node	*node;

	if (!stack)
		return (0);
	value = stack->top->next->value;
	node = stack->top->next;
	stack->top->next->next->prev = stack->top;
	stack->top->next = stack->top->next->next;
	free(node);
	stack->size--;
	return (value);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	node = stack->top->next;
	while (node != stack->top)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(node);
	free(stack);
}
