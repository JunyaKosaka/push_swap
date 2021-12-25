/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:28:41 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/16 22:46:11 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*dst_tail;

	if (!lst || !f)
		return (NULL);
	dst = ft_lstnew((*f)(lst->content));
	if (!dst)
		return (NULL);
	dst_tail = dst;
	while (lst->next)
	{
		lst = lst->next;
		dst_tail->next = ft_lstnew((*f)(lst->content));
		if (!(dst_tail->next))
		{
			ft_lstclear(&dst, (*del));
			return (NULL);
		}
		dst_tail = dst_tail->next;
	}
	return (dst);
}
