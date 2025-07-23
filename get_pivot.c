/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:16:42 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/23 15:16:42 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "sort.h"
#include <stdlib.h>

static int	*array_stack(t_stack *a, int size)
{
	int		*arr;
	int		i;
	t_node	*node;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	node = a->top->next;
	while (i < size)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	return (arr);
}

int	get_pivot(t_stack *a, int size)
{
	int		i;
	int		j;
	int		tmp;
	int		*arr;
	int		res;

	arr = array_stack(a, size);
	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (arr[j - 1] > arr[j])
			{
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
			j--;
		}
		i++;
	}
	res = arr[size / 2];
	return (free(arr), res);
}
