/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:02:31 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 18:16:51 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	cal_last_sum(int len, t_dlst *a)
{
	long	sum;
	int		i;

	sum = 0;
	i = 0;
	a = a->prev;
	while (i < len)
	{
		sum += a->value;
		a = a->prev;
		i++;
	}
	return (sum);
}

static int	check_two(t_dlst *last, int target)
{
	return (last->value == target + 1 && last->prev->value == target);
}

static void	pb_and_rb(t_info *info, t_dlst **ans, long border)
{
	pb(info, ans);
	if (dlst_back(info->b) < border)
		rb(info, ans);
}

void	push_a_to_b(int len, t_info *info, t_dlst **ans)
{
	int		i;
	long	sum;
	long	border;

	sum = cal_last_sum(len, info->a);
	border = sum / len - 4;
	i = 0;
	while (i < len && info->a->next->value != -1)
	{
		if (i < len - 1 && check_two(info->a->prev, info->target))
		{
			sa(info, ans);
			ra(info, ans);
			info->target += 1;
		}
		else if (dlst_back(info->a) == info->target)
		{
			ra(info, ans);
			info->target += 1;
		}
		else
			pb_and_rb(info, ans, border);
		i++;
	}
}
