/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:06:00 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/17 16:06:02 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "printf/ft_printf.h"

static void	f_pb(t_stack *a, t_stack *b)
{
	t_node	*a_first;

	if (a->size < 1)
		return ;
	a_first = a->top->next;
	a_first->prev->next = a_first->next;
	a_first->next->prev = a_first->prev;
	a->size--;
	a_first->prev = b->top;
	a_first->next = b->top->next;
	b->top->next->prev = a_first;
	b->top->next = a_first;
	b->size++;
}

static void	f_pa(t_stack *a, t_stack *b)
{
	t_node	*b_first;

	if (b->size < 1)
		return ;
	b_first = b->top->next;
	b_first->prev->next = b_first->next;
	b_first->next->prev = b_first->prev;
	b->size--;
	b_first->prev = a->top;
	b_first->next = a->top->next;
	a->top->next->prev = b_first;
	a->top->next = b_first;
	a->size++;
}

void	pb(t_stack *a, t_stack *b)
{
	f_pb(a, b);
	ft_printf("pb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	f_pa(a, b);
	ft_printf("pa\n");
}
