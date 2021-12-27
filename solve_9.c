/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:12:12 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 20:24:51 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*set_wall_9(t_info *info, int n)
{
	int	*wall;
	int i;

	wall = (int *)malloc(sizeof(int) * (info->divide + 1));
	if (!wall)
		return (NULL);
	i = -1;
	while (++i <= info->divide)
	{
		wall[i] = n / (info->divide) * i;
	}
	// wall[3] -= 10;
	// wall[4] -= 20;
	// wall[5] -= 30;
	// // ここを大きく
	// wall[6] += 10;
	// wall[7] += 30;
	// wall[8] += 30;
	wall[3] -= 5;
	wall[4] -= 10;
	wall[5] -= 15;
	// ここを大きく
	wall[6] += 10;
	wall[7] += 10;
	wall[8] += 13; // 200の時はこれが良さそう
	wall[info->divide] = info->total;
	return (wall);
}

static void	divide_9_block(t_info *info, t_dlst **ans, int *wall)
{
	int	i;
	int	len;

	i = 0;
	len = info->total;
	while (i < 4)
	{
		set_border_a(info, wall[5 + i], wall[6 + i]);
		set_border_b(info, wall[0 + i], wall[1 + i]);
		divide_a_to_b(len, info, ans);
		len -= wall[6 + i] - wall[5 + i] + wall[1 + i] - wall[0 + i];
		// aからbへ１回目の移動が完了
		set_border_a(info, wall[6 + i], wall[7 + i]);
		set_border_b(info, wall[1 + i], wall[2 + i]);
		divide_b_to_a(len, info, ans);
		len -= wall[7 + i] - wall[6 + i] + wall[2 + i] - wall[1 + i];
		// bからaへ２回目の移動が完了
		i += 2;
	}
}

void	solve_9_core(t_info *info, t_dlst **ans, int *wall)
{
	int	i;
	int	len;

	// show(info);
	// printf("wall %d %d\n", wall[0], wall[1]);
	// quick_sort_b(len, info, ans);
	push_b_to_a(info, ans);
	// show(info);
	push_b_to_a(info, ans);
	// show(info);
	// printf("divide done %d\n", ft_dlst_size(*ans));
	i = 5;
	while (i <= info->divide)
	{
		len = wall[i] - wall[i-1];
		// printf("target %d\n", info->target);
		push_a_to_b(len, info, ans);
		// printf("target %d\n", info->target);
		
		// printf("69 len %d\n", len);
		// show(info);
		// printf("a_size %d b_size %d\n", info->a_size, info->b_size);
		push_b_to_a(info, ans);
		// show(info);
		// printf("80 &&&&&&&&&&&&&\n");
		i++;
	}
	// printf("core done\n");
}

int	solve_9(int total_len, int *arr)
{
	t_info	*info;
	t_dlst	*ans;
	int		len;
	int		*wall;

	if (ft_is_sorted(total_len, arr))
		return (0);
	info = init_stack(total_len, arr, &ans);
	info->divide = 9;
	if (!info)
		return (free_all_info(info, ans, &wall));
	wall = set_wall_9(info, total_len);
	if (!wall)
		return (free_all_info(info, ans, &wall));
	divide_9_block(info, &ans, wall);
	// show(info);
	// printf("divide done %d\n", ft_dlst_size(ans));
	solve_9_core(info, &ans, wall);
	// show(info);
	ans = compress_ans(ans);
	// show_ans(ans);
	len = ft_dlst_size(ans);
	free_all_info(info, ans, &wall);
	return (len);
}
