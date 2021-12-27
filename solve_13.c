/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:12:12 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 20:24:51 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*set_wall_13(t_info *info, int n)
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
	wall[3] -= 10;
	wall[4] -= 20;
	wall[5] -= 30;
	wall[6] -= 40;
	wall[7] -= 50;
	// ここを大きく
	wall[8] += -20;
	wall[9] += 0;
	wall[10] += 20;
	wall[11] += 30;
	wall[12] += 20; // 4205
	// 今のところ上が良い
	// wall[3] -= 10;
	// wall[4] -= 30;
	// wall[5] -= 50;
	// wall[6] -= 70;
	// wall[7] -= 70;
	// // ここを大きく
	// wall[8] += -40;
	// wall[9] += 0;
	// wall[10] += 20;
	// wall[11] += 30;
	// wall[12] += 20; // 4244
	wall[info->divide] = info->total;
	// printf("25 %d %d\n", info->divide, info->total);
	// i = -1;
	// while (++i <= info->divide)
	// 	printf("wall %d %d \n", i, wall[i]);
	// if (n > 90)
	// {
	// 	wall[3] -= n / 14; // 53
	// 	wall[4] += n / 7;  // 93
	// }
	return (wall);
}

static void	divide_13_block(t_info *info, t_dlst **ans, int *wall)
{
	int	i;
	int	len;

	i = 0;
	len = info->total;
	while (i < 6)
	{
		set_border_a(info, wall[7 + i], wall[8 + i]);
		set_border_b(info, wall[0 + i], wall[1 + i]);
		divide_a_to_b(len, info, ans);
		len -= wall[8 + i] - wall[7 + i] + wall[1 + i] - wall[0 + i];
		// aからbへ１回目の移動が完了
		set_border_a(info, wall[8 + i], wall[9 + i]);
		set_border_b(info, wall[1 + i], wall[2 + i]);
		divide_b_to_a(len, info, ans);
		len -= wall[9 + i] - wall[8 + i] + wall[2 + i] - wall[1 + i];
		// bからaへ２回目の移動が完了
		i += 2;
	}
}

void	solve_13_core(t_info *info, t_dlst **ans, int *wall)
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
	i = 7;
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

int	solve_13(int total_len, int *arr)
{
	t_info	*info;
	t_dlst	*ans;
	int		len;
	int		*wall;

	if (ft_is_sorted(total_len, arr))
		return (0);
	info = init_stack(total_len, arr, &ans);
	info->divide = 13;
	if (!info)
		return (free_all_info(info, ans, &wall));
	wall = set_wall_13(info, total_len);
	if (!wall)
		return (free_all_info(info, ans, &wall));
	divide_13_block(info, &ans, wall);
	// show(info);
	// printf("divide done %d\n", ft_dlst_size(ans));
	solve_13_core(info, &ans, wall);
	// show(info);
	ans = compress_ans(ans);
	// show_ans(ans);
	len = ft_dlst_size(ans);
	free_all_info(info, ans, &wall);
	return (len);
}
