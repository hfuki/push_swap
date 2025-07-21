/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:50:22 by hfuki             #+#    #+#             */
/*   Updated: 2025/05/02 16:57:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"
#include <stdlib.h>

size_t	word_count(char const *s, char c)
{
	size_t	i;
	int		newword;
	size_t	count;

	i = 0;
	count = 0;
	newword = 0;
	while (s[i])
	{
		if (s[i] != c && !newword)
		{
			newword = 1;
			count++;
		}
		else if (s[i] == c)
			newword = 0;
		i++;
	}
	return (count);
}

static char	*dup_word(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i++] = *start++;
	}
	word[i] = '\0';
	return (word);
}

static int	add_word(char **res, char const *s, size_t *i, char c)
{
	size_t	len;
	size_t	start;

	while (s[*i] == c && s[*i])
		(*i)++;
	start = *i;
	len = 0;
	while (s[*i] && s[*i] != c)
	{
		len++;
		(*i)++;
	}
	*res = dup_word(s + start, len);
	if (!(*res))
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		if (!add_word(&res[j++], s, &i, c))
			return (NULL);
	}
	res[j] = NULL;
	return (res);
}
