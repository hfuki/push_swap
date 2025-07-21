/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:19:11 by hfuki             #+#    #+#             */
/*   Updated: 2025/05/01 12:52:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*lsame;

	lsame = NULL;
	while (*s)
	{
		if (*s == (char)c)
			lsame = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)lsame);
}
