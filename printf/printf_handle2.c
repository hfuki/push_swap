/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_handle2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:43:30 by hfuki             #+#    #+#             */
/*   Updated: 2025/05/29 17:07:52 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_unbr_count(unsigned int n)
{
	char				str;
	unsigned int		tmp;
	size_t				t;

	tmp = n;
	t = 0;
	while (9 < tmp)
	{
		tmp = tmp / 10;
		t++;
	}
	if (9 < n)
		ft_put_unbr_count(n / 10);
	str = '0' + n % 10;
	write(1, &str, 1);
	return (t + 1);
}

int	ft_handle_uint(unsigned int uint)
{
	int	n;

	n = 0;
	n = ft_put_unbr_count(uint);
	return (n);
}

int	ft_handle_first(int c, va_list args)
{
	int	n;

	n = 0;
	if (c == 'c')
		n = ft_handle_char(va_arg(args, int));
	else if (c == 's')
		n = ft_handle_string(va_arg(args, char *));
	else if (c == 'p')
		n = ft_handle_point(va_arg(args, void *));
	else if (c == 'u')
		n = ft_handle_uint((unsigned int)
				va_arg(args, unsigned int));
	else if (c == 'x')
		n = ft_handle_hex(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		n = ft_handle_hex(va_arg(args, unsigned int), 2);
	else if (c == '%')
		n = ft_putstr_count("%");
	else if (c == 'd' || c == 'i')
		n = ft_handle_int(va_arg(args, int));
	return (n);
}
