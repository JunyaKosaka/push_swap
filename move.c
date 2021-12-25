/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:06 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/25 19:47:10 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	cal_last_sum(int len, t_dlst *a)
{
	long	sum;
	int		i;

	sum = 0;
	i = 0;
	a = a->prev;
	while (i < len)
	{
		sum += a->value;
		a = a->prev;
		i++;
	}
	return (sum);
}

static int	check_two(t_dlst *last, int target)
{
	return (last->value == target + 1 && last->prev->value == target);
}

void	push_a_to_b(int len, t_info *info, t_dlst **ans)
{
	int		i;
	long	sum;
	long	border;

	sum = cal_last_sum(len, info->a);
	border = sum / len - (len / 7);
	i = 0;
	while (i < len && info->a->next->value != -1)
	{
		if (i < len - 1 && check_two(info->a->prev, info->target))
		{
			sa(info, ans);
			ra(info, ans);
			info->target += 1;
		}
		else if (dlst_back(info->a) == info->target)
		{
			ra(info, ans);
			info->target += 1;
		}
		else
		{
			pb(info , ans);
			if (dlst_back(info->b) < border)
				rb(info, ans);
		}
		i++;
	}
}

static int	b_target_index(t_info *info, int target)
{
	int		i;
	t_dlst	*cur;

	i = 0;
	cur = info->b->next;
	while (cur->value != target)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

static int	bottom_move(t_info *info, t_dlst **ans, int move)
{
	while (dlst_back(info->b) != info->target)
	{
		if (dlst_back(info->a) > dlst_back(info->b))
		{
			pa(info, ans);
			info->b_size -= 1;
			move++;
		}
		else
			rrb(info, ans);
	}
	return (move);
}

static int	top_move(t_info *info, t_dlst **ans, int move)
{
	while (dlst_back(info->b) != info->target)
	{
		if (dlst_back(info->a) > dlst_back(info->b))
		{
			pa(info, ans);
			info->b_size -= 1;
			move++;
		}
		else
			rb(info, ans);
	}
	return (move);
}

void	push_b_to_a(t_info *info, t_dlst **ans)
{
	int	move;
	int	i;

	info->b_size = ft_dlst_size(info->b);
	move = 0;
	while (info->b_size)
	{
		i = b_target_index(info, info->target);
		if (i < info->b_size / 2)
			move = bottom_move(info, ans, move);
		else
			move = top_move(info, ans, move);
		pa(info, ans);
		ra(info, ans);
		info->target += 1;
		while (move && dlst_back(info->a) == info->target)
		{
			ra(info, ans);
			move--;
			info->target++;
		}
		info->b_size--;
	}
}

void	divide_a_to_b(int len, t_info *info, t_dlst **ans)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (isin(info->border_a, dlst_back(info->a)))
			ra(info, ans);
		else
		{
			pb(info, ans);
			if (isin(info->border_b, dlst_back(info->b)))
				rb(info, ans);
		}
		i++;
	}
}

void	divide_b_to_a(int len, t_info *info, t_dlst **ans)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (isin(info->border_b, dlst_back(info->b)))
			rb(info, ans);
		else
		{
			pa(info, ans);
			if (isin(info->border_a, dlst_back(info->a)))
				ra(info, ans);
		}
		i++;
	}
}
