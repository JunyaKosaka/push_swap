/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk5_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:16:38 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 01:20:28 by jkosaka          ###   ########.fr       */
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
	set_border_a(info, 4, 5);
	set_border_b(info, 1, 2);
	len -= (info->wall)[1] - (info->wall)[0];
	len -= (info->wall)[4] - (info->wall)[3];
	divide_b_to_a(len, info);
}

static void	line_up(t_info *info)
{
	int	i;
	int	len;

	push_b_to_a(info);
	i = 3;
	while (i <= info->divide)
	{
		len = (info->wall)[i] - (info->wall)[i - 1];
		push_a_to_b(len, info);
		push_b_to_a(info);
		i++;
	}
}

void	change_lead(t_info *info)
{
	t_dlst	*cur;

	cur = info->a->next;
	while (cur->value != SENTINEL)
	{
		if (cur->value < 3)
			cur->value += info->total_len;
		cur = cur->next;
	}
	info->target = 3;
}

int	chunk5_sort(t_info *info)
{
	int		len;

	info->divide = 5;
	set_wall(info, 2);
	change_lead(info);
	divide_five_blocks(info);
	line_up(info);
	final_three(info);
	info->ans = compress_ans(info);
	len = dlst_size(info->ans);
	return (len);
}
