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
#include "utils.h"
#include "printf/ft_printf.h"

static void	sort_three_b(t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = b->top->next->value;
	second = b->top->next->next->value;
	third = b->top->next->next->next->value;
	if (first > second && second < third && first < third)
		sb(b);
	else if (first > second && second > third)
	{
		sb(b);
		rrb(b);
	}
	else if (first > second && second < third && first > third)
		rb(b);
	else if (first < second && second > third && first < third)
	{
		sb(b);
		rb(b);
	}
	else if (first < second && second > third && first > third)
		rrb(b);
}

static void	b_to_a_bottom(t_stack *a, t_stack *b, int size)
{
	while (size > 0)
	{
		pa(a, b);
		ra(a);
		size--;
	}
	if (!b->size)
	{
		while (size > 0)
		{
			ra(a);
			size--;
		}
	}
	return ;
}

void	sort_small_b(t_stack *a, t_stack *b, int size)
{
	if (!is_sorted(b))
	{
		if (b->size == 2)
			sb(b);
		else if (b->size == 3)
			sort_three_b(b);
	}
	b_to_a_bottom(a, b, size);
}
