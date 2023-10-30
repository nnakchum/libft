/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:36:23 by nnakchum          #+#    #+#             */
/*   Updated: 2023/10/30 21:17:46 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	max_handle(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

static char	check_max(int sign)
{
	if (sign == 1)
		return ('7');
	else
		return ('8');
}

int	ft_atoi(const char *str)
{
	long	n;
	int		sign;
	int		max;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	max = check_max(sign);
	while (*str >= '0' && *str <= '9')
	{
		if ((n == LONG_MAX / 10 && *str > max) || (n > LONG_MAX / 10))
			return (max_handle(sign));
		n = (n * 10) + (*str - '0');
		str++;
	}
	return (n * sign);
}
