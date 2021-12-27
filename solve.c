/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:12:12 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 00:44:48 by jkosaka          ###   ########.fr       */
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
	info->a = ft_dlst_new(-1); // sentinel
	info->b = ft_dlst_new(-1);
	info->total = total_len;
	info->target = 0;
	info->a_size = total_len;
	info->b_size = 0;
	while (total_len--)
	{
		new = ft_dlst_new(*(arr + total_len));
		ft_dlst_addback(&(info->a), new);
	}
	*ans = ft_dlst_new(-1);
	// free(new);
	// new = NULL;
	return (info);
}

int	*set_wall_five(int *wall, int n)
{
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
	printf("a_malloc_size is %zu\n", malloc_size(info->a));
	printf("b_malloc_size is %zu\n", malloc_size(info->b));
	printf("info_malloc_size is %zu\n", malloc_size(info));
	wall = NULL;
	wall = set_wall_five(wall, total_len);
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
	ft_dlst_clear(&(info->a));
	ft_dlst_clear(&(info->b));
	printf("a_malloc_size is %zu\n", malloc_size(info->a));
	free(info);
	info = NULL;
	ans = compress_ans(ans);
	ans = compress_ans(ans); // 複数回やらないと完全にはならない
	// show_ans(ans);
	len = ft_dlst_size(ans);
	ft_dlst_clear(&ans);
	free(ans);
	ans = NULL;
	printf("ans_malloc_size is %zu\n", malloc_size(ans));
	printf("info_malloc_size is %zu\n", malloc_size(info));
	free(wall);
	wall = NULL;
	printf("wall_malloc_size is %zu\n", malloc_size(wall));
	return (len);
}
