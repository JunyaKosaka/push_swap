/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_dlist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:29 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/25 19:47:32 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*ft_dlst_last(t_dlst *lst)
{
	if (!lst)
		return (NULL);
	lst = lst->prev;
	return (lst);
}

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

void	ft_dlst_delone(t_dlst *lst)
{
	if (!lst)
		return ;
	free(lst);
	lst = NULL;
}

void	ft_dlst_clear(t_dlst **lst)
{
	t_dlst	*cur;
	t_dlst	*prev;

	if (!lst)
		return ;
	cur = *lst;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		ft_dlst_delone(prev);
	}
	*lst = NULL;
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

void	ft_dlst_swap(t_dlst *a, t_dlst *b)
{
	int	temp;

	temp = a->value;
	a->value = b->value;
	b->value = temp;
}

int	dlst_back(t_dlst *a)
{
	return (a->prev->value);
}
