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
#include "utils.h"

void	error_fin(t_stack *a, t_stack *b)
{
	ft_printf("Error\n");
	free_all(a, b);
	return ;
}
