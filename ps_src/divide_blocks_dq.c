/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_blocks_dq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:18:09 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/03 11:52:55 by jkosaka          ###   ########.fr       */
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
	int	inside_border_size;

	center = (4 + info->divide - 1) / 2;
	i = 0;
	len = info->a_size;
	set_border_a(info, center, center + 1);
	inside_border_size = info->border_a[1] - info->border_a[0];
	while (i < len)
	{
		if (info->a_size == inside_border_size)
			break ;
		if (to_go_b(info, center, is_second))
		{
			pb(info);
			if (to_go_bottom_b(info, center))
				rb(info);
		}
		else
			ra(info);
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

void	divide_blocks_dq(t_info *info)
{
	int	diff;
	int	len;
	int	center;

	center = (4 + info->divide - 1) / 2;
	divide_first_a_to_b(info, 0);
	divide_first_a_to_b(info, 1);
	diff = 4;
	while (center - diff >= 2)
	{
		len = info->b_size;
		while (len--)
		{
			if (to_go_a(info, center, diff, dlst_back(info->b)))
			{
				pa(info);
				if ((info->wall)[center + 1] <= dlst_back(info->a))
					ra(info);
			}
			else
				rb(info);
		}
		diff += 4;
	}
}
