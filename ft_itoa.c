/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:45:16 by nnakchum          #+#    #+#             */
/*   Updated: 2023/10/28 22:40:07 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_len(long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (++len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	nlen;
	long	nb;
	char	*tab;

	nb = n;
	nlen = nb_len(nb);
	tab = malloc(sizeof(char) * (nlen + 1));
	if (!tab)
		return (NULL);
	i = 0;
	if (n < 0)
		nb *= -1 ;
	while (i < nlen)
	{
		tab[nlen - i - 1] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
		*tab = '-';
	tab[nlen] = '\0';
	return (tab);
}
