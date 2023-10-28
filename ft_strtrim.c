/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:45:16 by nnakchum          #+#    #+#             */
/*   Updated: 2023/10/28 23:04:55 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*tab;

	tab = NULL;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (!*s1)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[start]))
		start++;
	while (start < end && ft_strchr(set, s1[end]))
		end--;
	tab = ft_substr(s1, start, end - start + 1);
	return (tab);
}
