/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:26:00 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 17:32:55 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_last(t_dlst **d)
{
	t_dlst	*last;
	t_dlst	*last2;

	last = ft_dlst_last(*d);
	last2 = last->prev;
	ft_dlst_swap(last, last2);
}

void	sa(t_info *info, t_dlst **ans)
{
	t_dlst	*new;

	if (info->a_size <= 1)
		return ;
	new = ft_dlst_new(SA);
	ft_dlst_addback(ans, new);
	swap_last(&(info->a));
}

void	sb(t_info *info, t_dlst **ans)
{
	t_dlst	*new;

	if (info->b_size <= 1)
		return ;
	new = ft_dlst_new(SB);
	ft_dlst_addback(ans, new);
	swap_last(&(info->b));
}

void	ss(t_info *info, t_dlst **ans)
{
	t_dlst	*new;

	if (info->a_size <= 1 || info->b_size <= 1)
		return ;
	new = ft_dlst_new(SS);
	ft_dlst_addback(ans, new);
	swap_last(&(info->a));
	swap_last(&(info->b));
}
