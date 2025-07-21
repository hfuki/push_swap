/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:05:44 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/17 16:05:44 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "printf/ft_printf.h"

static void	f_sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (a->size < 2)
		return ;
	first = a->top->next;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

static void	f_sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (b->size < 2)
		return ;
	first = b->top->next;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

void	sa(t_stack *a)
{
	f_sa(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	f_sb(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	f_sa(a);
	f_sb(b);
	ft_printf("ss\n");
}
