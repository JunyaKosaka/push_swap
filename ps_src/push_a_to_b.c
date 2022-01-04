/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:02:31 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/04 01:55:11 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_three(t_dlst *last, int target)
{
	t_dlst	*last2;

	last2 = last->prev;
	return (last->value == target + 1 && last2->prev->value == target);
}

static int	check_two(t_dlst *last, int target)
{
	return (last->value == target + 1 && last->prev->value == target);
}

static void	pb_and_rb(t_info *info, long border, int i, int len)
{
	int	b_last2;

	pb(info);
	b_last2 = dlst_rbegin(info->b)->prev->value;
	if (i >= len - 5)
		return ;
	if (dlst_back(info->b) < border && b_last2 >= border)
		rb(info);
}

static void	sa_and_ra(t_info *info)
{
	sa(info);
	ra(info);
	info->target += 1;
}

void	push_a_to_b(int len, t_info *info)
{
	int		i;
	long	sum;
	long	border;

	sum = cal_last_sum(len, info->a);
	border = set_border(sum, len);
	i = -1;
	while (++i < len && info->a_size)
	{
		check_b(info);
		if (i < len - 1 && check_two(dlst_rbegin(info->a), info->target))
			sa_and_ra(info);
		else if (dlst_back(info->a) == info->target)
		{
			ra(info);
			info->target += 1;
		}
		else if (i < len - 2 && check_three(dlst_rbegin(info->a), info->target))
		{
			sa(info);
			pb_and_rb(info, border, i, len);
		}
		else
			pb_and_rb(info, border, i, len);
	}
}
