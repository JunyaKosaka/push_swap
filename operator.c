/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:17 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/25 19:47:19 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (ft_dlst_size(info->a) <= 1)
		return ;
	new = ft_dlst_new(SA);
	ft_dlst_addback(ans, new);
	swap_last(&(info->a));
}

void	sb(t_info *info, t_dlst **ans)
{
	t_dlst	*new;

	if (ft_dlst_size(info->b) <= 1)
		return ;
	new = ft_dlst_new(SB);
	ft_dlst_addback(ans, new);
	swap_last(&(info->b));
}

void	ss(t_info *info, t_dlst **ans)
{
	t_dlst	*new;

	if (ft_dlst_size(info->a) <= 1 || ft_dlst_size(info->b) <= 1)
		return ;
	new = ft_dlst_new(SS);
	ft_dlst_addback(ans, new);
	swap_last(&(info->a));
	swap_last(&(info->b));
}

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
}

void	ra(t_info *info, t_dlst **ans)
{
	t_dlst	*new;
	t_dlst	*last;

	if (ft_dlst_size(info->a) <= 1)
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

	if (ft_dlst_size(info->b) <= 1)
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

	if (ft_dlst_size(info->a) == 0 || ft_dlst_size(info->b) == 0)
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

void	rra(t_info *info, t_dlst **ans)
{
	t_dlst	*new;
	t_dlst	*begin;

	if (ft_dlst_size(info->a) <= 1)
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

	if (ft_dlst_size(info->b) <= 1)
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

	if (ft_dlst_size(info->a) == 0 || ft_dlst_size(info->b) == 0)
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
