/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:35:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/03 23:04:46 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_wall_five(t_info *info)
{
	int	total;
	int	*wall;

	wall = (info->wall);
	total = info->total_len;
	if (total > 90)
	{
		wall[2] += total / 40;
		wall[3] -= total / 14 - total / 22;
		wall[4] += total / 7 - total / 80;
	}
}

static void	set_wall_21(t_info *info)
{
	int	total;
	int	*wall;

	wall = (info->wall);
	total = info->total_len;
	wall[4] -= total / 150;
	wall[8] -= total / 150;
	wall[9] -= total / 100;
	wall[10] -= total / 100;
	wall[11] += total / 60;
	wall[12] += total / 41;
	wall[13] += total / 100;
	wall[14] += total / 100;
	wall[15] += total / 100;
	wall[16] += total / 150;
	wall[17] += total / 150;
	wall[18] += total / 150;
	wall[19] += total / 150;
	wall[20] += total / 70;
}

static void	set_wall_other(t_info *info, int a_top_index)
{
	int	total;
	int	center;
	int	i;

	total = info->total_len;
	center = (a_top_index + info->divide - 1) / 2;
	i = a_top_index;
	while (++i <= center)
		(info->wall)[i] -= total / (info->divide * 2);
	i = center;
	while (++i < info->divide)
	{
		(info->wall)[i] += total / (info->divide + 2);
	}
}

void	set_wall(t_info *info, int a_top_index)
{
	int	i;

	i = -1;
	while (++i < info->divide)
		(info->wall)[i] = info->total_len / info->divide * i;
	(info->wall)[info->divide] = info->total_len;
	if (info->divide == 5)
		set_wall_five(info);
	else
		set_wall_other(info, a_top_index);
	if (info->divide == 21)
		set_wall_21(info);
}
