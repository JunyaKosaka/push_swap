/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:58:34 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/01 21:56:11 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	to_go_b(t_info *info, int center, int is_second)
{
	int	i;
	int	diff;

	if (is_in_border(info->border_a, dlst_back(info->a)))
		return (FALSE);
	if (is_second)
		return (TRUE);
	i = -1;
	while (++i < info->divide)
	{
		set_border_b(info, i, i + 1);
		if (is_in_border(info->border_b, dlst_back(info->a)))
		{
			diff = abs_v(i - center) % 4;
			if (diff == 2 || diff == 3)
				return (TRUE);
			else
				return (FALSE);
		}
	}
	return (FALSE);
}

static int	to_go_bottom_b(t_info *info, int center)
{
	int	i;
	int	diff;

	i = -1;
	while (++i < info->divide)
	{
		set_border_b(info, i, i + 1);
		if (is_in_border(info->border_b, dlst_back(info->b)))
		{
			diff = abs_v(i - center) % 4;
			if (i < 4 && i % 4 >= 2)
				return (TRUE);
			else if (i >= 4 && (diff == 0 || diff == 3))
				return (TRUE);
			else
				return (FALSE);
		}
	}
	return (FALSE);
}

static void	divide_first_a_to_b(t_info *info, int is_second)
{
	int	i;
	int	center;
	int	len;

	center = (4 + info->divide - 1) / 2; // 8
	i = 0;
	len = info->a_size;
	set_border_a(info, center, center + 1);
	while (i < len)
	{
		if (to_go_b(info, center, is_second))
		{
			pb(info);
			if (to_go_bottom_b(info, center))
				rb(info);
		}
		else
		{
			ra(info);
		}
		i++;
	}
}

static int	to_go_a(t_info *info, int center, int diff, int last)
{
	int	bottom;
	int	top;

	bottom = center - diff;
	top = center + 1 + diff;
	return ((info->wall)[bottom] <= last && last < (info->wall)[top]);
}

static void	divide_21_blocks(t_info *info)
{
	int	diff;
	int	len;
	int	last;
	int	center;

	center = (4 + info->divide - 1) / 2;
	// aからbへ１回目の分配
	divide_first_a_to_b(info, 0);
	divide_first_a_to_b(info, 1);
	// return ;
	diff = 4;
	while (center - diff >= 2)
	{
		len = info->b_size;
		while (len)
		{
			last = dlst_back(info->b);
			if (to_go_a(info, center, diff, last))
			{
				pa(info);
				if ((info->wall)[center + 1] <= last)
					ra(info);
			}
			else
				rb(info);
			len--;
		}
		diff += 4;
	}
}

static void	line_up(t_info *info)
{
	int	i;
	int	len;

	push_b_to_a(info);
	i = 4;
	while (i < info->divide)
	{
		len = (info->wall)[i + 1] - (info->wall)[i];
		push_a_to_b(len, info);
		push_b_to_a(info);
		i++;
	}
}

int	deque_sort(t_info *info)
{
	int		len;

	info->divide = 5 + 8 * (info->total_len / 220);
	if (info->divide == 5)
		info->divide = 13;
	set_wall(info);
	divide_21_blocks(info);
	line_up(info);
	// show(*info);
	assert(info->b_size == 0);
	info->ans = compress_ans(info->ans);
	// show_ans(info.ans);
	len = dlst_size(info->ans);
	// printf("divide done %d\n", len);
	// exit(0);
	return (len);
}
