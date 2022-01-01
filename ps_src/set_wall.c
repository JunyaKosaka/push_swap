/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:35:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/01 22:14:59 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_wall_five(t_info *info)
{
	int	total;

	total = info->total_len;
	if (total > 90)
	{
		(info->wall)[2] += total / 40; // 53
		(info->wall)[3] -= total / 14 - total / 22; // 53
		(info->wall)[4] += total / 7 - total / 80;  // 93
	}
}

static void	set_wall_15(t_info *info)
{
	int	total;

	total = info->total_len;
	(info->wall)[1] -= total / 250;
	(info->wall)[2] -= total / 120;
	(info->wall)[3] -= total / 29;
	(info->wall)[4] -= total / 26;
	(info->wall)[5] -= total / 23;
	(info->wall)[6] -= total / 25;
	(info->wall)[7] -= total / 38;
	(info->wall)[8] += total / 300;
	// ここを大きく
	(info->wall)[9] += total / 20 + total / 300;
	(info->wall)[10] += total / 15 + total / 300;
	(info->wall)[11] += total / 15 + total / 160; // 36
	(info->wall)[12] += total / 15 + total / 83; // +39
	(info->wall)[13] += total / 15 + total / 200; // +33
	(info->wall)[14] += total / 17; // 492  3795
}

static void	set_wall_other(t_info *info)
{
	int	total;
	int	center;
	int	i;

	total = info->total_len;
	center = (2 + info->divide - 1) / 2;
	i = 2;
	while (++i <= center)
		(info->wall[i]) -= total / (info->divide * 2);
	i = center;
	while (++i < info->divide)
	{
		(info->wall)[i] += total / (info->divide + 2);
	}
}

void	set_wall(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->divide)
		(info->wall)[i] = info->total_len / info->divide * i;
	(info->wall)[info->divide] = info->total_len;
	if (info->divide == 5)
		set_wall_five(info);
	else if (info->divide == 15)
		set_wall_15(info);
	else
		set_wall_other(info);
}
