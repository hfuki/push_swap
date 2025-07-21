/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:31:53 by hfuki             #+#    #+#             */
/*   Updated: 2025/07/14 17:45:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_handle_char(char c);
int		ft_handle_string(char *str);
int		ft_handle_point(void *point);
int		ft_handle_int(int i);
int		ft_handle_hex(unsigned int i, int f);
int		ft_handle_uint(unsigned int uint);
int		ft_putstr_count(char *c);
int		ft_handle_first(int c, va_list args);
char	*ft_point_base(unsigned long point, int base);
char	*ft_tolower_all(char *c);

#endif
