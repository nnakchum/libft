/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:45:16 by nnakchum          #+#    #+#             */
/*   Updated: 2023/10/28 23:03:01 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)

{
	size_t			l;
	unsigned char	chr;
	char			*p;

	chr = (unsigned char)c;
	p = (char *)s;
	l = ft_strlen(s);
	if (chr == '\0')
		return (p + l);
	while (l)
	{
		if (s[--l] == chr)
			return (p + l);
	}
	return (NULL);
}
