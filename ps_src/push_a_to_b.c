/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:02:31 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 01:40:47 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	sa_and_pb_and_rb(t_info *info, long border, int i, int len)
{
	sa(info);
	pb_and_rb(info, border, i, len);
}

void	push_a_to_b(int len, t_info *info)
{
	int		i;
	long	sum;
	long	border;

	sum = cal_last_sum(len, info->a);
	border = set_border(sum, len);
	i = -1;
	while (++i < len && info->a_size && info->target < info->total_len)
	{
		check_b(info);
		if (info->target >= info->total_len)
			break ;
		if (i < len - 1 && check_two(dlst_rbegin(info->a), info->target))
			sa_and_ra(info);
		else if (dlst_back(info->a) == info->target)
		{
			ra(info);
			info->target += 1;
		}
		else if (i < len - 2 && check_three(dlst_rbegin(info->a), info->target))
			sa_and_pb_and_rb(info, border, i, len);
		else
			pb_and_rb(info, border, i, len);
	}
}
