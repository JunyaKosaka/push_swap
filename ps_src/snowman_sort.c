/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snowman_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:39:38 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 18:26:13 by jkosaka          ###   ########.fr       */
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

static void	divide_blocks(t_info *info) // 別ファイルへ
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

// void	solve_15_core(t_info *info, t_dlst **ans, int *wall)
// {
// 	int	i;
// 	int	len;

// 	push_b_to_a(info, ans);
// 	// show(info);
// 	// printf("onetime done %d\n", ft_dlst_size(*ans));
// 	i = 3;
// 	while (i <= info->divide)
// 	{
// 		len = wall[i] - wall[i-1];
// 		push_a_to_b(len, info, ans);
// 		push_b_to_a(info, ans);
// 		i++;
// 	}
// }

int	snowman_sort(int total_len, int **arr)
{
	t_info	info;
	int		len;
	int		divide;

	divide = 3 + 4 * (total_len / 150);
	if (divide == 3)
		divide = 7;
	info = init_stack(total_len, arr, divide);
	show(info);
	divide_blocks(&info);
	show(info);
	exit(0);
	// // show(info);
	// solve_15_core(info, &ans, wall);
	// // show(info);
	// assert(info->b_sum == 0);
	// ans = compress_ans(ans);
	// // show_ans(ans);
	// len = ft_dlst_size(ans);
	// free_all_info(info, ans, &wall);
	return (len);
}
