/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quick_15.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:19:39 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/28 20:11:20 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*set_wall_15(t_info *info, int n)
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
	wall[1] -= 2;
	wall[2] -= 2;
	wall[3] -= 13;
	wall[4] -= 15;
	wall[5] -= 13;
	wall[6] -= 10;
	wall[7] -= 7;
	wall[8] += 3;
	// ここを大きく
	wall[9] += 20;
	wall[10] += 25;
	wall[11] += 25;
	wall[12] += 25;
	wall[13] += 20;
	wall[14] += 17; // 3860
	// wall[1] -= 2;
	// wall[2] -= 2;
	// wall[3] -= 13;
	// wall[4] -= 15;
	// wall[5] -= 13;
	// wall[6] -= 10;
	// wall[7] -= 7;
	// wall[8] += 3;
	// // ここを大きく
	// wall[9] += 20;
	// wall[10] += 25;
	// wall[11] += 25;
	// wall[12] += 25;
	// wall[13] += 20;
	// wall[14] += 17; // 3860


	wall[info->divide] = info->total;
	return (wall);
}

static int	to_got_bottom_b(t_info *info, int *wall)
{
	int	last;
	int	i;

	last = dlst_back(info->b);
	if (wall[1] <= last && last < wall[2])
		return (1);
	i = 2;
	while (i < info->divide)
	{
		if (wall[i] <= last && last < wall[i + 1])
			return (1);
		i += 2;
	}
	return (0);
}

static void	divide_first_a_to_b(t_info *info, t_dlst **ans, int *wall)
{
	int	i;

	i = 0;
	set_border_a(info, wall[8], wall[9]);
	while (i < info->total)
	{
		if (isin(info->border_a, dlst_back(info->a)))
			ra(info, ans);
		else
		{
			pb(info, ans);
			if (to_got_bottom_b(info, wall))
				rb(info, ans);
		}
		i++;
	}
}

static void	divide_15_block(t_info *info, t_dlst **ans, int *wall)
{
	int	i;
	int	j;
	int	len;
	int	last;

	// aからbへ１回目の分配
	divide_first_a_to_b(info, ans, wall);
	i = 0;
	while (i < 3)
	{
		len = info->b_size;
		j = 0;
		while (j < len)
		{
			last = dlst_back(info->b);
			if (wall[6 - 2 * i] <= last && last < wall[11 + 2 * i])
			{
				pa(info, ans);
				if (wall[9] <= last)
					ra(info, ans);
			}
			else
				rb(info, ans);
			j++;
		}
		i++;
	}
}

void	solve_15_core(t_info *info, t_dlst **ans, int *wall)
{
	int	i;
	int	len;

	push_b_to_a(info, ans);
	// show(info);
	// printf("onetime done %d\n", ft_dlst_size(*ans));
	i = 3;
	while (i <= info->divide)
	{
		len = wall[i] - wall[i-1];
		push_a_to_b(len, info, ans);
		push_b_to_a(info, ans);
		i++;
	}
}

int	solve_quick_15(int total_len, int *arr)
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
	info->divide = 15;
	wall = set_wall_15(info, total_len);
	if (!wall)
		return (free_all_info(info, ans, &wall));
	divide_15_block(info, &ans, wall);
	// show(info);
	solve_15_core(info, &ans, wall);
	// show(info);
	assert(info->b_sum == 0);
	ans = compress_ans(ans);
	len = ft_dlst_size(ans);
	free_all_info(info, ans, &wall);
	return (len);
}
