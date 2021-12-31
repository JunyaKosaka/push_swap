/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:35:02 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 14:01:54 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_wall_five(t_info *info)
{
	if (info->total_len > 90)
	{
		(info->wall)[3] -= info->total_len / 14; // 53
		(info->wall)[4] += info->total_len / 7;  // 93
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
	(info->wall)[8] += total / 500;
	// ここを大きく
	(info->wall)[9] += total / 20 - 1;
	(info->wall)[10] += total / 15 - 1;
	(info->wall)[11] += total / 14 - 1;
	(info->wall)[12] += total / 15 - 1;
	(info->wall)[13] += total / 17 - 1;
	(info->wall)[14] += total / 29; // 3811
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
	if (info->divide == 15)
		set_wall_15(info);
}
