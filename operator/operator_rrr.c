/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:29:25 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 17:32:04 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_info *info, t_dlst **ans)
{
	t_dlst	*new;
	t_dlst	*begin;

	if (info->a_size <= 1)
		return ;
	new = ft_dlst_new(RRA);
	ft_dlst_addback(ans, new);
	begin = info->a->next;
	ft_dlst_swap(info->a, begin);
	info->a = begin;
}

void	rrb(t_info *info, t_dlst **ans)
{
	t_dlst	*new;
	t_dlst	*begin;

	if (info->b_size <= 1)
		return ;
	new = ft_dlst_new(RRB);
	ft_dlst_addback(ans, new);
	begin = info->b->next;
	ft_dlst_swap(info->b, begin);
	info->b = begin;
}

void	rrr(t_info *info, t_dlst **ans)
{
	t_dlst	*new;
	t_dlst	*begin;

	if (info->a_size == 0 || info->b_size == 0)
		return ;
	new = ft_dlst_new(RRR);
	ft_dlst_addback(ans, new);
	begin = info->a->next;
	ft_dlst_swap(info->a, begin);
	info->a = begin;
	begin = info->b->next;
	ft_dlst_swap(info->b, begin);
	info->b = begin;
}
