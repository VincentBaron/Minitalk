/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:14:59 by vbaron            #+#    #+#             */
/*   Updated: 2020/05/03 23:35:31 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		split_size(char const *s, char c)
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
	if (!(array = (char *)malloc(sizeof(char) * (i + 1))))
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
	if (!(split = (char **)malloc(sizeof(char *) * (split_size(s, c)))))
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
