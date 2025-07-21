/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:10:44 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/17 16:10:44 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		is_sorted(t_stack *a);
int		has_duplicates(t_stack *a);
int		str_is_int(const char *s);
void	free_all(t_stack *a, t_stack *b);

#endif
