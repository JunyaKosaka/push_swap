/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:29:25 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/02 14:22:44 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	rra(t_info *info)
{
	t_dlst	*new;
	t_dlst	*begin;

	if (info->a_size <= 1)
		return ;
	new = dlst_new(RRA);
	if (!new)
		exit(free_all_info(info, TRUE));
	dlst_addback(&(info->ans), new);
	begin = info->a->next;
	dlst_swap(info->a, begin);
	info->a = begin;
}

void	rrb(t_info *info)
{
	t_dlst	*new;
	t_dlst	*begin;

	if (info->b_size <= 1)
		return ;
	new = dlst_new(RRB);
	if (!new)
		exit(free_all_info(info, TRUE));
	dlst_addback(&(info->ans), new);
	begin = info->b->next;
	dlst_swap(info->b, begin);
	info->b = begin;
}

void	rrr(t_info *info)
{
	t_dlst	*new;
	t_dlst	*begin;

	if (info->a_size == 0 || info->b_size == 0)
		return ;
	new = dlst_new(RRR);
	if (!new)
		exit(free_all_info(info, TRUE));
	dlst_addback(&(info->ans), new);
	begin = info->a->next;
	dlst_swap(info->a, begin);
	info->a = begin;
	begin = info->b->next;
	dlst_swap(info->b, begin);
	info->b = begin;
}
