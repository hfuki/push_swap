/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:05:52 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/17 16:05:55 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "printf/ft_printf.h"

static void	f_ra(t_stack *a)
{
	t_node	*node;

	if (a->size < 2)
		return ;
	node = a->top->next;
	a->top->next->next->prev = a->top;
	a->top->next = a->top->next->next;
	node->next = a->top;
	node->prev = a->top->prev;
	a->top->prev->next = node;
	a->top->prev = node;
}

static void	f_rb(t_stack *b)
{
	t_node	*node;

	if (b->size < 2)
		return ;
	node = b->top->next;
	b->top->next->next->prev = b->top;
	b->top->next = b->top->next->next;
	node->next = b->top;
	node->prev = b->top->prev;
	b->top->prev->next = node;
	b->top->prev = node;
}

void	ra(t_stack *a)
{
	f_ra(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	f_rb(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	f_ra(a);
	f_rb(b);
	ft_printf("rr\n");
}
