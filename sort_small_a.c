/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:06:28 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/17 16:06:28 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	sort_three_a(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->next->value;
	second = a->top->next->next->value;
	third = a->top->next->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static int	find_min(t_stack *s)
{
	t_node	*cur;
	int		min;

	cur = s->top->next;
	min = cur->value;
	while (cur != s->top)
	{
		if (cur->value < min)
			min = cur->value;
		cur = cur->next;
	}
	return (min);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	int		min;
	t_node	*cur;
	int		i;

	while (a->size > 3)
	{
		min = find_min(a);
		cur = a->top->next;
		i = 0;
		while (cur->value != min)
		{
			i++;
			cur = cur->next;
		}
		if (i <= a->size / 2)
			while (a->top->next->value != min)
				ra(a);
		else
			while (a->top->next->value != min)
				rra(a);
		pb(a, b);
	}
	sort_three_a(a);
	while (b->size > 0)
		pa(a, b);
}

void	sort_small_a(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three_a(a);
	else if (a->size > 3)
		sort_five(a, b);
}
