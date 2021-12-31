/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block5_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:16:38 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 15:15:14 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	divide_five_block(t_info *info)
{
	int	len;

	// show(info);
	set_border_a(info, 3, 4);
	set_border_b(info, 0, 1);
	len = info->total_len;
	divide_a_to_b(len, info);
	exit(1);
	// aからbへ１回目の移動が完了
	// show(info);
	set_border_a(info, 4, 5);
	set_border_b(info, 1, 2);
	len -= info->wall[1] - (info->wall[4] - info->wall[3]);
	divide_b_to_a(len, info);
	// show(info);
	// bからaへ２回目の移動が完了
}

int	block5_sort(int total_len, int **arr)
{
	t_info	info;
	int		len;
	int		divide;

	divide = 5;
	info = init_stack(total_len, arr, divide);
	len = 0;
	divide_five_block(&info);
	return (len);
	// // printf("divide done %d\n", dlst_size(ans));
	// solve_five_core(info, &ans, wall);
	// ans = compress_ans(ans);
	// // show_ans(ans);
	// len = dlst_size(ans);
	// free_all_info(info, ans, &wall);
	free_all_info(&info, arr, FALSE);
	return (len);
}
