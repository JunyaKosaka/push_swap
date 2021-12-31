/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:53:43 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 01:50:31 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlst	*dlst_rbegin(t_dlst *lst)
{
	if (!lst)
		return (NULL);
	lst = lst->prev;
	return (lst);
}

t_dlst	*dlst_new(int value)
{
	t_dlst	*ret;

	ret = (t_dlst *)malloc(sizeof(t_dlst));
	if (!ret)
		exit(error_handler()); // ここでfree_all_infoする必要あるのか
	ret->value = value;
	ret->next = ret;
	ret->prev = ret;
	return (ret);
}

/*   not include sentinel   */
int	dlst_size(t_dlst *lst)
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

/*   value of the last of dlst   */
int	dlst_back(t_dlst *a)
{
	return (a->prev->value);
}
