/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:05:25 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/17 16:05:25 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"
#include "sort.h"
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (free_all(a, b), 0);
	argc--;
	while (argc > 0)
	{
		if (str_is_int(argv[argc]))
			push_top(a, (int)ft_atoi(argv[argc]));
		else
			return (free_all(a, b), 0);
		argc--;
	}
	if (is_sorted(a) || has_duplicates(a))
		return (free_all(a, b), 0);
	if (a->size <= 5)
		sort_small_a(a, b);
	else
		sort_large(a, b);
	return (free_all(a, b), 0);
}
