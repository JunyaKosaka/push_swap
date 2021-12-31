/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:26:00 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 14:57:13 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_last(t_dlst **dlst)
{
	t_dlst	*last;
	t_dlst	*last2;

	last = dlst_rbegin(*dlst);
	last2 = last->prev;
	dlst_swap(last, last2);
}

void	sa(t_info *info)
{
	t_dlst	*new;

	if (info->a_size <= 1)
		return ;
	new = dlst_new(SA);
	if (!new)
		exit(error_handler());
	dlst_addback(&(info->ans), new);
	swap_last(&(info->a));
}

void	sb(t_info *info)
{
	t_dlst	*new;

	if (info->b_size <= 1)
		return ;
	new = dlst_new(SB);
	if (!new)
		exit(error_handler());
	dlst_addback(&(info->ans), new);
	swap_last(&(info->b));
}

void	ss(t_info *info)
{
	t_dlst	*new;

	if (info->a_size <= 1 || info->b_size <= 1)
		return ;
	new = dlst_new(SS);
	if (!new)
		exit(error_handler());
	dlst_addback(&(info->ans), new);
	swap_last(&(info->a));
	swap_last(&(info->b));
}
