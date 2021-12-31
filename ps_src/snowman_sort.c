/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snowman_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:39:38 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/01 01:28:43 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	line_up(t_info *info)
{
	int	i;
	int	len;

	push_b_to_a(info);
	i = 2;
	while (i < info->divide)
	{
		len = (info->wall)[i + 1] - (info->wall)[i];
		push_a_to_b(len, info);
		push_b_to_a(info);
		i++;
	}
}

int	snowman_sort(int total_len, int **arr)
{
	t_info	info;
	int		len;
	int		divide;

	divide = 3 + 4 * (total_len / 150);
	if (divide == 3)
		divide = 7;
	info = init_stack(total_len, arr, divide);
	divide_blocks(&info);
	line_up(&info);
	assert(info.b_size == 0);
	info.ans = compress_ans(info.ans);
	// show_ans(info.ans);
	len = dlst_size(info.ans);
	free_all_info(&info, arr, FALSE);
	return (len);
}
