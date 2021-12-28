/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:20:03 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/28 12:27:29 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_core(t_info *info, t_dlst **ans)
{
	int		i;
	int		move;
	int		len;
	long	border;

	if (info->b_size < 30)
	{
		push_b_to_a(info, ans);
		return ;
	}		
	// 2つに分ける
	move = 0;
	len = info->b_size;
	border = info->b_sum / info->b_size;
	i = 0;
	while (i < len)
	{
		if (dlst_back(info->b) == info->target)
		{
			pa(info, ans);
			ra(info, ans);
			info->target += 1;
		}
		else if (dlst_back(info->b) < border)
		{
			rb(info, ans);
		}
		else
		{
			pa(info, ans);
			move++;
		}
		i++;
	}
	quick_sort_core(info, ans);
	push_a_to_b(move, info, ans);
	quick_sort_core(info, ans);
}

int	solve_quick(int total_len, int *arr)
{
	t_info	*info;
	t_dlst	*ans;
	int		len;
	int		border;
	int		stay;

	if (ft_is_sorted(total_len, arr))
		return (0);
	stay = 0;
	info = init_stack(total_len, arr, &ans);
	// info->divide = 13;
	if (!info)
		return (free_all_info(info, ans, NULL));
	border = total_len / 2;
	while (total_len)
	{
		if (dlst_back(info->a) >= border)
		{
			ra(info, &ans);
			stay++;
		}
		else
		{
			pb(info, &ans);
		}
		total_len--;
	}
	quick_sort_core(info, &ans);
	push_a_to_b(stay, info, &ans);
	quick_sort_core(info, &ans);
	// show(info);
	assert(info->b_sum == 0);
	ans = compress_ans(ans);
	// show_ans(ans);
	len = ft_dlst_size(ans);
	free_all_info(info, ans, NULL);
	return (len);
}
