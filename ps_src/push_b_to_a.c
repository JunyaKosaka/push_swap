/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:04:13 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/03 01:45:25 by jkosaka          ###   ########.fr       */
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
		if (dlst_back(info->a) > b_last || dlst_back(info->a) == 0)
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

void	push_b_to_a(t_info *info)
{
	int	move;
	int	index;

	move = 0;
	while (info->b_size)
	{
		index = b_target_index(info, info->target);
		if (index < info->b_size / 2 - 1)
			move = bottom_move(info, move);
		else
			move = top_move(info, move);
		pa(info);
		ra(info);
		info->target += 1;
		while (move && dlst_back(info->a) == info->target)
		{
			ra(info);
			move--;
			info->target += 1;
		}
	}
}
