/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:07:09 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/17 16:07:09 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"

void	sort_small_a(t_stack *a, t_stack *b);
void	sort_small_b(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);
int		get_pivot(t_stack *a, int size);
void	quick_sort_b(t_stack *a, t_stack *b, int size);
void	quick_sort_a(t_stack *a, t_stack *b, int size);

#endif
