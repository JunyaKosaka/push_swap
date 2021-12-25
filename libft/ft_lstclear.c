/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:25:31 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/21 14:08:34 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*prev;

	if (!lst || !del)
		return ;
	cur = *lst;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		ft_lstdelone(prev, (*del));
	}
	*lst = NULL;
}
