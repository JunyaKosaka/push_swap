/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:36:16 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 17:36:20 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_info *info, t_dlst **ans)
{
	t_dlst	*new;
	t_dlst	*last;

	if (info->a_size <= 1)
		return ;
	new = ft_dlst_new(RA);
	ft_dlst_addback(ans, new);
	last = ft_dlst_last(info->a);
	ft_dlst_swap(info->a, last);
	info->a = last;
}

void	rb(t_info *info, t_dlst **ans)
{
	t_dlst	*new;
	t_dlst	*last;

	if (info->b_size <= 1)
		return ;
	new = ft_dlst_new(RB);
	ft_dlst_addback(ans, new);
	last = ft_dlst_last(info->b);
	ft_dlst_swap(info->b, last);
	info->b = last;
}

void	rr(t_info *info, t_dlst **ans)
{
	t_dlst	*new;
	t_dlst	*last;

	if (info->a_size == 0 || info->b_size == 0)
		return ;
	new = ft_dlst_new(RR);
	ft_dlst_addback(ans, new);
	last = ft_dlst_last(info->a);
	ft_dlst_swap(info->a, last);
	info->a = last;
	last = ft_dlst_last(info->b);
	ft_dlst_swap(info->b, last);
	info->b = last;
}
