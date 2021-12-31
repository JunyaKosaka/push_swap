/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snowman_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:39:38 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/01 00:58:11 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
