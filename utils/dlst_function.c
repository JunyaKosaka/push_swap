/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 01:55:55 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/04 21:16:36 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	dlst_pushback(t_dlst **lst, t_dlst *new)
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
		t_last = dlst_rbegin(*lst);
		t_last->next = new;
		new->prev = t_last;
		new->next = t_begin;
		t_begin->prev = new;
	}
}

t_dlst	*dlst_popback(t_dlst **lst)
{
	t_dlst	*t_last;

	if (!lst || dlst_size(*lst) == 0)
		return (NULL);
	t_last = dlst_rbegin(*lst);
	t_last->next->prev = t_last->prev;
	t_last->prev->next = t_last->next;
	return (t_last);
}

void	dlst_delone(t_dlst *lst)
{
	if (!lst)
		return ;
	free(lst);
	lst = NULL;
}

void	dlst_clear(t_dlst **lst)
{
	t_dlst	*cur;
	t_dlst	*prev;

	if (!lst || !(*lst))
		return ;
	cur = *lst;
	cur = cur->next;
	while (cur->value != SENTINEL)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	free(cur);
	*lst = NULL;
}

void	dlst_swap(t_dlst *a, t_dlst *b)
{
	int	temp;

	temp = a->value;
	a->value = b->value;
	b->value = temp;
}
