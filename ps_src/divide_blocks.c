/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_blocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 00:56:33 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/01 00:59:24 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	to_go_bottom_b(t_info *info)
{
	int	last;
	int	i;

	last = dlst_back(info->b);
	if ((info->wall)[1] <= last && last < (info->wall)[2])
		return (1);
	i = 2;
	while (i < info->divide)
	{
		if ((info->wall)[i] <= last && last < (info->wall)[i + 1])
			return (1);
		i += 2;
	}
	return (0);
}

static void	divide_first_a_to_b(t_info *info)
{
	int	i;
	int	center;

	center = (2 + info->divide - 1) / 2; // 8
	i = 0;
	set_border_a(info, center, center + 1);
	while (i < info->total_len)
	{
		if (is_in_border(info->border_a, dlst_back(info->a)))
			ra(info);
		else
		{
			pb(info);
			if (to_go_bottom_b(info))
				rb(info);
		}
		i++;
	}
}

static int	to_go_a(t_info *info, int center, int diff, int last)
{
	return ((info->wall)[center - diff] <= last && last < (info->wall)[center + 1 + diff]);
}

void	divide_blocks(t_info *info)
{
	int	diff;
	int	len;
	int	last;
	int	center;

	center = (2 + info->divide - 1) / 2;
	// aからbへ１回目の分配
	divide_first_a_to_b(info);
	diff = 2;
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
		diff += 2;
	}
}
