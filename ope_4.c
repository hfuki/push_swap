/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:06:07 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/17 16:06:08 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "printf/ft_printf.h"

static void	f_rra(t_stack *a)
{
	t_node	*node;

	if (a->size < 2)
		return ;
	node = a->top->prev;
	a->top->prev->prev->next = a->top;
	a->top->prev = a->top->prev->prev;
	node->prev = a->top;
	node->next = a->top->next;
	a->top->next->prev = node;
	a->top->next = node;
}

static void	f_rrb(t_stack *b)
{
	t_node	*node;

	if (b->size < 2)
		return ;
	node = b->top->prev;
	b->top->prev->prev->next = b->top;
	b->top->prev = b->top->prev->prev;
	node->prev = b->top;
	node->next = b->top->next;
	b->top->next->prev = node;
	b->top->next = node;
}

void	rra(t_stack *a)
{
	f_rra(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	f_rrb(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	f_rra(a);
	f_rrb(b);
	ft_printf("rrr\n");
}
