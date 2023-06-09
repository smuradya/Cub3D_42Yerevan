/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:57:41 by anhakob2          #+#    #+#             */
/*   Updated: 2023/06/09 15:51:10 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static size_t	wordlen(char const *s, char c)
{
	size_t	index;

	index = 0;
	while (*s)
	{
		index++;
		while (*s && *s == c)
		s++;
		if (*s == '\0')
			index--;
		while (*s && *s != c)
			s++;
	}
	return (index);
}

static char	**fill_string(char **store, char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			store[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	store[i] = 0;
	return (store);
}

char	**ft_split(char const *s, char c)
{
	char	**split_string;
	size_t	len_words;

	if (!s)
		return (NULL);
	len_words = wordlen(s, c);
	split_string = malloc(sizeof(char *) * (len_words + 1));
	if (!split_string)
		return (NULL);
	split_string = fill_string(split_string, s, c);
	return (split_string);
}
