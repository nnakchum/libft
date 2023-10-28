/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:45:16 by nnakchum          #+#    #+#             */
/*   Updated: 2023/10/28 22:57:30 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freetab(char **s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
		free(s2[i++]);
	free (s2);
	return (NULL);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			|| (i == 0 && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;
	size_t	i;
	size_t	j;
	size_t	mem;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	s2 = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!s2)
		return (NULL);
	while (s[i] && j < ft_countword(s, c))
	{
		while (s[i] == c)
			i++;
		mem = i;
		while (s[i] && s[i] != c)
			i++;
		s2[j] = ft_substr(s, mem, i - mem);
		if (s2[j++] == NULL)
			return (ft_freetab(s2));
	}
	s2[j] = NULL;
	return (s2);
}
