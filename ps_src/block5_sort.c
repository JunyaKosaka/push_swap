/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block5_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:16:38 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 17:49:59 by jkosaka          ###   ########.fr       */
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
	// aからbへ１回目の移動が完了
	// show(info);
	set_border_a(info, 4, 5);
	set_border_b(info, 1, 2);
	len -= info->wall[1] + (info->wall[4] - info->wall[3]);
	divide_b_to_a(len, info);
	// show(info);
	// bからaへ２回目の移動が完了
}

static void	solve_five_core(t_info *info)
{
	int	i;
	int	len;

	push_b_to_a(info);
	i = 3;
	while (i <= info->divide)
	{
		len = info->wall[i] - info->wall[i - 1];
		push_a_to_b(len, info);
		push_b_to_a(info);
		i++;
	}
}

int	block5_sort(int total_len, int **arr)
{
	t_info	info;
	int		len;
	int		divide;

	divide = 5;
	info = init_stack(total_len, arr, divide);
	divide_five_blocks(&info);
	solve_five_core(&info);
	// show(info);
	info.ans = compress_ans(info.ans);
	// show_ans(info.ans);
	len = dlst_size(info.ans);
	free_all_info(&info, arr, FALSE);
	return (len);
}
