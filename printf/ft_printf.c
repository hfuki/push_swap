/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:35:15 by hfuki             #+#    #+#             */
/*   Updated: 2025/06/02 16:36:15 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_output(const char *save, va_list args)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (save[i])
	{
		if (save[i] == '%')
		{
			i++;
			c += ft_handle_first(save[i], args);
		}
		else
		{
			ft_putchar_fd(save[i], 1);
			c++;
		}
		i++;
	}
	return (c);
}

int	ft_printf(const char *format, ...)
{
	const char	*save;
	va_list		args;
	int			num;

	num = 0;
	if (!format)
		return (-1);
	save = ft_strdup(format);
	if (!save)
		return (0);
	va_start(args, format);
	num = ft_count_output(save, args);
	va_end(args);
	free((char *)save);
	return (num);
}
