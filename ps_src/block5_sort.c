/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block5_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:16:38 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/03 23:04:46 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	divide_five_blocks(t_info *info)
{
	int	len;

	set_border_a(info, 3, 4);
	set_border_b(info, 0, 1);
	len = info->total_len;
	divide_a_to_b(len, info);
	set_border_a(info, 4, 5);
	set_border_b(info, 1, 2);
	len -= (info->wall)[1] + ((info->wall)[4] - (info->wall)[3]);
	divide_b_to_a(len, info);
}

static void	solve_five_core(t_info *info)
{
	int	i;
	int	len;

	push_b_to_a(info);
	i = 3;
	while (i <= info->divide)
	{
		len = (info->wall)[i] - (info->wall)[i - 1];
		push_a_to_b(len, info);
		push_b_to_a(info);
		i++;
	}
}

int	block5_sort(t_info *info)
{
	int		len;

	info->divide = 5;
	set_wall(info, 2);
	divide_five_blocks(info);
	solve_five_core(info);
	info->ans = compress_ans(info);
	len = dlst_size(info->ans);
	return (len);
}
