/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:26:39 by hfuki             #+#    #+#             */
/*   Updated: 2025/05/29 17:48:49 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_count(char *c)
{
	int	n;

	if (!c)
		return (0);
	n = ft_strlen(c);
	ft_putstr_fd(c, 1);
	return (n);
}

static char	*change_base(unsigned long us, int b, char *r, int c)
{
	while (us != 0)
	{
		if ((us % b) < 10)
			r[c - 1] = (us % b) + '0';
		else
			r[c - 1] = (us % b) + 'A' - 10;
		us /= b;
		c--;
	}
	return (r);
}

char	*ft_point_base(unsigned long point, int base)
{
	char			*rt;
	unsigned long	us;
	int				c;

	c = 0;
	us = point;
	if (point == 0)
		return (ft_strdup("0"));
	while (point != 0)
	{
		point = point / base;
		c++;
	}
	rt = ft_calloc(c + 1, sizeof(char));
	if (!rt)
		return (0);
	rt = change_base(us, base, rt, c);
	return (rt);
}

char	*ft_tolower_all(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		c[i] = ft_tolower(c[i]);
		i++;
	}
	return (c);
}
