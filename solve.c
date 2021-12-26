/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:12:12 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/26 12:41:30 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(int n, int *arr)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

t_info	*init_stack(int n, int *arr, t_dlst **ans)
{
	t_info	*info;
	t_dlst	*new;

	info = (t_info *)malloc(sizeof(t_info));
	info->a = ft_dlst_new(-1); // sentinel
	info->b = ft_dlst_new(-1);
	info->total = n;
	info->target = 0;
	while (n--)
	{
		new = ft_dlst_new(*(arr + n));
		ft_dlst_addback(&(info->a), new);
	}
	*ans = NULL;
	*ans = ft_dlst_new(-1);
	return (info);
}

static int	*set_wall_five(int *wall, int n)
{
	wall = (int *)malloc(sizeof(int) * 6);
	int i = -1;
	while (++i < 6)
		wall[i] = n / 5 * i;
	int	diff = 10;
	wall[3] -= diff - 3;
	wall[4] += diff + 3;
	wall[1] = 20;
	wall[2] = 40;
	wall[3] = 53;
	wall[4] = 93;
	return (wall);
}

static void	divide_five_block(t_info *info, t_dlst **ans, int *wall)
{
	int	len;

	set_border_a(info, wall[3], wall[4]);
	set_border_b(info, wall[0], wall[1]);
	divide_a_to_b(info->total, info, ans);
	// aからbへ１回目の移動が完了
	set_border_a(info, wall[4], wall[5]);
	set_border_b(info, wall[1], wall[2]);
	len = info->total - wall[1] - (wall[4] - wall[3]);
	divide_b_to_a(len, info, ans);
	// bからaへ２回目の移動が完了
}

int	solve(int n, int *arr)
{
	t_info	*info;
	t_dlst	*ans;
	int		len;
	int		i;
	int		*wall;

	if (ft_is_sorted(n, arr))
		return (0);
	info = init_stack(n, arr, &ans);
	wall = NULL;
	wall = set_wall_five(wall, n);
	// show(info);

	divide_five_block(info, &ans, wall);
	
	push_b_to_a(info, &ans);
	i = 3;
	while (i <= 5)
	{
		len = wall[i] - wall[i-1];
		push_a_to_b(len, info, &ans);
		push_b_to_a(info, &ans);
		i++;
	}
	// show(info);
	// show_ans(ans);
	ans = compress_ans(ans);
	ans = compress_ans(ans); // 複数回やらないと完全にはならない
	// show_ans(ans);
	return (ft_dlst_size(ans));
}
