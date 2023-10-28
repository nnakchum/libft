/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:24:45 by nnakchum          #+#    #+#             */
/*   Updated: 2023/10/10 20:08:29 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dl;
	size_t	sl;

	sl = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (sl);
	dl = ft_strlen(dst);
	if (dstsize <= dl)
		return (dstsize + sl);
	i = 0;
	while (src[i] && dl + 1 < dstsize)
		dst[dl++] = src[i++];
	dst[dl] = '\0';
	return (dl + ft_strlen(src + i));
}
