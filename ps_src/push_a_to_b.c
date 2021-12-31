/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:02:31 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 17:22:32 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_two(t_dlst *last, int target)
{
	return (last->value == target + 1 && last->prev->value == target);
}

static void	pb_and_rb(t_info *info, long border)
{
	pb(info);
	if (dlst_back(info->b) < border)
		rb(info);
}

void	push_a_to_b(int len, t_info *info)
{
	int		i;
	long	sum;
	long	border;

	sum = cal_last_sum(len, info->a);
	border = sum / len - 4;
	if (len > 33)
		border -= len / 30;
	i = 0;
	while (i < len && info->a->next->value != SENTINEL)
	{
		if (i < len - 1 && check_two(info->a->prev, info->target))
		{
			sa(info);
			ra(info);
			info->target += 1;
		}
		else if (dlst_back(info->a) == info->target)
		{
			ra(info);
			info->target += 1;
		}
		else
			pb_and_rb(info, border);
		i++;
	}
}
