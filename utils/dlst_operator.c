/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:43:32 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 17:44:15 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_dlst_addback(t_dlst **lst, t_dlst *new)
{
	t_dlst	*t_begin;
	t_dlst	*t_last;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		t_begin = *lst;
		t_last = ft_dlst_last(*lst);
		t_last->next = new;
		new->prev = t_last;
		new->next = t_begin;
		t_begin->prev = new;
	}
}

t_dlst	*ft_dlst_popback(t_dlst **lst)
{
	t_dlst	*t_last;

	if (!lst || ft_dlst_size(*lst) == 0)
		return (NULL);
	t_last = ft_dlst_last(*lst);
	t_last->next->prev = t_last->prev;
	t_last->prev->next = t_last->next;
	return (t_last);
}
