/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:49:33 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 19:46:08 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dlst	*ft_dlst_last(t_dlst *lst)
{
	if (!lst)
		return (NULL);
	lst = lst->prev;
	return (lst);
}

t_dlst	*ft_dlst_new(long value)
{
	t_dlst	*ret;

	ret = (t_dlst *)malloc(sizeof(t_dlst));
	if (!ret)
		return (NULL);
	ret->value = value;
	ret->next = ret;
	ret->prev = ret;
	return (ret);
}

// not include sentinel
int	ft_dlst_size(t_dlst *lst)
{
	int		ret;
	t_dlst	*begin;

	begin = lst;
	if (!lst)
		return (0);
	ret = 0;
	while (lst->next != begin)
	{
		ret++;
		lst = lst->next;
	}
	return (ret);
}

int	dlst_back(t_dlst *a)
{
	return (a->prev->value);
}
