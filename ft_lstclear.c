/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:21:42 by nnakchum          #+#    #+#             */
/*   Updated: 2023/10/31 21:12:43 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*pre;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		pre = current;
		current = current->next;
		del(pre->content);
		free(current);
	}
	*lst = NULL;
}
