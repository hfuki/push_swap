/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_handle1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:12:03 by hfuki             #+#    #+#             */
/*   Updated: 2025/05/29 17:39:22 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_handle_string(char *str)
{
	int	n;

	if (str == NULL)
		str = "(null)";
	n = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (n);
}

int	ft_handle_point(void *point)
{
	char			*p;
	unsigned long	lp;
	int				n;

	lp = (unsigned long)point;
	if (!point)
		return (write(1, "(nil)", 5));
	else
		p = ft_tolower_all(ft_point_base(lp, 16));
	n = ft_putstr_count("0x");
	n += ft_putstr_count(p);
	free(p);
	return (n);
}

int	ft_handle_int(int i)
{
	char	*str;
	int		n;

	str = ft_itoa(i);
	n = ft_putstr_count(str);
	free(str);
	return (n);
}

int	ft_handle_hex(unsigned int i, int f)
{
	char	*hex;
	int		n;

	if (!i)
		i = 0;
	hex = ft_point_base((unsigned long)i, 16);
	if (f == 1)
		hex = ft_tolower_all(hex);
	n = ft_putstr_count(hex);
	free(hex);
	return (n);
}
