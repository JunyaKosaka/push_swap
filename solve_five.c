/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_five.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:12:12 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 20:24:51 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*set_wall_five(t_info *info, int n)
{
	int	*wall;
	int i;

	wall = (int *)malloc(sizeof(int) * (info->divide + 1));
	if (!wall)
		return (NULL);
	i = -1;
	while (++i <= info->divide)
		wall[i] = n / (info->divide) * i;
	if (n > 90)
	{
		wall[3] -= n / 14; // 53
		wall[4] += n / 7;  // 93
	}
	wall[info->divide] = info->total;
	return (wall);
}

static void	divide_five_block(t_info *info, t_dlst **ans, int *wall)
{
	int	len;

	// show(info);
	set_border_a(info, wall[3], wall[4]);
	set_border_b(info, wall[0], wall[1]);
	divide_a_to_b(info->total, info, ans);
	// aからbへ１回目の移動が完了
	// show(info);
	set_border_a(info, wall[4], wall[5]);
	set_border_b(info, wall[1], wall[2]);
	len = info->total - wall[1] - (wall[4] - wall[3]);
	divide_b_to_a(len, info, ans);
	// show(info);
	// bからaへ２回目の移動が完了
}

void	solve_five_core(t_info *info, t_dlst **ans, int *wall)
{
	int	i;
	int	len;

	push_b_to_a(info, ans);
	i = 3;
	while (i <= 5)
	{
		len = wall[i] - wall[i-1];
		push_a_to_b(len, info, ans);
		push_b_to_a(info, ans);
		i++;
	}
}

int	solve_five(int total_len, int *arr)
{
	t_info	*info;
	t_dlst	*ans;
	int		len;
	int		*wall;

	if (ft_is_sorted(total_len, arr))
		return (0);
	info = init_stack(total_len, arr, &ans);
	if (!info)
		return (free_all_info(info, ans, &wall));
	info->divide = 5;
	wall = set_wall_five(info, total_len);
	if (!wall)
		return (free_all_info(info, ans, &wall));
	divide_five_block(info, &ans, wall);
	solve_five_core(info, &ans, wall);
	ans = compress_ans(ans);
	show_ans(ans);
	len = ft_dlst_size(ans);
	free_all_info(info, ans, &wall);
	return (len);
}
