/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:04:13 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/06 21:59:44 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static int	bottom_move(t_info *info, int move)
{
	int	last;

	while (dlst_back(info->b) != info->target)
	{
		last = dlst_back(info->b);
		if (dlst_back(info->a) > last || dlst_back(info->a) == 0)
		{
			pa(info);
			move++;
		}
		else
			rrb(info);
	}
	return (move);
}

static int	top_move(t_info *info, int move)
{
	int	b_last;
	int	a_last2;

	while (dlst_back(info->b) != info->target)
	{
		b_last = dlst_back(info->b);
		a_last2 = dlst_rbegin(info->a)->prev->value;
		if (dlst_back(info->a) > b_last || dlst_back(info->a) == 3)
		{
			pa(info);
			move++;
		}
		else if (a_last2 > b_last && dlst_back(info->a) < b_last)
		{
			pa(info);
			move++;
			sa(info);
		}
		else
			rb(info);
	}
	return (move);
}

static int	lower_distance(t_info *info, int index)
{
	int	lower_dist;
	int	last;
	int	min;
	t_dlst	*cur;

	lower_dist = index + 1;
	last = dlst_back(info->b);
	if (last > dlst_back(info->a))
		last = dlst_back(info->a);
	cur = info->b->next;
	min = last;
	while (cur->value != info->target)
	{
		if (min > cur->value)
		{
			lower_dist -= 1;
			min = cur->value;
		}
		cur = cur->next;
	}
	return (lower_dist);
}

static int	upper_distance(t_info *info, int index)
{
	int	upper_dist;
	int	last;
	int	min;
	t_dlst	*cur;

	upper_dist = info->b_size - (index + 1);
	last = dlst_back(info->b);
	if (last > dlst_back(info->a))
		last = dlst_back(info->a);
	cur = dlst_rbegin(info->b)->prev;
	min = last;
	while (cur->value != info->target)
	{
		if (min > cur->value)
		{
			upper_dist -= 2;
			min = cur->value;
		}
		cur = cur->prev;
	}
	return (upper_dist - 2);
}

void	push_b_to_a(t_info *info)
{
	int	move;
	int	index;

	move = 0;
	while (info->b_size && info->target < info->total_len)
	{
		index = b_target_index(info, info->target);
		if (lower_distance(info, index) < upper_distance(info, index))
			move = bottom_move(info, move);
		else
			move = top_move(info, move);
		pa(info);
		ra(info);
		info->target += 1;
		while (move && dlst_back(info->a) == info->target && info->target < info->total_len)
		{
			ra(info);
			move--;
			info->target += 1;
		}
	}
}
