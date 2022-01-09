/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:56:17 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 10:39:33 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*   check b front ans back   */
void	check_b(t_info *info)
{
	if (info->target >= info->total_len)
		return ;
	if (dlst_back(info->b) == info->target)
	{
		pa(info);
		ra(info);
		info->target += 1;
	}
	else if (info->b->next->value == info->target)
	{
		rrb(info);
		pa(info);
		ra(info);
		info->target += 1;
	}
}

bool	check_three(t_dlst *last, int target)
{
	t_dlst	*last3;

	last3 = last->prev->prev;
	return (last->value == target + 1 && last3->value == target);
}

bool	check_two(t_dlst *last, int target)
{
	return (last->value == target + 1 && last->prev->value == target);
}
