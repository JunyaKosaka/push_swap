/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:25:00 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 01:54:04 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	ra(t_info *info)
{
	t_dlst	*new;
	t_dlst	*last;

	if (info->a_size <= 1)
		return ;
	new = dlst_new(RA);
	if (!new)
		exit(free_all_info(info, true));
	dlst_pushback(&(info->ans), new);
	last = dlst_rbegin(info->a);
	dlst_swap(info->a, last);
	info->a = last;
}

void	rb(t_info *info)
{
	t_dlst	*new;
	t_dlst	*last;

	if (info->b_size <= 1)
		return ;
	new = dlst_new(RB);
	if (!new)
		exit(free_all_info(info, true));
	dlst_pushback(&(info->ans), new);
	last = dlst_rbegin(info->b);
	dlst_swap(info->b, last);
	info->b = last;
}

void	rr(t_info *info)
{
	t_dlst	*new;
	t_dlst	*last;

	if (info->a_size == 0 || info->b_size == 0)
		return ;
	new = dlst_new(RR);
	if (!new)
		exit(free_all_info(info, true));
	dlst_pushback(&(info->ans), new);
	if (info->a_size > 1)
	{
		last = dlst_rbegin(info->a);
		dlst_swap(info->a, last);
		info->a = last;
	}
	if (info->b_size > 1)
	{
		last = dlst_rbegin(info->b);
		dlst_swap(info->b, last);
		info->b = last;
	}
}
