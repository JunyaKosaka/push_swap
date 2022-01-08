/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:58:34 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 00:06:12 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	line_up(t_info *info)
{
	int	i;
	int	len;

	push_b_to_a(info);
	i = 4;
	while (i < info->divide)
	{
		len = (info->wall)[i + 1] - (info->wall)[i];
		push_a_to_b(len, info);
		push_b_to_a(info);
		i++;
	}
}

int	deque_sort(t_info *info)
{
	int		len;
	// t_dlst	*cur;

	info->divide = 5 + 8 * (info->total_len / 220);
	if (info->divide == 5)
		info->divide = 13;
	set_wall(info, 4);
	change_lead(info);
	// cur = info->a->next;
	// while (cur->value != SENTINEL)
	// {
	// 	if (cur->value < 3)
	// 		cur->value += info->total_len;
	// 	cur = cur->next;
	// }
	// info->target = 3;
	divide_chunks_dq(info);
	line_up(info);
	final_three(info);
	info->ans = compress_ans(info);
	len = dlst_size(info->ans);
	return (len);
}
