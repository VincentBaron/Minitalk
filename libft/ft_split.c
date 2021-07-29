/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:14:59 by vbaron            #+#    #+#             */
/*   Updated: 2021/07/28 17:36:29 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	split_size(char const *s, char c)
{
	int	element;

	element = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			element++;
			while (*s != c && *s)
				s++;
		}
	}
	return (element + 1);
}

char	*alloc_array(char const *s, char c)
{
	int		i;
	char	*array;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	array = (char *)malloc(sizeof(char) * (i + 1));
	if (!array)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (split_size(s, c)));
	if (!split)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			split[i] = alloc_array(s, c);
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	split[i] = NULL;
	return (split);
}
