/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:34:25 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 17:34:57 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_info *info, t_dlst **ans)
{
	t_dlst	*new;
	t_dlst	*last;

	if (ft_dlst_size((info->b)) == 0)
		return ;
	new = ft_dlst_new(PA);
	ft_dlst_addback(ans, new);
	last = ft_dlst_popback(&(info->b));
	ft_dlst_addback(&(info->a), last);
	info->a_size++;
	info->b_size--;
}

void	pb(t_info *info, t_dlst **ans)
{
	t_dlst	*new;
	t_dlst	*last;

	if (ft_dlst_size((info->a)) == 0)
		return ;
	new = ft_dlst_new(PB);
	ft_dlst_addback(ans, new);
	last = ft_dlst_popback(&(info->a));
	ft_dlst_addback(&(info->b), last);
	info->b_size++;
	info->a_size--;
}
