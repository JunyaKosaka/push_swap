/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:49:06 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/06 23:02:24 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	two_sort(t_info *info)
{
	int	first;
	int	second;

	first = info->a->next->value;
	second = dlst_back(info->a);
	if (first > second)
		return (0);
	sa(info);
	return (1);
}

static int	check_two(t_info *info)
{
	int	top;
	int	top2;

	top = dlst_back(info->a);
	top2 = dlst_rbegin(info->a)->prev->value;
	return (top > top2);
}

static int	three_sort(t_info *info)
{
	int	first;
	int	second;
	int	third;

	first = info->a->next->value;
	second = info->a->next->next->value;
	third = dlst_back(info->a);
	if (first > third && first > second)
	{
		if (second < third)
			sa(info);
		return (dlst_size(info->ans));
	}
	if (second > third)
		rra(info);
	else
		ra(info);
	second = info->a->next->next->value;
	third = dlst_back(info->a);
	if (check_two(info))
		sa(info);
	return (dlst_size(info->ans));
}

static int	less7_sort(t_info *info)
{
	while (info->a_size > 3)
	{
		if (dlst_back(info->a) < info->total_len - 3)
			pb(info);
		else
			ra(info);
	}
	three_sort(info);
	if (dlst_back(info->b) == 0)
		rb(info);
	pa(info);
	if (dlst_back(info->b) == 0)
		rb(info);
	pa(info);
	if (check_two(info))
		sa(info);
	pa(info);
	if (check_two(info))
		sa(info);
	info->ans = compress_ans(info);
	return (dlst_size(info->ans));
}

int	small_size_sort(t_info *info)
{
	int		len;
	t_dlst	*cur;

	if (info->total_len == 2)
		return (two_sort(info));
	else if (info->total_len == 3)
		return (three_sort(info));
	if (info->total_len < 7)
		return (less7_sort(info));
	info->divide = 3;
	set_wall(info, 2);
	cur = info->a->next;
	while (cur->value != SENTINEL)
	{
		if (cur->value < 3)
			cur->value += info->total_len;
		cur = cur->next;
	}
	info->target = 3;
	set_border_a(info, 2, 3);
	set_border_b(info, 1, 2);
	divide_a_to_b(info->total_len, info);
	push_b_to_a(info);
	len = (info->wall)[3] - (info->wall)[2];
	push_a_to_b(len, info);
	push_b_to_a(info);
	final_three(info);
	info->ans = compress_ans(info);
	len = dlst_size(info->ans);
	return (len);
}
