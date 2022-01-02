/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:56:17 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/02 17:03:45 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*   check b front ans back   */
void	check_b(t_info *info)
{
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
