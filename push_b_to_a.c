/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:04:13 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/28 01:21:49 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			move++;
		}
		else
			rb(info, ans);
	}
	return (move);
}

// ここでlenとmoveがうまく計算できていない
void	push_b_to_a(t_info *info, t_dlst **ans)
{
	int	move;
	int	index;

	move = 0;
	while (info->b_size)
	{
		index = b_target_index(info, info->target);
		if (index < info->b_size / 2)
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
	}
}

// void	quick_sort_b(int len, t_info *info, t_dlst **ans)
// {
// 	int		i;
// 	long	sum;
// 	long	border;
// 	int		move;
// 	int		stay;

// 	move = 0;
// 	stay = 0;
// 	sum = cal_last_sum(len, info->b);
// 	border = sum / len + 4;
// 	i = 0;
// 	while (i < len && info->b->next->value != -1)
// 	{
// 		if (dlst_back(info->b) == info->target)
// 		{
// 			pa(info, ans);
// 			ra(info, ans);
// 			info->target++;
// 		}
// 		else if (dlst_back(info->b) < border)
// 		{
// 			rb(info, ans);
// 			stay++;
// 		}
// 		else	
// 		{
// 			pa(info, ans);
// 			move++;
// 		}
// 		i++;
// 	}
// 	push_b_to_a(stay, info, ans);
// 	stay = push_a_to_b(move, info, ans);
// 	push_b_to_a(stay, info, ans);
// }
