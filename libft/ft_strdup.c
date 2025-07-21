/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:41:40 by hfuki             #+#    #+#             */
/*   Updated: 2025/05/01 13:03:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t			i;
	size_t			len;
	unsigned char	*str;

	len = 0;
	while (s1[len])
		len++;
	str = (unsigned char *) malloc ((len + 1) * sizeof(unsigned char));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		str[i] = s1[i];
		i++;
	}
	return ((char *)str);
}
