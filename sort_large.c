/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:06:23 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/21 18:45:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"

static int	partition_a_to_b(t_stack *a, t_stack *b, int size, int pivot)
{
	int	tmp;
	int	c;

	c = 0;
	while (size > 0)
	{
		if (a->top->next->value <= pivot)
			pb(a, b);
		else
		{
			ra(a);
			c++;
		}
		size--;
	}
	tmp = c;
	while (tmp > 0)
	{
		rra(a);
		tmp--;
	}
	return (c);
}

static int	partition_b_to_a(t_stack *a, t_stack *b, int size, int pivot)
{
	int	tmp;
	int	c;

	c = 0;
	while (size > 0)
	{
		if (b->top->next->value > pivot)
			pa(a, b);
		else
		{
			rb(b);
			c++;
		}
		size--;
	}
	tmp = c;
	while (tmp > 0)
	{
		rrb(b);
		tmp--;
	}
	return (c);
}

void	quick_sort_b(t_stack *a, t_stack *b, int size)
{
	int	count_rb;

	if (size <= 3)
		return (sort_small_b(b, a));
	count_rb = partition_b_to_a(a, b, size, get_pivot(b, size));
	quick_sort_b(a, b, count_rb);
	quick_sort_a(a, b, size - count_rb);
}

void	quick_sort_a(t_stack *a, t_stack *b, int size)
{
	int	count_ra;

	if (size <= 3)
	{
		while (size > 0)
		{
			pb(a, b);
			size--;
		}
		return (sort_small_b(b, a));
	}
	count_ra = partition_a_to_b(a, b, size, get_pivot(a, size));
	quick_sort_b(a, b, size - count_ra);
	quick_sort_a(a, b, count_ra);
}

void	sort_large(t_stack *a, t_stack *b)
{
	quick_sort_a(a, b, a->size);
	return ;
}
