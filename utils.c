/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:10:39 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/17 16:10:39 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"

int	is_sorted(t_stack *a)
{
	t_node	*node;

	if (a->size < 2)
		return (1);
	node = a->top->next;
	while (node != a->top)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	has_duplicates(t_stack *a)
{
	t_node	*outer;
	t_node	*inner;

	outer = a->top->next;
	while (outer != a->top)
	{
		inner = outer->next;
		while (inner != outer && inner != a->top)
		{
			if (inner->value == outer->value)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}

int	str_is_int(const char *s)
{
	size_t	i;
	long	num;

	i = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	num = ft_atoi(s);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	return ;
}
