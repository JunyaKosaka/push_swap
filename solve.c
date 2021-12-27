/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:12:12 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 15:56:02 by jkosaka          ###   ########.fr       */
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

t_info	*init_stack(int total_len, int *arr, t_dlst **ans)
{
	t_info	*info;
	t_dlst	*new;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->a = ft_dlst_new(-1); // sentinel
	info->b = ft_dlst_new(-1);
	if (!(info->a) || !(info->b))
		return (NULL);
	info->total = total_len;
	info->target = 0;
	info->a_size = total_len;
	info->b_size = 0;
	while (total_len--)
	{
		new = ft_dlst_new(*(arr + total_len));
		if (!new)
			return (NULL);
		ft_dlst_addback(&(info->a), new);
	}
	*ans = ft_dlst_new(-1);
	if (!(*ans))
		return (NULL);
	return (info);
}

int	*set_wall_five(int n)
{
	int	*wall;

	wall = (int *)malloc(sizeof(int) * 6);
	int i = -1;
	while (++i < 6)
		wall[i] = n / 5 * i;
	if (n > 90) {
		wall[3] -= n / 14; // 53
		wall[4] += n / 7;  // 93	
	}
	return (wall);
}

void	divide_five_block(t_info *info, t_dlst **ans, int *wall)
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

void	free_info(t_info *info)
{
	ft_dlst_clear(&(info->a));
	ft_dlst_clear(&(info->b));
	free(info);
	info = NULL;
}

// int	free_all(t_info *info, t_dlst **ans, int**arr)
// {
	
// 	return (-1);
// }

int	solve(int total_len, int *arr)
{
	t_info	*info;
	t_dlst	*ans;
	int		len;
	int		i;
	int		*wall;

	if (ft_is_sorted(total_len, arr))
		return (0);
	info = init_stack(total_len, arr, &ans);
	// if (!info)
	// 	return (free_all(info, ans, wall));
	show(info);
	wall = set_wall_five(total_len);
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
	free_info(info);
	// ans = compress_ans(ans);
	ans = compress_ans(ans); // 複数回やらないと完全にはならない
	show_ans(ans);
	len = ft_dlst_size(ans);
	ft_dlst_clear(&ans);
	free_int_arr(&wall);
	return (len);
}
